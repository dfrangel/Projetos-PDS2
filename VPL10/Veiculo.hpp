#ifndef VEICULO_HPP
#define VEICULO_HPP
#include <string>

class Veiculo {
    private:
        std::string _placa; 
        int _ano; 
        int _capacidade_kg;
        int _id;

    public:
        static int _next_id;
        Veiculo(std::string placa, int ano, int capacidade_kg);
        virtual ~Veiculo();

        std::string placa();
        int ano();
        int capacidade_kg();
        virtual std::string tipo() = 0;
        int get_id();

        virtual void print_info();

        virtual double custo_viagem(double km, double carga_kg) = 0;
};

#endif