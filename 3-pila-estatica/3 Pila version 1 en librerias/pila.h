#include<iostream>
#ifndef PILA_H
#define PILA_H
using namespace std;
const int  maxi=8; //TAMAÑO MAXIMO PILA
int dat[maxi]; //ARREGLO QUE SE USA COMO CONTENEDOR 
    int lim=-1; //TOPE:VACIO 
 bool isEmpty() {   //FUNCION QUE VERIFICA QUE ESTE VACIA 
        return lim==-1;
    }

    bool isFull() { //FUNCION QUE VERIFICA SI ESTA LLENA 
        return lim==maxi-1;
    }

    void push(int val) { //FUNCION PARA INSERTAR NUMERO EN LA PILA
        if (isFull()) { //SI ESTA LLENA NO SE PUEDE 
            cout<<"La pila esta llena." <<endl;
            return;
        }
        dat[++lim]=val; //INCREMENTA EL LIM Y PONE EL NUMERO EN SU POSICION CORRESPONDIENTE 
        cout<<"Numero " <<val<<" insertado en la pila."<<endl;
    }

    void pop(){ //FUNCION PARA ELEMINAR EL NUMERO TOPE DE LA PILA 
        if (isEmpty()){ //VACIA NO SE PUEDE 
            cout<<"La pila esta vacia."<<endl;
            return;
        }
        cout<<"Numero eliminado: "<<dat[lim--]<<endl;
    } //ELIMINA ELEMENTO TOPE

    int peek(){ //MUESTRA VALOR DEL TOPE SIN ELIMINAR EL NUMERO 
        if (isEmpty()){
            cout<<"La pila esta vacia."<<endl;
            return -1; //NO HAY PARA MOSTRAR 
        }
        return dat[lim];
    } //VALOR TOPE DE REGRESO

    void dis(){ //MUESTRA TODOS LOS ELEMENTOS 
        if (isEmpty()){
            cout<<"La pila esta vacia."<<endl;
            return;
        }
        cout<<"Contenido de la pila: " <<endl;
        for(int i=lim;i>=0;i--){ //ARRIBA HACIA ABAJO 
            cout<<dat[i]<<endl;
        }
    }
#endif
