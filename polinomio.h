#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Polinomio{

    public:

    std::vector<double> coeficientes; //Armazena os coeficientes  em oredem crescente

    // Construtor que recebe os coeficientes
    Polinomio(const std::vector<double>& coefs) : coeficientes(coefs) {}

    // Retorna o grau do polinômio
    int grau() const {
        return coeficientes.empty() ? 0 : coeficientes.size() - 1;
    }

     
    // Avalia o polinômio em um ponto x (operator() permite usar como função)
    // double func(double x) const {
    //     double resultado = 0.0;
    //     for (size_t i = 0; i < coeficientes.size(); ++i) {
    //         resultado += coeficientes[i] * std::pow(x, i);
    //     }
    //     return resultado;
    // }

    static Polinomio lerDoConsole() {
        std::vector<double> coeficientes;
        std::string entrada;
        double coef;
        
        std::cout << "Digite os coeficientes do polinômio (a0 a1 a2 ... an): ";
        std::getline(std::cin, entrada);
        
        std::istringstream iss(entrada);
        while (iss >> coef) {
            coeficientes.push_back(coef);
        }
        
        return Polinomio(coeficientes);
    }

};