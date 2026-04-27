#include "libreria.h"

#define MAX_PRODUCTOS 100  // Número máximo de productos que podemos manejar

int main() {
    Producto productos[MAX_PRODUCTOS];
    int numProductos = 0, opcion;
    
    do {
        printf("\n--- MENU CSV DE PRODUCTOS ---\n");
        printf("1. Escribir productos a CSV\n");
        printf("2. Leer productos desde CSV\n");
        printf("3. Mostrar productos\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        switch(opcion) {
            case 1:
                printf("Ingrese el número de productos: ");
                scanf("%d", &numProductos);
                getchar();  // Limpiar el buffer

                for (int i = 0; i < numProductos; i++) {
                    printf("\nProducto #%d\n", i + 1);
                    printf("ID: ");
                    scanf("%d", &productos[i].id);
                    getchar();
                    printf("Nombre: ");
                    fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);
                    productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0'; // Eliminar salto de línea
                    printf("Precio: ");
                    scanf("%f", &productos[i].precio);
                }

                escribirCSV("productos.csv", productos, numProductos);
                break;
            case 2:
                numProductos = leerCSV("productos.csv", productos, MAX_PRODUCTOS);
                printf("Datos leídos desde el archivo CSV: %d productos encontrados.\n", numProductos);
                break;
            case 3:
                mostrarProductos(productos, numProductos);
                break;
            case 4:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 4);

    return 0;
}
