#include <iostream>

#include "patriot_ui.hpp"

int main(int /*argc*/, char* /*argv*/[]) {
  std::cout << "====> Air defence system <===="
            << std::endl
            << std::endl;

  PatriotUI user_interface;
  user_interface.Run();

  return 0;
}