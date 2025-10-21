#ifndef FROTA_HPP
#define FROTA_HPP
#include "Veiculo.hpp"
#include <vector>


class Frota {
    public:
    std::vector<Veiculo*> _veiculos;

    Frota() = default;
    ~Frota();

    void add_carro(std::string placa, int ano, int capacidade_kg, int num_portas);
    void add_moto(std::string placa, int ano, int capacidade_kg, int cilindradas);
    void add_caminhao(std::string placa, int ano, int capacidade_kg, int num_eixos);

    void list();
    void find(int indice) const;
    void remover(int indice);
    void viagem(int indice, double km, int carga_kg);
};

#endif