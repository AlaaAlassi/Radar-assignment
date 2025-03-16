#include "firing_unit.hpp"

double FiringUnit::fire(){

    std::cout <<  "Missile Launched" << std::endl;
    static std::random_device rd;
    static std::mt19937 gen(rd()); 
    static std::uniform_real_distribution<double> dist(0.0, 1.0);

    return dist(gen);
}