#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils/state.h"
#include "services/traffic_light.h"

class Controller {
private:
  int STATE = INIT;
public:
	Controller();
	void Work();
  int GetState();
  void SetState(int newState);
};

#endif
