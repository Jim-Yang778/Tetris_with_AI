#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gameboard.h"

class Controller {
 public:
  void HandleInput(bool &running, Gameboard &gameboard) const;
  void HandleInput(bool &running, Gameboard &gameboard_1, Gameboard &gameboard_2) const;
};

#endif