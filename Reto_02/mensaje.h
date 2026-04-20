#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>

class Mensaje {
private:
    std::string emisor;
    std::string contenido;
    std::string fechaHora;

    // Solo declaramos que esta función existirá
    std::string obtenerFechaHoraActual(); 

public:
    // Declaración del constructor
    Mensaje(std::string _emisor, std::string _contenido); 

    // Declaración de Getters
    std::string getEmisor();
    std::string getContenido();
    std::string getFechaHora();
    
    // Declaración del método de formato
    std::string obtenerFormatoLog();
};

#endif