#include <string>
#include <vector>
#include <fstream>
#include <bitset>


class Radar
{
private:
    std::vector <std::bitset<7>> radarSignals;
    std::vector<std::vector<std::bitset<7>>> cachedData;
    void readfile();
public:
    Radar();
    std::vector<std::bitset<7>> getSignal();
};
