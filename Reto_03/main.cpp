///Polimorfismoooooo

#include <iostream>
#include "alumno.h"
#include "Profesor.h"
#include "persona.h"



int main () {
    persona *vector[4];

    vector[0] = new alumno("Alejandro", 20, 18.9);
    vector[1] = new alumno("Maria", 19, 15.5);
    vector[2] = new profesor("Jose", 25, "Algoritmos" );    
    vector[3] = new alumno("Jhonny jhonny yes papa ", 666, 100.0);

    vector[0]->mostrar();
    std::cout << std::endl;
    vector[1]->mostrar();
    std::cout << std::endl;
    vector[2]->mostrar();
    std::cout << std::endl;
    vector[3]->mostrar();
    std::cout << std::endl;


    return 0;
}
