#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::cout << "=== Chat con Inteligencia Artificial (Gemini API) ===" << std::endl;

    // 1. PEGA TU LLAVE AQUÍ ENTRE LAS COMILLAS
    std::string apiKey = "AIzaSyAKDTy4xBGkQSRXdNGedAqFZ4XtaWWTIXs"; 
   // 2. Apuntamos directamente a la versión 2.5 que marca la documentación oficial
    std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + apiKey;

    // 3. Le pedimos al usuario (tú o tu profe) que escriba la pregunta
    std::string miPregunta;
    std::cout << "\nEscribe tu pregunta para la IA: ";
    std::getline(std::cin, miPregunta); // Leemos toda la línea que escribas

    std::cout << "\nEnviando mensaje... esperando respuesta de Google...\n" << std::endl;

    // 4. Armamos el paquete inyectando tu pregunta en el formato JSON
    std::string comando = "curl -s -H \"Content-Type: application/json\" -X POST \"" + url + "\" ";
    comando += "-d \"{\\\"contents\\\": [{\\\"parts\\\":[{\\\"text\\\": \\\"" + miPregunta + "\\\"}]}]}\"";

    // 5. ¡Ejecutamos la magia en la terminal!
    system(comando.c_str());

    std::cout << "\n\n=== Conexion terminada ===" << std::endl;
    
    return 0;
}