#ifndef TETRIS_H
#define TETRIS_H

#include "SDL.h"
#include "variable.h"
#include <vector>

class Tetris {
public:
  Tetris() : Tetris(Mino::straight_mino) {}
  Tetris(Mino type, double x, double y);
  Tetris(Mino type) : Tetris(type, 0, 0) {}
  Tetris(const Tetris &source);
  Tetris &operator=(const Tetris &source);
  Tetris(Tetris &&source) = default;
  Tetris &operator=(Tetris &&source) = default;
  ~Tetris() = default;

  // helper variable
  int size_;
  std::vector<std::pair<int, int>> current_pos_;

  // Getter / Setter
  std::vector<std::vector<Mino>> GetShape() const { return shape_; }
  Mino GetBlock(double x, double y) const { return shape_[x][y]; }
  double GetX() const { return x_; }
  double GetY() const { return y_; }
  Mino GetType() { return type_; }
  void SetBlock(double x, double y, Mino new_block) {
    shape_[x][y] = new_block;
  }
  void SetShape(std::vector<std::vector<Mino>> new_shape) {
    shape_ = new_shape;
  }
  void SetX(bool turn_left) {
    if (turn_left)
      --x_;
    else
      ++x_;
  }
  void SetY(bool turn_down) {
    if (turn_down)
      ++y_;
    else
      --y_;
  }

private:
  double x_;
  double y_;
  Mino type_;
  std::vector<std::vector<Mino>> shape_;
};

#endif