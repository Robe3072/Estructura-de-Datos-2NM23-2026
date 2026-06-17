#include "Pila.h"
#include <iostream>
using namespace std;

void Pila::agregar(int valor) {
    datos.push_back(valor);
}

void Pila::quitar() {
    if (datos.empty()) {
        cout << "La pila esta vacia.\n";
    } else {
        cout << "Eliminado: " << datos.back() << endl;
        datos.pop_back();
    }
}

void Pila::visualizar() const {
    cout << "Pila (de arriba a abajo): ";
    for (auto it = datos.rbegin(); it != datos.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void Pila::validar(int valor) const {
    for (int v : datos) {
        if (v == valor) {
            cout << "Si esta en la pila.\n";
            return;
        }
    }
    cout << "No esta en la pila.\n";
}

void Pila::mostrarPosicion(int valor) const {
    int pos = 1;
    for (auto it = datos.rbegin(); it != datos.rend(); ++it, ++pos) {
        if (*it == valor) {
            cout << "Esta en la posicion (desde cima): " << pos << endl;
            return;
        }
    }
    cout << "No encontrado.\n";
}

