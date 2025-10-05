#include "Tarefa.hpp"
#include <string>

Tarefa::Tarefa() = default;

int Tarefa::_t_prox_id = 1;

Tarefa::Tarefa(const std::string& descricao) 
    :_id(_t_prox_id), _descricao(descricao) {

    this->_status = "aberta";
    _t_prox_id++;
}

int Tarefa::get_id() const {
    return this->_id;
}
const std::string& Tarefa::get_descricao() const {
    return this->_descricao;
}
const std::string& Tarefa::get_status() const {
    return this->_status;
}

void Tarefa::set_descricao(const std::string& a) {
    this->_descricao = a;
    return;
}
void Tarefa::set_status(const std::string& a) {
    this->_status = a;
    return;
}