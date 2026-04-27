#ifndef COLA_H
#define COLA_H
#include<iostream>
using namespace std;
const int maxi=5;
int dato[maxi]={8,6,7,2,3};
int frent=0;
int final=4;

bool isEmpty(){            
        return frent>final;
    }

    bool isFull() {             
        return final==maxi-1;
    }

    void enqueue(int valo) {   
        if (isFull()){
            cout<<"Error:La cola esta llena."<<endl;
            return;
        }
        dato[++final]=valo;
        cout<<"Numero "<<valo<<" insertado en la cola."<<endl;
    }

    void dequeue() {           
        if (isEmpty()) {
            cout<<"Error: La cola esta vacia."<<endl;
            return;
        }
        cout<<"Numero eliminado: "<<dato[frent++]<<endl;
    }

    int peek(){               
        if(isEmpty()){
            cout<<"Error: La cola esta vacia."<<endl;
            return -1;
        }
        return dato[frent];
    }

    void disp(){            
        if(isEmpty()){
            cout<<"La cola esta vacia."<<endl;
            return;
        }
        cout<<"Contenido de la cola:"<<endl;
        for(int i=frent;i<=final;i++){
            cout<<dato[i]<<endl;
        }
    }
#endif
