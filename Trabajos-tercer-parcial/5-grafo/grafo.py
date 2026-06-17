import json
from collections import defaultdict

class BaseGrafo:
    def __init__(self, dirigido=False):
        self.conexiones = defaultdict(list)
        self.dirigido = dirigido
        self.rutas_nombradas = {}  # {(A, B): "a", ...}
        self.contador_rutas = 0

    def _generar_nombre_ruta(self):
        # Convierte el número a letras: a, b, c, ..., z, aa, ab...
        n = self.contador_rutas
        nombre = ""
        while True:
            nombre = chr(97 + (n % 26)) + nombre
            n = n // 26 - 1
            if n < 0:
                break
        self.contador_rutas += 1
        return nombre

    def agregar_conexion(self, nodo_a, nodo_b):
        if nodo_b not in self.conexiones[nodo_a]:
            self.conexiones[nodo_a].append(nodo_b)
            nombre_ruta = self._generar_nombre_ruta()
            self.rutas_nombradas[(nodo_a, nodo_b)] = nombre_ruta
        if not self.dirigido and nodo_a not in self.conexiones[nodo_b]:
            self.conexiones[nodo_b].append(nodo_a)
            self.rutas_nombradas[(nodo_b, nodo_a)] = self.rutas_nombradas[(nodo_a, nodo_b)]

    def _buscar_rutas(self, actual, fin, visitados, ruta, rutas):
        visitados.add(actual)
        ruta.append(actual)

        if actual == fin:
            rutas.append(list(ruta))
        else:
            for camino in self.conexiones[actual]:
                if camino not in visitados:
                    self._buscar_rutas(camino, fin, visitados, ruta, rutas)

        ruta.pop()
        visitados.remove(actual)

    def obtener_rutas(self, inicio, fin):
        rutas = []
        self._buscar_rutas(inicio, fin, set(), [], rutas)
        return rutas

    def rutas_entre_todos(self):
        nodos = set(self.conexiones.keys())
        for caminos in self.conexiones.values():
            nodos.update(caminos)

        rutas_todas = {}
        nodos = sorted(nodos)

        for i in range(len(nodos)):
            for j in range(len(nodos)):
                if i != j:
                    a, b = nodos[i], nodos[j]
                    rutas = self.obtener_rutas(a, b)
                    if rutas:
                        rutas_todas[(a, b)] = rutas
        return rutas_todas

    def mostrar_conexiones(self):
        print("\nConexiones del grafo:")
        for nodo in self.conexiones:
            simbolo = "→" if self.dirigido else "↔"
            for camino in self.conexiones[nodo]:
                nombre = self.rutas_nombradas.get((nodo, camino), "?")
                print(f"{nodo} {simbolo} {camino}  (Ruta: {nombre})")

    def exportar_a_json(self, nombre_archivo="grafo.json"):
        nodos = list(set(self.conexiones.keys()) | {v for caminos in self.conexiones.values() for v in caminos})
        conexiones = [
            {"origen": origen, "destino": destino, "nombre": nombre}
            for (origen, destino), nombre in self.rutas_nombradas.items()
        ]
        data = {
            "dirigido": self.dirigido,
            "nodos": nodos,
            "rutas": conexiones
        }
        with open(nombre_archivo, "w") as f:
            json.dump(data, f, indent=4)
        print(f"Grafo exportado como '{nombre_archivo}'")

# -------------------- MENÚ INTERACTIVO --------------------

def menu():
    tipo = input("¿Deseas crear un grafo dirigido (d) o no dirigido (n)? [d/n]: ").lower()
    dirigido = True if tipo == 'd' else False
    grafo = BaseGrafo(dirigido)

    while True:
        print("\n--- MENÚ ---")
        print("1. Agregar conexión")
        print("2. Mostrar conexiones")
        print("3. Ver rutas entre dos nodos")
        print("4. Ver todas las rutas")
        print("5. Exportar grafo a JSON")
        print("6. Salir")

        opcion = input("Selecciona una opción: ")

        if opcion == '1':
            nodo1 = input("Nodo origen: ").strip()
            nodo2 = input("Nodo destino: ").strip()
            grafo.agregar_conexion(nodo1, nodo2)
            print(f"Conexión añadida: {nodo1} {'→' if dirigido else '↔'} {nodo2}")

        elif opcion == '2':
            grafo.mostrar_conexiones()

        elif opcion == '3':
            origen = input("Nodo origen: ").strip()
            destino = input("Nodo destino: ").strip()
            rutas = grafo.obtener_rutas(origen, destino)
            if rutas:
                print(f"\nTodas las rutas de {origen} a {destino}:")
                for ruta in rutas:
                    print(" → ".join(ruta))

        # Encontrar rutas más rápidas (las más cortas)
            longitud_min = min(len(r) for r in rutas)
            rutas_mas_rapidas = [r for r in rutas if len(r) == longitud_min]

            print(f"\nRuta(s) más rápida(s) de {origen} a {destino}:")
            for ruta in rutas_mas_rapidas:
                print(" → ".join(ruta))
            else:
                print("No hay rutas entre esos nodos.")


        elif opcion == '4':
            rutas_todas = grafo.rutas_entre_todos()
            for (inicio, fin), caminos in rutas_todas.items():
                print(f"\nRutas de {inicio} a {fin}:")
                for ruta in caminos:
                    print(" → ".join(ruta))
            if not rutas_todas:
                print("No hay rutas disponibles entre nodos.")

        elif opcion == '5':
            nombre_archivo = input("Nombre del archivo JSON (por defecto: grafo.json): ").strip()
            if not nombre_archivo:
                nombre_archivo = "grafo.json"
            grafo.exportar_a_json(nombre_archivo)

        elif opcion == '6':
            print("Saliendo del programa.")
            break
        else:
            print("Opción inválida. Intenta de nuevo.")

# Ejecutar el menú
if __name__ == "__main__":
    menu()
