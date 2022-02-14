#include "../include/controller.h"
#include "../include/game.h"
#include <iostream>

int main() {
  // 1.single player 2.AI player
  int mode = 0;
  while (mode == 0) {
    std::cout << "Select a game mode:";
    std::cin >> mode;
    if (mode <= 0 || mode > 2) {
      std::cout << "This is not a valid game mode(1.single player 2.AI player)\n";
      mode = 0;
    } else {
      break;
    }
  }
  srand((unsigned)time(nullptr));
  size_t width = kScreenWidth;
  Renderer renderer(width, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game = Game(mode);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  game.PrintScore();
  return 0;
}