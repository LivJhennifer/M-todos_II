#include <iostream>
#include "derivada.h"
using namespace std;




int main(){

    double x, deltax;
    int dr;

    cout << "Digite o valor de x ";
    cin >> x;
    cout << "digite o valor de delta x";
    cin >> deltax;
    cout << "Digite a direção: 1 para forward, 2 para backwarrdd e 3 para central";
    cin >> dr;

    cout << Derivada::derivar(x, deltax, dr);

};
