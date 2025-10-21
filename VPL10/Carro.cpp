#include "Carro.hpp"
#include <iostream>

Carro::Carro(std::string placa, int ano, int capacidade_kg, int num_portas) 
      : Veiculo(placa, ano, capacidade_kg), _num_portas(num_portas) {};

Carro::~Carro() {
    std::cout << "Destrutor Carro" << std::endl;
}

std::string Carro::tipo() {
    return "Carro";
}

void Carro::print_info() {
    std::cout << "Tipo: " << Carro::tipo();
    Veiculo::print_info();
    std::cout << ", Portas: " << _num_portas << std::endl;
}

double Carro::custo_viagem(double km, double carga_kg) {
    return ((1.2 * km) + (40.0 * carga_kg));
}