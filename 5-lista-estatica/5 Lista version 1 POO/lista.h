#ifndef LISTA_H
#define LISTA_H

class Lista { //DEFINO CLASE 
private:
    int dat[10]; //ARREGLO PARA VALORES DE LISTA 
    int tam; //VARIABLE PARA EL TAMAÑO ACTUAL DE LA LISTA 
public:
    Lista(); //CONSTRUCTOR  INICIALIZA LA LISTA 
    bool isEmpty();
    void inser(int valo);
    void elimi();
    int ultimo(); //METODOS DE LA LISTA 
    void mos();
};

#endif

