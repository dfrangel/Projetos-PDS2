#ifndef PODCAST_HPP
#define PODCAST_HPP
#include "Midia.hpp"

class Podcast : public Midia {
private:
    std::string _host;
    int _episodio;

public:
    Podcast(std::string titulo, int duracao_s, std::string host, int episodio);

    void print_info() const override;

    void play() const override;

    std::string tipo() const override;
};
#endif