#ifndef ROBO_HPP
#define ROBO_HPP
#include <iostream>
#include <iomanip>

#include "Ponto2D.hpp"

struct Robo {
    int id;
    double _energia = 100; 
    bool _com_bola;
    Ponto2D pos;

    Robo(int id, Ponto2D pos, bool _com_bola);

    void mover(double v, double th, double t);

    double calcular_distancia(Robo* robo);
    
    Robo* determinar_robo_mais_proximo(Robo** naves, int n);
    
    void passar_bola(Robo** time, int n);
    
    void imprimir_status();
};

#endif