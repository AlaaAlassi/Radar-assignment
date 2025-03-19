#include <iostream>
#include <string>

#include "patriot_ui.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <relative_file_path>" << std::endl;
    return 1;
  }

  std::string filePath = argv[1];

  std::cout << "====> Air defence system <===="
            << std::endl
            << "Using input file: " << filePath << std::endl
            << std::endl;

  PatriotUI user_interface(filePath);
  user_interface.run();

  return 0;
}