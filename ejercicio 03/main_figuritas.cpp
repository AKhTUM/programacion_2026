#include <iostream>
#include "figura.h"
#include "circulo.h"
#include "rectangulo.h"


int main() {
 std::cout << "--- POLIMORFISMO DE FIGURAS: FIGURA, CÍRCULO Y RECTÁNGULO; USANDO PUNTEROS---" << std::endl;
std::cout << std::endl;

//punteros
Figura* figura1 = new Circulo("Círculo", 5.0);
Figura* figura2 = new Rectangulo("Rectángulo", 4.0, 6.0);

std::cout << "---Figura 1 (Círculo)---:" << std::endl;
figura1->Describir_Figura();
std::cout << "Área del círculo: " << figura1->CalcularArea() << std::endl;


std::cout << "\nFigura 2 (Rectángulo):" << std::endl;
figura2->Describir_Figura();
std::cout << "Área del rectángulo: " << figura2->CalcularArea() << std::endl;

// Misma interfaz, comportamiento diferente (polimorfismo)  
std::cout << "\n---Polimorfismo en acción: misma interfaz, comportamiento diferente---" << std::endl;
Figura* figuras[] = {figura1, figura2};
for (int i = 0; i < 2; ++i) {
    figuras[i]->Describir_Figura();
    std::cout << "Área: " << figuras[i]->CalcularArea() << std::endl;
}

//DESTRUCTORES PARA LIBERAR MEMORIA
delete figura1;
delete figura2;




    return 0;
}