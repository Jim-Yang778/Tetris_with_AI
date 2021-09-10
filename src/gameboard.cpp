#include "gameboard.h"

Gameboard::Gameboard() {
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

  next_tetris = RandomMino();
  GetNextMino();
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

void Gameboard::MoveMino(Direction dir) {
  switch (dir) {
  case Direction::up:
    Rotate();
    break;
  case Direction::left:
    tetris.SetX(true);
    break;
  case Direction::right:
    tetris.SetX(false);
    break;
  case Direction::down:
    tetris.SetX(true);
    break;
  }
}

void Gameboard::draw(SDL_Rect block) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      if (IsTetris(i, j)) {
        block.x = (tetris.GetX() + i) * BRICK_SIZE;
        block.y = (tetris.GetY() + j) * BRICK_SIZE;
        SDL_SetRenderDrawColor(sdl_renderer, tetris.color_.r, tetris.color_.g,
                               tetris.color_.b, 255);
        SDL_RenderFillRect(sdl_renderer, &block);
        SDL_SetRenderDrawColor(sdl_renderer, 219, 219, 219, 255);
        SDL_RenderDrawRect(sdl_renderer, &block);
      } else {

      }
    }
  }
}