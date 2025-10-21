#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP
#include "Veiculo.hpp"

class Caminhao : public Veiculo {
    public:

        int _num_eixos;

        Caminhao(std::string placa, int ano, int capacidade_kg, int num_eixos);
        ~Caminhao();

        virtual std::string tipo() override;
        void print_info();
        virtual double custo_viagem(double km, double carga_kg) override;
};

#endif