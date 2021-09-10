#ifndef TETRIS_H
#define TETRIS_H

#include "SDL.h"
#include <vector>

constexpr int BRICK_SIZE = 22;

enum class Mino : int {
  straight_mino = 0,
  square_mino,
  t_mino,
  l_mino,
  reverse_t_mino,
  reverse_skew_mino,
  skew_mino,
  border = -1,
  non_brick = -2
};

static std::vector<Mino> ALL_MINOS({Mino::straight_mino, Mino::square_mino,
                                    Mino::t_mino, Mino::l_mino,
                                    Mino::reverse_t_mino,
                                    Mino::reverse_skew_mino, Mino::skew_mino});

class Tetris {
public:
  Tetris() : Tetris(Mino::straight_mino) {}
  Tetris(Mino type, double x, double y);
  Tetris(Mino type) : Tetris(type, 5, 4) {}
  Tetris(const Tetris &source);
  Tetris &operator=(const Tetris &source);
  Tetris(Tetris &&source) = default;
  Tetris &operator=(Tetris &&source) = default;
  ~Tetris() = default;

  // assist var
  int size_;
  SDL_Color color_;

  // Getter / Setter
  std::vector<std::vector<Mino>> GetShape() const { return shape_; }
  void SetShape(std::vector<std::vector<Mino>> new_shape) {
    shape_ = new_shape;
  }
  Mino GetBlock(double x, double y) const { return shape_[x][y]; }
  void SetBlock(double x, double y, Mino new_block) {
    shape_[x][y] = new_block;
  }
  double GetX() const { return x_; }
  double GetY() const { return y_; }
  void SetX(bool turn_left) {
    if (turn_left) --x_;
    else ++x_;
  }
  void SetY(bool turn_down) {
    if (turn_down) ++y_;
  }

private:
  double x_;
  double y_;
  Mino type_;
  std::vector<std::vector<Mino>> shape_;
};

#endif