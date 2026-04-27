#ifndef COLA_H
#define COLA_H

const int maxi = 5;

class Cola {
private:
    int dato[maxi];
    int frent;
    int final;

public:
    Cola();

    bool isEmpty();
    bool isFull();
    void enqueue(int valo);
    void dequeue();
    int peek();
    void disp();
};

#endif

