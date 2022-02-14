#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "SDL.h"
#include "tetris.h"
#include "variable.h"
#include <random>
#include <climits>

class Gameboard {
public:
  Gameboard();
  Gameboard(const Gameboard &source);
  Gameboard &operator=(const Gameboard &source);
  Gameboard(Gameboard &&source) = default;
  Gameboard &operator=(Gameboard &&source) = default;
  ~Gameboard() = default;

  // Getter / Setter
  unsigned long long GetScore() const { return score; }
  void SetScore(int count) {
    score += count == 0 ? 0 : BASE_SCORE * std::pow(2, count);
  }
  Tetris getTetris() const { return tetris; };
  int GetLine() const { return line_elimination; };

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
  static int mode_;

private:
  Mino RandomMino();
  bool IsTetris(double x, double y) const;
  SDL_Color GetColor(Mino mino) const;
private:
  std::vector<std::vector<Mino>> firm_board;
  std::vector<std::vector<Mino>> board;
  unsigned long long score{0};

private:
  Tetris tetris;
  Tetris next_tetris;
  int line_elimination{0};
private:
  // AI related helper function
  float LandingHeight();
  std::pair<float, float> NumbersOfHolesAndColumnTransitions();
  float RowTransitions();
  float WellSums();

};

#endif