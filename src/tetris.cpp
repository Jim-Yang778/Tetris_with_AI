#include "tetris.h"

Tetris::Tetris(Mino type, double x, double y) : type_{type}, x_{x}, y_{y} {
  switch (type) {
  case Mino::straight_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {type, type, type, type},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 4;
    color_ = {0, 255, 255};
    break;
  case Mino::square_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {type, type, Mino::non_brick, Mino::non_brick},
        {type, type, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 2;
    color_ = {255, 255, 0};
    break;
  case Mino::t_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, type, Mino::non_brick, Mino::non_brick},
        {type, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    color_ = {128, 0, 128};
    break;
  case Mino::l_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, Mino::non_brick, type, Mino::non_brick},
        {type, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    color_ = {0, 255, 0};
    break;
  case Mino::reverse_t_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {type, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {type, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    color_ = {255, 0, 0};
    break;
  case Mino::reverse_skew_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {type, type, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, type, type, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    color_ = {0, 0, 255};
    break;
  case Mino::skew_mino:
    shape_ = std::vector<std::vector<Mino>>{
        {Mino::non_brick, type, type, Mino::non_brick},
        {type, type, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick},
        {Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick}};
    size_ = 3;
    color_ = {255, 127, 0};
    break;
  }
}

Tetris::Tetris(const Tetris &source)
    : x_{source.x_}, y_{source.y_}, size_{source.size_}, color_{source.color_},
      type_{source.type_}, shape_{source.shape_} {}

Tetris &Tetris::operator=(const Tetris &source) {
  x_ = source.x_;
  y_ = source.y_;
  size_ = source.size_;
  color_ = source.color_;
  type_ = source.type_;
  shape_ = source.shape_;
  return *this;
}
