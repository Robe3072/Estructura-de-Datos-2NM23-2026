#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona() : edad(0), siguiente(nullptr) {}

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
    cin.ignore(); // Limpiar el salto de línea
}

void Persona::setSiguiente(Persona* p) {
    siguiente = p;
}

Persona* Persona::getSiguiente() {
    return siguiente;
}

void Persona::mostrar() {
    cout << nombre << " " << ap << " " << am << ", " << genero << ", " << edad << " anios" << endl;
}
