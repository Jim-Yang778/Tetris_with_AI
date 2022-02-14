#include "../include/game.h"
#include "SDL.h"
#include <cmath>

Game::Game(int mode) {
  Gameboard::mode_ = mode;
  game_board_1 = Gameboard();
  game_board_1.PlaceMino();
  if (mode > 1) {
    game_board_1.AIDecideNextMove();
  }
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, game_board_1);
    Update(running);
    renderer.Render(game_board_1);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    // And the current tetromino move down one space
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(GetScore(game_board_1), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
      game_board_1.MoveMino(Direction::down);
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

// One update will refresh the gameboard.
// And update the position of current moving tetromino if game is still running.
void Game::Update(bool& running) {
  game_board_1.FreshBoard();
  game_board_1.PlaceMino(running);
}
