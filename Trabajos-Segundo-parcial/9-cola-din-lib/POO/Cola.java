import java.util.LinkedList;
import java.util.Queue;

public class Cola {
    private Queue<Integer> cola;

    public Cola() {
        cola = new LinkedList<>();
    }

    public void encolar(int elemento) {
        cola.add(elemento);
        System.out.println("Elemento " + elemento + " encolado.");
    }

    public void desencolar() {
        if (!cola.isEmpty()) {
            int elemento = cola.poll();
            System.out.println("Elemento " + elemento + " desencolado.");
        } else {
            System.out.println("La cola está vacía.");
        }
    }

    public void mostrarCola() {
        System.out.println("Contenido de la cola: " + cola);
    }

    public boolean estaVacia() {
        return cola.isEmpty();
    }
}
