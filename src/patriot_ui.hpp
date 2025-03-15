#pragma once
#include <iostream>
#include <limits>

#include "radar.hpp"
#include "iff.hpp"

class PatriotUI {
public:
  void Run();

private:
  int RequestCommand();
  void HandleCommand(int command);
  void ResetSimulation();

  //Radar radar;
  Iff iff;
};