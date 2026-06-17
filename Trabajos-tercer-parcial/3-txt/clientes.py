from escritura import guardar_clientes_en_txt
# CLASE QUE REPRESENTA A UN CLIENTE CON SUS ATRIBUTOS BASICOS
class Cliente:
    def __init__(self, nombre, edad, prioridad):
        self.nombre = nombre
        self.edad = int(edad)
        self.prioridad = prioridad

    def __str__(self):
        return f"{self.nombre}, {self.edad} ANOS, PRIORIDAD: {self.prioridad}"

# CLASE CONTENEDORA PARA MANEJAR MULTIPLES CLIENTES
class ArregloClientes:
    def __init__(self):
        self.lista = []

    def agregar_cliente(self, cliente):
        self.lista.append(cliente)

    def obtener_todos(self):
        return self.lista

# IMPLEMENTACION DE UNA COLA (FIFO)
class Cola:
    def __init__(self):
        self.elementos = []

    def encolar(self, cliente):
        self.elementos.append(cliente)

    def desencolar(self):
        if not self.esta_vacia():
            return self.elementos.pop(0)

    def esta_vacia(self):
        return len(self.elementos) == 0

    def mostrar(self):
        for c in self.elementos:
            print(c)

    def obtener_todos(self):
        return self.elementos

# FUNCION PARA LEER CLIENTES DESDE UN ARCHIVO .TXT
def leer_clientes_desde_txt(ruta_entrada):
    arreglo = ArregloClientes()
    with open(ruta_entrada, 'r', encoding='utf-8') as archivo:
        for linea in archivo:
            # SEPARAR CADA CAMPO POR COMAS Y ELIMINAR ESPACIOS Y SALTOS DE LINEA
            partes = linea.strip().split(',')
            if len(partes) == 3:
                nombre, edad, prioridad = partes
                cliente = Cliente(nombre.strip(), edad.strip(), prioridad.strip())
                arreglo.agregar_cliente(cliente)
    return arreglo

# FUNCION PRINCIPAL QUE LEE, FILTRA Y GUARDA CLIENTES PRIORIDAD ALTA
def procesar_clientes_txt(ruta_entrada, ruta_salida):
    arreglo = leer_clientes_desde_txt(ruta_entrada)
    cola_prioridad = Cola()

    # FILTRAR CLIENTES CON PRIORIDAD ALTA Y ENCOLARLOS
    for cliente in arreglo.obtener_todos():
        if cliente.prioridad.upper() == "ALTA":
            cola_prioridad.encolar(cliente)

    print("CLIENTES CON PRIORIDAD ALTA:")
    cola_prioridad.mostrar()

    # GUARDAR CLIENTES FILTRADOS EN ARCHIVO TXT DE SALIDA
    guardar_clientes_en_txt(cola_prioridad.obtener_todos(), ruta_salida)

# EJECUTAR EL PROCESO CON LOS ARCHIVOS TXT
procesar_clientes_txt('clientes.txt', 'prioridad_alta.txt')
