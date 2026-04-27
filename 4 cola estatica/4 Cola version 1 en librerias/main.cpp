#include <iostream>
#include "cola.h"
using namespace std;
int main() {
    int opci,valo;
    do {
        cout<< "\nMENU COLA ESTATICA\n";
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
                insert(valo);
                break;
            case 2:
                elimi();
                break;
            case 3:
                valo=frenteCola();
                if(valo!=-1)
                    cout<<"Numero en el frente: "<<valo<<endl;
                break;
            case 4:
                most();
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
