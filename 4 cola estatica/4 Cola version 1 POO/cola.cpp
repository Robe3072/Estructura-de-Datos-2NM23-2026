#include <iostream>
#include "Cola.h"
using namespace std;

Cola::Cola() { //CONSTRUCTOR 
    frent = 0; //INICIALIZA FRENTE EN 0
    final = -1; //INICIA FINAL EN VACIO
}

bool Cola::isEmpty() { //METODO PARA VERIFICAR QUE ESTE VACIA LA COLA 
    return frent > final;
}

bool Cola::isFull() { //METODO PARA VER SI ESTA LLENA
    return final == maxi - 1;
}

void Cola::enqueue(int valo) { //METODO PARA INSERTAR VALOR A LA COLA
    if (isFull()) { //LLENA
        cout << "Error: La cola esta llena." << endl;
        return;
    }
    dato[++final] = valo; //AUMENTA INDICE DE FINAL Y INSERTA EL NUMERO 
    cout << "Numero " << valo << " insertado en la cola." << endl;
}

void Cola::dequeue() { //METODO PARA ELEMINAR VALOR DE LA COLA 
    if (isEmpty()) { //ESTA VACIA 
        cout << "Error: La cola esta vacia." << endl;
        return;
    }
    cout << "Numero eliminado: " << dato[frent++] << endl; //MUESTRA EL VALOR ELIMINADO Y AUMENTA INDICE DE FRENTE 
}

int Cola::peek() { //METODO PARA VER EL VALOR DEL FRENTE 
    if (isEmpty()) { //ESTA VACIA 
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    return dato[frent]; //VALOR DE FRENTE 
}

void Cola::disp() { //METODO PARA MOSTRAR CONTENIDO DE COLA
    if (isEmpty()) { //ESTA VACIA 
        cout << "La cola esta vacia." << endl;
        return;
    }
    cout << "Contenido de la cola:" << endl; //MUESTRA EL CONTENIDO DE FRENTE A FINAL 
    for (int i = frent; i <= final; i++) {
        cout << dato[i] << endl;
    }
}

