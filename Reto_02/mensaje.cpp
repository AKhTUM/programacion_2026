#include "Mensaje.h"
#include <ctime> // Aquí sí va la librería del tiempo, porque aquí se usa

// 1. Implementación del método privado (nota el Mensaje::)
std::string Mensaje::obtenerFechaHoraActual() {
    time_t ahora = time(0);
    tm *tiempo = localtime(&ahora);
    char buffer[80];
    // Da el formato: DD/MM/YYYY HH:MM:SS
    strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", tiempo);
    return std::string(buffer);
}

// 2. Implementación del Constructor
Mensaje::Mensaje(std::string _emisor, std::string _contenido) {
    emisor = _emisor;
    contenido = _contenido;
    fechaHora = obtenerFechaHoraActual(); // Se manda a llamar al nacer
}

// 3. Implementación de los Getters
std::string Mensaje::getEmisor() { 
    return emisor; 
}

std::string Mensaje::getContenido() { 
    return contenido; 
}

std::string Mensaje::getFechaHora() { 
    return fechaHora; 
}

// 4. Implementación del formato para el archivo
std::string Mensaje::obtenerFormatoLog() {
    return "[" + fechaHora + "] " + emisor + ": " + contenido;
}