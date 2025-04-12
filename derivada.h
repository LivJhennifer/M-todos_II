#include <cmath>
#include <iostream>
#include <string>
#include <vector>


class Derivada{
public:



    static double func(int x){
        return sin(x);
    }
    

    static double derivar(double x, double deltax, int direcao) {
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
};