#include "Nodo.h"
#include <iostream>
using namespace std;

int main() {
    Nodo* frente = nullptr;
    Nodo* fin = nullptr;
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
                    if (fin == nullptr) {
                        frente = fin = nuevo;
                    } else {
                        fin->setSiguiente(nuevo);
                        fin = nuevo;
                    }
                }
                break;

            case 2: // Quitar
                if (frente == nullptr) {
                    cout << "La cola esta vacia.\n";
                } else {
                    Nodo* temp = frente;
                    frente = frente->getSiguiente();
                    if (frente == nullptr) fin = nullptr;
                    cout << "Eliminado: " << temp->getDato() << endl;
                    delete temp;
                }
                break;

            case 3: // Visualizar
                {
                    Nodo* aux = frente;
                    cout << "Cola (de frente a fin): ";
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
                    Nodo* aux = frente;
                    bool encontrado = false;
                    while (aux != nullptr) {
                        if (aux->getDato() == valor) {
                            encontrado = true;
                            break;
                        }
                        aux = aux->getSiguiente();
                    }
                    cout << (encontrado ? "Si esta en la cola.\n" : "No esta en la cola.\n");
                }
                break;

            case 5: // Mostrar posición
                {
                    cout << "Valor a buscar: ";
                    cin >> valor;
                    Nodo* aux = frente;
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
                        cout << "Ests en la posicion (desde frente): " << pos << endl;
                    } else {
                        cout << "No encontrado.\n";
                    }
                }
                break;
        }

    } while (opcion != 6);

    // Liberar memoria
    while (frente != nullptr) {
        Nodo* temp = frente;
        frente = frente->getSiguiente();
        delete temp;
    }

    return 0;
}

