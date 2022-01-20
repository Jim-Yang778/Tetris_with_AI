#include "renderer.h"
#include <iostream>
#include <string>

void createTexture(SDL_Renderer *sdl_renderer, SDL_Surface *sdl_surface,
                   SDL_Texture **texture, const std::string &path) {
  sdl_surface = IMG_Load(path.c_str());
  if (!sdl_surface) {
    auto new_path = "../" + path;
    sdl_surface = IMG_Load(new_path.c_str());
    std::cerr << "Image could not be loaded mostly because you are under the "
                 "build folder.\n";
    std::cerr << "Now trying a new path: " << new_path << "\n";
    if (!sdl_surface) {
      std::cerr << "Image could not be loaded eventually.\n";
      std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
  }
  *texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_surface);
  if (!(*texture)) {
    std::cerr << "Image could not be rendered.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  SDL_FreeSurface(sdl_surface);
}

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width), screen_height(screen_height),
      grid_width(grid_width), grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Initialize SDL_IMG
  if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
    std::cerr << "SDL_image could not initialize.\n";
  }

  // Create Window
  sdl_window =
      SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       screen_width, screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // // Create logo image
  createTexture(sdl_renderer, sdl_surface, &logo, kLogoPath);
  // Create "next" sign image
  createTexture(sdl_renderer, sdl_surface, &sign, kSignPath);
}

Renderer::~Renderer() {
  SDL_DestroyTexture(logo);
  SDL_DestroyTexture(sign);
  SDL_DestroyWindow(sdl_window);
  IMG_Quit();
  SDL_Quit();
}

void Renderer::Render(Gameboard &gameboard_1, Gameboard &gameboard_2) {
  SDL_Rect block;
  block.w = BRICK_SIZE;
  block.h = BRICK_SIZE;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
  SDL_RenderClear(sdl_renderer);

  // Render Logo and "Next" sign
  SDL_Rect logo_rect = {13 * BRICK_SIZE, 14 * BRICK_SIZE, 7 * BRICK_SIZE,
                        7 * BRICK_SIZE};
  if (logo) {
    SDL_RenderCopy(sdl_renderer, logo, nullptr, &logo_rect);
  }

  SDL_Rect next_rect = {13 * BRICK_SIZE, BRICK_SIZE, 4 * BRICK_SIZE,
                        4 * BRICK_SIZE};
  if (sign) {
    SDL_RenderCopy(sdl_renderer, sign, nullptr, &next_rect);
  }

  // Render gameboard
  gameboard_1.Draw(sdl_renderer, block, false);
  gameboard_2.Draw(sdl_renderer, block, true);
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Tetris Score: " + std::to_string(score) +
                    " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
