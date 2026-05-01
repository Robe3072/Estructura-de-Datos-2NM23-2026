#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <string>
using namespace std;

struct Persona {
    string nombre;
    int edad;
};

class Ordenador {
private:
    static const int MAX = 100;
    int n;
    int numeros[MAX], idxNum[MAX];
    char letras[MAX];
    int idxLetras[MAX];
    Persona personas[MAX];
    int idxPersonas[MAX];

    void mergeSortInt(int[], int, int);
    void mergeInt(int[], int, int, int);
    void mergeSortChar(int[], int, int);
    void mergeChar(int[], int, int, int);
    void mergeSortPersona(int[], int, int);
    void mergePersona(int[], int, int, int);

public:
    Ordenador(int cantidad);
    void leerDatos();
    void ordenarTodo();
    void mostrarTodo();
};

#endif