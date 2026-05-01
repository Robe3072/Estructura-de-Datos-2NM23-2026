#include <iostream>
#include "Lista.h"
using namespace std;

int main() {
    Lista lista;
    int opc, valo;

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
                cin >> valo;
                lista.inser(valo);
                break;
            case 2:
                lista.elimi();
                break;
            case 3:
                valo = lista.ultimo();
                if (valo != -1)
                    cout << "Ultimo numero: " << valo << endl;
                break;
            case 4:
                lista.mos();
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

