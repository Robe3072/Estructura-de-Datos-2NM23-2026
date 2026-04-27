#include "Persona.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Cuantas personas deseas ingresar? ";
    cin >> n;
    cin.ignore();

    Persona* inicio = nullptr;
    Persona* anterior = nullptr;

    for (int i = 0; i < n; ++i) {
        Persona* nueva = new Persona();
        cout << "\nPersona #" << i + 1 << endl;
        nueva->capturarDatos();

        if (inicio == nullptr) {
            inicio = nueva;
        } else {
            anterior->setSiguiente(nueva);
        }
        anterior = nueva;
    }

    cout << "\nLista de personas:\n";
    Persona* temp = inicio;
    while (temp != nullptr) {
        temp->mostrar();
        temp = temp->getSiguiente();
    }

    // Liberar memoria
    while (inicio != nullptr) {
        Persona* borrar = inicio;
        inicio = inicio->getSiguiente();
        delete borrar;
    }

    return 0;
}

