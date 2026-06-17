#include <iostream>
#include "ordenador.h"

using namespace std;

Ordenador::Ordenador(int cantidad) : n(cantidad) {}

void Ordenador::leerDatos() {
    cout << "--- Numeros ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Numero[" << i << "]: ";
        cin >> numeros[i];
        idxNum[i] = i;
    }

    cout << "--- Letras ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Letra[" << i << "]: ";
        cin >> letras[i];
        idxLetras[i] = i;
    }

    cout << "--- Personas ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Nombre[" << i << "]: ";
        cin >> personas[i].nombre;
        cout << "Edad[" << i << "]: ";
        cin >> personas[i].edad;
        idxPersonas[i] = i;
    }
}

void Ordenador::mergeSortInt(int idx[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortInt(idx, left, mid);
        mergeSortInt(idx, mid + 1, right);
        mergeInt(idx, left, mid, right);
    }
}

void Ordenador::mergeInt(int idx[], int left, int mid, int right) {
    int temp[100], i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (numeros[idx[i]] <= numeros[idx[j]])
            temp[k++] = idx[i++];
        else
            temp[k++] = idx[j++];
    }
    while (i <= mid) temp[k++] = idx[i++];
    while (j <= right) temp[k++] = idx[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        idx[i] = temp[k];
}

void Ordenador::mergeSortChar(int idx[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortChar(idx, left, mid);
        mergeSortChar(idx, mid + 1, right);
        mergeChar(idx, left, mid, right);
    }
}

void Ordenador::mergeChar(int idx[], int left, int mid, int right) {
    int temp[100], i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (letras[idx[i]] <= letras[idx[j]])
            temp[k++] =  idx[i++];
        else
            temp[k++] = idx[j++];
    }
    while (i <= mid) temp[k++] = idx[i++];
    while (j <= right) temp[k++] = idx[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        idx[i] = temp[k];
}

void Ordenador::mergeSortPersona(int idx[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortPersona(idx, left, mid);
        mergeSortPersona(idx, mid + 1, right);
        mergePersona(idx, left, mid, right);
    }
}

void Ordenador::mergePersona(int idx[], int left, int mid, int right) {
    int temp[100], i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (personas[idx[i]].edad <= personas[idx[j]].edad)
            temp[k++] = idx[i++];
        else
            temp[k++] = idx[j++];
    }
    while (i <= mid) temp[k++] = idx[i++];
    while (j <= right) temp[k++] = idx[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        idx[i] = temp[k];
}

void Ordenador::ordenarTodo() {
    mergeSortInt(idxNum, 0, n - 1);
    mergeSortChar(idxLetras, 0, n - 1);
    mergeSortPersona(idxPersonas, 0, n - 1);
}

void Ordenador::mostrarTodo() {
    cout << "\n--- Numeros Ordenados ---\n";
    for (int i = 0; i < n; i++)
        cout << numeros[idxNum[i]] << " ";
    cout << "\n--- Letras Ordenadas ---\n";
    for (int i = 0; i < n; i++)
        cout << letras[idxLetras[i]] << " ";
    cout << "\n--- Personas Ordenadas por Edad ---\n";
    for (int i = 0; i < n; i++)
        cout << personas[idxPersonas[i]].nombre << " - " << personas[idxPersonas[i]].edad << "\n";
}
