#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "SDL.h"
#include "tetris.h"
#include <random>

constexpr int BASE_SCORE = 10;

enum class Direction : int { up = 0, down, left, right };

const std::vector<Mino> NORMAL_LINE = {
    Mino::border,    Mino::non_brick, Mino::non_brick, Mino::non_brick,
    Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick,
    Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::border};

const std::vector<Mino> BORDER_LINE = {
    Mino::border, Mino::border, Mino::border, Mino::border,
    Mino::border, Mino::border, Mino::border, Mino::border,
    Mino::border, Mino::border, Mino::border, Mino::border};

class Gameboard {
public:
  Gameboard();
  Gameboard(const Gameboard &source);
  Gameboard &operator=(const Gameboard &source);
  Gameboard(Gameboard &&source) = default;
  Gameboard &operator=(Gameboard &&source) = default;
  ~Gameboard() = default;

  // Getter / Setter
  int GetScore() const { return score; }
  void SetScore(int count) {
    score += count == 0 ? 0 : BASE_SCORE * std::pow(2, count);
  }

  // functions
  void GetNextMino();
  void FreshBoard() { board = firm_board; }
  void LockMino() { firm_board = std::move(board); }
  void PlaceMino(bool& running);
  void MoveMino(Direction dir);
  bool DetectBlock(Direction &dir);
  void Rotate();
  void LineElimination();
  void Draw(SDL_Renderer *sdl_renderer, SDL_Rect &block) const;

private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_tetris{0, 6};
  Mino RandomMino();
  bool IsTetris(double x, double y) const;
  SDL_Color GetColor(Mino mino) const;

  std::vector<std::vector<Mino>> firm_board;
  std::vector<std::vector<Mino>> board;
  int score{0};
  Tetris tetris;
  Tetris next_tetris;
};

#endif