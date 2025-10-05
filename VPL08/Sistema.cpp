#ifndef SISTEMA_HPP
#include "Sistema.hpp"
#include <iostream>

void Sistema::adicionar_usuario(const std::string& nome, const std::string& email) {
    Usuario novo_user = Usuario(nome, email);
    _usuarios[_num_usuarios] = novo_user;
    _num_usuarios++;

    std::cout << "Usuario adicionado: " 
              << novo_user.get_id() << " " 
              << novo_user.get_nome() << " "
              << novo_user.get_email() << std::endl;

    return;
}

void Sistema::remover_usuario(int id) {
    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_dono_id() == id) {
            _projetos[i].set_dono_id(0);
        }
    }
    
    for (int i = 0; i < _num_usuarios; i++) {
        if (_usuarios[i].get_id() == id) {
            
            std::cout << "Usuario removido: " << id << std::endl;

            for (int j = i; j < _num_usuarios - 1; j++) {
                _usuarios[j] = _usuarios[j + 1];   
            }

            _num_usuarios--;
            return;
        }
         
    }
    
    std::cout << "Erro: usuario " << id << " nao existe" << std::endl;
    return;
}

void Sistema::buscar_usuario(int id) const {

    if (_num_usuarios == 0) {
        std::cout << "Usuario " << id << " nao encontrado" << std::endl;
        
        return;
    }

    for (int i = 0; i < _num_usuarios; i++) {
        if (_usuarios[i].get_id() == id) {
            std::cout << "Usuario: " 
                      << _usuarios[i].get_id() << " " 
                      << _usuarios[i].get_nome() << " "
                      << _usuarios[i].get_email() << std::endl;
            return;
        }
    }
    
    std::cout << "Usuario " << id << " nao encontrado" << std::endl;
    
    return;
}


void Sistema::listar_usuarios() const {
    if (_num_usuarios == 0) {
        std::cout << "Nenhum usuario" << std::endl; 
    }
    else {
        for (int i = 0; i < _num_usuarios; i++) {
            std::cout << _usuarios[i].get_id() << " " 
                      << _usuarios[i].get_nome() << " "
                      << _usuarios[i].get_email() << std::endl;
        }

    }

    return;
}



void Sistema::adicionar_projeto(const std::string& nome, const std::string& descricao) {
    Projeto novo_proj = Projeto(nome, descricao);
    _projetos[_num_projetos] = novo_proj;

    std::cout << "Projeto adicionado: " 
              << novo_proj.get_id() << " " 
              << novo_proj.get_nome() << " "
              << novo_proj.get_descricao() << std::endl;

    _num_projetos++;
    return;
}

void Sistema::remover_projeto(int id) {
    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id) {
            for (int j = i; j < _num_projetos - 1; j++) {
                _projetos[j] = _projetos[j + 1];   
            }

            std::cout << "Projeto removido: " 
              << _projetos[i].get_id() << std::endl;

            _num_projetos--;
            return;
        }
    }
    std::cout << "Erro: projeto " << id << " nao existe" << std::endl;
    
    return;
}

void Sistema::buscar_projeto(int id) const {
    int proj_counter = 0;
    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id) {
            std::cout << "Projeto " 
                      << _projetos[i].get_id() << ": " 
                      << _projetos[i].get_nome() << " "
                      << _projetos[i].get_descricao();

            if (_projetos[i].get_dono_id() > 0) {
                std::cout << " dono=" << _projetos[i].get_dono_id();
            }
            std::cout << std::endl;

            return;
        }
        proj_counter++;
    }

    if (_num_projetos == proj_counter) {
        std::cout << "Projeto " << id << " nao encontrado" << std::endl;
        return;
    }
}

void Sistema::listar_projetos() const {
    if (_num_projetos == 0) {
        std::cout << "Nenhum projeto" << std::endl; 

        return;
    }
    else {
        for (int i = 0; i < _num_projetos; i++) {
            std::cout << _projetos[i].get_id() << " " 
                      << _projetos[i].get_nome() << " "
                      << _projetos[i].get_descricao();

            if (_projetos[i].get_dono_id() > 0) {
                std::cout << " dono=" << _projetos[i].get_dono_id();
            }
            std::cout << std::endl;
        }
    }
    return;
}

void Sistema::atribuir_dono(int id_projeto, int id_usuario) {
    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id_projeto) {

            for (int j = 0; j < _num_usuarios; j++) {
                if (_usuarios[j].get_id() == id_usuario) {

                    _projetos[i].set_dono_id(_usuarios[j].get_id());

                    std::cout << "Atribuido dono: " 
                              << "projeto " << id_projeto << " -> "
                              << "usuario " << id_usuario << std::endl;
                return;
                }
            }
        }
    }

    int proj_counter = 0, user_counter = 0;

    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() != id_projeto) {
            proj_counter++;
        }
    }

    if(_num_projetos == proj_counter) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
    }

    for (int j = 0; j < _num_usuarios; j++) {
        if (_usuarios[j].get_id() != id_usuario) {
            user_counter++;
        }
    }

    if(_num_usuarios == user_counter) {
        std::cout << "Erro: usuario " << id_usuario << " nao existe" << std::endl;
    }

    return;
}



void Sistema::adicionar_tarefa(int id_projeto, const std::string& descricao) {
    int id_tarefa;
    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id_projeto) {
            _projetos[i].adicionar_tarefa(descricao, id_tarefa);

            std::cout << "Tarefa adicionada: projeto "
              << _projetos[i].get_id() 
              << " tarefa " << id_tarefa << " " << descricao << std::endl;

            return;
        }
    }
}

void Sistema::atualizar_tarefa(int id_projeto, int id_tarefa, const std::string& status) {
    int proj_counter = 0, tarefa_counter = 0;
    Projeto* esse_projeto = nullptr;
    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id_projeto) {
            esse_projeto = &_projetos[i];

            if(_projetos[i].atualizar_tarefa(id_tarefa, status)) {
                std::cout << "Tarefa atualizada: projeto " 
                          << id_projeto << " tarefa " << id_tarefa << " "
                          << "status=" << status << std::endl;

                return;
            }
        }
        proj_counter++;
    }
    if (_num_projetos == proj_counter) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
        return;
    }

    for (int k = 0; k < esse_projeto->get_num_tarefas(); k++) {
        if (esse_projeto->get_tarefas()->get_id() != id_tarefa) {
            tarefa_counter++;
        }
        if (esse_projeto->get_num_tarefas() == tarefa_counter) {
            std::cout << "Erro: tarefa " << id_tarefa << " nao existe" << std::endl;
            return;
        }
    }
}

void Sistema::remover_tarefa(int id_projeto, int id_tarefa) {
    Projeto* esse_projeto = nullptr;
    int proj_counter = 0, tarefa_counter = 0;

    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id_projeto) {
            esse_projeto = &_projetos[i];
            break;
        }
        proj_counter++;
    }

    if (esse_projeto->remover_tarefa(id_tarefa)) {
        std::cout << "Tarefa removida: projeto " << esse_projeto->get_id()
                  << " tarefa " << id_tarefa << std::endl;
            
        return;
    }

    if (proj_counter == _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;

        return;
    }

    for (int j = 0; j < esse_projeto->get_num_tarefas(); j++) {
        if (esse_projeto->get_tarefas()[j].get_id() != id_tarefa) {
            tarefa_counter++;
        }

        if (tarefa_counter == esse_projeto->get_num_tarefas()) {
        std::cout << "Erro: tarefa " << id_tarefa << " nao existe no projeto "
        << id_projeto << std::endl;

        return;
        }
    }
}

void Sistema::listar_tarefas(int id_projeto) const {
    int proj_counter = 0;

    for (int i = 0; i < _num_projetos; i++) {
        if (_projetos[i].get_id() == id_projeto) {
            
            if (_projetos[i].get_num_tarefas() == 0) {
                std::cout << "Nenhuma tarefa no projeto " << id_projeto << std::endl; 

                return;
            }

            for (int j = 0; j < _projetos[i].get_num_tarefas(); j++) {
                std::cout << _projetos[i].get_tarefas()[j].get_id() << " "
                          << _projetos[i].get_tarefas()[j].get_descricao() << " "
                          << _projetos[i].get_tarefas()[j].get_status() << std::endl;
            }

            return;
        }
        proj_counter++;
    }

    if (proj_counter == _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;

        return;
    }
}

#endif