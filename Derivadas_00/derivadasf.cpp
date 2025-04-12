#include <cmath>
#include <iostream>

using namespace std;

static double func(double x) {
    return sin(x);
}

double derivada_recursiva(double x, double deltax, int direcao, int ordem) {
    if (ordem == 0) {
        return func(x);
    }
    
    switch (direcao) {
        case 1: // forward
            return (derivada_recursiva(x + deltax, deltax, direcao, ordem-1) - 
                    derivada_recursiva(x, deltax, direcao, ordem-1)) / deltax;
        case 2: // backward
            return (derivada_recursiva(x, deltax, direcao, ordem-1) - 
                    derivada_recursiva(x - deltax, deltax, direcao, ordem-1)) / deltax;
        case 3: // central
            return (derivada_recursiva(x + deltax, deltax, direcao, ordem-1) - 
                    derivada_recursiva(x - deltax, deltax, direcao, ordem-1)) / (2*deltax);
        default:
            throw invalid_argument("Direção inválida para derivada");
    }
}

int main() {
    double x, deltax;
    int dr;
    int ordem;

    cout << "Digite a ordem da derivada: ";
    cin >> ordem;
    cout << "Digite o valor de x: ";
    cin >> x;
    cout << "Digite o valor de delta x: ";
    cin >> deltax;
    cout << "Digite a direção (1=forward, 2=backward, 3=central): ";
    cin >> dr;

    try {
        double resultado = derivada_recursiva(x, deltax, dr, ordem);
        cout << "Derivada de ordem " << ordem << ": " << resultado << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}