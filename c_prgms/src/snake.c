#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Global constants
#define SCREEN_WIDTH     640 // Game window width
#define SCREEN_HEIGHT    480 // Game window height
#define TILE_SIZE        20  // Size of each snake segment and food
#define SNAKE_MAX_LENGTH 100 // Maximum allowed length of the snake
#define FRAME_DELAY      100 // Delay in milliseconds between frames

// Structure to represent a 2D point
typedef struct
{
    int x, y;
} Point;

// SDL components
SDL_Window *window = NULL;     // Game window
SDL_Renderer *renderer = NULL; // Renderer for drawing graphics
TTF_Font *font = NULL;         // Font for displaying score

// Game state variables
Point snake[SNAKE_MAX_LENGTH]; // Array holding snake segments
int snake_length = 5;          // Initial length of the snake
Point food;                    // Position of the food
int dx = TILE_SIZE, dy = 0;    // Movement direction of the snake
bool running = true;           // Game running state
bool paused = false;           // Pause flag
int score = 0;                 // Player score

// Function declarations
void setup_game(void);
void reset_game(void);
void handle_player_input(void);
void update_snake(void);
bool check_snake_collision(void);
void spawn_food(void);
void render_graphics(void);
void render_score(void);

int main(void)
{
    setup_game();
    spawn_food();

    unsigned long int last_tick = SDL_GetTicks();
    
    while (running)
    {
        handle_player_input();
        
        if (!paused && SDL_GetTicks() - last_tick >= FRAME_DELAY)
        {
            update_snake();
            last_tick = SDL_GetTicks();
        }
        
        render_graphics();
    }

    // Cleanup SDL resources
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    return 0;
}

// Initializes SDL, sets up the game window, renderer, and font.
// Resets the game state and prepares the game for the first run.
void setup_game(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    font = TTF_OpenFont("../assets/fonts/arial.ttf", 24);

    srand((unsigned int)time(NULL)); // Seed the RNG
    
    reset_game();
}

// Resets the game state including snake position, score, and food placement.
void reset_game(void)
{
    snake_length = 5;
    score = 0;
    dx = TILE_SIZE;
    dy = 0;
    
    for (int i = 0; i < snake_length; i++)
    {
        snake[i].x = SCREEN_WIDTH / 2 - i * TILE_SIZE;
        snake[i].y = SCREEN_HEIGHT / 2;
    }
    
    spawn_food(); // Place new food
}

// Handles user input, including key presses for movement and pausing the game.
void handle_player_input(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            running = false;
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
                case SDLK_UP:
                    if (dy == 0)
                    {
                        dx = 0;
                        dy = -TILE_SIZE;
                    }
                    break;
                case SDLK_DOWN:
                    if (dy == 0)
                    {
                        dx = 0;
                        dy = TILE_SIZE;
                    }
                    break;
                case SDLK_LEFT:
                    if (dx == 0)
                    {
                        dx = -TILE_SIZE;
                        dy = 0;
                    }
                    break;
                case SDLK_RIGHT:
                    if (dx == 0)
                    {
                        dx = TILE_SIZE;
                        dy = 0;
                    }
                    break;
                case SDLK_SPACE:
                    paused = !paused; // Toggle pause
                    break;
                case SDLK_r:
                    reset_game(); // Restart game
                    break;
            }
        }
    }
}

// Updates the snake's position, checks for collisions, and handles food consumption.
void update_snake(void)
{
    // Compute new head position
    Point new_head = {snake[0].x + dx, snake[0].y + dy};

    // Check for collisions
    if (new_head.x < 0 || new_head.x >= SCREEN_WIDTH || 
        new_head.y < 0 || new_head.y >= SCREEN_HEIGHT || 
        check_snake_collision())
    {
        reset_game();
        return;
    }

    // Shift body forward
    for (int i = snake_length; i > 0; i--)
        snake[i] = snake[i - 1];

    // Update new head position
    snake[0] = new_head;

    // Check if food is eaten
    if (new_head.x == food.x && new_head.y == food.y)
    {
        if (snake_length < SNAKE_MAX_LENGTH)
            snake_length++;
        
        score += 10;
        spawn_food();
    }
}

// Checks if the snake has collided with itself.
// Returns true if a collision is detected, false otherwise.
bool check_snake_collision(void)
{
    for (int i = 1; i < snake_length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    return false;
}

// Spawns food at a random position, ensuring it does not overlap with the snake.
void spawn_food(void)
{
    bool valid;
    do
    {
        valid = true;
        food.x = (rand() % (SCREEN_WIDTH / TILE_SIZE)) * TILE_SIZE;
        food.y = (rand() % (SCREEN_HEIGHT / TILE_SIZE)) * TILE_SIZE;

        for (int i = 0; i < snake_length; i++)
        {
            if (food.x == snake[i].x && food.y == snake[i].y)
            {
                valid = false;
                break;
            }
        }
    } while (!valid);
}

// Renders the snake, food, and score on the screen.
void render_graphics(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render food
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect food_rect = {food.x, food.y, TILE_SIZE, TILE_SIZE};
    SDL_RenderFillRect(renderer, &food_rect);

    // Render snake
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < snake_length; i++)
    {
        SDL_Rect r = {snake[i].x, snake[i].y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(renderer, &r);
    }

    render_score();
    SDL_RenderPresent(renderer);
}

// Renders the current score at the top-left corner of the screen.
void render_score(void)
{
    SDL_Color white = {255, 255, 255, 255};
    char score_text[20];
    sprintf(score_text, "Score: %d", score);

    SDL_Surface *surface = TTF_RenderText_Solid(font, score_text, white);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {10, 10, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
