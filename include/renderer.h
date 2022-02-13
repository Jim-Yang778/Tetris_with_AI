#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "SDL_image.h"
#include "gameboard.h"
#include "variable.h"
#include <vector>

class Renderer {
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Gameboard &gameboard_1, Gameboard &gameboard_2);
  void Render(Gameboard &gameboard);
  void UpdateWindowTitle(int score, int fps);
  void UpdateWindowTitle(int score_1, int score_2, int fps);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Surface *sdl_surface;

  SDL_Texture *logo = nullptr;
  SDL_Texture *sign = nullptr;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif