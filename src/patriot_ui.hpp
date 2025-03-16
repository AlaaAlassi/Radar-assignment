#pragma once
#include <iostream>
#include <limits>

#include "radar.hpp"
#include "iff.hpp"
#include "firing_unit.hpp"

class PatriotUI {
public:
  void run();


private:
  int requestCommand();
  void handleCommand(int command);
  void startSimulation();
  void resetSimulation();

  Radar radar;
  Iff iff;
  FiringUnit firingUnit;
};