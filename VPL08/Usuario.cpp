#include "Usuario.hpp"

#include <string>

Usuario::Usuario() = default;

int Usuario::_prox_id = 1;

Usuario::Usuario(std::string nome, std::string email)
    :_id(_prox_id), _nome(nome), _email(email) {
        
    _prox_id++;
}

int Usuario::get_id() const {
    return this->_id;
}
const std::string& Usuario::get_nome() const {
    return this->_nome;
}
const std::string& Usuario::get_email() const {
    return this->_email;
}

void Usuario::set_nome(const std::string& a) {
    this->_nome = a;
    return;
}
void Usuario::set_email(const std::string& a) {
    this->_email = a;
    return;
}
