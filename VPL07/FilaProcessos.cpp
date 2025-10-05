#include "Processo.hpp"
#include "FilaProcessos.hpp"
#include <iostream>
#include <string>

void FilaProcessos::adicionar_processo(std::string nome, int prioridade){
    Processo* aux = new Processo;

    Processo* counter = head;
    int tam = 0;
    while (counter != nullptr) {
        tam++;
        counter = counter->next;
    }
    aux->_id = tam + 1;

    aux->_nome = nome;
    aux->_prioridade = prioridade;
    aux->next = nullptr;
    aux->previous = nullptr;
    
    //Se for o primeiro elemento ambos extremos apontam para o mesmo struct
    if (head == nullptr) {
        head = aux;
        tail = aux;
        return;
    }

    //Se for maior que qualquer elemento da lista
    if (aux->getPrioridade() > head->getPrioridade()) {
        aux->next = head;
        head->previous = aux;
        head = aux;
        return;
    }


    //Itera-se até encontrar uma prioridade menor
    Processo* atual = head;
    Processo* anterior = nullptr;

    while (atual != nullptr) {
        if (aux->getPrioridade() > atual->getPrioridade()) {
            aux->next = atual;
            aux->previous = anterior;
            atual->previous = aux;
            return;
        }

        anterior = atual;
        atual = atual->next;
    }

    //Se não for o primeiro elemento, nem o maior e o código sair do loop
    anterior->next = aux;
    aux->previous = anterior;
    tail = aux;
}

Processo* FilaProcessos::remover_processo_maior_prioridade(){
    Processo* pointer = new Processo;
    if (head == nullptr)
        return nullptr;
    
    else {
        pointer = head;
        head = head->next;
        head->next->previous = nullptr;
    }

    return pointer;
}

Processo* FilaProcessos::remover_processo_por_id(int id) {
    Processo* atual = head;
    Processo* anterior = nullptr;

    if (head == nullptr)
        return nullptr;

    if (atual->getID() == id) {
        head = head->next;

        if (head != nullptr) {
            //Se a lista ainda tem elementos
            head->previous = nullptr;
        } else {
            //Se a lista ficou vazia
            tail = nullptr;  
        }

        atual->next = nullptr;
        return atual;
    }

    while (atual != nullptr) {
        if (atual->getID() == id) {
            //Se não for o último elemento da lista
            if (atual->next != nullptr) {
                anterior->next = atual->next;
                atual->next->previous = anterior;
                atual->next = nullptr;
                atual->previous = nullptr;
                return atual;
            }
            //Se for o último elemento da lista
            else {
                anterior->next = nullptr;
                atual->previous = nullptr;
                tail = anterior;
                return atual;
            }
        }
        anterior = atual;
        atual = atual->next;
    }
    
    return nullptr;
} 

void FilaProcessos::estimativa_tempo_para_execucao(int id) {
    Processo* atual = head;
    
    if (head->getID() == id) {
        std::cout << "Tempo estimado para execução do processo " << atual->getNome();
        std::cout << "(id=" << id << ") eh 0.0 segundos." << std::endl;
        return;
    }

    double temp = 0;

    while (atual != nullptr) {
        if (atual->getID() == id) {
            std::cout << "Tempo estimado para execução do processo " << atual->getNome();
            std::cout << "(id=" << id << ") eh " << temp << " segundos." << std::endl;
            return;
        }
        temp += atual->tempo_reservado_processo();
        atual = atual->next;
    }
}

void FilaProcessos::imprimir_fila() {
    Processo* atual = head;
    while (atual != nullptr) {
        atual->imprimir_dados();
        atual = atual->next;
    }
}