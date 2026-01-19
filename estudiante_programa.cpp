#include <iostream>
using namespace std;

int main() {
    cout << "====== MENU INTERACTIVO ======" << endl;
    cout << "1. Opcion 1" << endl;
    cout << "2. Opcion 2" << endl;
    cout << "3. Opcion 3" << endl;
    cout << "4. Salir" << endl;
    cout << "==============================" << endl;
    cout << "Selecciona una opcion: ";
    
    int opcion;
    cin >> opcion;  // Lee la entrada del usuario
    
    cout << "Tu seleccion fue: " << opcion << endl;
    
    return 0;
}
