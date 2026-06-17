import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ListaEnlazada<Integer> lista = new ListaEnlazada<>();
        Scanner scanner = new Scanner(System.in);
        int opcion;
        int dato;

        while (true) {
            mostrarMenu();
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    System.out.print("Introduce el dato a agregar: ");
                    dato = scanner.nextInt();
                    lista.agregar(dato);
                    break;
                case 2:
                    lista.eliminarTodos();
                    System.out.println("Todos los datos han sido eliminados.");
                    break;
                case 3:
                    System.out.print("Introduce el dato a eliminar: ");
                    dato = scanner.nextInt();
                    if (lista.eliminar(dato)) {
                        System.out.println("Dato eliminado.");
                    } else {
                        System.out.println("Dato no encontrado.");
                    }
                    break;
                case 4:
                    if (!lista.estaVacia()) {
                        System.out.println("Datos en la lista:");
                        lista.mostrarDatos();
                    } else {
                        System.out.println("La lista está vacía.");
                    }
                    break;
                case 5:
                    System.out.println("Saliendo del programa.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Opción no válida. Por favor, seleccione una opción válida.");
            }
        }
    }

    private static void mostrarMenu() {
        System.out.println("\nMenú:");
        System.out.println("1. Agregar dato");
        System.out.println("2. Eliminar todos los datos");
        System.out.println("3. Eliminar un dato");
        System.out.println("4. Mostrar datos");
        System.out.println("5. Salir");
        System.out.print("Seleccione una opción: ");
    }
}