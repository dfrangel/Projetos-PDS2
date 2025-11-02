#include "Musica.hpp"

Musica::Musica(std::string titulo, int duracao_s, std::string artista, std::string genero) 
       : Midia(titulo, duracao_s), _artista(artista), _genero(genero) {}

void Musica::print_info() const {
    Midia::print_info();
    std::cout << "Tipo: " << tipo() << "\n"
              << "Artista: " << _artista << "\n"
              << "Genero: " << _genero << "\n";
}

void Musica::play() const {
    for (int i = 1; i <= _duracao_s; i++) {
        std::cout << "Playing " << _titulo << " [" << i << "/" << _duracao_s << "]\n";
    }
}

std::string Musica::tipo() const {
    return "Musica";
}