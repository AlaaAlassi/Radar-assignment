#include "patriot_ui.hpp"

int PatriotUI::RequestCommand() {
    std::cout << "Available commands:" << std::endl
              << "0. Quit" << std::endl
              << "1. Start Simulation" << std::endl
              << "2. Reset Simulation" << std::endl
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

void PatriotUI::Run() {
    bool stop_command_received = false;
    while (!stop_command_received) {
        const int command = RequestCommand();
        if (command > 0) {
        HandleCommand(command);
        } else if (command < 0) {
        std::cout << "ERROR: Input error occurred" << std::endl << std::endl;
        } else if (command == 0) {
        stop_command_received = true;
        }
    }
}

void PatriotUI::HandleCommand(int command) {
    switch (command) {
    case 1:
      //startSimulation();
      std::cout << "Simulation started " << command << std::endl << std::endl;
      break;
    case 2:
      //resetSimulation();
      std::cout << "Simulation reseted " << command << std::endl << std::endl;
      break;
    default:
      std::cout << "ERROR: Invalid command " << command << std::endl << std::endl;
      break;
    }
  }