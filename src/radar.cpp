#include <iostream>
#include <fstream>
#include <sstream>
#include"radar.hpp"

Radar::Radar(){
    readfile();
}

std::vector<std::bitset<7>>Radar::getSignal()
{
    std::vector<int> dummySignal{10,51,38,16,28,45,122,93,52,107,19};

    std::vector<std::bitset<7>> signalBits;

    for (size_t i = 0; i < dummySignal.size(); ++i) {
        std::bitset<7> bits(dummySignal[i]);
        signalBits.push_back(bits);

        std::cout << bits;  
        if (i < dummySignal.size() - 1) {
            std::cout << ";";
        }
    }
    std::cout << std::endl;

    return signalBits;

}

void Radar::readfile(){

std::ifstream file("../../data/radar_data.csv");
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