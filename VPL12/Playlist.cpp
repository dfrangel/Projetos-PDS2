#include "Playlist.hpp"

Playlist::Playlist(std::string nome)
         :_nome(nome), _faixas() {}

void Playlist::add(std::shared_ptr<Midia> faixa) {
    _faixas.push_back(faixa);
    return;
}

void Playlist::list() const {
    if ((int)_faixas.size() == 0) {
        std::cout << "Info: (vazio)\n";
        return;
    }
    
    int counter = 1;
    for (auto faixa : _faixas) {
        std::cout << "Info: Faixa " << counter << std::endl;
        faixa->print_info();
        counter++;
    }

    return;
}

void Playlist::play_all() const {
    for (auto midia : _faixas) {
        midia->play();
    }

    return;
}

std::string Playlist::get_nome() {
    return this->_nome;
}

void Playlist::clear() {
    _faixas.clear();
}