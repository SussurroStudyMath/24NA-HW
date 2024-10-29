#include "Interpolation.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

const double pi = acos(-1.);
class F1: public Function{
public:
    double operator() (double x) const{
        return 1.0/(1 + 25*x*x);
    }
};

int main(){
    std::vector<double> draw_points; // points for drawing figures
    F1 f;
    int N = 100;
    std::ofstream file;
    file.open("fig/ProblemC.txt");
    for(int i = 0; i <= N; i++){
        double point = -1 + 2.0*i/N;
        file << point << " ";
        draw_points.push_back(point);
    }
    file << std::endl;
    for(int i = 0; i <= N; i++){
        file << f(draw_points[i]) << " ";
    }
    file << std::endl;
    for(int n = 5; n <= 20; n+=5){
        std::vector<double> points; // points for interpolation
        for(int i = 1; i <= n; i++){
            double point = cos((2*i-1)*pi/(2*n));
            points.push_back(point);
        }
        Newton_Interpolaion p(F1(), points);
        for(int i = 0; i <= N; i++){
            file << p(draw_points[i]) << " ";
        }
        file << std::endl;
    }
    file.close();
    
}