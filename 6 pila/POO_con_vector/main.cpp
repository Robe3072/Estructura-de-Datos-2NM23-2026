#include "Pila.h"
#include <iostream>
using namespace std;

int main() {
    Pila pila;
    int opcion, valor;

    do {
        cout << "\n1. Agregar\n2. Quitar\n3. Visualizar\n4. Validar\n5. Mostrar posicion\n6. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a agregar: ";
                cin >> valor;
                pila.agregar(valor);
                break;
            case 2:
                pila.quitar();
                break;
            case 3:
                pila.visualizar();
                break;
            case 4:
                cout << "Valor a buscar: ";
                cin >> valor;
                pila.validar(valor);
                break;
            case 5:
                cout << "Valor a buscar: ";
                cin >> valor;
                pila.mostrarPosicion(valor);
                break;
        }

    } while (opcion != 6);

    return 0;
}

