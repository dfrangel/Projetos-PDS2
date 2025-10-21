#ifndef CARRO_HPP
#define CARRO_HPP
#include "Veiculo.hpp"

class Carro : public Veiculo {
    public:
        
        int _num_portas;

        Carro(std::string placa, int ano, int capacidade_kg, int num_portas);
        ~Carro();

        virtual std::string tipo() override;
        void print_info();
        virtual double custo_viagem(double km, double carga_kg) override;
};

#endif