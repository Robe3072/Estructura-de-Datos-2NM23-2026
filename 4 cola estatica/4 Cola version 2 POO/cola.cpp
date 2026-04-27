#include <iostream>
#include "Cola.h"
using namespace std;

Cola::Cola() {
    dato[0] = 8;
    dato[1] = 6;
    dato[2] = 7;
    dato[3] = 2;
    dato[4] = 3;
    frent = 0;
    final = 4;
}

bool Cola::isEmpty() {
    return frent > final;
}

bool Cola::isFull() {
    return final == maxi - 1;
}

void Cola::enqueue(int valo) {
    if (isFull()) {
        cout << "Error: La cola esta llena." << endl;
        return;
    }
    dato[++final] = valo;
    cout << "Numero " << valo << " insertado en la cola." << endl;
}

void Cola::dequeue() {
    if (isEmpty()) {
        cout << "Error: La cola esta vacia." << endl;
        return;
    }
    cout << "Numero eliminado: " << dato[frent++] << endl;
}

int Cola::peek() {
    if (isEmpty()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    return dato[frent];
}

void Cola::disp() {
    if (isEmpty()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    cout << "Contenido de la cola:" << endl;
    for (int i = frent; i <= final; i++) {
        cout << dato[i] << endl;
    }
}

