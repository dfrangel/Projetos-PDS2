#include "Carrossel.hpp"
#include <algorithm>
#include <iomanip>

Carrossel::Carrossel(const std::string& cod, int ano, double kw, int cap, int bichos)
          :Brinquedo(cod, ano, kw, cap), _bichos(bichos) {
}

std::string Carrossel::tipo() const {
    return "Carrossel";
}

void Carrossel::imprimir_status() const {
    std::string estado;
    if (this->pausado()) {
        estado = "pausado";
    } else {
        estado = "ativo";
    }
        
    std::cout << this->codigo() << " "
              << this->tipo() << " "
              << this->ano() << " "
              << this->capacidade() << " "
              << std::fixed << std::setprecision(1)
              << this->potencia_kw() << " "
              << estado << " "
              << "bichos " << _bichos << std::endl;
}

void Carrossel::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
    if (pausado()) {
        atendidos = 0;
        receita = 0;
        energia = 0;
        return;
    }

    if (demanda >= capacidade()) {
        atendidos = capacidade();
        demanda -= atendidos;
    }
    else if (demanda - capacidade() < 0) {
        atendidos = demanda;
        demanda = 0;
    }

    receita = atendidos * (6 + (0.75 * _bichos));

    if (atendidos > 0) {
        energia = 0.3 * _potencia_kw;
    }
    else {
        energia = 0;
    }

    return;
}