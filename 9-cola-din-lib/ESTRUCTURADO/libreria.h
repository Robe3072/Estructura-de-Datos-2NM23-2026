#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura del Nodo
typedef struct Nodo {
    char dato[11]; // 10 caracteres + '\0'
    struct Nodo *siguiente;
} Nodo;

// Funciones para manejar la cola
void encolar(Nodo **frente, Nodo **final, const char *valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }
    strncpy(nuevo->dato, valor, 10);
    nuevo->dato[10] = '\0'; // Asegurar terminación
    nuevo->siguiente = NULL;

    if (*final == NULL) { // Cola vacía
        *frente = *final = nuevo;
    } else {
        (*final)->siguiente = nuevo;
        *final = nuevo;
    }
}

void desencolar(Nodo **frente, Nodo **final) {
    if (*frente == NULL) {
        printf("La cola está vacía.\n");
        return;
    }

    Nodo *temp = *frente;
    printf("Elemento desencolado: [%s]\n", temp->dato);
    *frente = temp->siguiente;

    if (*frente == NULL) { // Si se vació la cola
        *final = NULL;
    }

    free(temp);
}

void mostrar(Nodo *frente) {
    if (frente == NULL) {
        printf("La cola está vacía.\n");
        return;
    }

    Nodo *actual = frente;
    printf("Cola:\n");
    while (actual != NULL) {
        printf("[%s] -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void vaciar(Nodo **frente, Nodo **final) {
    Nodo *actual = *frente;
    Nodo *temp;

    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    *frente = NULL;
    *final = NULL;
    printf("Cola vaciada.\n");
}

#endif
