#include "controller.h"
#include "SDL.h"
#include "gameboard.h"
#include <iostream>

void Controller::HandleInput(bool &running, Gameboard &gameboard) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
      case SDLK_UP:
        gameboard.MoveMino(Direction::up);
        break;

      case SDLK_DOWN:
        gameboard.MoveMino(Direction::down);
        break;

      case SDLK_LEFT:
        gameboard.MoveMino(Direction::left);
        break;

      case SDLK_RIGHT:
        gameboard.MoveMino(Direction::right);
        break;

      case SDLK_ESCAPE:
        running = false;
        break;

      case SDLK_SPACE:
        running = false;
        break;
      }
      // } else if (e.type == SDL_MOUSEMOTION) {
      //   int x, y;
      //   SDL_GetMouseState( &x, &y );
      //   std::cout << x << ", " << y << std::endl;
    }
  }
}