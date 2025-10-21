#include "Frota.hpp"
#include <iostream>
#include <string>


int main () {
    std::string comando, placa;
    int ano, capacidade, indice, atributo, carga;
    double km;

    Frota* f = new Frota();

    while (std::cin >> comando) {
        if (comando == "add_c") {
            std::cin >> placa >> ano >> capacidade >> atributo;
            f->add_carro(placa, ano, capacidade, atributo);
        }

        if (comando == "add_m") {
            std::cin >> placa >> ano >> capacidade >> atributo;
            f->add_moto(placa, ano, capacidade, atributo);
        }

        if (comando == "add_k") {
            std::cin >> placa >> ano >> capacidade >> atributo;
            f->add_caminhao(placa, ano, capacidade, atributo);
        }

        if (comando == "list") {
            f->list();
        }

        if (comando == "find") {
            std::cin >> indice;
            f->find(indice);
        }

        if (comando == "rm") {
            std::cin >> indice;
            f->remover(indice);            
        }

        if (comando == "viagem") {
            std::cin >> indice >> km >> carga;
            f->viagem(indice, km, carga);
        }

        if (comando == "quit") {
            delete f;
        }
    }
    
}