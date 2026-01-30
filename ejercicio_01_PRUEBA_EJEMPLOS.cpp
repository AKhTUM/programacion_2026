#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * Clase Estudiante
 * 
 * Propósito: Gestionar la información básica de un estudiante universitario
 * 
 * Conceptos aplicados:
 * - Encapsulamiento (atributos privados, métodos públicos)
 * - Constructores (por defecto y parametrizado)
 * - Getters y Setters
 * - Métodos de utilidad
 * - Validación de datos
 */
class Estudiante {
private:
    // Atributos privados (encapsulamiento)
    int matricula;              // Número de matrícula único
    string nombre;              // Nombre completo del estudiante
    string apellido;            // Apellido del estudiante
    string carrera;             // Carrera académica
    float promedio;             // Promedio acumulado
    vector<float> calificaciones; // Historial de calificaciones
    
    // Método privado de validación
    bool esCalificacionValida(float calificacion) const {
        return calificacion >= 0.0f && calificacion <= 10.0f;
    }

public:
    // ============ CONSTRUCTORES ============
    
    /**
     * Constructor por defecto
     * Inicializa el estudiante con valores por defecto
     */
    Estudiante() 
        : matricula(0), nombre(""), apellido(""), carrera(""), promedio(0.0f) {
        cout << "[Constructor por defecto] Estudiante creado sin datos\n";
    }
    
    /**
     * Constructor parametrizado
     * Inicializa el estudiante con los datos proporcionados
     */
    Estudiante(int mat, string nom, string ape, string car) 
        : matricula(mat), nombre(nom), apellido(ape), carrera(car), promedio(0.0f) {
        cout << "[Constructor parametrizado] Estudiante " << nombre << " " 
             << apellido << " registrado\n";
    }
    
    // ============ GETTERS (métodos para obtener datos) ============
    
    /**
     * Obtiene el número de matrícula
     */
    int getMatricula() const {
        return matricula;
    }
    
    /**
     * Obtiene el nombre del estudiante
     */
    string getNombre() const {
        return nombre;
    }
    
    /**
     * Obtiene el apellido del estudiante
     */
    string getApellido() const {
        return apellido;
    }
    
    /**
     * Obtiene el nombre completo (nombre + apellido)
     */
    string getNombreCompleto() const {
        return nombre + " " + apellido;
    }
    
    /**
     * Obtiene la carrera
     */
    string getCarrera() const {
        return carrera;
    }
    
    /**
     * Obtiene el promedio actual
     */
    float getPromedio() const {
        return promedio;
    }
    
    /**
     * Obtiene el número de calificaciones registradas
     */
    int getCantidadCalificaciones() const {
        return calificaciones.size();
    }
    
    // ============ SETTERS (métodos para establecer datos) ============
    
    /**
     * Establece el nombre del estudiante
     */
    void setNombre(string nom) {
        if (nom.empty()) {
            cout << "[Error] El nombre no puede estar vacío\n";
            return;
        }
        nombre = nom;
        cout << "[Nombre actualizado] " << nombre << "\n";
    }
    
    /**
     * Establece el apellido del estudiante
     */
    void setApellido(string ape) {
        if (ape.empty()) {
            cout << "[Error] El apellido no puede estar vacío\n";
            return;
        }
        apellido = ape;
        cout << "[Apellido actualizado] " << apellido << "\n";
    }
    
    /**
     * Establece la carrera
     */
    void setCarrera(string car) {
        if (car.empty()) {
            cout << "[Error] La carrera no puede estar vacía\n";
            return;
        }
        carrera = car;
        cout << "[Carrera actualizada] " << carrera << "\n";
    }
    
    // ============ MÉTODOS DE UTILIDAD ============
    
    /**
     * Añade una nueva calificación al historial
     * Valida que la calificación esté entre 0 y 10
     */
    void agregarCalificacion(float calificacion) {
        if (!esCalificacionValida(calificacion)) {
            cout << "[Error] La calificación debe estar entre 0 y 10\n";
            return;
        }
        
        calificaciones.push_back(calificacion);
        actualizarPromedio();
        cout << "[Calificación agregada] " << fixed << setprecision(2) 
             << calificacion << " - Nuevo promedio: " << promedio << "\n";
    }
    
    /**
     * Obtiene la calificación más alta
     */
    float getCalificacionMaxima() const {
        if (calificaciones.empty()) {
            cout << "[Advertencia] No hay calificaciones registradas\n";
            return 0.0f;
        }
        return *max_element(calificaciones.begin(), calificaciones.end());
    }
    
    /**
     * Obtiene la calificación más baja
     */
    float getCalificacionMinima() const {
        if (calificaciones.empty()) {
            cout << "[Advertencia] No hay calificaciones registradas\n";
            return 0.0f;
        }
        return *min_element(calificaciones.begin(), calificaciones.end());
    }
    
    /**
     * Verifica si el estudiante está aprobado (promedio >= 6.0)
     */
    bool estaAprobado() const {
        return promedio >= 6.0f;
    }
    
    /**
     * Determina el estado académico del estudiante
     */
    string getEstadoAcademico() const {
        if (calificaciones.empty()) {
            return "Sin calificaciones";
        } else if (promedio >= 9.0f) {
            return "Excelente";
        } else if (promedio >= 8.0f) {
            return "Muy bueno";
        } else if (promedio >= 7.0f) {
            return "Bueno";
        } else if (promedio >= 6.0f) {
            return "Aprobado";
        } else {
            return "Reprobado";
        }
    }
    
    /**
     * Muestra toda la información del estudiante
     */
    void mostrarInformacion() const {
        cout << "\n" << string(50, '=') << "\n";
        cout << "INFORMACIÓN DEL ESTUDIANTE\n";
        cout << string(50, '=') << "\n";
        cout << "Matrícula:    " << matricula << "\n";
        cout << "Nombre:       " << getNombreCompleto() << "\n";
        cout << "Carrera:      " << carrera << "\n";
        cout << "Promedio:     " << fixed << setprecision(2) << promedio << "\n";
        cout << "Estado:       " << getEstadoAcademico() << "\n";
        cout << "Calificaciones: " << getCantidadCalificaciones() << "\n";
        
        if (!calificaciones.empty()) {
            cout << "  Máxima: " << fixed << setprecision(2) << getCalificacionMaxima() << "\n";
            cout << "  Mínima: " << fixed << setprecision(2) << getCalificacionMinima() << "\n";
        }
        cout << string(50, '=') << "\n\n";
    }

private:
    /**
     * Actualiza el promedio basado en todas las calificaciones
     */
    void actualizarPromedio() {
        if (calificaciones.empty()) {
            promedio = 0.0f;
            return;
        }
        
        float suma = 0.0f;
        for (float cal : calificaciones) {
            suma += cal;
        }
        promedio = suma / calificaciones.size();
    }
};

// ============ FUNCIÓN PRINCIPAL ============

int main() {
    cout << "\n========== SISTEMA DE GESTIÓN DE ESTUDIANTES ==========\n\n";
    
    // Ejemplo 1: Crear estudiante con constructor por defecto
    cout << "--- EJEMPLO 1: Constructor por defecto ---\n";
    Estudiante est1;
    est1.setNombre("Juan");
    est1.setApellido("Pérez");
    est1.setCarrera("Ingeniería en Informática");
    
    // Ejemplo 2: Crear estudiante con constructor parametrizado
    cout << "\n--- EJEMPLO 2: Constructor parametrizado ---\n";
    Estudiante est2(2024001, "María", "García", "Administración de Empresas");
    
    // Ejemplo 3: Agregar calificaciones y ver promedio
    cout << "\n--- EJEMPLO 3: Agregando calificaciones ---\n";
    est2.agregarCalificacion(8.5f);
    est2.agregarCalificacion(9.0f);
    est2.agregarCalificacion(7.5f);
    est2.agregarCalificacion(8.8f);
    
    // Ejemplo 4: Uso de getters
    cout << "\n--- EJEMPLO 4: Consultando información ---\n";
    cout << "Nombre completo: " << est2.getNombreCompleto() << "\n";
    cout << "Promedio: " << fixed << setprecision(2) << est2.getPromedio() << "\n";
    cout << "¿Está aprobado? " << (est2.estaAprobado() ? "Sí" : "No") << "\n";
    
    // Ejemplo 5: Mostrar información completa
    cout << "\n--- EJEMPLO 5: Información completa ---\n";
    est2.mostrarInformacion();
    
    // Ejemplo 6: Intentar agregar calificación inválida
    cout << "--- EJEMPLO 6: Validación de datos ---\n";
    est2.agregarCalificacion(12.5f);  // Será rechazada
    est2.agregarCalificacion(-1.0f);  // Será rechazada
    est2.agregarCalificacion(6.0f);   // Será aceptada
    
    // Ejemplo 7: Crear y gestionar otro estudiante
    cout << "\n--- EJEMPLO 7: Otro estudiante ---\n";
    Estudiante est3(2024002, "Carlos", "López", "Ingeniería Civil");
    est3.agregarCalificacion(5.5f);
    est3.agregarCalificacion(5.0f);
    est3.mostrarInformacion();
    
    cout << "========== FIN DEL PROGRAMA ==========\n\n";
    
    return 0;
}
