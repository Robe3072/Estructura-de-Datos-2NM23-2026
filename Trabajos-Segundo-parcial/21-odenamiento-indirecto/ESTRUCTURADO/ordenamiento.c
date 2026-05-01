#include <stdio.h>
#include <string.h>
#include "ordenamiento.h"

void leerDatos(int numeros[], char letras[], Persona personas[], int indicesNum[], int indicesLetra[], int indicesPers[], int n) {
    printf("\n== Ingreso de numeros ==\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        indicesNum[i] = i;
    }

    printf("\n== Ingreso de letras ==\n");
    for ( i = 0; i < n; i++) {
        printf("Letra %d: ", i + 1);
        scanf(" %c", &letras[i]);
        indicesLetra[i] = i;
    }

    printf("\n== Ingreso de personas ==\n");
    for ( i = 0; i < n; i++) {
        printf("Nombre: ");
        scanf("%s", personas[i].nombre);
        printf("ID: ");
        scanf("%d", &personas[i].id);
        indicesPers[i] = i;
    }
}


void quickSortInt(int arr[], int valores[], int low, int high) {
    if (low < high) {
        int pivot = valores[arr[(low + high) / 2]];
        int i = low, j = high;
        while (i <= j) {
            while (valores[arr[i]] < pivot) i++;
            while (valores[arr[j]] > pivot) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++; j--;
            }
        }
        quickSortInt(arr, valores, low, j);
        quickSortInt(arr, valores, i, high);
    }
}


void quickSortChar(int arr[], char valores[], int low, int high) {
    if (low < high) {
        char pivot = valores[arr[(low + high) / 2]];
        int i = low, j = high;
        while (i <= j) {
            while (valores[arr[i]] < pivot) i++;
            while (valores[arr[j]] > pivot) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++; j--;
            }
        }
        quickSortChar(arr, valores, low, j);
        quickSortChar(arr, valores, i, high);
    }
}


void quickSortPersona(int arr[], Persona valores[], int low, int high) {
    if (low < high) {
        char *pivot = valores[arr[(low + high) / 2]].nombre;
        int i = low, j = high;
        while (i <= j) {
            while (strcmp(valores[arr[i]].nombre, pivot) < 0) i++;
            while (strcmp(valores[arr[j]].nombre, pivot) > 0) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++; j--;
            }
        }
        quickSortPersona(arr, valores, low, j);
        quickSortPersona(arr, valores, i, high);
    }
}

void ordenarTodo(int numeros[], char letras[], Persona personas[], int indicesNum[], int indicesLetra[], int indicesPers[], int n) {
    quickSortInt(indicesNum, numeros, 0, n - 1);
    quickSortChar(indicesLetra, letras, 0, n - 1);
    quickSortPersona(indicesPers, personas, 0, n - 1);
}

void mostrarResultados(int numeros[], char letras[], Persona personas[], int indicesNum[], int indicesLetra[], int indicesPers[], int n) {
    printf("\n== Numeros ordenados ==\n");
    int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", numeros[indicesNum[i]]);
    }

    printf("\n\n== Letras ordenadas ==\n");
    for ( i = 0; i < n; i++) {
        printf("%c ", letras[indicesLetra[i]]);
    }

    printf("\n\n== Personas ordenadas por nombre ==\n");
    for ( i = 0; i < n; i++) {
        int idx = indicesPers[i];
        printf("%s (ID: %d)\n", personas[idx].nombre, personas[idx].id);
    }
}

