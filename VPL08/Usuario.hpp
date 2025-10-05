#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#define MAX_USUARIOS 100

class Usuario {

    public:
        static int _prox_id;
        int _id;
        std::string _nome;
        std::string _email;

        Usuario();
        Usuario(std::string nome, std::string email);

        int get_id() const;
        const std::string& get_nome() const;
        const std::string& get_email() const;

        void set_nome(const std::string& a);
        void set_email(const std::string& a);
};
#endif