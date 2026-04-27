#ifndef COLA_H
#define COLA_H

const int maxi = 10; //DEFINO EL MAXIMO DE MI COLA

class Cola {
private:
    int dato[maxi]; //ARREGLO PARA ALMACENAR VALORES DE LA COLA
    int frent;  //INDICE FRENTE
    int final; //INDICE FINAL 

public:
    Cola(); //CONSTRUCTOR 
    bool isEmpty();
    bool isFull();
    void enqueue(int valo);
    void dequeue(); //METODOS DE LA CLASE 
    int peek();
    void disp();
};

#endif

