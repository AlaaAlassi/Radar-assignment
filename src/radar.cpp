#include <iostream>
#include"radar.hpp"

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