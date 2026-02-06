#include <iostream>
#include "estudiante.h"

using namespace std;

int main() {
    cout << "\n=== Sistema de Gestión de Estudiante ===\n" << endl;

    // Estudiante 1 (constructor por defecto)
    cout << "Estudiante 1 (constructor por defecto):" << endl;
    Estudiante est1;
    est1.mostrar();

    // Estudiante 1 después de actualizar
    cout << "\nEstudiante 1 después de actualizar:" << endl;
    est1.setNombre("Mario pech panchito");
    est1.setCodigo("EST-2025-609");
    est1.setEdad(40);
    est1.setPromedio(10.0);
    est1.setActivo(true);
    est1.mostrar();
    cout << "Estado académico: " << est1.calcularEstadoAcademico() << "\n" << endl;

    // Estudiante 2 (constructor con parámetros)
    cout << "Estudiante 2 (constructor con parámetros):" << endl;
    Estudiante est2("Jhony jhony yes papa", "EST-1997-001", 99, 1.1, true);
    est2.mostrar();
    cout << "Estado académico: " << est2.calcularEstadoAcademico() << "\n" << endl;

    // Incrementar edad del estudiante 2
    cout << "Incrementando edad del estudiante 2:" << endl;
    est2.incrementarEdad();
    cout << "Edad: " << est2.getEdad() << " años\n" << endl;

    // Intentar actualizar promedio con valor inválido
    cout << "Intentando actualizar promedio con valor inválido:" << endl;
    float nuevoProm = 15.0f;
    if (nuevoProm < 0.0f || nuevoProm > 10.0f) {
        cout << "Error: El promedio debe estar entre 0.0 y 10.0" << endl;
        cout << "Promedio: " << est2.getPromedio() << endl;
    } else {
        est2.setPromedio(nuevoProm);
        cout << "Promedio actualizado: " << est2.getPromedio() << endl;
    }

    return 0;
}
