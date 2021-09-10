#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "SDL.h"
#include "tetris.h"
#include <random>

enum class Direction : int { up = 0, down, left, right };

class Gameboard {
public:
  Gameboard();
  Gameboard(const Gameboard &source);
  Gameboard &operator=(const Gameboard &source);
  Gameboard(Gameboard &&source) = default;
  Gameboard &operator=(Gameboard &&source) = default;
  ~Gameboard() = default;

  Mino RandomMino();
  void GetNextMino();
  void MoveMino(Direction dir);
  void Rotate();
  void draw(SDL_Rect block);

private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_tetris{0, 6};

  std::vector<std::vector<Mino>> board;
  Tetris tetris;
  Tetris next_tetris;
};

#endif