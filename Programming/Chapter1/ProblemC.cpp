#include "EquationSolver.hpp"

class F1 : public Function{
public:
    double operator() (double x) const{
        return x - tan(x);
    }
    double derivative(double x) const{
        return 1 - 1/(cos(x) * cos(x));
    }
};

void solve(double x0){
    std::cout << "Solving x = tanx near x = " << x0 << " by Newton method:" << std::endl;
    Newton_Method solver(F1(), x0);
    double x = solver.solve();
    std::cout << "A root is: " << x << std::endl;
}

int main(){
    solve(4.5);
    solve(7.7);
    std::cout << std::endl;
}