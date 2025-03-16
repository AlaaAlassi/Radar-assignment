#include <string>
#include <vector>
#include <fstream>
#include <bitset>


class Radar
{
private:
    std::vector <unsigned char> radar_signal;
public:
    std::vector<std::bitset<7>> getSignal();
};
