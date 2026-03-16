#include "circulo.h"
#include <iostream>



Circulo::Circulo(std::string nombre, double radio) : Figura(nombre), radio(radio) {
     this->nombre = nombre; 
    this->radio = radio;
    
}


// FUNCIONES VIRTUALES
double Circulo::CalcularArea() {
    return 3.14159 * radio * radio;
}

void Circulo::Describir_Figura() {
    std::cout << "yo soy un  " << nombre << " con radio " << radio << "." << std::endl;
}

// GETTER
double Circulo::Obtener_Radio() const {
    return radio;
}
