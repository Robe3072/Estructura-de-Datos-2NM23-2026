#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona() : edad(0) {}

void Persona::capturarDatos() {
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellido paterno: ";
    getline(cin, ap);
    cout << "Apellido materno: ";
    getline(cin, am);
    cout << "Genero: ";
    getline(cin, genero);
    cout << "Edad: ";
    cin >> edad;
    cin.ignore();
}

void Persona::mostrar() const {
    cout << nombre << " " << ap << " " << am << ", " << genero << ", " << edad << " anios" << endl;
}

