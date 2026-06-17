#include <iostream>
#include "Pila.h"
using namespace std;

int main() {
    Pila pila;
    int opc, valo;

    do {
        cout << "\nMENU PILA ESTATICA\n";
        cout << "1. Insertar numero \n";
        cout << "2. Eliminar numero\n";
        cout << "3. Ver tope \n";
        cout << "4. Mostrar  \n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingresa un numero: " << endl;
                cin >> valo;
                pila.push(valo);
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                valo = pila.peek();
                if (valo != -1)
                    cout << "Elemento en el tope: " << valo << endl;
                break;
            case 4:
                pila.dis();
                break;
            case 5:
                cout << "Saliendo." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opc != 5);

    return 0;
}

