#include "Nodo.h"

Nodo::Nodo(int d) : dato(d), siguiente(nullptr) {}

void Nodo::setSiguiente(Nodo* s) {
    siguiente = s;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

int Nodo::getDato() {
    return dato;
}

