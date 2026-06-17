#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Funciones para la pila
void push(Nodo **tope, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *tope;
    *tope = nuevo;
}

void pop(Nodo **tope) {
    if (*tope == NULL) {
        printf("La pila está vacía.\n");
        return;
    }

    Nodo *temp = *tope;
    printf("Elemento retirado: %d\n", temp->dato);
    *tope = temp->siguiente;
    free(temp);
}

void mostrar(Nodo *tope) {
    if (tope == NULL) {
        printf("La pila está vacía.\n");
        return;
    }

    Nodo *actual = tope;
    printf("Pila:\n");
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

void eliminar_todo(Nodo **tope) {
    Nodo *actual = *tope;
    Nodo *temp;

    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    *tope = NULL;
    printf("Pila eliminada.\n");
}

#endif
