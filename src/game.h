#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "gameboard.h"
#include "renderer.h"
#include <iostream>
#include <random>

class Game {
public:
  Game(int mode);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore(Gameboard board) const { return board.GetScore(); }
  void PrintScore() const {
    std::cout << "Player 1 Score: " << game_board_1.GetScore() << "\n";
    if (_mode > 1) {
      std::cout << "Player 2 Score: " << game_board_2.GetScore() << "\n";
    }
  }

private:
  int _mode = 0;
  Gameboard game_board_1;
  Gameboard game_board_2;

  void Update(bool& runnning);
};

#endif