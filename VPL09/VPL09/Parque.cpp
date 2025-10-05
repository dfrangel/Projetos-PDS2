#include "Parque.hpp"
#include <iostream>
#include <iomanip>

Parque::Parque(): _num_brinquedos (0), _demanda (0), _energia_acum (0), _receita_acum (0), _atendidos_acum (0) {
    for (int i = 0; i < MAX_BRINQUEDOS; i++) {
        _brinquedos[i] = nullptr;
    }
}

Parque::~Parque() {
    for (int i = 0; i < _num_brinquedos; i++) {
        delete _brinquedos[i];
    }
}

Brinquedo* Parque::find_brinquedo(const std::string& cod) const {
    for (int i = 0; i < _num_brinquedos; i++) {
        if (_brinquedos[i]->codigo() == cod) {
            return _brinquedos[i];
        }
    }
    std::cout << "Brinquedo informado nao existe." << std::endl;
    return nullptr;
}

void Parque::adicionar(Brinquedo* b) {
    if (_num_brinquedos < 100) {
        _brinquedos[_num_brinquedos] = b;
        _num_brinquedos++;
    }
}

void Parque::definir_demanda(int d) {
    _demanda = d;
}

void Parque::pausar(const std::string& cod) {
    Brinquedo* b = find_brinquedo(cod);

    if (b->pausado() == false) {
        b->pausar();
        return;
    }

    std::cout << "Brinquedo ja esta pausado." << std::endl;
    return;
}

void Parque::retomar(const std::string& cod) {
    Brinquedo* b = find_brinquedo(cod);

    if (b->pausado()) {
        b->retomar();
        return;
    }

    std::cout << "Brinquedo ja esta em operacao." << std::endl;
    return;
}

void Parque::rodar(int T) {
    for (int i = 0; i < T; i++) {
        int demanda_r = _demanda;
        int atendidos = 0;
        double receita = 0.0;
        double energia = 0.0;

        for (int j = 0; j < _num_brinquedos; j++) {
            _brinquedos[j]->operar_tick(demanda_r, atendidos, receita, energia);
            demanda_r -= atendidos;
            _atendidos_acum += atendidos;
            _receita_acum += receita;
            _energia_acum += energia;
        }
    }
    return;
}

void Parque::status(const std::string& cod) const {
    if (find_brinquedo(cod) == nullptr) {
        return;
    }
    find_brinquedo(cod)->imprimir_status();
    return;
}

void Parque::painel() const {
    std::cout << std::fixed << std::setprecision(2)
              << _energia_acum << " "
              << _receita_acum << " "
              << _atendidos_acum << std::endl;
    return;
}