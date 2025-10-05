#include "MontanhaRussa.hpp"
#include <algorithm>
#include <iomanip>

MontanhaRussa::MontanhaRussa(const std::string& cod, int ano, double kw, int cap, int loops)
    : Brinquedo(cod, ano, kw, cap), _loops(loops) {
}

std::string MontanhaRussa::tipo() const {
    return "MontanhaRussa";
}

void MontanhaRussa::imprimir_status() const {
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
              << "loops " << _loops << std::endl;
}

void MontanhaRussa::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
    if (pausado()) {
        atendidos = 0;
        receita = 0;
        energia = 0;
        return;
    }

    if (demanda > capacidade()) {
        atendidos = capacidade();
        demanda -= atendidos;
    }
    else if (demanda <= capacidade()) {
        atendidos = demanda;
        demanda = 0;
    }

    receita = atendidos * (12 + (0.25 * _loops));

    if (atendidos > 0) {
        energia = 0.8 * _potencia_kw;
    }
    else {
        energia = 0;
    }

    return;
}