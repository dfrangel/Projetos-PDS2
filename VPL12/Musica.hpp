#ifndef MUSICA_HPP
#define MUSICA_HPP
#include "Midia.hpp"

class Musica : public Midia {
private:
    std::string _artista;
    std::string _genero;

public:
    Musica(std::string titulo, int duracao_s, std::string artista, std::string genero);

    void print_info() const override;

    void play() const override;

    std::string tipo() const override;
};
#endif