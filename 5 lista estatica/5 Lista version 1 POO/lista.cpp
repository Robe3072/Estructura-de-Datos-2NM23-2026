#include <iostream>
#include "Lista.h"
using namespace std;

Lista::Lista() { //CONSTRUCTOR DE LA CLASE 
    tam = 0; //INICIALIZA EL TAMAÑO EN CERO 
}

bool Lista::isEmpty() {
    return tam == 0; //METODO PARA VERIFICAR QUE LA LISTA ESTA VACIA
}

void Lista::inser(int valo) { //METODO PARA INSERTAR VALOR EN LISTA 
    if (tam < 10) {
        dat[tam++] = valo; //INSERTA EL VALOR EN LA SIGUIENTE POSICION Y AUMENTA TAMAÑO
        cout << "Numero " << valo << " insertado en la lista." << endl;
    } else { //SI ESTA LLENA,NO PERMITE INSERTAR
        cout << "La lista esta llena." << endl;
    }
}

void Lista::elimi() { //METODO PARA ELIMINAR ELEMENTO DE LA LISTA
    if (isEmpty()) { //SI ESTA VACIA 
        cout << "Error: La lista esta vacia." << endl;
        return;
    } else { // SI NO ESTA VACIA 
        cout << "Numero eliminado: " << dat[tam - 1] << endl; //DISMINUYE EL TAMAÑO DE LA LISTA
        tam--;
    }
}

int Lista::ultimo() { //METODO PARA MOSTRAR EL ULTIMO ELEMNETO DE LA LISTA
    if (isEmpty()) { //SI ESTA VACIA
        cout << "Error: La lista esta vacia." << endl;
        return -1;
    }
    return dat[tam - 1]; //EL ULTIMO VALOR DE LA LISTA LO RETORNA 
}

void Lista::mos() { //METODO PARA MOSTRAR TODOS LOS VALORES DE LA LISTA 
    if (isEmpty()) { //SI ESTA VACIA 
        cout << "La lista esta vacia." << endl;
        return;
    }
    cout << "Contenido de la lista:" << endl; //SI NO ESTA VACIA,MUESTRA EL CONTENIDO DEL PRIMERO AL ULTIMO
    for (int i = 0; i < tam; i++) {
        cout << dat[i] << endl;
    }
}

