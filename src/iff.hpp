#include <bitset>
#include <vector>
enum class TargetType {
    Friend,
    Hostile,
};

class Iff{

public:
TargetType identifyTarget(std::vector<std::bitset<7>> radarSignal);
};

