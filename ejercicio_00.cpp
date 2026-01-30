#include <stdio.h>
#include <string.h>

// Definir la estructura de un estudiante
struct Estudiante {
    char nombre[50];
    int matricula;
    int edad;
    float promedio;
    char estado[20];
};

// Array para almacenar los estudiantes (máximo 100)
struct Estudiante estudiantes[100];
int totalEstudiantes = 0;  // Contador de estudiantes registrados

// Funcion para agregar un estudiante
void agregarEstudiante() {
    if (totalEstudiantes >= 100) {
        printf("No hay espacio para mas estudiantes.\n\n");
        return;
    }
    
    printf("\n--- AGREGAR NUEVO ESTUDIANTE ---\n");
    
    // Pedir datos del estudiante
    printf("\nIngresa el nombre (puede incluir espacios): ");
    fgets(estudiantes[totalEstudiantes].nombre, 50, stdin);
    // Eliminar el salto de linea que agrega fgets
    int len = strlen(estudiantes[totalEstudiantes].nombre);
    if (len > 0 && estudiantes[totalEstudiantes].nombre[len - 1] == '\n') {
        estudiantes[totalEstudiantes].nombre[len - 1] = '\0';
    }
    
    printf("Ingresa la matricula: ");
    scanf("%d", &estudiantes[totalEstudiantes].matricula);
    getchar(); // Limpiar el salto de linea del buffer
    
    printf("Ingresa la edad: ");
    scanf("%d", &estudiantes[totalEstudiantes].edad);
    getchar(); // Limpiar el salto de linea del buffer
    
    printf("Ingresa el promedio: ");
    scanf("%f", &estudiantes[totalEstudiantes].promedio);
    getchar(); // Limpiar el salto de linea del buffer
    
    printf("Ingresa el estado (Activo/Inactivo): ");
    fgets(estudiantes[totalEstudiantes].estado, 20, stdin);
    // Eliminar el salto de linea que agrega fgets
    len = strlen(estudiantes[totalEstudiantes].estado);
    if (len > 0 && estudiantes[totalEstudiantes].estado[len - 1] == '\n') {
        estudiantes[totalEstudiantes].estado[len - 1] = '\0';
    }
    
    printf("Estudiante agregado exitosamente.\n\n");
    totalEstudiantes++;  // Incrementar el contador
}

// Funcion para mostrar todos los estudiantes
void mostrarEstudiantes() {
    printf("\n--- LISTA DE ESTUDIANTES ---\n");
    
    if (totalEstudiantes == 0) {
        printf("No hay estudiantes registrados.\n\n");
        return;
    }
    
    for (int i = 0; i < totalEstudiantes; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Matricula: %d\n", estudiantes[i].matricula);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Promedio: %.2f\n", estudiantes[i].promedio);
        printf("Estado: %s\n", estudiantes[i].estado);
    }
    printf("\nTotal de estudiantes: %d\n\n", totalEstudiantes);
}

// Prototipo de la funcion buscar (declarada antes de main)
void buscarEstudiante();

//Menu del programa

int main() {
    int opcion = 0;

    do {
        // Mostrar menu
        printf("====== MENU INTERACTIVO ======\n");
        printf("1. Agregar nuevo estudiante\n");
        printf("2. Mostrar a todos los estudiantes\n");
        printf("3. Buscar estudiante\n");
        printf("4. Salir\n");
        printf("==============================\n");
        printf("Selecciona una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            // Entrada no valida: limpiar buffer y forzar opcion invalida
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            opcion = 0;
        }
        
        // Limpiar el buffer después del scanf del menu
        getchar();

        switch (opcion) {
            case 1:
                // Llama a la funcion que pide los datos y guarda en el array
                agregarEstudiante();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, selecciona una opcion del 1 al 4.\n\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}

// Funcion para buscar un estudiante por matricula
void buscarEstudiante() {
    if (totalEstudiantes == 0) {
        printf("\nNo hay estudiantes registrados.\n\n");
        return;
    }

    int matriculaBuscada;
    printf("\n--- BUSCAR ESTUDIANTE ---\n");
    printf("Ingresa la matricula a buscar: ");
    if (scanf("%d", &matriculaBuscada) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Entrada invalida. Volviendo al menu.\n\n");
        return;
    }

    // Buscar en el array
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].matricula == matriculaBuscada) {
            printf("\nEstudiante encontrado:\n");
            printf("Nombre: %s\n", estudiantes[i].nombre);
            printf("Matricula: %d\n", estudiantes[i].matricula);
            printf("Edad: %d\n", estudiantes[i].edad);
            printf("Promedio: %.2f\n", estudiantes[i].promedio);
            printf("Estado: %s\n\n", estudiantes[i].estado);
            return;
        }
    }

    printf("\nNo se encontro ningun estudiante con la matricula %d.\n\n", matriculaBuscada);
}