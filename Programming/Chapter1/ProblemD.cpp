#include "EquationSolver.hpp"

const double Pi = acos(-1.);

class F1 : public Function{
public:
    double operator() (double x) const{
        return sin(x/2) - 1;
    }
};

class F2 : public Function{
public:
    double operator() (double x) const{
        return exp(x) - tan(x);
    }
};

class F3 : public Function{
public:
    double operator() (double x) const{
        return pow(x,3) - 12*pow(x,2) + 3*x + 1;
    }
};

void solve_f1(double x0, double x1){
    std::cout << "Solving sin(x/2) - 1 = 0 with initial value " << x0  << " and " << x1 << " by Secant method:" << std::endl;
    Secant_Method solver(F1(), x0, x1);
    double x = solver.solve();
    std::cout << "A root is: " << x << std::endl;
}

void solve_f2(double x0, double x1){
    std::cout << "Solving exp(x) - tan(x) = 0 with initial value " << x0  << " and " << x1 << " by Secant method:" << std::endl;
    Secant_Method solver(F2(), x0, x1);
    double x = solver.solve();
    std::cout << "A root is: " << x << std::endl;
}

void solve_f3(double x0, double x1){
    std::cout << "Solving x^3 - 12x^2 + 3x + 1 = 0 with initial value " << x0  << " and " << x1 << " by Secant method:" << std::endl;
    Secant_Method solver(F3(), x0, x1);
    double x = solver.solve();
    std::cout << "A root is: " << x << std::endl;
}
int main(){
    solve_f1(0,Pi/2);
    solve_f1(4*Pi,9*Pi/2);
    solve_f2(1,1.4);
    solve_f2(10,11);
    solve_f3(0,-0.5);
    solve_f3(10,11);
    std::cout << std::endl;
}