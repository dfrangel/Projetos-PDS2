#include "Veiculo.hpp"
#include <iostream>

int Veiculo::_next_id = 0;

Veiculo::Veiculo(std::string placa, int ano, int capacidade_kg)
    : _placa (placa), _ano (ano), _capacidade_kg (capacidade_kg), _id(_next_id) {
    _next_id++;
}

Veiculo::~Veiculo () {
    std::cout << "Destrutor Veiculo" << std::endl;
}

std::string Veiculo::placa() {
    return this->_placa;
}

int Veiculo::ano() {
    return this->_ano;
}

int Veiculo::capacidade_kg() {
    return this->_capacidade_kg;
}

int Veiculo::get_id() {
    return this->_id;
}

void Veiculo::print_info() {
    std::cout << ", " << "Placa: " << placa() << ", " <<
                 "Ano: " << ano() << ", " <<
                 "Capacidade: " << capacidade_kg();
}