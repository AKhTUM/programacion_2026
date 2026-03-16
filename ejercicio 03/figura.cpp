#include "figura.h"
#include <iostream>
// CONSTRUCTORES
Figura::Figura(std::string nombre) : nombre(nombre) {
    this->nombre = nombre;

}
 
// DESTRUCTOR
Figura::~Figura() {
}

//GETTERS
std::string Figura::obtenerNombre() const {
    return nombre;
}