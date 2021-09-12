#include "gameboard.h"
#include <algorithm>
#include <iostream>

Gameboard::Gameboard() {

  engine = std::mt19937(dev());
  // create the 21 * 12 game board (20 * 10 game play area + the border)
  board = std::vector<std::vector<Mino>>(20, NORMAL_LINE);
  board.emplace_back(BORDER_LINE);
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

// Select a random tetromino from the "Mino" enum class
Mino Gameboard::RandomMino() { return ALL_MINOS[random_tetris(engine)]; }

/*
Setting tne next tetromino as the current tetromino.
Then randomly select the next tetromino.
*/
void Gameboard::GetNextMino() {
  tetris = next_tetris;
  next_tetris = Tetris(RandomMino());
}

/*
Rotate the current tetromino 90 degrees clockwise.
And make a check that whether this tetronino is able to rotate.
Otherwise cancel this action.
*/
void Gameboard::Rotate() {
  auto temp = tetris.GetShape();
  auto pre_shape = temp;
  for (auto i = 0; i < tetris.size_; ++i) {
    for (auto j = 0; j < tetris.size_; ++j) {
      temp[i][j] = tetris.GetBlock(j, i);
    }
  }
  tetris.SetShape(temp);
  if (tetris.GetType() != Mino::square_mino &&
      tetris.GetType() != Mino::straight_mino) {
    for (auto i = 0; i < tetris.size_; ++i) {
      for (auto j = 0; j < tetris.size_ / 2; ++j) {
        Mino t = tetris.GetBlock(i, j);
        temp[i][j] = tetris.GetBlock(i, tetris.size_ - j - 1);
        temp[i][tetris.size_ - j - 1] = t;
      }
    }
    tetris.SetShape(temp);
  }
  tetris.current_pos_.clear();
  for (int i = 0; i < 4; ++i) {
    for (int j = 4; j < 8; ++j) {
      double x = tetris.GetType() == Mino::straight_mino ? tetris.GetX() - 1
                                                         : tetris.GetX();
      double y = tetris.GetY();
      if (i + x >= 21 || j + y >= 12 || i + x < 0) {
        tetris.SetShape(pre_shape);
        return;
      }
      if (tetris.GetBlock(i, j - 4) != Mino::non_brick &&
          board[i + x][j + y] != Mino::border &&
          firm_board[i + x][j + y] == Mino::non_brick) {
        board[i + x][j + y] = tetris.GetBlock(i, j - 4);
        tetris.current_pos_.emplace_back(std::make_pair(i + x, j + y));
      }
    }
  }
  if (tetris.current_pos_.size() != 4) {
    tetris.SetShape(pre_shape);
  }
}

// Place the current tetrimino into the board.
void Gameboard::PlaceMino(bool& running) {
  tetris.current_pos_.clear();
  for (int i = 0; i < 4; ++i) {
    for (int j = 4; j < 8; ++j) {
      double x = tetris.GetType() == Mino::straight_mino ? tetris.GetX() - 1
                                                         : tetris.GetX();
      double y = tetris.GetY();
      if (tetris.GetBlock(i, j - 4) != Mino::non_brick &&
          board[i + x][j + y] != Mino::border &&
          firm_board[i + x][j + y] == Mino::non_brick) {
        board[i + x][j + y] = tetris.GetBlock(i, j - 4);
        tetris.current_pos_.emplace_back(std::make_pair(i + x, j + y));
      }
    }
  }
  if (tetris.current_pos_.size() != 4) {
    running = false;
  }
}

/*
Pass a direction as the parameter.
Checks whether the tetromino is able to rotate or move one space in the
specified direction. Actting if possible.
*/
void Gameboard::MoveMino(Direction dir) {
  bool can_move = true;
  switch (dir) {
  case Direction::up:
    Rotate();
    break;
  case Direction::left:
    for (auto &each : tetris.current_pos_) {
      if (std::find(tetris.current_pos_.begin(), tetris.current_pos_.end(),
                    std::make_pair(each.first, each.second - 1)) ==
          tetris.current_pos_.end()) {
        if (board[each.first][each.second - 1] != Mino::non_brick) {
          can_move = false;
          break;
        }
      }
    }
    if (can_move) {
      tetris.SetY(false);
    }
    break;
  case Direction::right:
    for (auto &each : tetris.current_pos_) {
      if (std::find(tetris.current_pos_.begin(), tetris.current_pos_.end(),
                    std::make_pair(each.first, each.second + 1)) ==
          tetris.current_pos_.end()) {
        if (board[each.first][each.second + 1] != Mino::non_brick) {
          can_move = false;
          break;
        }
      }
    }
    if (can_move) {
      tetris.SetY(true);
    }
    break;
  case Direction::down:
    for (auto &each : tetris.current_pos_) {
      if (std::find(tetris.current_pos_.begin(), tetris.current_pos_.end(),
                    std::make_pair(each.first + 1, each.second)) ==
          tetris.current_pos_.end()) {
        if (board[each.first + 1][each.second] != Mino::non_brick) {
          can_move = false;
          break;
        }
      }
    }
    if (can_move) {
      tetris.SetX(false);
    } else {
      LockMino();
      GetNextMino();
      LineElimination();
    }
    break;
  }
}

SDL_Color Gameboard::GetColor(Mino mino) const {
  switch (mino) {
  case Mino::straight_mino:
    return {0, 229, 255};
  case Mino::square_mino:
    return {255, 255, 0};
  case Mino::t_mino:
    return {128, 0, 128};
  case Mino::l_mino:
    return {0, 255, 0};
  case Mino::reverse_l_mino:
    return {255, 0, 0};
  case Mino::reverse_skew_mino:
    return {0, 0, 255};
  case Mino::skew_mino:
    return {255, 127, 0};
  }
  return {85, 73, 73};
}

void Gameboard::LineElimination() {
  for (auto it = firm_board.begin(); it != firm_board.end() - 1;) {
    // unable to find a "Mino::non_brick" in a single line;
    if (std::find(it->begin(), it->end(), Mino::non_brick) == it->end()) {
      it = firm_board.erase(it);
    } else {
      ++it;
    }
  }
  int count = 0;
  std::reverse(firm_board.begin(), firm_board.end());
  while (firm_board.size() < 21) {
    firm_board.emplace_back(NORMAL_LINE);
    ++count;
  }
  std::reverse(firm_board.begin(), firm_board.end());
  SetScore(count);
}

// Check if the specific position is currently occupied by a mino.
// Except "non_brick" or "border"
bool Gameboard::IsTetris(double x, double y) const {
  if (board[x][y] == Mino::border || board[x][y] == Mino::non_brick)
    return false;
  return true;
}

// Render the whole gameboard
void Gameboard::Draw(SDL_Renderer *sdl_renderer, SDL_Rect &block) const {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      block.x = j * BRICK_SIZE;
      block.y = i * BRICK_SIZE;
      auto mino_color = GetColor(board[i][j]);
      if (IsTetris(i, j)) {
        SDL_SetRenderDrawColor(sdl_renderer, mino_color.r, mino_color.g,
                               mino_color.b, 255);
        SDL_RenderFillRect(sdl_renderer, &block);
        SDL_SetRenderDrawColor(sdl_renderer, 219, 219, 219, 255);
        SDL_RenderDrawRect(sdl_renderer, &block);
      } else {
        if (board[i][j] == Mino::border) {
          SDL_SetRenderDrawColor(sdl_renderer, mino_color.r, mino_color.g,
                                 mino_color.b, 255);
          SDL_RenderFillRect(sdl_renderer, &block);
          SDL_SetRenderDrawColor(sdl_renderer, 219, 219, 219, 255);
          SDL_RenderDrawRect(sdl_renderer, &block);
        } else {
          SDL_SetRenderDrawColor(sdl_renderer, 86, 86, 86, 255);
          SDL_RenderDrawRect(sdl_renderer, &block);
        }
      }
    }
  }
}