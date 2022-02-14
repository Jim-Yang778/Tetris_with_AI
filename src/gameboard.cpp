#include "../include/gameboard.h"
#include <algorithm>
#include <iostream>

int Gameboard::mode_ = 0;

Gameboard::Gameboard() {

  // create the 21 * 12 game board (20 * 10 game play area + the border)
  board = std::vector<std::vector<Mino>>(20, NORMAL_LINE);
  board.emplace_back(BORDER_LINE);

  // Create a firm_board which takes all the sticky tetromino 
  // and border as the blocks.
  firm_board = board;
  
  // Create the first and second tetromino.
  next_tetris = RandomMino();
  GetNextMino();
}

Gameboard::Gameboard(const Gameboard &source) {
  board = source.board;
  firm_board = source.firm_board;
  tetris = source.tetris;
  next_tetris = source.next_tetris;
  line_elimination = source.line_elimination;
}

Gameboard &Gameboard::operator=(const Gameboard &source) {
  board = source.board;
  tetris = source.tetris;
  firm_board = source.firm_board;
  next_tetris = source.next_tetris;
  line_elimination = source.line_elimination;
  return *this;
}

// Select a random tetromino from the "Mino" enum class
Mino Gameboard::RandomMino() { return ALL_MINOS[rand() % 7]; }

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
  // This is an implementation of NO "wall-kick" rotation system.
  // Which means that the tetromino is unable to rotate if there
  // is no place for it to do that.
  tetris.current_pos_.clear();
  for (int i = 0; i < 4; ++i) {
    for (int j = 4; j < 8; ++j) {
      double x = tetris.GetX();
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
  } else {
    tetris.rotated();
  }
}

// Place the current tetrimino into the board.
void Gameboard::PlaceMino(bool& running) {
  tetris.current_pos_.clear();
  for (int i = 0; i < MID_POS_FRONT; ++i) {
    for (int j = MID_POS_FRONT; j < MID_POS_BACK; ++j) {
//      double x = tetris.GetType() == Mino::straight_mino ? tetris.GetX() - 1
//                                                         : tetris.GetX();
      double x = tetris.GetX();
      double y = tetris.GetY();
      if (tetris.GetBlock(i, j - MID_POS_FRONT) != Mino::non_brick &&
          board[i + x][j + y] != Mino::border &&
          firm_board[i + x][j + y] == Mino::non_brick) {
        board[i + x][j + y] = tetris.GetBlock(i, j - 4);
        tetris.current_pos_.emplace_back(std::make_pair(i + x, j + y));
      }
    }
  }
  // Each type of tetromino is combined with 4 blocks.
  // End the game if there is no way to place a new tetromino.
  if (tetris.current_pos_.size() != 4) {
    running = false;
  }
}

void Gameboard::PlaceMino() {
  tetris.current_pos_.clear();
  for (int i = 0; i < MID_POS_FRONT; ++i) {
    for (int j = MID_POS_FRONT; j < MID_POS_BACK; ++j) {
//      double x = tetris.GetType() == Mino::straight_mino ? tetris.GetX() - 1
//                                                         : tetris.GetX();
      double x = tetris.GetX();
      double y = tetris.GetY();
      if (tetris.GetBlock(i, j - MID_POS_FRONT) != Mino::non_brick &&
          board[i + x][j + y] != Mino::border &&
          firm_board[i + x][j + y] == Mino::non_brick) {
        board[i + x][j + y] = tetris.GetBlock(i, j - 4);
        tetris.current_pos_.emplace_back(std::make_pair(i + x, j + y));
      }
    }
  }
}

/*
Pass a direction as the parameter.
Checks whether the tetromino is able to rotate or move one space in the
specified direction. Actting if possible.
*/
bool Gameboard::MoveMino(Direction dir) {
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
      tetris.SetX();
    } else {
      LockMino();
      GetNextMino();
      LineElimination();
      if (Gameboard::mode_ > 1) {
        AIDecideNextMove();
      }
    }
    break;
  }

  return can_move;
}

// Get SDL_color properties base on the type of tetrimino.
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
  case Mino::border:
    return {85, 73, 73};
  }
  return {0, 0, 0};
}

// Check each row in the board and eliminate the row that is full.
int Gameboard::LineElimination() {
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
  line_elimination += count;
  return count;
}

// Check if the specific position is currently occupied by a mino.
// Except "non_brick" or "border"
bool Gameboard::IsTetris(double x, double y) const {
  if (board[x][y] == Mino::border || board[x][y] == Mino::non_brick)
    return false;
  return true;
}

// render helper function
void RenderBlock(SDL_Renderer *sdl_renderer, SDL_Rect &block,
                 SDL_Color &color) {
  SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(sdl_renderer, &block);
  SDL_SetRenderDrawColor(sdl_renderer, 219, 219, 219, 255);
  SDL_RenderDrawRect(sdl_renderer, &block);
}

// Render the whole gameboard
void Gameboard::Draw(SDL_Renderer *sdl_renderer, SDL_Rect &block, bool is_second_player) const {
  size_t offset = is_second_player ? 21 * BRICK_SIZE : 0;
  // render for next mino
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      block.x = (14 + j) * BRICK_SIZE + offset;
      block.y = (5 + i) * BRICK_SIZE;
      auto mino_color = GetColor(next_tetris.GetBlock(i, j));
      RenderBlock(sdl_renderer, block, mino_color);
    }
  }

  // render for the gameboard
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      block.x = j * BRICK_SIZE + offset;
      block.y = i * BRICK_SIZE;
      auto mino_color = GetColor(board[i][j]);
      if (IsTetris(i, j)) {
        RenderBlock(sdl_renderer, block, mino_color);
      } else {
        if (board[i][j] == Mino::border) {
          RenderBlock(sdl_renderer, block, mino_color);
        } else {
          SDL_SetRenderDrawColor(sdl_renderer, 86, 86, 86, 255);
          SDL_RenderDrawRect(sdl_renderer, &block);
        }
      }
    }
  }
}

///////////////////// AI related function ////////////////////////

float Gameboard::LandingHeight() {
  int lh = INT_MAX;
  for (auto& each : tetris.current_pos_) {
    lh = std::min(each.first, lh);
  }
  return 20.0f - lh - float(tetris.GetHeight()) / 2;
}
std::pair<float, float> Gameboard::NumbersOfHolesAndColumnTransitions() {
  float nh = 0;
  float ct = 0;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 0; j <= 19; ++j) {
      if ((board[j][i] != Mino::non_brick && board[j + 1][i] == Mino::non_brick) ||
          (board[j][i] == Mino::non_brick && board[j + 1][i] != Mino::non_brick)) {
        ++ct;
      }
      if (j <= 18) {
        if (board[j][i] != Mino::non_brick &&
            board[j + 1][i] == Mino::non_brick &&
            board[j + 2][i] != Mino::non_brick) {
          ++nh;
        }
      }
    }
  }
  return std::make_pair(ct, nh);
}

float Gameboard::RowTransitions() {
  float rt = 0;
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j <= 10; ++j) {
      if ((board[i][j] == Mino::non_brick && board[i][j + 1] != Mino::non_brick) ||
          (board[i][j] != Mino::non_brick && board[i][j + 1] == Mino::non_brick)){
        ++rt;
      }
    }
  }
  return rt;
}

float Gameboard::WellSums() {
  float ws = 0;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 0; j <= 19; ++j) {
      if (board[j][i - 1] != Mino::non_brick &&
          board[j][i] == Mino::non_brick &&
          board[j][i + 1] != Mino::non_brick) {
        ++ws;
        for (int k = j + 1; j <= 18; ++k) {
          if (board[k][i] == Mino::non_brick) {
            ++ws;
          } else {
            break;
          }
        }
      }
    }
  }
  return ws;
}

std::vector<int> Gameboard::AIDecideNextMove() {
  Gameboard simulation;
  float max_score = INT_MIN;
  std::vector<int> best_move;
//  std::vector<float> params;
  // i: number of rotate
  for (int i = 0; i <= 3; ++i) {
    simulation = *this;
    std::vector<int> curr_move{0, 0, 0};  //horizontal step, vertical step, rotate
    float RE = 0;
    while (curr_move[2] < i) {
      simulation.MoveMino(Direction::up);
      simulation.FreshBoard();
      simulation.PlaceMino();
      ++curr_move[2];
    }
    while (simulation.MoveMino(Direction::left)) {
      simulation.FreshBoard();
      simulation.PlaceMino();
      --curr_move[0];
    }
    bool flag = true;
    while (flag) {
      curr_move[1] = 0;
      auto curr = simulation.getTetris();
      // move down until fixed
      bool can_move = true;
      while (can_move) {
        for (auto &each : simulation.tetris.current_pos_) {
          if (std::find(simulation.tetris.current_pos_.begin(), simulation.tetris.current_pos_.end(),
                        std::make_pair(each.first + 1, each.second)) ==
              simulation.tetris.current_pos_.end()) {
            if (simulation.board[each.first + 1][each.second] != Mino::non_brick) {
              can_move = false;
              break;
            }
          }
        }
        if (can_move) {
          simulation.tetris.SetX();
        }
        simulation.FreshBoard();
        simulation.PlaceMino();
        ++curr_move[1];
      }
      RE = simulation.LineElimination();
      // calculate the parameters
      float LH = simulation.LandingHeight();
      auto temp = simulation.NumbersOfHolesAndColumnTransitions();
      float CT = temp.first;
      float NH = temp.second;
      float RT = simulation.RowTransitions();
      float WS = simulation.WellSums();
      float curr_score = (LH * LH_WEIGHT) + (RE * RE_WEIGHT) +  (RT * RT_WEIGHT) + (CT * CT_WEIGHT) + (NH * NH_WEIGHT) + (WS * WS_WEIGHT);
      if (max_score < curr_score) {
        max_score = curr_score;
        // memorise the step it does
//        params = std::vector<float>{LH, RE, RT, CT, NH, WS};
        best_move = curr_move;
      } else if (max_score == curr_score) {
          int priority_best = 100 * (abs(best_move[0]) + abs(best_move[1])) + best_move[2];
          int priority_curr = 100 * (abs(curr_move[0]) + abs(curr_move[1])) + curr_move[2];
          if (priority_curr < priority_best) {
            max_score = curr_score;
            // memorise the step it does
//            params = std::vector<float>{LH, RE, RT, CT, NH, WS};
            best_move = curr_move;
          }
      }

      // retrive the place of mino and move right once
      simulation.tetris = curr;
      flag = simulation.MoveMino(Direction::right);
      simulation.FreshBoard();
      simulation.PlaceMino();
      ++curr_move[0];
    }
  }
//  std::cout << "The best parameter is: " << std::endl;
//  std::cout << "LH: " << params[0] << std::endl;
//  std::cout << "RE: " << params[1] << std::endl;
//  std::cout << "RT: " << params[2] << std::endl;
//  std::cout << "CT: " << params[3] << std::endl;
//  std::cout << "NH: " << params[4] << std::endl;
//  std::cout << "WS: " << params[5] << std::endl;
//  std::cout << "And the move is: " << std::endl;
//  std::cout << "move left: " << best_move[0] << std::endl;
//  std::cout << "move down: " << best_move[1] << std::endl;
//  std::cout << "rotate: " << best_move[2] << std::endl;
  for (int i = 0; i < best_move[2]; ++i) {
    MoveMino(Direction::up);
    FreshBoard();
    PlaceMino();
  }
  int horizontalMove = abs(best_move[0]);
  Direction dir = best_move[0] < 0 ? Direction::left : Direction::right;
  for (int i = 0; i < horizontalMove; ++i) {
    MoveMino(dir);
    FreshBoard();
    PlaceMino();
  }
  for (int i = 0; i < best_move[1] - 1; ++i) {
    MoveMino(Direction::down);
    FreshBoard();
    PlaceMino();
  }
  return best_move;
}
