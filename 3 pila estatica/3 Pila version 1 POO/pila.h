#ifndef PILA_H
#define PILA_H

const int maxi = 8; //TAMAÑO MAXIMO

class Pila {
private:
    int dat[maxi]; //ARREGLO QUE ALMACENA LOS VALORES DE LA PILA
    int lim; //INDICE QUE INDICA EL TOPE DE MI PILA

public:
    Pila(); //CONSTRUCTOR QUE INICIA LA PILA EN VACIO 
    bool isEmpty();
    bool isFull();
    void push(int val);
    void pop(); //METODOS DE MI CLASE 
    int peek();
    void dis();
};

#endif

