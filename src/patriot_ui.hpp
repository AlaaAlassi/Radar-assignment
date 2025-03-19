#pragma once
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "radar.hpp"
#include "iff.hpp"
#include "firing_unit.hpp"

class PatriotUI {
public:
  PatriotUI(const std::string& inputFilePath):radar(inputFilePath){};
  void run();

private:
  int requestCommand();
  void handleCommand(int command);
  void startSimulation();
  void resetSimulation();

  Radar radar;
  Iff iff;
  FiringUnit firingUnit;
  double pk_ = 0.8;
};