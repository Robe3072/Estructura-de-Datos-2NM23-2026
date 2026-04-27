import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Lista miLista = new Lista();
        Scanner sc = new Scanner(System.in);
        int opcion;
        String ruta = "datos.csv";

        do {
            System.out.println("1. Agregar arreglo");
            System.out.println("2. Mostrar lista");
            System.out.println("3. Guardar en archivo CSV");
            System.out.println("4. Leer desde archivo CSV");
            System.out.println("5. Salir");
            System.out.print("Elige una opción: ");
            opcion = sc.nextInt();
            sc.nextLine(); // limpiar buffer

            switch (opcion) {
                case 1:
                    System.out.println("Introduce elementos separados por espacios (máximo 10):");
                    String entrada = sc.nextLine();
                    String[] arreglo = entrada.trim().split("\\s+");
                    if (arreglo.length <= 10) {
                        miLista.agregar(arreglo);
                    } else {
                        System.out.println("Error: más de 10 elementos.");
                    }
                    break;
                case 2:
                    miLista.mostrar();
                    break;
                case 3:
                    ArchivoManager.escribirCSV(ruta, miLista.obtenerTodo());
                    break;
                case 4:
                    miLista.cargarDesdeLista(ArchivoManager.leerCSV(ruta));
                    break;
                case 5:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción inválida.");
            }

        } while (opcion != 5);

        sc.close();
    }
}
