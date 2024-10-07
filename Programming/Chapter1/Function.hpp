#pragma once

class Function{
public:
    virtual double operator() (double x) const = 0;
    virtual double derivative(double x) const{ return 0;};
};