#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream> // ¡Nueva librería mágica para leer archivos!

int main() {
    std::cout << "=== Chat con Inteligencia Artificial (Gemini API) ===" << std::endl;

    std::string apiKey;
    // 1. Abrimos el archivo secreto
    std::ifstream archivoSecreto(".env"); 

    // 2. Comprobamos si el archivo existe y se pudo abrir
    if (archivoSecreto.is_open()) {
        std::getline(archivoSecreto, apiKey); // Leemos la primera línea y la guardamos en apiKey
        archivoSecreto.close();               // Cerramos el archivo por seguridad
    } else {
        std::cout << "¡ERROR CRÍTICO!: No se encontro el archivo .env con la llave." << std::endl;
        return 1; // Apagamos el programa si no hay llave
    }

    // A partir de aquí, el código es exactamente igual al que ya tenías
    std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + apiKey;

    std::string miPregunta;
    std::cout << "\nEscribe tu pregunta para la IA: ";
    std::getline(std::cin, miPregunta);

    std::cout << "\nEnviando mensaje... esperando respuesta de Google...\n" << std::endl;

    std::string comando = "curl -s -H \"Content-Type: application/json\" -X POST \"" + url + "\" ";
    comando += "-d \"{\\\"contents\\\": [{\\\"parts\\\":[{\\\"text\\\": \\\"" + miPregunta + "\\\"}]}]}\"";

    system(comando.c_str());

    std::cout << "\n\n=== Conexion terminada ===" << std::endl;
    
    return 0;
}