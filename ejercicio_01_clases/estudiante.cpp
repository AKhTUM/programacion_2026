#include "estudiante.h"
#include <iostream>

using namespace std;

// Constructores
Estudiante::Estudiante() {
    nombre = "";
    codigo = "";
    edad = 0;
    promedio = 0.0;
    activo = false;
}

Estudiante::Estudiante(string nombre, string codigo, int edad, float promedio, bool activo) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->edad = edad;
    this->promedio = promedio;
    this->activo = activo;
}

// Getters
string Estudiante::getNombre() const {
    return nombre;
}

string Estudiante::getCodigo() const {
    return codigo;
}

int Estudiante::getEdad() const {
    return edad;
}

float Estudiante::getPromedio() const {
    return promedio;
}

bool Estudiante::getActivo() const {
    return activo;
}

// Setters
void Estudiante::setNombre(string nombre) {
    this->nombre = nombre;
}

void Estudiante::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Estudiante::setEdad(int edad) {
    if (edad > 0 && edad < 120) {
        this->edad = edad;
    }
}

void Estudiante::setPromedio(float promedio) {
    if (promedio >= 0.0 && promedio <= 10.0) {
        this->promedio = promedio;
    }
}

void Estudiante::setActivo(bool activo) {
    this->activo = activo;
}

// Otros métodos
void Estudiante::mostrar() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Código: " << codigo << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << (activo ? "Activo" : "Inactivo") << endl;
}

bool Estudiante::esAprobado() const {
    return promedio >= 6.0;
}

void Estudiante::incrementarEdad() {
    edad++;
}

string Estudiante::calcularEstadoAcademico() const {
    if (promedio >= 0.0 && promedio < 5.9) {
        return "Necesita Mejorar";
    } else if (promedio >= 5.9 && promedio < 6.9) {
        return "Regular";
    } else if (promedio >= 6.9 && promedio < 7.9) {
        return "Bueno";
    } else if (promedio >= 7.9 && promedio < 8.9) {
        return "Muy Bueno";
    } else if (promedio >= 8.9 && promedio <= 10.0) {
        return "Excelente";
    } else {
        return "Promedio inválido";
    }
}
