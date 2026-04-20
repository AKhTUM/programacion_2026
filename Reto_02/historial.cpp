#include "Historial.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <filesystem> // ¡La librería clave para carpetas!

namespace fs = std::filesystem; // Un "apodo" para no escribir tanto

// 1. Ahora generamos solo el nombre de la carpeta con la fecha
std::string Historial::generarNombreCarpeta() {
    time_t ahora = time(0);
    tm *tiempo = localtime(&ahora);
    char buffer[80];
    strftime(buffer, 80, "%d_%m_%Y", tiempo);
    return std::string(buffer);
}

Historial::Historial() {
    std::string carpeta = generarNombreCarpeta();
    
    // 2. Revisamos si la carpeta existe; si no, la creamos
    if (!fs::exists(carpeta)) {
        fs::create_directory(carpeta);
        std::cout << "[Sistema] Carpeta del dia creada: " << carpeta << std::endl;
    }

    // 3. El archivo siempre se llamará chat.txt pero dentro de su carpeta
    nombreArchivo = carpeta + "/chat.txt";
}

void Historial::agregarMensaje(Mensaje m) {
    listaDeMensajes.push_back(m);

    // Guardamos en la ruta: fecha_del_dia/chat.txt
    std::ofstream archivo(nombreArchivo, std::ios::app);

    if (archivo.is_open()) {
        archivo << m.obtenerFormatoLog() << "\n"; 
        archivo.close();
    } else {
        std::cout << "Error al abrir el historial en: " << nombreArchivo << "\n";
    }
}