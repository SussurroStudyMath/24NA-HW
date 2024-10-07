#include "EquationSolver.hpp"

const double Pi = acos(-1.);

class F1 : public Function{
private:
    double A, B, C, D, E;
    double beta1;
    double l, h;
public:
    F1(double beta1, double l, double h, double D):
        beta1(beta1), l(l), h(h), D(D){
            A = l*sin(beta1);
            B = l*cos(beta1);
            C = (h + 0.5*D)*sin(beta1) - 0.5*D*tan(beta1);
            E = (h + 0.5*D)*cos(beta1) - 0.5*D;
        }
    double operator() (double alpha) const{
        return A*sin(alpha)*cos(alpha) + B*sin(alpha)*sin(alpha) - C*cos(alpha) - E*sin(alpha);
    }
    double derivative(double alpha) const{
        return A*(cos(alpha)*cos(alpha) - sin(alpha)*sin(alpha)) + 2*B*sin(alpha)*cos(alpha) + C*sin(alpha) - E*cos(alpha);
    }
};

void solver1(double alpha, double beta1, double l, double h, double D){
    Newton_Method solver(F1(beta1, l, h, D), alpha);
    double x = solver.solve();
    x *= 360/(2*Pi);
    std::cout << "A root is: " << x << " degrees." << std::endl;
}

void solver2(double alpha1, double alpha2, double beta1, double l, double h, double D){
    Secant_Method solver(F1(beta1, l, h, D), alpha1, alpha2);
    double x = solver.solve();
    x *= 360/(2*Pi);
    std::cout << "A root is: " << x << " degrees." << std::endl;
}

int main(){
    double beta1 = 11.5*2*Pi/360;
    double l = 89;
    double h = 49;
    double D = 55;
    double alpha = 33*2*Pi/360;
    std::cout << "(a)" << std::endl;
    solver1(alpha, beta1, l, h, D);
    D = 30;
    std::cout << "(b)" << std::endl;
    solver1(alpha, beta1, l, h, D);
    double alpha1 = 30;
    double alpha2 = 60;
    std::cout << "(c)" << std::endl;
    std::cout << "alpha1 = " << alpha1 << " degrees, alpha2 = " << alpha2 << " degrees:" << std::endl;
    solver2(alpha1*2*Pi/360, alpha2*2*Pi/360, beta1, l, h, D);
    alpha1 = 0;
    alpha2 = 10;
    std::cout << "alpha1 = " << alpha1 << " degrees, alpha2 = " << alpha2 << " degrees:" << std::endl;
    solver2(alpha1*2*Pi/360, alpha2*2*Pi/360, beta1, l, h, D);
    alpha1 = 80;
    alpha2 = 90;
    std::cout << "alpha1 = " << alpha1 << " degrees, alpha2 = " << alpha2 << " degrees:" << std::endl;
    solver2(alpha1*2*Pi/360, alpha2*2*Pi/360, beta1, l, h, D);
    std::cout << std::endl;
}