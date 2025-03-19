#include <string>
#include <vector>
#include <fstream>
#include <bitset>


class Radar
{

public:
    Radar(const std::string& filePath);
    std::vector<std::bitset<7>> getSignal(int signalIndex);

private:
    std::vector <std::bitset<7>> radarSignals;
    std::vector<std::vector<std::bitset<7>>> cachedData;
    void readfile(const std::string& filePath);
};
