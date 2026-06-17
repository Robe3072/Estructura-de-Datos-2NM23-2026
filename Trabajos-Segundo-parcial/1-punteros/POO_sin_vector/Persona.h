#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
private:
    std::string nombre, ap, am, genero;
    int edad;
    Persona* siguiente;

public:
    Persona();
    void capturarDatos();
    void setSiguiente(Persona* p);
    Persona* getSiguiente();
    void mostrar();
};

#endif
