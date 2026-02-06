#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
public:
    // Constructores
    Estudiante();
    Estudiante(std::string nombre, std::string codigo, int edad, float promedio, bool activo);
    
    // Métodos (getters - para obtener valores)
    std::string getNombre() const;
    std::string getCodigo() const;
    int getEdad() const;
    float getPromedio() const;
    bool getActivo() const;
    
    // Métodos (setters - para cambiar valores)
    void setNombre(std::string nombre);
    void setCodigo(std::string codigo);
    void setEdad(int edad);
    void setPromedio(float promedio);
    void setActivo(bool activo);
    
    // Otros métodos
    void mostrar() const;
    bool esAprobado() const;
    void incrementarEdad();
    std::string calcularEstadoAcademico() const;

private:
    std::string nombre;
    std::string codigo;
    int edad;
    float promedio;
    bool activo;
};

#endif
