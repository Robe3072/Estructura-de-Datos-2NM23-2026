import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Pila miPila = new Pila();
        Scanner sc = new Scanner(System.in);
        int opcion;

        do {
            utilidades.imprimirLinea();
            System.out.println("1. Apilar");
            System.out.println("2. Desapilar");
            System.out.println("3. Mostrar pila");
            System.out.println("4. Salir");
            System.out.print("Elige una opción: ");
            opcion = sc.nextInt();

            switch (opcion) {
                case 1:
                    System.out.print("Introduce un número: ");
                    int numero = sc.nextInt();
                    miPila.apilar(numero);
                    break;
                case 2:
                    miPila.desapilar();
                    break;
                case 3:
                    miPila.mostrarPila();
                    break;
                case 4:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción no válida.");
            }
        } while (opcion != 4);

        sc.close();
    }
}
