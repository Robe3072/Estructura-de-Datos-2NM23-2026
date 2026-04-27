import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Lista {
    private List<String[]> lista;

    public Lista() {
        lista = new ArrayList<>();
    }

    public void agregar(String[] arreglo) {
        lista.add(arreglo);
        System.out.println("Agregado: " + Arrays.toString(arreglo));
    }

    public void mostrar() {
        System.out.println("Contenido de la lista:");
        for (int i = 0; i < lista.size(); i++) {
            System.out.println("[" + i + "]: " + Arrays.toString(lista.get(i)));
        }
    }

    public List<String[]> obtenerTodo() {
        return lista;
    }

    public void cargarDesdeLista(List<String[]> otraLista) {
        lista.clear();
        lista.addAll(otraLista);
    }
}
