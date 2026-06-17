#ifndef COLA_H
#define COLA_H
#include <iostream>
using namespace std;
const int maxi=10; //TAMAÑO MAXIMO DE LA COLA
int dato[maxi]; //ARREGLO PARA COLA
int frent=0; //VARIABLES DE FRENTE Y FINAL , CON SUS INDICES 
int final=-1;

void insert(int valo){ //INSERTAR VALOR A LA COLA
	if(final==maxi-1){ // SI FINAL=MAXIMO DE LA COLA, YA NO SE PUEDE 
		cout<<"La cola esta llena"<<endl;
		return;
	}
	dato[++final]=valo; //SE INCREMENTA EL INDICE DEL FINAL Y AGREGAMOS EL ELEMENTO
	cout<<"Numero"<<valo<<"insertado a la cola"<<endl;
}
void elimi(){ //ELIMINAR VALOR 
	if(frent>final){ //COLA VACIA 
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cout<<"Numero eliminado: "<<dato[frent++]<<endl; //IMPRIME EL VALOR ELIMINADO Y AUNMENTA EL INDICE DEL FRENTE 
}
int frenteCola(){ // VER VALOR DE FRENTE SIN ELIMINAR
	if(frent>final){ //COLA VACIA
		cout<<"La cola esta vacia"<<endl;
		return -1;
	}
	return dato[frent]; //VALOR DE FRENTE 
}
void most(){ //MOSTRAR VALORES DE COLA
	if(frent>final){ //VACIA 
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cout<<"Contenido de la cola: "<<endl; //IMPRIME DE FRENTE A FINAL 
	for(int i=frent;i<=final;i++){
		cout<<dato[i]<<endl;
	}
}
#endif
