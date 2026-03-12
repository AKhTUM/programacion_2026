#ifdef FIGURA_H
#define FIGURA_H

#include <string>

class figura {
    protected:
        std::string nombre;

// CONSTRUCTORES
    public:
        figura(std::string nombre) : nombre(nombre) {}
        virtual ~figura() {} //  Destructor virtual para permitir la eliminación adecuada de objetos derivados

// FUNCIONES VIRTUALES
        virtual double CalcularArea() = 0;
        virtual void Describir_Figura() = 0;

// GETTERS
        std::string ObtenNombre() const { return nombre; }
};