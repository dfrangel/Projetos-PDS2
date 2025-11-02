#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include "Midia.hpp"
#include <memory>
#include <vector>
#include <string>

class Playlist {
private:
    std::string _nome; 
    std::vector<std::shared_ptr<Midia>> _faixas;

public:
    Playlist(std::string nome);

    void add(std::shared_ptr<Midia> faixa);

    void list() const;

    void play_all() const;

    std::string get_nome();

    void clear();
};
#endif