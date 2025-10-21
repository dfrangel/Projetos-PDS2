#include "Frota.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include "Caminhao.hpp"
#include "Carro.hpp"
#include "Moto.hpp"
#include "Veiculo.hpp"

Frota::Frota() 
     : _veiculos() {};

Frota::~Frota() {
    for (Veiculo* i : _veiculos) {
        delete i;
    }
}

void Frota::add_carro(std::string placa, int ano, int capacidade_kg, int num_portas) {
    Veiculo* c = new Carro(placa, ano, capacidade_kg, num_portas);
    _veiculos.push_back(c);
}

void Frota::add_moto(std::string placa, int ano, int capacidade_kg, int cilindradas) {
    Veiculo* m = new Moto(placa, ano, capacidade_kg, cilindradas);
    _veiculos.push_back(m);
}

void Frota::add_caminhao(std::string placa, int ano, int capacidade_kg, int num_eixos) {
    Veiculo* c = new Caminhao(placa, ano, capacidade_kg, num_eixos);
    _veiculos.push_back(c);
}


void Frota::list() {
    if (_veiculos.size() == 0) {
        std::cout << "Frota vazia!" << std::endl;
        return;
    }

    for (Veiculo* i : _veiculos) {
            i->print_info();
    }
}

void Frota::find(int indice) const {

    for (Veiculo* i : _veiculos) {
        if (i->get_id() == indice) {
            i->print_info();
            return;
        }
    }

    std::cout << "Erro: indice invalido" << std::endl;
    return;
}

void Frota::remover(int indice) {
    if (indice >= 0 && indice <= ((int) _veiculos.size()) - 1) {
        delete _veiculos[indice];
        _veiculos.erase(_veiculos.begin() + indice);
        return;
    }

    std::cout << "Erro: indice invalido" << std::endl;
    return;
}

void Frota::viagem(int indice, double km, int carga_kg) {
    for (Veiculo* i : _veiculos) {
        if (i->get_id() == indice) {
            if(carga_kg > i->capacidade_kg()) {
                std::cout << "Erro: carga excede capacidade" << std::endl;
                return;
            }
            else {
                std::cout << "Custo: " << std::fixed << std::setprecision(2) << i->custo_viagem(km, carga_kg) << std::endl;
                return;
            }
        }
    }
    
    std::cout << "Erro: indice invalido" << std::endl;
    return;
}