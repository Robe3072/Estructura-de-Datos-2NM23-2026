#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

const int MAX = 10;
int dat[MAX];
int tam;

void inicializarLista() {
    dat[0] = 9;
    dat[1] = 8;
    dat[2] = 4;
    dat[3] = 7;
    dat[4] = 1;
    dat[5] = 6;
    dat[6] = 0;
    dat[7] = 4;
    dat[8] = 5;
    dat[9] = 9;
    tam = 10;
}

bool isEmpty() {
    return tam == 0;
}

void insertar(int valo) {
    if (tam < MAX) {
        dat[tam++] = valo;
        cout << "Numero " << valo << " insertado en la lista." << endl;
    } else {
        cout << "La lista esta llena." << endl;
    }
}

void eliminar() {
    if (isEmpty()) {
        cout << "Error: La lista esta vacia." << endl;
    } else {
        cout << "Numero eliminado: " << dat[tam - 1] << endl;
        tam--;
    }
}

int ultimo() {
    if (isEmpty()) {
        cout << "Error: La lista esta vacia." << endl;
        return -1;
    }
    return dat[tam - 1];
}

void mostrar() {
    if (isEmpty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    cout << "Contenido de la lista:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << dat[i] << endl;
    }
}

#endif

