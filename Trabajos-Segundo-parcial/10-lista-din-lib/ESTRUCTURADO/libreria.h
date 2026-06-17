#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    int dato;  // Dato numérico (puede ser float, double, etc.)
    struct Nodo *siguiente;
} Nodo;

// Función para insertar al final de la lista
void insertar(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*cabeza == NULL) { // Si la lista está vacía
        *cabeza = nuevo;
    } else {
        Nodo *temp = *cabeza;
        while (temp->siguiente != NULL) {  // Avanzamos hasta el final
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

// Función para eliminar un nodo por posición
void eliminar(Nodo **cabeza, int posicion) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo *temp = *cabeza;
    if (posicion == 0) {  // Si es el primer nodo
        *cabeza = temp->siguiente;
        free(temp);
        printf("Nodo en posición %d eliminado.\n", posicion);
        return;
    }

    Nodo *anterior = NULL;
    int contador = 0;
    while (temp != NULL && contador < posicion) {
        anterior = temp;
        temp = temp->siguiente;
        contador++;
    }

    if (temp == NULL) {
        printf("Posición inválida.\n");
        return;
    }

    anterior->siguiente = temp->siguiente;
    free(temp);
    printf("Nodo en posición %d eliminado.\n", posicion);
}

// Función para mostrar la lista
void mostrar(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo *temp = cabeza;
    printf("Lista:\n");
    while (temp != NULL) {
        printf("[%d] -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Función para eliminar toda la lista
void vaciar(Nodo **cabeza) {
    Nodo *temp = *cabeza;
    while (temp != NULL) {
        Nodo *siguiente = temp->siguiente;
        free(temp);
        temp = siguiente;
    }
    *cabeza = NULL;
    printf("Lista vaciada.\n");
}

#endif
