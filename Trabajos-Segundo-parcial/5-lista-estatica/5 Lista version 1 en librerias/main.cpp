#include "lista.h"

int main() {
    int opc, valor;

    do {
        cout << "\n MENU LISTA\n";
        cout << "1. Insertar \n";
        cout << "2. Eliminar \n";
        cout << "3. Ver ultimo elemento \n";
        cout << "4. Mostrar lista\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingresa un numero: ";
                cin >> valor;
                insertar(valor);
                break;
            case 2:
                eliminar();
                break;
            case 3:
                valor = ultimo();
                if (valor != -1)
                    cout << "Ultimo numero: " << valor << endl;
                break;
            case 4:
                mostrar();
                break;
            case 5:
                cout << "Saliendo." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 5);

    return 0;
}

