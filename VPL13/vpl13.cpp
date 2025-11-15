#include <exception>
#include <vector>
#include <iostream>
#include <string>

class NegativeResultException : public std::exception {
private:
    int _valor;

public:
    NegativeResultException(int v) : _valor(v) {}

    virtual const char* what() const noexcept override {
            return "Erro: Resultado Negativo.";
    }

    int getValor() const {
        return _valor;
    }
}; 

int main() {
    std::vector<int> vec = {-20, -10, 0, 10, 20};

    try {
        int posicao;
        std::cin >> posicao;

        int valor = vec.at(posicao);
            
        if (valor < 0) {
            throw NegativeResultException(valor);
        } 
        else if (valor == 0) {
            throw std::logic_error("Erro: O resultado nao deve ser zero.");
        }

        std::cout << valor << std::endl;
    } 
    catch (const NegativeResultException& e) {
        std::cout << e.what() << std::endl;
        std::cout << e.getValor() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Erro: Parametro invalido" << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}