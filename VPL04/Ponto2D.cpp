#include <iostream>
#include <iomanip>
#include <cmath>

#include "Ponto2D.hpp"

Ponto2D::Ponto2D() {
        x = 0;
        y = 0;
}

Ponto2D::Ponto2D(double x, double y) {
        this->x = x;
        this->y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto) {
        double dist;
        double x1 = this->x - ponto->x;
        double y1 = this->y - ponto->y;

        dist = sqrt(pow(x1, 2) + pow(y1, 2));

        return dist;
}