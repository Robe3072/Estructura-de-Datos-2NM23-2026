#ifndef PILA_H
#define PILA_H

const int maxi = 5;

class Pila {
private:
    int dat[maxi];
    int lim;

public:
    Pila();
    bool isEmpty();
    bool isFull();
    void push(int val);
    void pop();
    int peek();
    void dis();
};

#endif

