#include "Midia.hpp"
#include <string>

std::ostream& operator<<(std::ostream& os, const Midia& m) {
    m.print_info();
    return os;
}

Midia::Midia(std::string titulo, int duracao_s) 
      : _duracao_s(duracao_s), _titulo(titulo) {}

void Midia::print_info() const {   
    std::cout << "Info: Midia\n"
              << "Titulo: " << _titulo << "\n"
              << "Duracao (s): " << _duracao_s << "\n";
}

void Midia::play() const {
    for (int i = 0; i <= _duracao_s; i++) {
        std::cout << "Playing " << _titulo << " [" << i << "/" << (int)_duracao_s << "]\n";
    }
}

std::string Midia::tipo() const {
    return "Midia";
}

std::string Midia::get_titulo() {
    return this->_titulo;
}
