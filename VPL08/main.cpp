#include "Sistema.hpp"
#include <iostream>
#include <string>

int main () {
    Sistema sistema;

    std::string comando;
    std::string nome;
    std::string email;
    std::string status;
    std::string descricao;
    int id;
    int id_usuario;
    int id_projeto;
    int id_tarefa;

    while (std::cin >> comando) {

        if (comando == "adicionar_usuario") {
            std::cin >> nome;
            std::cin >> email;

            sistema.adicionar_usuario(nome, email);
        }

        if (comando == "remover_usuario") {
            std::cin >> id;

            sistema.remover_usuario(id);
        }

        if (comando == "buscar_usuario") {
            std::cin >> id;

            sistema.buscar_usuario(id);
        }

        if (comando == "listar_usuarios") {
            sistema.listar_usuarios();
        }

        if (comando == "adicionar_projeto") {
            std::cin >> nome;
            std::cin >> descricao;

            sistema.adicionar_projeto(nome, descricao);
        }

        if (comando == "remover_projeto") {
            std::cin >> id;

            sistema.remover_projeto(id);
        }

        if (comando == "buscar_projeto") {
            std::cin >> id;

            sistema.buscar_projeto(id);
        }

        if (comando == "listar_projetos") {
            sistema.listar_projetos();
        }

        if (comando == "atribuir_dono") {
            std::cin >> id_projeto;
            std::cin >> id_usuario;

            sistema.atribuir_dono(id_projeto, id_usuario);
        }

        if (comando == "adicionar_tarefa") {
            std::cin >> id_projeto;
            std::cin >> descricao;

            sistema.adicionar_tarefa(id_projeto, descricao);
        }

        if (comando == "atualizar_tarefa") {
            std::cin >> id_projeto;
            std::cin >> id_tarefa;
            std::cin >> status;

            sistema.atualizar_tarefa(id_projeto, id_tarefa, status);
        }

        if (comando == "remover_tarefa") {
            std::cin >> id_projeto;
            std::cin >> id_tarefa;

            sistema.remover_tarefa(id_projeto, id_tarefa);
        }

        if (comando == "listar_tarefas") {
            std::cin >> id_projeto;

            sistema.listar_tarefas(id_projeto);
        }
    }
    
    return 0;
}
