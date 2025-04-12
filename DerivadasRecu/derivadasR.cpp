#include <cmath>
#include <iostream>

using namespace std;

static double func(double x){
    return sin(x);
}

static double derivada_primeira(double x, double deltax, int direcao) {
    
        switch (direcao) {
            case 1: //forward
                return  (func(x + deltax) - func(x)) / (deltax);
            case 2: //backward
                return  (func(x) - func(x - deltax)) / (deltax);
            case 3: //central 
                return   (func(x + deltax) - func(x - deltax)) / (2*deltax);
                default:  // Caso inválido
                throw std::invalid_argument("Direção inválida para derivada");
        } 
}


double derivada_segunda(double x, double deltax, int direcao){
    
    
    switch (direcao) {
        case 1: //forward
            return  (derivada_primeira(x + deltax, deltax, 1) - derivada_primeira(x, deltax, 1)) / (deltax);
        case 2: //backward
            return  (derivada_primeira(x, deltax, 2) - derivada_primeira(x - deltax, deltax, 2)) / (deltax);
        case 3: //central 
            return   (derivada_primeira(x + deltax, deltax, 3) - derivada_primeira(x - deltax, deltax, 3)) / (2*deltax);
            default:  // Caso inválido
            throw std::invalid_argument("Direção inválida para derivada");
    } 

}



int main(){

    double x, deltax;
    int dr;
    int ordem;

    cout << "Digite a ordem da derivada (1 para primeira, 2 para segunda): ";
    cin >> ordem;
    cout << "Digite o valor de x: ";
    cin >> x;
    cout << "digite o valor de delta x: ";
    cin >> deltax;
    cout << "Digite a direção (1=forward, 2=backward, 3=central): ";
    cin >> dr;

    try {
        switch (ordem) {
            case 1:
                cout << "Derivada primeira: " << derivada_primeira(x, deltax, dr) << endl;
                break;
            case 2:
                cout << "Derivada segunda: " << derivada_segunda(x, deltax, dr) << endl;
                break;
            default:
                cout << "Ordem de derivada inválida!" << endl;
        }
    } catch (const invalid_argument& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;

};
