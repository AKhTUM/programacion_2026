#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <string>
#include "figura.h"

class Rectangulo : public Figura {  
    private:    // SUS ATRIBUTOS ESPECIALES QUE SOLO TIENE EL RECTANGULO Y SOLO EL RECTANGULO.
        double base;
        double altura;

// CONSTRUCTORES
    public:
        Rectangulo(std::string nombre, double base, double altura);

// FUNCIONES VIRTUALES
        double CalcularArea() override; 
        void Describir_Figura() override;

// GETTERS
        double Obtener_Base() const;
        double Obtener_Altura() const;
};  

#endif