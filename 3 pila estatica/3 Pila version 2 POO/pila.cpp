#include <iostream>
#include "Pila.h"
using namespace std;

Pila::Pila() {
    dat[0] = 4;
    dat[1] = 3;
    dat[2] = 6;
    dat[3] = 9;
    dat[4] = 7;
    lim = 4;
}

bool Pila::isEmpty() {
    return lim == -1;
}

bool Pila::isFull() {
    return lim == maxi - 1;
}

void Pila::push(int val) {
    if (isFull()) {
        cout << "La pila esta llena." << endl;
        return;
    }
    dat[++lim] = val;
    cout << "Numero " << val << " insertado en la pila." << endl;
}

void Pila::pop() {
    if (isEmpty()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Numero eliminado: " << dat[lim--] << endl;
}

int Pila::peek() {
    if (isEmpty()) {
        cout << "La pila esta vacia." << endl;
        return -1;
    }
    return dat[lim];
}

void Pila::dis() {
    if (isEmpty()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Contenido de la pila: " << endl;
    for (int i = lim; i >= 0; i--) {
        cout << dat[i] << endl;
    }
}

