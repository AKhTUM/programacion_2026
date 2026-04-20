#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <vector>
#include <string>
#include "Mensaje.h" 

class Historial {
private:
    std::vector<Mensaje> listaDeMensajes; 
    std::string nombreArchivo;            

    std::string generarNombreCarpeta();

public:
    // Constructor
    Historial();

    // Método principal
    void agregarMensaje(Mensaje m);
};

#endif