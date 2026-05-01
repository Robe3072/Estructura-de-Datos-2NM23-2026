#include "Ordenador.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T, int N>
Ordenador<T, N>::Ordenador() : cantidad(0) {
    for (int i = 0; i < N; ++i)
        indices[i] = i;
}

template <typename T, int N>
void Ordenador<T, N>::agregarDato(const T& valor) {
    if (cantidad < N) {
        datos[cantidad] = valor;
        indices[cantidad] = cantidad;
        cantidad++;
    } else {
        cout << "Limite alcanzado." << endl;
    }
}

template <typename T, int N>
void Ordenador<T, N>::ordenar() {
    quicksort(0, cantidad - 1);
}

template <typename T, int N>
void Ordenador<T, N>::quicksort(int left, int right) {
    if (left < right) {
        int pi = partition(left, right);
        quicksort(left, pi - 1);
        quicksort(pi + 1, right);
    }
}

template <typename T, int N>
int Ordenador<T, N>::partition(int left, int right) {
    T pivot = datos[indices[right]];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (datos[indices[j]] <= pivot) {
            ++i;
            swap(indices[i], indices[j]);
        }
    }
    swap(indices[i + 1], indices[right]);
    return i + 1;
}

template <typename T, int N>
void Ordenador<T, N>::mostrarOriginal() const {
    cout << "Original: ";
    for (int i = 0; i < cantidad; ++i)
        cout << datos[i] << " ";
    cout << endl;
}

template <typename T, int N>
void Ordenador<T, N>::mostrarOrdenado() const {
    cout << "Ordenado (indirecto): ";
    for (int i = 0; i < cantidad; ++i)
        cout << datos[indices[i]] << " ";
    cout << endl;
}


template class Ordenador<int, 100>;
template class Ordenador<char, 100>;


struct Persona {
    string nombre;
    int edad;

    bool operator<=(const Persona& otra) const {
        return edad <= otra.edad;
    }

    friend ostream& operator<<(ostream& os, const Persona& p) {
        return os << p.nombre << "(" << p.edad << ")";
    }
};

template class Ordenador<Persona, 100>;
