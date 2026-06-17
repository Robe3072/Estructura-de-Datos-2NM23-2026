#ifndef LISTA_H
#define LISTA_H

class Lista {
private:
    int dat[10];
    int tam;
public:
    Lista();
    bool isEmpty();
    void inser(int valo);
    void elimi();
    int ultimo();
    void mos();
};

#endif

