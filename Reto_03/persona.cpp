#include "Persona.h"
#include <iostream>

persona::persona(std::string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

void persona::mostrar() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
}