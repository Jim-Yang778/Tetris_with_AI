#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <iostream>

int main() {
  // 1.single player 2.local multiplayer
  int mode = 0;
  while (1) {
    std::cout << "Select a game mode:";
    std::cin >> mode;
    if (mode <= 0 || mode > 2) {
      std::cout << "This is not a valid game mode(1.single player 2.local multiplayer)\n";
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