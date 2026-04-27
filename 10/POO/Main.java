import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Lista miLista = new Lista();
        Scanner sc = new Scanner(System.in);
        int opcion;

        do {
            Utilidades.imprimirLinea();
            System.out.println("1. Agregar arreglo al final");
            System.out.println("2. Eliminar arreglo por índice");
            System.out.println("3. Insertar arreglo en una posición");
            System.out.println("4. Mostrar lista");
            System.out.println("5. Salir");
            System.out.print("Elige una opción: ");
            opcion = sc.nextInt();
            sc.nextLine(); // limpiar buffer

            switch (opcion) {
                case 1:
                    System.out.println("Introduce los elementos (máximo 10), separados por espacios:");
                    String linea1 = sc.nextLine();
                    String[] arreglo1 = linea1.trim().split("\\s+");
                    miLista.agregarElemento(arreglo1);
                    break;
                case 2:
                    System.out.print("Introduce el índice del arreglo a eliminar: ");
                    int indiceEliminar = sc.nextInt();
                    miLista.eliminarElemento(indiceEliminar);
                    break;
                case 3:
                    System.out.print("Introduce el índice donde insertar: ");
                    int indiceInsertar = sc.nextInt();
                    sc.nextLine(); // limpiar buffer
                    System.out.println("Introduce los elementos (máximo 10), separados por espacios:");
                    String linea3 = sc.nextLine();
                    String[] arreglo3 = linea3.trim().split("\\s+");
                    miLista.insertarEnPosicion(indiceInsertar, arreglo3);
                    break;
                case 4:
                    miLista.mostrarLista();
                    break;
                case 5:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción no válida.");
            }

        } while (opcion != 5);

        sc.close();
    }
}
