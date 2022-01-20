#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <iostream>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{21 * BRICK_SIZE};
  constexpr std::size_t kScreenHeight{21 * BRICK_SIZE};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // 1.single player 2.local multiplayer 3.remote multiplayer(TODO)
  int mode = 0;
  while (1) {
    std::cout << "Select a game mode:";
    std::cin >> mode;
    if (mode <= 0 || mode > 2) {
      std::cout << "This is not a valid game mode(1.single player 2.local multiplayer 3.remote multiplayer(TODO))\n";
    } else {
      break;
    }
  }
  size_t width = kScreenWidth;
  if(mode > 1) {
    width *= 2;
  }
  Renderer renderer(width, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game = Game(mode);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  game.PrintScore();
  return 0;
}