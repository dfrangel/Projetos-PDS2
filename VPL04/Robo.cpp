#include <iostream>
#include <iomanip>
#include <cmath>

#include "Ponto2D.hpp"
#include "Robo.hpp"

Robo::Robo(int id, Ponto2D pos, bool bola) {
        this->_com_bola = bola;
        this->id = id;
        this->pos = pos;
}

void Robo::mover(double v, double th, double t) {
    Ponto2D posi = pos;
    double sx, sy;
    double vx, vy;

    vx = cos(th) * v;
    vy = sin(th) * v;

    sx = this->pos.x + (vx * t);
    sy = this->pos.y + (vy * t);

    this->pos.x = sx;
    this->pos.y = sy;

   _energia -= pos.calcular_distancia(&posi);
}

double Robo::calcular_distancia(Robo* robo) {
    return this->pos.calcular_distancia(&robo->pos);
}

Robo* Robo::determinar_robo_mais_proximo(Robo** naves, int n) {
    Robo* mais_prox;
    
    if (this->id != naves[0]->id) {
        mais_prox = naves[0];
    }
    else {
        mais_prox = naves[1];
    }

    for (int i = 0; i < n; i++) {
        if (this->calcular_distancia(naves[i]) < this->calcular_distancia(mais_prox) && 
            this->id != naves[i]->id) {
            mais_prox = naves[i];
        }
    }

    return mais_prox;
}

void Robo::passar_bola(Robo** time, int n) {
    if (!this->_com_bola) {
        std::cout << "Estou sem a bola!" << std::endl;
    }
    else {
        determinar_robo_mais_proximo(time, n)->_com_bola = this->_com_bola;
        this->_com_bola = !this->_com_bola;
    }
}

void Robo::imprimir_status() {
    std::cout << this->id << "\t";
    std::cout << std::fixed << std::setprecision(2) << this->pos.x << "\t";
    std::cout << std::fixed << std::setprecision(2) << this->pos.y << "\t";
    std::cout << this->_com_bola << "\t";
    std::cout << std::fixed << std::setprecision(2) << this->_energia << std::endl;
}