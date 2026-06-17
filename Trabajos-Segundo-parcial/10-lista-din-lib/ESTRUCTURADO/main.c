#include "libreria.h"

int main() {
    Nodo *cabeza = NULL;
    int opcion, valor, posicion;

    do {
        printf("\n--- MENU LISTA ENLAZADA DE NUMEROS ENTEROS ---\n");
        printf("1. Insertar (al final)\n");
        printf("2. Eliminar (por posición)\n");
        printf("3. Mostrar lista\n");
        printf("4. Vaciar lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el número a insertar: ");
                scanf("%d", &valor);
                insertar(&cabeza, valor);
                break;
            case 2:
                printf("Ingrese la posición del nodo a eliminar: ");
                scanf("%d", &posicion);
                eliminar(&cabeza, posicion);
                break;
            case 3:
                mostrar(cabeza);
                break;
            case 4:
                vaciar(&cabeza);
                break;
            case 5:
                vaciar(&cabeza);
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 5);

    return 0;
}
