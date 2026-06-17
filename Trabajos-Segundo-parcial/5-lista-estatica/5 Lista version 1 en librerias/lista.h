#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

const int MAX = 10; //MAXIMO DE MI LISTA
int lista[MAX]; //ARREFLO PARA GUARDAR ELEMENTOS DE LA LISTA
int tam = 0; // LA VARIABLE QUE GUARDA EL NUMERO ACTUAL DE  LOS VALORES DE MI LISTA

bool isEmpty() {
    return tam == 0; //VERIFICA QUE LA LISTA EST VACIA 
}

void insertar(int valor) { //FUNCION PARA INSERTAR UN VALOR EN LA LISTA 
    if (tam < MAX) { //NO ESTA LLENA 
        lista[tam++] = valor; //INSERTAMOS EL VALOR AL FINAL 
        cout << "Numero " << valor << " insertado en la lista." << endl;
    } else { //ESTA LLENA 
        cout << "La lista esta llena." << endl;
    }
}

void eliminar() { //FUNCION PARA ELIMINAR UN VALOR DE LA LISTA
    if (isEmpty()) { // SI LA LISTA ESTA VACIA 
        cout << "Error: La lista esta vacia." << endl;
    } else { // SI NO ESTA LLENA 
        cout << "Numero eliminado: " << lista[tam - 1] << endl;
        tam--;//REDUZCO TAMAÑO DE LA LISTA
    }
}

int ultimo() { //FUNCION PARA VER EL ULTIMO VALOR DE LA LISTA 
    if (isEmpty()) { //SI ESTA VACIA 
        cout << "Error: La lista esta vacia." << endl;
        return -1;
    }
    return lista[tam - 1];
}// SI NO, DEVULVE  EL ULTIMO VALOR 

void mostrar() { //FUNCION PARA MOSTRAR EL CONTENIDO DE LA LISTA 
    if (isEmpty()) { //SI ESTA VACIA 
        cout << "La lista esta vacia." << endl;
    } else { // SI TIENE CONTENIDO
        cout << "Contenido de la lista:" << endl;
        for (int i = 0; i < tam; i++) {
            cout << lista[i] << endl; //MOSTRAMOS LA LISTA 
        }
    }
}

#endif

