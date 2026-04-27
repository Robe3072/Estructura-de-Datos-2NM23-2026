public class ListaEnlazada<T> {
    private Nodo<T> cabeza;

    public ListaEnlazada() {
        this.cabeza = null;
    }

    // Agregar un dato al final de la lista
    public void agregar(T dato) {
        Nodo<T> nuevoNodo = new Nodo<>(dato);
        if (cabeza == null) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T> actual = cabeza;
            while (actual.getSiguiente() != null) {
                actual = actual.getSiguiente();
            }
            actual.setSiguiente(nuevoNodo);
        }
    }

    // Eliminar todos los datos de la lista
    public void eliminarTodos() {
        cabeza = null;
    }

    // Eliminar un dato específico de la lista
    public boolean eliminar(T dato) {
        if (cabeza == null) {
            return false;
        }
        if (cabeza.getDato().equals(dato)) {
            cabeza = cabeza.getSiguiente();
            return true;
        }
        Nodo<T> actual = cabeza;
        while (actual.getSiguiente() != null && !actual.getSiguiente().getDato().equals(dato)) {
            actual = actual.getSiguiente();
        }
        if (actual.getSiguiente() == null) {
            return false;
        }
        actual.setSiguiente(actual.getSiguiente().getSiguiente());
        return true;
    }

    // Mostrar todos los datos de la lista
    public void mostrarDatos() {
        Nodo<T> actual = cabeza;
        while (actual != null) {
            System.out.println(actual.getDato());
            actual = actual.getSiguiente();
        }
    }

    // Verificar si la lista está vacía
    public boolean estaVacia() {
        return cabeza == null;
    }
}