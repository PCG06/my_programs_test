#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TILE_SIZE 20
#define SNAKE_MAX_LENGTH 100

typedef struct
{
    int x, y;
} Point;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

Point snake[SNAKE_MAX_LENGTH];
int snake_length = 5;
Point food;
int dx = TILE_SIZE, dy = 0;
bool running = true;

void init(void);
void handle_input(void);
void update(void);
void render(void);
void place_food(void);
bool check_collision(void);

int main(void)
{
    init();
    place_food();

    while (running)
    {
        handle_input();
        update();
        render();
        SDL_Delay(100); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    for (int i = 0; i < snake_length; i++)
    {
        snake[i].x = SCREEN_WIDTH / 2 - i * TILE_SIZE;
        snake[i].y = SCREEN_HEIGHT / 2;
    }
}

void handle_input(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) running = false;
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
            }
        }
    }
}

void update(void)
{
    Point new_head = {snake[0].x + dx, snake[0].y + dy};
    
    if (new_head.x < 0 || new_head.x >= SCREEN_WIDTH || new_head.y < 0 || new_head.y >= SCREEN_HEIGHT || check_collision())
    {
        running = false; 
        return;
    }
    
    for (int i = snake_length; i > 0; i--)
        snake[i] = snake[i - 1];

    snake[0] = new_head;
    
    if (new_head.x == food.x && new_head.y == food.y)
    {
        snake_length++;
        place_food();
    }
}

bool check_collision(void)
{
    for (int i = 1; i < snake_length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    return false;
}

void place_food(void)
{
    food.x = (rand() % (SCREEN_WIDTH / TILE_SIZE)) * TILE_SIZE;
    food.y = (rand() % (SCREEN_HEIGHT / TILE_SIZE)) * TILE_SIZE;
}

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect food_rect = {food.x, food.y, TILE_SIZE, TILE_SIZE};
    SDL_RenderFillRect(renderer, &food_rect);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < snake_length; i++)
    {
        SDL_Rect r = {snake[i].x, snake[i].y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(renderer, &r);
    }

    SDL_RenderPresent(renderer);
}
