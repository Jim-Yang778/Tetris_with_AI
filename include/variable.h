#ifndef SDL2TEST_VARIABLE_H
#define SDL2TEST_VARIABLE_H

#include <vector>
#include <string>

const float LH_WEIGHT = -4.500158825082766;
const float RE_WEIGHT = 3.4181268101392694;
const float RT_WEIGHT = -3.2178882868487753;
const float CT_WEIGHT = -9.348695305445199;
const float NH_WEIGHT = -7.899265427351652;
const float WS_WEIGHT = -3.3855972247263626;



const std::string kLogoPath{"res/Tetris.png"};
const std::string kSignPath{"res/Next.png"};

constexpr int BASE_SCORE{10};
constexpr int MID_POS_FRONT{4};
constexpr int MID_POS_BACK{8};

constexpr int BRICK_SIZE{30};

constexpr std::size_t kFramesPerSecond{60};
constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
constexpr std::size_t kScreenWidth{21 * BRICK_SIZE};
constexpr std::size_t kScreenHeight{21 * BRICK_SIZE};
constexpr std::size_t kGridWidth{32};
constexpr std::size_t kGridHeight{32};


enum class Mino : int {
  straight_mino = 0,
  square_mino,
  t_mino,
  l_mino,
  reverse_l_mino,
  reverse_skew_mino,
  skew_mino,
  border = -1,
  non_brick = -2
};

static std::vector<Mino> ALL_MINOS{Mino::straight_mino, Mino::square_mino,
                                   Mino::t_mino, Mino::l_mino,
                                   Mino::reverse_l_mino,
                                   Mino::reverse_skew_mino, Mino::skew_mino};

enum class Direction : int { up = 0, down, left, right };

const std::vector<Mino> NORMAL_LINE = {
    Mino::border,    Mino::non_brick, Mino::non_brick, Mino::non_brick,
    Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::non_brick,
    Mino::non_brick, Mino::non_brick, Mino::non_brick, Mino::border};

const std::vector<Mino> BORDER_LINE(12, Mino::border);

#endif // SDL2TEST_VARIABLE_H
