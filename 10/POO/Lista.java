import java.util.ArrayList;
import java.util.Arrays;

public class Lista {
    private ArrayList<String[]> lista;

    public Lista() {
        lista = new ArrayList<>();
    }

    public void agregarElemento(String[] arreglo) {
        if (arreglo.length <= 10) {
            lista.add(arreglo);
            System.out.println("Arreglo agregado: " + Arrays.toString(arreglo));
        } else {
            System.out.println("Error: El arreglo tiene más de 10 elementos.");
        }
    }

    public void eliminarElemento(int indice) {
        if (indice >= 0 && indice < lista.size()) {
            String[] eliminado = lista.remove(indice);
            System.out.println("Arreglo eliminado: " + Arrays.toString(eliminado));
        } else {
            System.out.println("Índice fuera de rango.");
        }
    }

    public void insertarEnPosicion(int indice, String[] arreglo) {
        if (arreglo.length <= 10) {
            if (indice >= 0 && indice <= lista.size()) {
                lista.add(indice, arreglo);
                System.out.println("Arreglo insertado en posición " + indice + ": " + Arrays.toString(arreglo));
            } else {
                System.out.println("Índice fuera de rango.");
            }
        } else {
            System.out.println("Error: El arreglo tiene más de 10 elementos.");
        }
    }

    public void mostrarLista() {
        System.out.println("Contenido de la lista:");
        for (int i = 0; i < lista.size(); i++) {
            System.out.println("[" + i + "] " + Arrays.toString(lista.get(i)));
        }
    }

    public boolean estaVacia() {
        return lista.isEmpty();
    }
}
