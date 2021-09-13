#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gameboard.h"

class Controller {
 public:
  void HandleInput(bool &running, Gameboard &gameboard) const;
};

#endif