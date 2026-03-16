#ifndef CIRCULO_H
#define CIRCULO_H

#include <string>
#include "figura.h" 

class Circulo : public Figura {
    private:
        double radio; /// ATRIBUTO ESPECIAL DEL CIRCULO QUE SOLO EL CIRCULO TIENE Y SOLO EL CIRCULO

 // CONSTRUCTORES
    public:
        Circulo(std::string nombre, double radio);

// FUNCIONES VIRTUALES 
        double CalcularArea() override; 
        void Describir_Figura() override;

// GETTER
        double Obtener_Radio() const;
};

#endif 