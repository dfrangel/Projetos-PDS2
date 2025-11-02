#include "Catalogo.hpp"
#include "Musica.hpp"
#include "Podcast.hpp"

bool Catalogo::add_musica(std::string titulo, int duracao_s, std::string artista, std::string genero) {
    auto m = this->get(titulo);

    if (m != nullptr) {
        std::cout << "Erro: titulo " << titulo << " repetido\n";
        return false;
    }

    _itens.push_back(std::make_shared<Musica>(titulo, duracao_s, artista, genero));
    std::cout << "OK: musica " << titulo << " adicionada \n"; 
    return true;
}

bool Catalogo::add_podcast(std::string titulo, int duracao_s, std::string host, int episodio) {
    auto p = this->get(titulo);

    if (p != nullptr) {
        std::cout << "Erro: titulo " << titulo << " repetido\n";
        return false;
    }

    _itens.push_back(std::make_shared<Podcast>(titulo, duracao_s, host, episodio));
    std::cout << "OK: podcast " << titulo << " adicionado \n"; 
    return true;
}

std::shared_ptr<Midia> Catalogo::get(std::string titulo) const {
    for (auto midia : _itens) {
        if (titulo == midia->get_titulo()) {
            return midia;
        }
    }
    return nullptr;
}

void Catalogo::list_all() const {
    if (_itens.size() == 0) {
        std::cout << "Info: (vazio)\n";
        return;
    }

    for (auto midia : _itens) {
        midia->print_info();
    }
    return;
}