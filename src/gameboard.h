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

  void FreshBoard() { board = firm_board; }
  void PlaceMino();
  void MoveMino(Direction& dir);
  bool DetectBlock(Direction& dir);
  void Rotate();
  bool IsTetris(double x, double y) const;
  void Draw(SDL_Renderer *sdl_renderer, SDL_Rect &block) const;

private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_tetris{0, 6};
  Mino RandomMino();
  void GetNextMino();

  std::vector<std::vector<Mino>> firm_board;
  std::vector<std::vector<Mino>> board;
  Tetris tetris;
  Tetris next_tetris;
};

#endif