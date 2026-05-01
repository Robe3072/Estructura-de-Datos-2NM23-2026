#include <stdio.h>
#include "ordenamiento.h"

int main() {
    int n;
    int numeros[MAX], indicesNum[MAX];
    char letras[MAX];
    int indicesLetra[MAX];
    Persona personas[MAX];
    int indicesPers[MAX];

    printf("¿Cuantos datos quieres ingresar? (MAXIMO %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    leerDatos(numeros, letras, personas, indicesNum, indicesLetra, indicesPers, n);
    ordenarTodo(numeros, letras, personas, indicesNum, indicesLetra, indicesPers, n);
    mostrarResultados(numeros, letras, personas, indicesNum, indicesLetra, indicesPers, n);

    return 0;
}

