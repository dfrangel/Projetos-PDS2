#include "Brinquedo.hpp"

Brinquedo::Brinquedo(const std::string& codigo, int ano, double potencia_kw, int capacidade) 
          :_codigo (codigo), _ano (ano), _potencia_kw (potencia_kw), _capacidade (capacidade), _pausado (false) {}

Brinquedo::~Brinquedo() {}

std::string Brinquedo::codigo() const {
    return this->_codigo;
}
int Brinquedo::ano() const {
    return this->_ano;
}
double Brinquedo::potencia_kw() const {
    return this->_potencia_kw;
}
int Brinquedo::capacidade() const {
    return this->_capacidade;
}
bool Brinquedo::pausado() const {
    return this->_pausado;
}

void Brinquedo::pausar() {
    this->_pausado = true;
    return;
}
void Brinquedo::retomar() {
    this->_pausado = false;
    return;
}