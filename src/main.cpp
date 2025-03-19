#include <iostream>
#include <string>
#include <filesystem>

#include "patriot_ui.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <relative_file_path>" << std::endl;
    return 1;
  }

  std::cout << "====> Air defence system <====" << std::endl << std::endl;

  fs::path filePath;

  try {
    filePath = fs::canonical(argv[1]);
    std::cout << "Using input file: " << filePath << std::endl;
      } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return 1;
      } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
      }




  PatriotUI user_interface(filePath);
  user_interface.run();

  return 0;
}