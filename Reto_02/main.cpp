#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
// Importamos clases
#include "Mensaje.h"
#include "Historial.h"

using namespace std;

int main() {
    cout << "=== Inicializando ChatBot Inteligente ===" << endl;


    Historial miChat;
    
    // 2. Leemos la API Key del archivo oculto .env
    string apiKey;
    ifstream archivoSecreto(".env"); 
    if (archivoSecreto.is_open()) {
        getline(archivoSecreto, apiKey); 
        archivoSecreto.close();               
    } else {
        cout << "¡ERROR!: No se encontro el archivo .env con la llave" << endl;
        return 1; 
    }

    string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + apiKey;
    string miPregunta;

    // 3. El Bucle del Chat: Se repetirá infinitamente hasta que escribas "salir"
    while (true) {
        cout << "\n=============================================" << endl;
        cout << "Escribe tu pregunta para la IA (o 'salir'): ";
        getline(cin, miPregunta);

        // Si el usuario quiere salir, rompemos el bucle
        if (miPregunta == "salir") {
            cout << "\n¡Nos vemos! Tu conversacion ha sido guardada en la carpeta del dia." << endl;
            break; 
        }

    

        // A) Guardamos tu pregunta en el historial
        Mensaje msgUsuario("Usuario", miPregunta);
        miChat.agregarMensaje(msgUsuario);

        cout << "Pensando..." << endl;

        
        string comando = "curl -s -H \"Content-Type: application/json\" -X POST \"" + url + "\" ";
        comando += "-d \"{\\\"contents\\\": [{\\\"parts\\\":[{\\\"text\\\": \\\"" + miPregunta + "\\\"}]}]}\"";
        comando += " > respuesta.txt"; 

        // C) Ejecutamos la petición a internet
        system(comando.c_str());

       
        ifstream archivoRespuesta("respuesta.txt");
        string jsonGemini = "";
        string linea;
        
        if (archivoRespuesta.is_open()) {
            while (getline(archivoRespuesta, linea)) {
                jsonGemini += linea + " "; // Juntamos todo el texto
            }
            archivoRespuesta.close();
        }

        // E) Imprimimos la respuesta en la terminal
        cout << "\n--- Gemini dice ---" << endl;
        cout << jsonGemini << endl;

        // F) Guardamos la respuesta de la IA en el historial
        Mensaje msgGemini("Gemini", jsonGemini);
        miChat.agregarMensaje(msgGemini);
    }

    // 4. Limpieza del sistema: Borramos el archivo temporal para no dejar rastro
    remove("respuesta.txt");
    
    return 0;
}