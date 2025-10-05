#include <iostream>
#include "Processo.hpp"
#include <string>

int Processo::getID() {
    return this->_id;
}

int Processo::getPrioridade() {
    return this->_prioridade;
}

std::string Processo::getNome() {
    return this->_nome;
}

Processo::Processo(int id, std::string nome, int prioridade){
    this->_id = id;
    this->_prioridade = prioridade;
    this->_nome = nome;
    this->next = nullptr;
    this->previous = nullptr;
}

double Processo::tempo_reservado_processo(){
    if(this->_prioridade == 0)
        return 0.5;
    if(this->_prioridade == 1)
        return 1.5;
    if(this->_prioridade == 2)
        return 3.0;
}

void Processo::imprimir_dados(){
    std::cout << this->getID() << '\t';
    std::cout << this->getNome() << '\t';
    if(this->getPrioridade() == 0)
        std::cout << "BAIXA" << std::endl;
    if(this->getPrioridade() == 1)
        std::cout << "MEDIA" << std::endl;
    if(this->getPrioridade() == 2)
        std::cout << "ALTA" << std::endl;
}