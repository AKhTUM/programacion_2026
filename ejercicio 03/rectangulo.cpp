#include "rectangulo.h"
#include <iostream>

Rectangulo::Rectangulo(std::string nombre, double base, double altura) : Figura(nombre), base(base), altura(altura) {
    this->nombre = nombre;
    this->base = base;
    this->altura = altura;
}


// FUNCIONES VIRTUALES
double Rectangulo::CalcularArea() {
    return base * altura;
}

void Rectangulo::Describir_Figura() {
    std::cout << "yo soy un " << nombre << " con base " << base << " y altura " << altura << "." << std::endl;
}
    
// GETTERS
double Rectangulo::Obtener_Base() const {
    return base;
}   

double Rectangulo::Obtener_Altura() const {
    return altura;
}