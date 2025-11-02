#ifndef MIDIA_HPP
#define MIDIA_HPP
#include <string>
#include <iostream>

class Midia {
protected:
    int _duracao_s; 
    std::string _titulo;

public:
    Midia(std::string titulo, int duracao_s);
    virtual ~Midia() = default;

    virtual void print_info() const;

    virtual void play() const = 0;

    virtual std::string tipo() const;

    std::string get_titulo();
};
#endif