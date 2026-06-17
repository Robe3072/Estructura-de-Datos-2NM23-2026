#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Funciones
void insertar(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void eliminar_posicion(Nodo **cabeza, int posicion) {
    if (*cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *actual = *cabeza;
    if (posicion == 0) {
        *cabeza = actual->siguiente;
        free(actual);
        printf("Elemento en posición 0 eliminado.\n");
        return;
    }

    for (int i = 0; actual != NULL && i < posicion - 1; i++) {
        actual = actual->siguiente;
    }

    if (actual == NULL || actual->siguiente == NULL) {
        printf("Posición no válida.\n");
        return;
    }

    Nodo *temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);
    printf("Elemento en posición %d eliminado.\n", posicion);
}

void eliminar_todo(Nodo **cabeza) {
    Nodo *actual = *cabeza;
    Nodo *temp;

    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    *cabeza = NULL;
    printf("Lista eliminada.\n");
}

void mostrar(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

#endif
