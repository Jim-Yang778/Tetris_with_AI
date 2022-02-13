#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "SDL.h"
#include "tetris.h"
#include "variable.h"
#include <random>
#include <limits.h>

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
  Tetris getTetris() const { return tetris; };

  // functions
  void GetNextMino();
  void FreshBoard() { board = firm_board; }
  void LockMino() { firm_board = board; }
  void PlaceMino(bool& running);
  void PlaceMino();
  bool MoveMino(Direction dir);
  void Rotate();
  int LineElimination();
  void Draw(SDL_Renderer *sdl_renderer, SDL_Rect &block, bool is_second_player) const;

  std::vector<int> AIDecideNextMove();


private:
  Mino RandomMino();
  bool IsTetris(double x, double y) const;
  SDL_Color GetColor(Mino mino) const;
private:
  std::default_random_engine engine;
  std::uniform_int_distribution<int> random_tetris{0, 6};
  std::vector<std::vector<Mino>> firm_board;
  std::vector<std::vector<Mino>> board;
  int score{0};
  Tetris tetris;
  Tetris next_tetris;
  int line_elimination{0};
private:
  // AI related helper function
  int LandingHeight();
  std::pair<int, int> NumbersOfHolesAndColumnTransitions();
  int RowTransitions();
  int WellSums();

};

#endif