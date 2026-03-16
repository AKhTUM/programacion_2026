#ifndef FIGURA_H
#define FIGURA_H

#include <string>

class Figura {
    protected:
        std::string nombre;

// CONSTRUCTORES
    public:
      Figura(std::string nombre);
// DESTRUCTOR
      virtual ~Figura();
        
// FUNCIONES VIRTUALES
        virtual double CalcularArea() = 0;
        virtual void Describir_Figura() = 0;

// GETTERS
      std::string obtenerNombre() const;
};

#endif