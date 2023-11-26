#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create window and renderer
    SDL_Window* window = SDL_CreateWindow("Where Am I?", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Load background image
    SDL_Surface* backgroundImage = IMG_Load("Finals Game C++.png");
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundImage);
    SDL_FreeSurface(backgroundImage);

    SDL_Event event;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Set the draw color to clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the background
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
