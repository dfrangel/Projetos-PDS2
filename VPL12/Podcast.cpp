#include "Podcast.hpp"

Podcast::Podcast(std::string titulo, int duracao_s, std::string host, int episodio)
        : Midia(titulo, duracao_s), _host(host), _episodio(episodio) {}

void Podcast::print_info() const {
    Midia::print_info();
    std::cout << "Tipo: " << tipo() << "\n"
              << "Host: " << _host << "\n"
              << "Episodio: " << _episodio << "\n";
}

void Podcast::play() const {
    for (int i = 1; i <= _duracao_s; i++) {
        std::cout << "Playing " << _titulo << " [" << i << "/" << _duracao_s << "]\n";
    }
}

std::string Podcast::tipo() const {
    return "Podcast";
}