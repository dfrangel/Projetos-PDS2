#include "Caminhao.hpp"
#include <iostream>

Caminhao::Caminhao(std::string placa, int ano, int capacidade_kg, int num_eixos)
         : Veiculo(placa, ano, capacidade_kg), _num_eixos(num_eixos) {};

Caminhao::~Caminhao() {
    std::cout << "Destrutor Caminhao" << std::endl;
}

std::string Caminhao::tipo() {
    return "Caminhao";
}

void Caminhao::print_info() {
    std::cout << "Tipo: " << Caminhao::tipo();
    Veiculo::print_info();
    std::cout << ", Eixos: " << _num_eixos << std::endl;
}

double Caminhao::custo_viagem(double km, double carga_kg) {
    return ((2.5 * km) + (60.0 * carga_kg));
}