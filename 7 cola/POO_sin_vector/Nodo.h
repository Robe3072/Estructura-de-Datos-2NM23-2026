#ifndef NODO_H
#define NODO_H

class Nodo {
private:
    int dato;
    Nodo* siguiente;

public:
    Nodo(int d);
    void setSiguiente(Nodo* s);
    Nodo* getSiguiente();
    int getDato();
};

#endif

