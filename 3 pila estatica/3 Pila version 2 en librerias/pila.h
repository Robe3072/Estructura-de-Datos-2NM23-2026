#ifndef PILA_H
#define PILA_H
#include <iostream>
using namespace std;
const int maximo=5;
int dat[maximo];
int lim=-1;
	void iniciarPila(){
        dat[0]=4;
        dat[1]=3;
        dat[2]=6;
        dat[3]=9;
        dat[4]=7;
        lim=4;
    }

    bool isEmpty() {
        return lim==-1;
    }

    bool isFull() {
        return lim==maximo-1;
    }

    void push(int val) {
        if (isFull()) {
            cout<<"La pila esta llena." <<endl;
            return;
        }
        dat[++lim]=val;
        cout<<"Numero " <<val<<" insertado en la pila."<<endl;
    }

    void pop(){
        if (isEmpty()){
            cout<<"La pila esta vacia."<<endl;
            return;
        }
        cout<<"Numero eliminado: "<<dat[lim--]<<endl;
    }

    int peek(){
        if (isEmpty()){
            cout<<"La pila esta vacia."<<endl;
            return -1;
        }
        return dat[lim];
    }

    void dis(){
        if (isEmpty()){
            cout<<"La pila esta vacia."<<endl;
            return;
        }
        cout<<"Contenido de la pila: " <<endl;
        for(int i=lim;i>=0;i--){
            cout<<dat[i]<<endl;
        }
    }
 #endif
