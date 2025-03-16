#include "iff.hpp"

TargetType Iff::identifyTarget(std::vector<std::bitset<7>> radarSignal){

    int radarSignalSize = radarSignal.size();
    int numOfEven = 0;
    for(auto value : radarSignal){

        //convert to decimal
        unsigned long dValue = value.to_ulong();

        //check even
        if(dValue % 2 == 0){
            numOfEven++;
        }

    }

    if (numOfEven > (radarSignalSize/2)){
        return TargetType::Friend;
    }

    return TargetType::Hostile;
}
