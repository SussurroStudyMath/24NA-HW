#pragma once
#include <vector>
#include <cmath>
#include <iostream>

class Function{
public:
    virtual double operator() (double x) const{return 0;};
};

// calculate factorial
int factorial(int n){
    if (n == 1){
        return 1;
    }
    return n*factorial(n-1);
}

// calculate combination number C_n^m
int C_nm(int n, int m){
    if(n == m || m == 1){
        return 1;
    }
    return C_nm(n,m-1) + C_nm(n-1,m-1);
}

class Newton_Interpolaion: public Function{    
private:
    const Function & F; // F : the interpolated function
    std::vector<double> interpolation_points; // points for interpolation
    std::vector<double> function_values; // function values of interpolation points
    std::vector<std::vector<double>> dd; // dd: table of divided difference
public:
    // initialize if given F and interpolation points
    Newton_Interpolaion(const Function & F, std::vector<double> interpolation_points):
        F(F), interpolation_points(interpolation_points){
            // fill function values
            for(int i = 0; i < interpolation_points.size(); i++){
                function_values.push_back(F(interpolation_points[i]));
            }
            // fill dd
            dd.resize(interpolation_points.size(),std::vector<double>(interpolation_points.size()));
            for(int i = 0; i < interpolation_points.size(); i++){
                dd[i][0] = function_values[i];
            }
            // i for columns
            for(int i = 1; i < interpolation_points.size(); i++){
                // j for rows
                for(int j = i; j < interpolation_points.size(); j++){
                    dd[j][i] = (dd[j][i-1] - dd[j-1][i-1])/(interpolation_points[j] - interpolation_points[j-i]);
                }
            }
        }
    // initialize if given interpolation points and function values
    Newton_Interpolaion(std::vector<double> function_values, std::vector<double> interpolation_points):
        F(*(new Function())),function_values(function_values), interpolation_points(interpolation_points){
            // fill dd
            dd.resize(interpolation_points.size(),std::vector<double>(interpolation_points.size()));
            for(int i = 0; i < interpolation_points.size(); i++){
                dd[i][0] = function_values[i];
            }
            // i for columns
            for(int i = 1; i < interpolation_points.size(); i++){
                // j for rows
                for(int j = i; j < interpolation_points.size(); j++){
                    dd[j][i] = (dd[j][i-1] - dd[j-1][i-1])/(interpolation_points[j] - interpolation_points[j-i]);
                }
            }
        }
    double operator()(double x) const{
        double result = dd[0][0];
        for(int i = 1; i < interpolation_points.size(); i++){
            double term = dd[i][i];
            for(int j = 0; j < i; j++){
                term *= x - interpolation_points[j];
            }
            result += term;
        }
        return result;
    }
};

class Hermite_Interpolation: public Function{
private:
    std::vector<double> interpolation_points;
    std::vector<int> order; // order of each interpolation point, 1: only function value, 2: function value and derivate, ...
    std::vector<double> function_values;
    std::vector<double> derivative_values;
    std::vector<std::vector<double>> dd; // dd: table of divided difference
public:
    Hermite_Interpolation(std::vector<double> points, std::vector<int> order, std::vector<double> function_values,std::vector<double> derivative_values):
         order(order), function_values(function_values), derivative_values(derivative_values){
            int dd_size = function_values.size() + derivative_values.size();
            dd.resize(dd_size, std::vector<double>(dd_size));
            int cnt = 0;
            for(int i = 0; i < points.size(); i++){
                for(int j = 0; j < order[i]; j++){
                    interpolation_points.push_back(points[i]);
                    dd[cnt++][0] = function_values[i];
                }
            }
            cnt = 0;
            for(int i = 1; i < dd_size; i++){
                for(int j = i; j < dd_size; j++){
                    if(interpolation_points[j] == interpolation_points[j-i]){
                        dd[j][i] = derivative_values[cnt++]/factorial(i);
                    }
                    else{
                        dd[j][i] = (dd[j][i-1] - dd[j-1][i-1])/(interpolation_points[j] - interpolation_points[j-i]);
                    }
                }
            }
        }
    double operator()(double x){
        double result = dd[0][0];
        for(int i = 1; i < interpolation_points.size(); i++){
            double term = dd[i][i];
            for(int j = 0; j < i; j++){
                term *= x - interpolation_points[j];
            }
            result += term;
        }
        return result;
    }
    double derivative(double x){
        double result = dd[1][1];
        for(int i = 2; i < interpolation_points.size(); i++){
            double term = 0;
            for(int j = 0; j < i; j++){
                double subterm = 1;
                for(int k = 0; k < i; k++){
                    if(k == j) continue;
                    subterm *= x - interpolation_points[k];
                }
                term += subterm;
            }
            term *= dd[i][i];
            result += term;
        }
        return result;
    }
};

class Point{
public:
    double x;
    double y;
    Point(){};
    Point(double x,double y):
        x(x),y(y){}
    // override operators for convenience
    Point operator +(Point a){
        Point b;
        b.x = this->x + a.x;
        b.y = this->y + a.y;
        return b;
    }
    Point operator -(Point a){
        Point b;
        b.x = this->x - a.x;
        b.y = this->y - a.y;
        return b;
    }
    Point operator *(double t){
        Point a;
        a.x = t*x;
        a.y = t*y;
        return a;
    }
    Point operator /(double t){
        Point a;
        a.x = x/t;
        a.y = y/t;
        return a;
    }
    void operator =(Point a){
        x = a.x;
        y = a.y;
    }
};

class Bezier_Curve{
private:
    std::vector<double> t_points; // interpolation of t
    std::vector<Point> interpolation_points; // interpolation of (x,y)
public:
    Bezier_Curve(std::vector<double> t_points, std::vector<Point> interpolation_points):
        t_points(t_points), interpolation_points(interpolation_points){}
    Point operator()(double t){
        int interval_index;
        // choose which interval to use
        for(int i = 0; i < t_points.size() - 1; i++){
            if(t >= t_points[i] && t <= t_points[i+1]){
                interval_index = i;
                break;
            }
        }
        // use difference as derivate
        Point q0 = interpolation_points[interval_index];
        Point q1 = interpolation_points[interval_index]*2/3 + interpolation_points[interval_index + 1]/3;
        Point q2 = interpolation_points[interval_index]/3 + interpolation_points[interval_index + 1]*2/3;
        Point q3 = interpolation_points[interval_index + 1];
        Point B_t = q0*pow(1-t,3) + q1*pow(1-t,2)*t*C_nm(3,1) + q2*pow(t,2)*(1-t)*C_nm(3,2) + q3*pow(t,3);
        return B_t;
    }
};