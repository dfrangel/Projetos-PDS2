#include <iostream>
#include <string>

#include "Parque.hpp"
#include "MontanhaRussa.hpp"
#include "Carrossel.hpp"
#include "RodaGigante.hpp"

int main() {
    Parque* p = new Parque();
    std::string comando;
    int ano, cap, atrib, n;
    std::string cod;
    double kw;

    while (std::cin >> comando && comando != "encerrar") {
        if (comando == "carregar") {
            std::cin >> n;
            for (int i = 0; i < n; i++) {
                std::cin >> comando;
                    if (comando == "mr") {
                        std::cin >> cod;
                        std::cin >> ano;
                        std::cin >> kw;
                        std::cin >> cap;
                        std::cin >> atrib;
                        MontanhaRussa* mr_ptr = new MontanhaRussa(cod, ano, kw, cap, atrib);
                        p->adicionar(mr_ptr);
                    }

                    if (comando == "car") {
                        std::cin >> cod;
                        std::cin >> ano;
                        std::cin >> kw;
                        std::cin >> cap;
                        std::cin >> atrib;
                        Carrossel* car_ptr = new Carrossel(cod, ano, kw, cap, atrib);
                        p->adicionar(car_ptr);
                    }

                    if (comando == "rod") {
                        std::cin >> cod;
                        std::cin >> ano;
                        std::cin >> kw;
                        std::cin >> cap;
                        std::cin >> atrib;
                        RodaGigante* rg_ptr = new RodaGigante(cod, ano, kw, cap, atrib);
                        p->adicionar(rg_ptr);
                    }
            }
        }
        
        if (comando == "mr") {
            std::cin >> cod;
            std::cin >> ano;
            std::cin >> kw;
            std::cin >> cap;
            std::cin >> atrib;
            MontanhaRussa* mr_ptr = new MontanhaRussa(cod, ano, kw, cap, atrib);
            p->adicionar(mr_ptr);
        }
    
        if (comando == "car") {
            std::cin >> cod;
            std::cin >> ano;
            std::cin >> kw;
            std::cin >> cap;
            std::cin >> atrib;
            Carrossel* car_ptr = new Carrossel(cod, ano, kw, cap, atrib);
            p->adicionar(car_ptr);
        }

        if (comando == "rod") {
            std::cin >> cod;
            std::cin >> ano;
            std::cin >> kw;
            std::cin >> cap;
            std::cin >> atrib;
            RodaGigante* rg_ptr = new RodaGigante(cod, ano, kw, cap, atrib);
            p->adicionar(rg_ptr);
        }

        if (comando == "demanda") {
            std::cin >> n;
            p->definir_demanda(n);
        }

        if (comando == "rodar") {
            std::cin >> n;
            p->rodar(n);
        }

        if (comando == "pausar") {
            std::cin >> cod;
            p->pausar(cod);
        }

        if (comando == "retomar") {
            std::cin >> cod;
            p->retomar(cod);
        }

        if (comando == "status") {
            std::cin >> cod;
            p->status(cod);
        }

        if (comando == "painel") {
            p->painel();
        }
    }
    delete p;
    return 0;
}