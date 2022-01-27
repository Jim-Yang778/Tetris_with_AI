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

      case SDLK_w:
        gameboard.MoveMino(Direction::up);
        break;

      case SDLK_s:
        gameboard.MoveMino(Direction::down);
        break;

      case SDLK_a:
        gameboard.MoveMino(Direction::left);
        break;

      case SDLK_d:
        gameboard.MoveMino(Direction::right);
        break;

      case SDLK_ESCAPE:
        running = false;
        break;
      }
    }
  }
}

void Controller::HandleInput(bool &running,
                             Gameboard &gameboard_1,
                             Gameboard &gameboard_2) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
      case SDLK_UP:
        gameboard_2.MoveMino(Direction::up);
        break;

      case SDLK_DOWN:
        gameboard_2.MoveMino(Direction::down);
        break;

      case SDLK_LEFT:
        gameboard_2.MoveMino(Direction::left);
        break;

      case SDLK_RIGHT:
        gameboard_2.MoveMino(Direction::right);
        break;

      case SDLK_w:
        gameboard_1.MoveMino(Direction::up);
        break;

      case SDLK_s:
        gameboard_1.MoveMino(Direction::down);
        break;

      case SDLK_a:
        gameboard_1.MoveMino(Direction::left);
        break;

      case SDLK_d:
        gameboard_1.MoveMino(Direction::right);
        break;

      case SDLK_ESCAPE:
        running = false;
        break;
      }
    }
  }
}