#include "Moto.hpp"
#include <iostream>

Moto::Moto(std::string placa, int ano, int capacidade_kg, int cilindradas) 
     : Veiculo(placa, ano, capacidade_kg), _cilindradas(cilindradas) {};

Moto::~Moto() {
    std::cout << "Destrutor Moto" << std::endl;
}

std::string Moto::tipo() {
    return "Moto";
}

void Moto::print_info() {
    std::cout << "Tipo: " << Moto::tipo();
    Veiculo::print_info();
    std::cout << ", Cilindradas: " << _cilindradas << std::endl;
}

double Moto::custo_viagem(double km, double carga_kg) {
    return ((0.8 * km) + (25.0 * carga_kg));
}