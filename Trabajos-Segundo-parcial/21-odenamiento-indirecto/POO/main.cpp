#include "Ordenador.h"
#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    int edad;

    bool operator<=(const Persona& otra) const {
        return edad <= otra.edad;
    }

    friend ostream& operator<<(ostream& os, const Persona& p) {
        return os << p.nombre << "(" << p.edad << ")";
    }
};

int main() {
    const int N = 100;

    Ordenador<int, N> ordEnteros;
    int n;
    cout << "Cuantos enteros deseas ingresar? ";
    cin >> n;
    cout << "Ingresa los enteros:";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ordEnteros.agregarDato(val);
    }

    ordEnteros.mostrarOriginal();
    ordEnteros.ordenar();
    ordEnteros.mostrarOrdenado();

    Ordenador<char, N> ordCaracteres;
    cout << "\nCuantos caracteres deseas ingresar? ";
    cin >> n;
    cout << "Ingresa los caracteres:";
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ordCaracteres.agregarDato(c);
    }

    ordCaracteres.mostrarOriginal();
    ordCaracteres.ordenar();
    ordCaracteres.mostrarOrdenado();

    Ordenador<Persona, N> ordPersonas;
    cout << "\nCuantas personas deseas ingresar? ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Persona p;
        cout << "Nombre: ";
        cin >> p.nombre;
        cout << "Edad: ";
        cin >> p.edad;
        ordPersonas.agregarDato(p);
    }

    ordPersonas.mostrarOriginal();
    ordPersonas.ordenar();
    ordPersonas.mostrarOrdenado();

    return 0;
}
