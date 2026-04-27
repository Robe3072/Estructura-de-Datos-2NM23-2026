#ifndef PILA_H
#define PILA_H
#include <vector>

class Pila {
private:
    std::vector<int> datos;

public:
    void agregar(int valor);
    void quitar();
    void visualizar() const;
    void validar(int valor) const;
    void mostrarPosicion(int valor) const;
};

#endif

