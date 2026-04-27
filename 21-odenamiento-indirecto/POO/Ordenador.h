#ifndef ORDENADOR_H
#define ORDENADOR_H

using namespace std;

template <typename T, int N>
class Ordenador {
private:
    T datos[N];
    int indices[N];
    int cantidad;

    void quicksort(int left, int right);
    int partition(int left, int right);

public:
    Ordenador();
    void agregarDato(const T& valor);
    void ordenar();
    void mostrarOriginal() const;
    void mostrarOrdenado() const;
};

#endif
