#include "Interpolation.hpp"
#include <iostream>
#include <cmath>
#include <fstream>

const double pi = acos(-1.);

class X : public Function{
public:
    double operator() (double t){
        return sqrt(3)*sin(2*pi*t);
    }
};

class Y: public Function{
public:
    double operator() (double t){
        return (sqrt(sqrt(3)*fabs(sin(2*pi*t))) + sqrt(3)*cos(2*pi*t))*2/3;
    }
};

int main(){
    
    
    int N = 500;
    std::vector<double> t_points;
    std::vector<Point> interpolation_points;
    X x;
    Y y;
    std::ofstream file;
    file.open("fig/ProblemF.txt");
    int n = 10;
    for(int i = 0; i <= n; i++){
        double t = 1.0*i/n;
        Point a(x(t),y(t));
        t_points.push_back(t);
        interpolation_points.push_back(a);
    }
    Bezier_Curve B1(t_points,interpolation_points);
    t_points.clear();
    interpolation_points.clear();
    n = 40;
    for(int i = 0; i <= n; i++){
        double t = 1.0*i/n;
        Point a(x(t),y(t));
        t_points.push_back(t);
        interpolation_points.push_back(a);
    }
    Bezier_Curve B2(t_points,interpolation_points);
    t_points.clear();
    interpolation_points.clear();
    n = 160;
    for(int i = 0; i <= n; i++){
        double t = 1.0*i/n;
        Point a(x(t),y(t));
        t_points.push_back(t);
        interpolation_points.push_back(a);
    }
    Bezier_Curve B3(t_points,interpolation_points);
    t_points.clear();
    interpolation_points.clear();
    for(int i = 0; i <= N; i++){
        double t = 1.0*i/N;
        Point a = B1(t);
        Point b = B2(t);
        Point c = B3(t);
        file << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << std::endl;
    }

}