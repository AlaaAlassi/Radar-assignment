#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include"radar.hpp"

namespace fs = std::filesystem;

Radar::Radar(const std::string& filePath){
    std::cout << "Radar initialized with file: " << filePath << std::endl;
    readfile(filePath);
}

std::vector<std::bitset<7>>Radar::getSignal(int signalIndex)
{

    std::vector<std::bitset<7>> signalBits = cachedData[signalIndex];

    for (size_t i = 0; i < signalBits.size(); ++i) {
        std::cout << signalBits[i];
        if (i < signalBits.size() - 1) {
            std::cout << ";";
        }
    }
    std::cout << std::endl;

    return signalBits;

}

void Radar::readfile(const std::string& filePath){

std::ifstream file(filePath);
if (!file.is_open()) {
    std::cerr << "Error opening file!\n";
}

std::string line;
while (std::getline(file, line)) {
    std::vector<std::bitset<7>> rowData;
    std::stringstream ss(line);
    std::string value;

    while (std::getline(ss, value, ';')) {
        rowData.push_back(std::bitset<7>(std::stoi(value, nullptr, 2)));
    }
    
    cachedData.push_back(rowData);
}

file.close();

}