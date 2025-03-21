#include "patriot_ui.hpp"

int PatriotUI::requestCommand() {
    std::cout << "Available commands:" << std::endl
              << "0. Quit" << std::endl
              << "1. Start Simulation" << std::endl
              << "==> Enter command: ";
            


  int command;
  std::cin >> command;

  if (std::cin.eof() || std::cin.bad()) {
    command = -1;
  } else if (std::cin.fail()) {
    std::cin.clear(); // unset failbit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // skip bad input
    command = -1;
  }

  std::cout << std::endl;
  return command;
}

void PatriotUI::run() {
    bool stop_command_received = false;
    while (!stop_command_received) {
        const int command = requestCommand();
        if (command > 0) {
        handleCommand(command);
        } else if (command < 0) {
        std::cout << "ERROR: Input error occurred" << std::endl << std::endl;
        } else if (command == 0) {
        stop_command_received = true;
        }
    }
}

void PatriotUI::startSimulation(){

  int simulationTime = 20;
  int simulationTimeStamp = 0;
  while(simulationTimeStamp < simulationTime){

  std::cout << "Radar signal: " << std::endl;
  auto radarSignal = radar.getSignal(simulationTimeStamp);
  auto target = iff.identifyTarget(radarSignal);

  if(target == TargetType::Hostile){
    std::cout <<  "Hostile Target Detected" << std::endl;
    double firingResult = firingUnit.fire();
    if(firingResult > pk_){
      std::cout << "Firing Result: " << firingResult << " -> "<<"Target Missed" << std::endl;
    }else{
      std::cout << "Firing Result: " << firingResult << " -> "<<"Target Neutralized" << std::endl;
    }

  }else if(target == TargetType::Friend){
    std::cout << "Friend Target Detected" << std::endl;
  }

  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  simulationTimeStamp++;
}
}

void PatriotUI::handleCommand(int command) {
    switch (command) {
    case 1:
      std::cout << "Simulation started " << command << std::endl << std::endl;
      startSimulation();
      break;
    default:
      std::cout << "ERROR: Invalid command " << command << std::endl << std::endl;
      break;
    }
  }