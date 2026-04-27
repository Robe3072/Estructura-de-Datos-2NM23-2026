#include "Pila.h"
#include <iostream>
using namespace std;

Pila::Pila() { //CONSTRUCTOR DE LA CLASE PILA 
    lim = -1;  //PILA VACIA 
}

bool Pila::isEmpty() {
    return lim == -1;  //ESTE VACIA 
}

bool Pila::isFull() {
    return lim == maxi - 1;  //ESTE LLENA 
}

void Pila::push(int val) { //INSERTAR VALORES 
    if (isFull()) {
        cout << "La pila esta llena." << endl;
        return;
    }
    dat[++lim] = val;
    cout << "Numero " << val << " insertado en la pila." << endl;
}

void Pila::pop() { //ELIMINA ELEMETO TOPE 
    if (isEmpty()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Numero eliminado: " << dat[lim--] << endl;
}

int Pila::peek() { //MUESTRA EL TOPE
    if (isEmpty()) {
        cout << "La pila esta vacia." << endl;
        return -1;
    }
    return dat[lim];
}

void Pila::dis() { //MUESTRA ELEMENTOS DE LA PILA DEL TOPE A LA BASE 
    if (isEmpty()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Contenido de la pila: " << endl;
    for (int i = lim; i >= 0; i--) {
        cout << dat[i] << endl;
    }
}

