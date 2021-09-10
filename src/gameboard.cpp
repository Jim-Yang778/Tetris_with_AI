#include "gameboard.h"
#include <iostream>

Gameboard::Gameboard() {

  engine = std::mt19937(dev());
  // create the 21 * 12 game board (20 * 10 game play area + the border)
  std::vector<Mino> normal_line = {
      Mino::border,    Mino::non_brick, Mino::non_brick, Mino::non_brick,
      Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick,
      Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::border};
  std::vector<Mino> border_line = {Mino::border, Mino::border, Mino::border,
                                   Mino::border, Mino::border, Mino::border,
                                   Mino::border, Mino::border, Mino::border,
                                   Mino::border, Mino::border, Mino::border};
  board = std::vector<std::vector<Mino>>(20, normal_line);
  board.emplace_back(border_line);
  firm_board = board;

  next_tetris = RandomMino();
  GetNextMino();
}

Gameboard::Gameboard(const Gameboard &source) {
  board = source.board;
  firm_board = source.firm_board;
  tetris = source.tetris;
  next_tetris = source.next_tetris;
  engine = source.engine;
}

Gameboard &Gameboard::operator=(const Gameboard &source) {
  board = source.board;
  tetris = source.tetris;
  firm_board = source.firm_board;
  next_tetris = source.next_tetris;
  engine = source.engine;
  return *this;
}

Mino Gameboard::RandomMino() { return ALL_MINOS[random_tetris(engine)]; }

void Gameboard::GetNextMino() {
  tetris = next_tetris;
  next_tetris = Tetris(RandomMino());
}

void Gameboard::Rotate() {
  // one rotation contains one transposition and one column reversion
  auto temp = tetris.GetShape();
  for (auto i = 0; i < tetris.size_; ++i) {
    for (auto j = 0; j < tetris.size_; ++j) {
      temp[i][j] = tetris.GetBlock(j, i);
    }
  }
  tetris.SetShape(temp);
  for (auto i = 0; i < tetris.size_; ++i) {
    for (auto j = 0; j < tetris.size_ / 2; ++j) {
      Mino t = tetris.GetBlock(i, j);
      temp[i][j] = tetris.GetBlock(i, tetris.size_ - j - 1);
      temp[i][tetris.size_ - j - 1] = t;
    }
  }
  tetris.SetShape(temp);
}

// Place the current tetrimino into the board.
void Gameboard::PlaceMino() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 4; j < 8; ++j) {
      double x = tetris.GetX();
      double y = tetris.GetY();
      if (tetris.GetBlock(i, j - 4) != Mino::non_brick &&
          board[i + x][j + y] != Mino::border) {
        board[i + x][j + y] = tetris.GetBlock(i, j - 4);
      }
    }
  }
}

void Gameboard::MoveMino(Direction& dir) {
  switch (dir) {
  case Direction::up:
    Rotate();
    break;
  case Direction::left:
    tetris.SetY(false);
    break;
  case Direction::right:
    tetris.SetY(true);
    break;
  case Direction::down:
    tetris.SetX(false);
    break;
  }
}

bool Gameboard::IsTetris(double x, double y) const {
  if (board[x][y] == Mino::border || board[x][y] == Mino::non_brick)
    return false;
  return true;
}

void Gameboard::Draw(SDL_Renderer *sdl_renderer, SDL_Rect &block) const {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      block.x = j * BRICK_SIZE;
      block.y = i * BRICK_SIZE;
      if (IsTetris(i, j)) {
        SDL_SetRenderDrawColor(sdl_renderer, tetris.color_.r, tetris.color_.g,
                               tetris.color_.b, 255);
        SDL_RenderFillRect(sdl_renderer, &block);
        SDL_SetRenderDrawColor(sdl_renderer, 219, 219, 219, 255);
        SDL_RenderDrawRect(sdl_renderer, &block);
      } else {
        if (board[i][j] == Mino::border) {
          SDL_SetRenderDrawColor(sdl_renderer, 85, 73, 73, 255);
          SDL_RenderFillRect(sdl_renderer, &block);
          SDL_SetRenderDrawColor(sdl_renderer, 219, 219, 219, 255);
          SDL_RenderDrawRect(sdl_renderer, &block);
        }
      }
    }
  }
}