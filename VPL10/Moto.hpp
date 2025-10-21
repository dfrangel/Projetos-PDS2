#ifndef MOTO_HPP
#define MOTO_HPP
#include "Veiculo.hpp"

class Moto : public Veiculo {
    public:
        
        int _cilindradas;

        Moto(std::string placa, int ano, int capacidade_kg, int cilindradas);
        ~Moto();

        virtual std::string tipo() override;
        void print_info();
        virtual double custo_viagem(double km, double carga_kg) override;
};

#endif