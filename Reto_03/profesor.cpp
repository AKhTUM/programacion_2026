#include "Profesor.h"
#include <iostream>


profesor::profesor(std::string _nombre, int _edad, std::string _materia) : persona(_nombre, _edad) {
    materia = _materia;
}

void profesor::mostrar() {
    persona::mostrar(); // EL PAPA DE LOS PAPAS
    std::cout << "Materia: " << materia << std::endl;
}