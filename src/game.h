#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "gameboard.h"
#include "renderer.h"
#include <random>

class Game {
public:
  Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const { return game_board.GetScore(); }

private:
  Gameboard game_board;

  void Update(bool& runnning);
};

#endif