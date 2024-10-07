#include "EquationSolver.hpp"

const double Pi = acos(-1.);

class F : public Function{
private:
    double r;
    double L;
    double V;
public:
    F(double r,double L,double V):
        r(r),L(L), V(V){}
    double operator() (double h) const{
        return L*(0.5 * Pi * r * r - r * r * asin(h/r) - h * sqrt(r * r - h * h)) - V;
    }
};

void solve(){
    double r = 1;
    double L = 10;
    double V = 12.4;
    Bisection_Method solver(F(r,L,V), 0 , 2*V/(L*Pi), 0.01);
    double x = solver.solve();
    std::cout << "The height is: " << x << std::endl;
}

int main(){
    solve();
    std::cout << std::endl;
}