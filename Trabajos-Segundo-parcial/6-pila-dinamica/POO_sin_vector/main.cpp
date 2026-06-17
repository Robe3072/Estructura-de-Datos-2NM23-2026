#include "Nodo.h"
#include <iostream>
using namespace std;

int main() {
    Nodo* cima = nullptr;
    int opcion, valor;

    do {
        cout << "\n1. Agregar\n2. Quitar\n3. Visualizar\n4. Validar\n5. Mostrar posicion\n6. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Agregar
                cout << "Valor a agregar: ";
                cin >> valor;
                {
                    Nodo* nuevo = new Nodo(valor);
                    nuevo->setSiguiente(cima);
                    cima = nuevo;
                }
                break;

            case 2: // Quitar
                if (cima == nullptr) {
                    cout << "La pila esta vacia.\n";
                } else {
                    Nodo* temp = cima;
                    cima = cima->getSiguiente();
                    cout << "Eliminado: " << temp->getDato() << endl;
                    delete temp;
                }
                break;

            case 3: // Visualizar
                {
                    Nodo* aux = cima;
                    cout << "Pila (de arriba a abajo): ";
                    while (aux != nullptr) {
                        cout << aux->getDato() << " ";
                        aux = aux->getSiguiente();
                    }
                    cout << endl;
                }
                break;

            case 4: // Validar
                {
                    cout << "Valor a buscar: ";
                    cin >> valor;
                    Nodo* aux = cima;
                    bool encontrado = false;
                    while (aux != nullptr) {
                        if (aux->getDato() == valor) {
                            encontrado = true;
                            break;
                        }
                        aux = aux->getSiguiente();
                    }
                    cout << (encontrado ? "Sí esta en la pila.\n" : "No esta en la pila.\n");
                }
                break;

            case 5: // Mostrar posición tipo lista
                {
                    cout << "Valor a buscar: ";
                    cin >> valor;
                    Nodo* aux = cima;
                    int pos = 0;
                    bool encontrado = false;
                    while (aux != nullptr) {
                        pos++;
                        if (aux->getDato() == valor) {
                            encontrado = true;
                            break;
                        }
                        aux = aux->getSiguiente();
                    }
                    if (encontrado) {
                        cout << "Esta en la posicion (desde cima): " << pos << endl;
                    } else {
                        cout << "No encontrado.\n";
                    }
                }
                break;
        }

    } while (opcion != 6);

    // Liberar memoria
    while (cima != nullptr) {
        Nodo* temp = cima;
        cima = cima->getSiguiente();
        delete temp;
    }

    return 0;
}

