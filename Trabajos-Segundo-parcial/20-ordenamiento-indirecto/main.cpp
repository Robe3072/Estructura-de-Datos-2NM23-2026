#include <iostream>
#include "ordenador.h"

using namespace std;

int main() {
    int n;
    cout << "Cuantos elementos deseas ingresar (max 100)? ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Cantidad invalida.\n";
        return 1;
    }

    Ordenador ord(n);
    ord.leerDatos();
    ord.ordenarTodo();
    ord.mostrarTodo();

    return 0;
}