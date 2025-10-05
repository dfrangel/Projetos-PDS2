#include "RodaGigante.hpp"
#include <algorithm>
#include <iomanip>

RodaGigante::RodaGigante(const std::string& cod, int ano, double kw, int cap, int cabines)
            :Brinquedo(cod, ano, kw, cap), _cabines(cabines) {}

std::string RodaGigante::tipo() const {
    return "RodaGigante";
}

void RodaGigante::imprimir_status() const {
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
              << "cabines " << _cabines << std::endl;
}

void RodaGigante::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
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

    receita = atendidos * (8 + (0.50 * _cabines));

    if (atendidos > 0) {
        energia = 0.5 * _potencia_kw;
    }
    else {
        energia = 0;
    }

    return;
}