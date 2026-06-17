#include "libreria.h"

int main() {
    Nodo *frente = NULL;
    Nodo *final = NULL;
    int opcion;
    char valor[50];

    do {
        printf("\n--- MENU COLA DE CADENAS (10 caracteres) ---\n");
        printf("1. Encolar (agregar dato)\n");
        printf("2. Desencolar (quitar dato)\n");
        printf("3. Mostrar cola\n");
        printf("4. Vaciar cola\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de teclado

        switch(opcion) {
            case 1:
                printf("Ingrese el texto (máximo 10 caracteres): ");
                fgets(valor, sizeof(valor), stdin);
                valor[strcspn(valor, "\n")] = '\0'; // Eliminar salto de línea
                encolar(&frente, &final, valor);
                break;
            case 2:
                desencolar(&frente, &final);
                break;
            case 3:
                mostrar(frente);
                break;
            case 4:
                vaciar(&frente, &final);
                break;
            case 5:
                vaciar(&frente, &final);
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 5);

    return 0;
}
