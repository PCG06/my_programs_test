#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>

// Global declarations

#define SCREEN_WIDTH 640     // Width of the game window
#define SCREEN_HEIGHT 480    // Height of the game window
#define TILE_SIZE 20         // Size of each unit (snake segments and food)
#define SNAKE_MAX_LENGTH 100 // Maximum snake length

// Structure to represent 2D coordinates
typedef struct
{
    int x, y;
} Point;

SDL_Window *window = NULL;     // SDL window
SDL_Renderer *renderer = NULL; // SDL renderer

Point snake[SNAKE_MAX_LENGTH]; // Array representing the snake's body segments
int snake_length = 5;          // Initial snake length
Point food;                    // Position of the food
int dx = TILE_SIZE, dy = 0;    // Snake movement direction
bool running = true;           // Game state flag

// Function declarations
void setup_game(void);
void handle_player_input(void);
void update_snake(void);
void render_graphics(void);
void spawn_food(void);
bool check_snake_collision(void);

int main(void)
{
    setup_game();
    spawn_food();

    while (running)
    {
        handle_player_input();
        update_snake();
        render_graphics();
        SDL_Delay(20); // Controls the game speed
    }

    // Cleanup SDL resources before exiting
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// Initializes the SDL window, renderer, and sets up the initial snake position.
void setup_game(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Place the snake in the center of the screen
    for (int i = 0; i < snake_length; i++)
    {
        snake[i].x = SCREEN_WIDTH / 2 - i * TILE_SIZE;
        snake[i].y = SCREEN_HEIGHT / 2;
    }
}

// Processes user input to control the snake's movement.
void handle_player_input(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) 
            running = false;
        else if (e.type == SDL_KEYDOWN)
        {
            // Prevent the snake from reversing its direction
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
            }
        }
    }
}

// Updates the game state, moves the snake, checks for collisions,
// and handles food consumption.
void update_snake(void)
{
    // Compute new head position based on direction
    Point new_head = {snake[0].x + dx, snake[0].y + dy};
    
    // Check if the snake collides with walls or itself
    if (new_head.x < 0 || new_head.x >= SCREEN_WIDTH || 
        new_head.y < 0 || new_head.y >= SCREEN_HEIGHT || 
        check_snake_collision())
    {
        running = false; 
        return;
    }
    
    // Move the snake forward (shift segments)
    for (int i = snake_length; i > 0; i--)
        snake[i] = snake[i - 1];

    snake[0] = new_head; // Update head position
    
    // Check if the snake eats food
    if (new_head.x == food.x && new_head.y == food.y)
    {
        snake_length++; // Grow the snake
        spawn_food();   // Generate new food position
    }
}

// Checks if the snake collides with itself.
// Returns true if there is a collision, false otherwise.
bool check_snake_collision(void)
{
    for (int i = 1; i < snake_length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    return false;
}

// Spawns food at a random position on the grid.
void spawn_food(void)
{
    srand((unsigned int)time(NULL));

    food.x = (rand() % (SCREEN_WIDTH / TILE_SIZE)) * TILE_SIZE;
    food.y = (rand() % (SCREEN_HEIGHT / TILE_SIZE)) * TILE_SIZE;
}

// Renders the game graphics including the snake and food.
void render_graphics(void)
{
    // Clear the screen with a black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the food (red)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect food_rect = {food.x, food.y, TILE_SIZE, TILE_SIZE};
    SDL_RenderFillRect(renderer, &food_rect);

    // Draw the snake (green)
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < snake_length; i++)
    {
        SDL_Rect r = {snake[i].x, snake[i].y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(renderer, &r);
    }

    // Display the rendered content
    SDL_RenderPresent(renderer);
}
