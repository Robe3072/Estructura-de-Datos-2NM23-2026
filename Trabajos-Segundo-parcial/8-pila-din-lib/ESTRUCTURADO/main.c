#include "libreria.h"

int main() {
    Nodo *pila = NULL;
    int opcion, valor;

    do {
        printf("\n--- MENU PILA ---\n");
        printf("1. Push (apilar dato)\n");
        printf("2. Pop (desapilar dato)\n");
        printf("3. Mostrar pila\n");
        printf("4. Vaciar pila\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el valor a apilar: ");
                scanf("%d", &valor);
                push(&pila, valor);
                break;
            case 2:
                pop(&pila);
                break;
            case 3:
                mostrar(pila);
                break;
            case 4:
                eliminar_todo(&pila);
                break;
            case 5:
                eliminar_todo(&pila);
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 5);

    return 0;
}
