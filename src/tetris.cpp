#include "../include/tetris.h"
#include <iostream>
Tetris::Tetris(Mino type, double x, double y) : type_{type}, x_{x}, y_{y} {
  switch (type) {
  case Mino::straight_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {type, type, type, type},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 4;
    height_ = 1;
    width_ = 4;
    break;
  case Mino::square_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, type, type, Mino::non_brick},
        {Mino::non_brick, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 2;
    height_ = 2;
    width_ = 2;
    break;
  case Mino::t_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, type, Mino::non_brick, Mino::non_brick},
        {type, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    height_ = 2;
    width_ = 3;
    break;
  case Mino::l_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, Mino::non_brick, type, Mino::non_brick},
        {type, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    height_ = 2;
    width_ = 3;
    break;
  case Mino::reverse_l_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {type, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {type, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    height_ = 2;
    width_ = 3;
    break;
  case Mino::reverse_skew_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {type, type, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    height_ = 2;
    width_ = 3;
    break;
  case Mino::skew_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, type, type, Mino::non_brick},
        {type, type, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    height_ = 2;
    width_ = 3;
    break;
  }
}

Tetris::Tetris(const Tetris &source)
    : x_{source.x_}, y_{source.y_}, size_{source.size_}, type_{source.type_},
      shape_{source.shape_}, current_pos_{source.current_pos_},
      height_{source.height_}, width_{source.width_} {}

Tetris &Tetris::operator=(const Tetris &source) {
  x_ = source.x_;
  y_ = source.y_;
  current_pos_ = source.current_pos_;
  size_ = source.size_;
  type_ = source.type_;
  shape_ = source.shape_;
  height_ = source.height_;
  width_ = source.width_;
  return *this;
}
