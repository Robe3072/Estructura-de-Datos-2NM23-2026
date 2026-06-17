#include "Persona.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Cuantas personas deseas ingresar? ";
    cin >> n;
    cin.ignore();

    vector<Persona> personas;

    for (int i = 0; i < n; ++i) {
        Persona p;
        cout << "\nPersona #" << i + 1 << endl;
        p.capturarDatos();
        personas.push_back(p);
    }

    cout << "\nLista de personas:\n";
    for (const Persona& p : personas) {
        p.mostrar();
    }

    return 0;
}

