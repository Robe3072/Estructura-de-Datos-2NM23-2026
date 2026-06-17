#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
private:
    std::string nombre, ap, am, genero;
    int edad;

public:
    Persona();
    void capturarDatos();
    void mostrar() const;
};

#endif

