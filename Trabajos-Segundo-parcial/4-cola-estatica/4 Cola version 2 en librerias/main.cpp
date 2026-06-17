#include<iostream>
#include "cola.h"
using namespace std;

int main() {
    int opci,valo;
    do {
        cout<< "\nMENU COLA ESTATICA PREDETERMINADA\n";
        cout<<"1. Insertar \n";		
        cout<<"2. Eliminar \n";		
        cout<<"3. Ver frente \n";		
        cout<<"4. Mostrar cola\n";
        cout<<"5. Salir\n";
        cout<<"Selecciona una opcion: ";
        cin>>opci;

        switch(opci){
            case 1:
                cout<<"Ingresa un numero: ";
                cin>>valo;
                enqueue(valo);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                valo=peek();
                if(valo!=-1)
                    cout<<"Numero en el frente: "<<valo<<endl;
                break;
            case 4:
                disp();
                break;
            case 5:
                cout<<"Saliendo."<<endl;
                break;
            default:
                cout<<"Opcion invalida."<<endl;
        }
    } while(opci!=5);
    return 0;
}
