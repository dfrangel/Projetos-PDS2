#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>
#define MAX_TAREFAS 100

class Tarefa {

    private:
        int _id;
        static int _t_prox_id;
        std::string _descricao;
        std::string _status;

    public:
        Tarefa();
        Tarefa(const std::string& descricao);

        int get_id() const;
        int get_prox_id();
        const std::string& get_descricao() const;
        const std::string& get_status() const;

        void set_descricao(const std::string&);
        void set_status(const std::string&);
};
#endif