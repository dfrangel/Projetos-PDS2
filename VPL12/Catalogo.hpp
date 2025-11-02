#ifndef CATALOGO_HPP
#define CATALOGO_HPP
#include "Midia.hpp"
#include "Playlist.hpp"
#include <vector>
#include <memory>

class Catalogo {
private:
    std::vector<std::shared_ptr<Midia>> _itens;

public:
    bool add_musica(std::string titulo, int duracao_s, std::string artista, std::string genero);

    bool add_podcast(std::string titulo, int duracao_s, std::string host, int episodio);

    std::shared_ptr<Midia> get(std::string titulo) const;

    void list_all() const;
};
#endif