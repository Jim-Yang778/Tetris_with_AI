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
  int GetScore(Gameboard &board) const { return board.GetScore(); }
  void PrintScore() const {
    std::cout << "Player 1 Score: " << game_board_1.GetScore() << "\n";
    std::cout << "Player 1 Eliminate " << game_board_1.GetLine() << " lines\n";
  }
private:
  Gameboard game_board_1;

  void Update(bool& runnning);
};

#endif