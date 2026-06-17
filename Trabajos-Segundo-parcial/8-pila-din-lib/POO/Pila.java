import java.util.Stack;

public class Pila {
    private Stack<Integer> pila;

    public Pila() {
        pila = new Stack<>();
    }

    public void apilar(int elemento) {
        pila.push(elemento);
        System.out.println("Elemento " + elemento + " apilado.");
    }

    public void desapilar() {
        if (!pila.isEmpty()) {
            int elemento = pila.pop();
            System.out.println("Elemento " + elemento + " desapilado.");
        } else {
            System.out.println("La pila está vacía.");
        }
    }

    public void mostrarPila() {
        System.out.println("Contenido de la pila: " + pila);
    }

    public boolean estaVacia() {
        return pila.isEmpty();
    }
}
