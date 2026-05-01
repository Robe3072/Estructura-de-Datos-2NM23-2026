#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#define MAX 100

typedef struct {
    int id;
    char nombre[30];
} Persona;

void leerDatos(int numeros[], char letras[], Persona personas[], int indicesNum[], int indicesLetra[], int indicesPers[], int n);
void ordenarTodo(int numeros[], char letras[], Persona personas[], int indicesNum[], int indicesLetra[], int indicesPers[], int n);
void mostrarResultados(int numeros[], char letras[], Persona personas[], int indicesNum[], int indicesLetra[], int indicesPers[], int n);

#endif

