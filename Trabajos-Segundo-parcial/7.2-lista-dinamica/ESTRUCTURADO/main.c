#include "libreria.h"

int main() {
    Nodo *lista = NULL;
    int opcion, valor, posicion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insertar dato\n");
        printf("2. Eliminar por posición\n");
        printf("3. Mostrar lista\n");
        printf("4. Eliminar toda la lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                insertar(&lista, valor);
                break;
            case 2:
                printf("Ingrese la posición a eliminar (comienza en 0): ");
                scanf("%d", &posicion);
                eliminar_posicion(&lista, posicion);
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                eliminar_todo(&lista);
                break;
            case 5:
                eliminar_todo(&lista);
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 5);

    return 0;
}
