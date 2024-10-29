#include "Interpolation.hpp"
#include <iostream>
#include <cmath>
#include <fstream>

int main(){
    std::vector<double> points = {0,6,10,13,17,20,28};
    std::vector<double> function_values1 ={6.67,17.3,42.7,37.3,30.1,29.3,28.7};
    std::vector<double> function_values2 ={6.67,16.1,18.9,15.0,10.6,9.44,8.89};
    Newton_Interpolaion p1(function_values1,points);
    Newton_Interpolaion p2(function_values2,points);
    std::ofstream file;
    file.open("fig/ProblemE.txt");
    for(double i = 0; i <= 28; i+=0.1){
        file << i << " ";
    }
    file << std::endl;
    for(double i = 0; i <= 28; i+=0.1){
        file << p1(i) << " ";
    }
    file << std::endl;
    for(double i = 0; i <= 28; i+=0.1){
        file << p2(i) << " ";
    }
    file << std::endl;
    file.close();
    std::cout << "Solution of Problem E:" << std::endl;
    int die = 0;
    for(int i = 29; i <= 43; i++){
        if(p1(i) < 0){
            std::cout << "Sp1 dies at Day " << i << std::endl;
            die = 1;
            break;
        }
    }
    if(die == 0){
        std::cout << "Sp1 survives after another 15 days and has average weight of " << p1(43) << std::endl;
    }
    die = 0;
    for(int i = 29; i <= 43; i++){
        if(p2(i) < 0){
            std::cout << "Sp2 dies at Day " << i << std::endl;
            die = 1;
            break;
        }
    }
    if(die == 0){
        std::cout << "Sp2 survives after another 15 days and has average weight of " << p2(43) << std::endl;
    }
    
}