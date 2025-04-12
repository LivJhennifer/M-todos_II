#include <cmath>
#include <iostream>

using namespace std;

static double func(double x){
    return sin(x);
}

static double derivar1(double x, double deltax, int direcao) {
    double dr;
        switch (direcao) {
            case 1: //forward
                return dr = (func(x + deltax) - func(x)) / (deltax);
            case 2: //backward
                return dr = (func(x) - func(x - deltax)) / (deltax);
            case 3: //central 
                return  dr = (func(x + deltax) - func(x - deltax)) / (2*deltax);
                default:  // Caso inválido
                throw std::invalid_argument("Direção inválida para derivada");
        } 
}

static double derivar2(double x, double deltax, int direcao) {
    double dr;
        switch (direcao) {
            case 1: //forward
                return dr = ((func(x + 2*deltax) - (2*func(x + deltax))) + func(x)) / pow(deltax, 2);
            case 2: //backward
                return dr = (func(x) - (2*func(x - deltax)) + func(x - (2*deltax)))/ pow(deltax, 2);
            case 3: //central 
                return  dr = (func(x + (2*deltax)) - (2*func(x)) + func(x - (2*deltax))) / (4*pow(deltax, 2));
                default:  // Caso inválido
                throw std::invalid_argument("Direção inválida para derivada");
        } 
}


int main(){

    double x, deltax;
    int dr;
    int derivada;

    cout << "Digita a ordem da derrivada: 1 para derivada primeira e 2 para derrivada segunda: ";
    cin >> derivada;
    cout << "Digite o valor de x: ";
    cin >> x;
    cout << "digite o valor de delta x: ";
    cin >> deltax;
    cout << "Digite a direção: 1 para forward, 2 para backwarrdd e 3 para central: ";
    cin >> dr;

    try {
        switch (derivada) {
            case 1:
                cout << "Derivada primeira: " << derivar1(x, deltax, dr) << endl;
                break;
            case 2:
                cout << "Derivada segunda: " << derivar2(x, deltax, dr) << endl;
                break;
            default:
                cout << "Ordem de derivada inválida!" << endl;
        }
    } catch (const invalid_argument& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;

};