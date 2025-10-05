#ifndef PONTO2D_HPP
#define PONTO2D_HPP
#include <iostream>
#include <iomanip>

struct Ponto2D {
    double x;
    double y;

    Ponto2D();
    Ponto2D(double, double);
    
    double calcular_distancia(Ponto2D* ponto);
};

#endif