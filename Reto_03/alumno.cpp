#include "alumno.h"
#include <iostream>

alumno::alumno(std::string _nombre, int _edad, float _notaFinal) : persona(_nombre, _edad) {
    notaFinal = _notaFinal;
}


void alumno::mostrar() {
    persona::mostrar(); // EL PAPA DE LOS PAPAS
    std::cout << "Nota Final: " << notaFinal << std::endl;
}