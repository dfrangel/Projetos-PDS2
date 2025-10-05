#include "Projeto.hpp"

Projeto::Projeto() = default;

int Projeto::_p_prox_id = 1;

Projeto::Projeto(const std::string& nome, const std::string& descricao) 
:_id(_p_prox_id), _nome(nome), _descricao(descricao), _dono_id(-1) {

    _p_prox_id++;
}


int Projeto::get_id() const {
    return this->_id;
}
const std::string& Projeto::get_nome() const {
    return this->_nome;
}
const std::string& Projeto::get_descricao() const {
    return this->_descricao;
}
int Projeto::get_dono_id() const {
    return this->_dono_id;
}
const Tarefa* Projeto::get_tarefas() const {
    return this->_tarefas;
}
int Projeto::get_num_tarefas() const {
    return this->_num_tarefas;
}

void Projeto::set_nome(const std::string& a) {
    this->_nome = a;
    return;
}
void Projeto::set_descricao(const std::string& a) {
    this->_descricao = a;
    return;
}
void Projeto::set_dono_id(int a) {
    this->_dono_id = a;
    return;
}

bool Projeto::adicionar_tarefa(const std::string& descricao, int& out_tarefa_id) {
    Tarefa nova_tarefa = Tarefa(descricao);
    out_tarefa_id = nova_tarefa.get_id();

    if(_num_tarefas < MAX_TAREFAS) {
        _tarefas[_num_tarefas] = nova_tarefa;
        _num_tarefas++;

        return true;
    }

    return false;
}

bool Projeto::atualizar_tarefa(int id_tarefa, const std::string& novo_status) {
    for (int i = 0; i < this->get_num_tarefas(); i++) {
        if (this->get_tarefas()[i].get_id() == id_tarefa) {
            _tarefas[i].set_status(novo_status);
            return true;
        }
    }
    return false;
}

bool Projeto::remover_tarefa(int id_tarefa) {
    for (int i = 0; i < this->get_num_tarefas(); i++) {
        if (this->get_tarefas()[i].get_id() == id_tarefa) {
            for (int j = i; j < this->get_num_tarefas() - 1; j++) {
                _tarefas[j] = _tarefas[j + 1];
            }
            _num_tarefas--;
            return true;
        }
    }
    return false;
}

const Tarefa* Projeto::buscar_tarefa(int id_tarefa) const {
    for (int i = 0; i < this->get_num_tarefas(); i++) {
        if (this->get_tarefas()[i].get_id() == id_tarefa) {
            return &_tarefas[i];
        }
    }
    return nullptr;
}