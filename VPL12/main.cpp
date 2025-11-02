// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_streaming.hpp"
#include "Midia.hpp"
#include "Musica.hpp"
#include "Podcast.hpp"
#include "Catalogo.hpp"
#include "Playlist.hpp"
#include <string>

std::vector<Playlist> _playlists;
Catalogo cat;

int main() {

    std::string comando, titulo, artista, host, genero, nome;
    int duracao_s, episodio;

    while (std::cin >> comando) {
        if(comando == "add_musica") {
            std::cin >> titulo >> duracao_s >> artista >> genero;
            cat.add_musica(titulo, duracao_s, artista, genero);
        }

        if(comando == "add_podcast") {
            std::cin >> titulo >> duracao_s >> host >> episodio;
            cat.add_podcast(titulo, duracao_s, host, episodio);
        }

        if(comando == "list_all") {
            cat.list_all();
        }

        if(comando == "pl_new") {
            std::cin >> nome;
            int count = 0;
            
            for (auto& pl : _playlists) {
                if (nome == pl.get_nome()) {
                    pl.clear();
                    std::cout << "OK: playlist " << nome << " criada\n";
                    break;
                }
                else {
                    count++;
                }
            }

            if (count == (int)_playlists.size()) {
                Playlist p = Playlist(nome);
                _playlists.push_back(p);
                std::cout << "OK: playlist " << nome << " criada\n";
            }
        }

        if(comando == "pl_add") {
            std::cin >> nome >> titulo;
            int count = 0;
            
            for (auto& pl : _playlists) {
                if (nome == pl.get_nome()) {
                    
                    if (cat.get(titulo) == nullptr) {
                        std::cout << "Erro: midia " << titulo << " inexistente\n";
                    }
                    else {
                        pl.add(cat.get(titulo));
                    }
                    
                    break;
                }

                else {
                    count++;
                }
            }

            if (count == (int)_playlists.size()) {
                Playlist p = Playlist(nome);
                
                std::cout << "OK: playlist " << nome << " criada\n";
                
                if (cat.get(titulo) == nullptr) {
                    std::cout << "Erro: midia " << titulo << " inexistente\n";
                }
                else {
                    p.add(cat.get(titulo));
                }
                _playlists.push_back(p);
            }
        }

        if(comando == "pl_list") {
            std::cin >> nome;

            for (auto pl : _playlists) {
                if (nome == pl.get_nome()) {
                    pl.list();
                }
            }
        }

        if(comando == "pl_play") {
            std::cin >> nome;

            for (auto pl : _playlists) {
                if (nome == pl.get_nome()) {
                    pl.play_all();
                }
            }
        }

        if(comando == "play") {
            std::cin >> titulo;
            if (cat.get(titulo) == nullptr) {
                std::cout << "Erro: midia " << titulo << " inexistente";
            }
            else {
                auto m = cat.get(titulo);
                m->play();
            }
        }

        if(comando == "b") {
            avaliacao_basica();
        }

        if(comando == "quit") {
            break;
        }

    }
    return 0;
}