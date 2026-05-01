import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Cola miCola = new Cola(); 
        Scanner sc = new Scanner(System.in);
        int opcion;

        do {
            Utilidades.imprimirLinea();
            System.out.println("1. Encolar");
            System.out.println("2. Desencolar");
            System.out.println("3. Mostrar cola");
            System.out.println("4. Salir");
            System.out.print("Elige una opción: ");
            
            // Validación básica por si el usuario mete algo que no sea número
            while (!sc.hasNextInt()) {
                System.out.print("Por favor, introduce un número válido: ");
                sc.next(); // consumir entrada inválida
            }
            opcion = sc.nextInt();

            switch (opcion) {
                case 1:
                    System.out.print("Introduce un número: ");
                    while (!sc.hasNextInt()) {
                        System.out.print("Por favor, introduce un número válido: ");
                        sc.next();
                    }
                    int numero = sc.nextInt();
                    miCola.encolar(numero);
                    break;
                case 2:
                    miCola.desencolar();
                    break;
                case 3:
                    miCola.mostrarCola();
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
