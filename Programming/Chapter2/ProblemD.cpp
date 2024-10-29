#include "Interpolation.hpp"
#include <iostream>

int main(){
    std::vector<double> points = {0,3,5,8,13};
    std::vector<int> order = {2,2,2,2,2};
    std::vector<double> functions_values = {0,225,383,623,993};
    std::vector<double> derivate_values = {75,77,80,74,72};
    Hermite_Interpolation p(points, order, functions_values, derivate_values);
    std::cout << "Solution of Problem D:" << std::endl;
    std::cout << "Position at t = 10s: " << p(10) << std::endl;
    std::cout << "Velocity at t = 10s: " << p.derivative(10) << std::endl;
    for(double i = 0 ; i < 13 ; i += 0.1){
        if(p.derivative(i) > 81){
            std::cout << "Exceed at time: " << i << "(s)" << std::endl;
            break;
        }
    }
}   