#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "gameboard.h"
#include <random>

class Game {
public:
  Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

private:
  Gameboard gameboard;

  int score{0};

  void Update();
};

#endif