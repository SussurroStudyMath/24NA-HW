#pragma once

#include "Function.hpp"
#include <cmath>
#include <iostream>

class EquationSolver{
protected:
    const Function & F;
public:
    EquationSolver(const Function& F) : F(F){}
    virtual double solve() = 0;
};

class Bisection_Method : public EquationSolver{
private:
    double a, b;
    double eps, delta;
    int Maxiter;
public:
    Bisection_Method(const Function& F, double a, double b, double eps = 1e-7, double delta = 1e-6, int Maxiter = 50):
        EquationSolver(F), a(a), b(b), eps(eps), delta(delta), Maxiter(Maxiter){}
    virtual double solve(){
        double h = b - a;
        double f_min_x = F(a);
        double f_max_x = F(b);
        if(F(a)*F(b) > 0){
            std::cout << "Function values of two endpoints are with the same sign!" << std::endl;
            return 0;
        }
        for(int i = 0; i < Maxiter; i++){
            h /= 2;
            double mid_x = a + h;
            if(h < delta){
                std::cout << "Iteration times: " << i << std::endl;
                std::cout << "Iteration stops for h < delta !" << std::endl;
                return mid_x;
            }
            double f_mid_x = F(mid_x);
            if(fabs(f_mid_x) < eps){
                std::cout << "Iteration times: " << i << std::endl;
                std::cout << "Iteration stops for fabs(f(x)) < eps !" << std::endl;
                return mid_x;
            }
            else if (f_min_x * f_mid_x > 0){
                a += h;
            }
        }
        std::cout << "Iteration times: " << Maxiter << std::endl;
        std::cout << "Iteration stops for reaching Maxiter !" << std::endl;
        return 0;
    }

};

class Newton_Method : public EquationSolver{
private:
    double x0;
    double eps;
    int Maxiter;
public:
    Newton_Method(const Function& F, double x0, double eps = 1e-7, int Maxiter = 30):
        EquationSolver(F), x0(x0), eps(eps), Maxiter(Maxiter){}
    virtual double solve(){
        double x = x0;
        double f_x = F(x);
        for(int i = 0; i < Maxiter; i++){
            if(fabs(f_x) < eps){
                std::cout << "Iteration times: " << i << std::endl;
                std::cout << "Iteration stops for fabs(f(x)) < eps !" << std::endl;
                return x;
            }
            double d_fx = F.derivative(x);
            x -= f_x / d_fx;
            f_x = F(x);
        }
        std::cout << "Iteration times: " << Maxiter << std::endl;
        std::cout << "Iteration stops for reaching Maxiter !" << std::endl;
        return 0;
    }
};

class Secant_Method : public EquationSolver{
private:
    double x0, x1;
    double eps, delta;
    int Maxiter;
public:
    Secant_Method(const Function& F,double x0, double x1, double eps = 1e-7, double delta = 1e-6, double Maxiter = 50):
        EquationSolver(F), x0(x0), x1(x1), eps(eps), delta(delta), Maxiter(Maxiter){}
    virtual double solve(){
        double x_0 = x0;
        double x_1 = x1;
        double f_x0 = F(x0);
        double f_x1 = F(x1);
        for(int i = 0; i < Maxiter; i++){
            double x_dis = fabs(x_0 - x_1);
            if(x_dis < delta){
                std::cout << "Iteration times: " << i << std::endl;
                std::cout << "Iteration stops for |x_{n+1} - x_n| < delta !" << std::endl;
                return x_1;
            }
            if(fabs(f_x1) < eps){
                std::cout << "Iteration times: " << i << std::endl;
                std::cout << "Iteration stops for fabs(f(x)) < eps !" << std::endl;
                return x_1;
            }
            double df = (f_x0 - f_x1) / (x_0 - x_1);
            x_0 = x_1;
            x_1 = x_1 - f_x1 / df;
            f_x0 = F(x_0);
            f_x1 = F(x_1);
        }
        std::cout << "Iteration times: " << Maxiter << std::endl;
        std::cout << "Iteration stops for reaching Maxiter !" << std::endl;
        return 0;
    }
};