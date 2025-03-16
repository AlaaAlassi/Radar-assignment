#include "iff.hpp"

TargetType Iff::identifyTarget(std::vector<std::bitset<7>> radarSignal){
    return TargetType::Hostile;
}
