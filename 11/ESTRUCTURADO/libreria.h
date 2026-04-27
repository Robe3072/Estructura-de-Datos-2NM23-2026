#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para almacenar los datos
typedef struct {
    int id;
    char nombre[50];
    float precio;
} Producto;

// Función para escribir datos en un archivo CSV
void escribirCSV(const char *nombreArchivo, Producto productos[], int numProductos) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }

    fprintf(archivo, "ID,Nombre,Precio\n");  // Escribir encabezado
    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%d,%s,%.2f\n", productos[i].id, productos[i].nombre, productos[i].precio);
    }

    fclose(archivo);
    printf("Datos escritos correctamente en el archivo.\n");
}

// Función para leer datos de un archivo CSV
int leerCSV(const char *nombreArchivo, Producto productos[], int maxProductos) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para lectura.\n");
        return 0;
    }

    char buffer[1024];
    int i = 0;
    
    // Saltar la línea de encabezado
    fgets(buffer, sizeof(buffer), archivo);
    
    // Leer los datos del archivo
    while (fgets(buffer, sizeof(buffer), archivo) != NULL && i < maxProductos) {
        sscanf(buffer, "%d,%49[^,],%f", &productos[i].id, productos[i].nombre, &productos[i].precio);
        i++;
    }

    fclose(archivo);
    return i;
}

// Función para mostrar los productos
void mostrarProductos(Producto productos[], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("ID: %d, Nombre: %s, Precio: %.2f\n", productos[i].id, productos[i].nombre, productos[i].precio);
    }
}

#endif
