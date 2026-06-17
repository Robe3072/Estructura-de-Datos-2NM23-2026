import json
from collections import deque
# CLASE CLIENTE
class Cliente:
    def __init__(self, nombre, edad, prioridad, cuota):
        self.nombre = nombre
        self.edad = edad
        self.prioridad = prioridad
        self.cuota = cuota

    def to_dict(self):
        return {
            "nombre": self.nombre,
            "edad": self.edad,
            "prioridad": self.prioridad,
            "cuota": self.cuota 
        }

    def mostrar(self):
        print(f"{self.nombre}, {self.edad} ANOS, PRIORIDAD: {self.prioridad} (CUOTA: ${self.cuota:.2f})")

# FUNCION PARA LEER CLIENTES DESDE JSON
def leer_clientes_desde_json(nombre_archivo):
    clientes = []
    try:
        with open(nombre_archivo, "r") as archivo:
            datos = json.load(archivo)
            for item in datos:
                cliente = Cliente(item["nombre"], item["edad"], item["prioridad"], item.get("cuota", 0.0))
                clientes.append(cliente)
    except FileNotFoundError:
        print("ARCHIVO NO ENCONTRADO.")
    except json.JSONDecodeError:
        print("ERROR DE FORMATO JSON.")
    return clientes

# FUNCION PARA GUARDAR CLIENTES EN JSON
def guardar_clientes_en_json(clientes, nombre_archivo):
    datos = [cliente.to_dict() for cliente in clientes]
    with open(nombre_archivo, "w") as archivo:
        json.dump(datos, archivo, indent=4)
    print(f"ARCHIVO GUARDADO COMO '{nombre_archivo}'")

# FUNCIONES DE MENU (MOSTRAR, AGREGAR, EDITAR, ETC.) IGUAL QUE ANTES

def mostrar_clientes(clientes):
    for idx, cliente in enumerate(clientes, 1):
        print(f"{idx}. ", end="")
        cliente.mostrar()

def agregar_cliente(clientes):
    print("\n--- AGREGAR CLIENTE ---")
    nombre = input("NOMBRE: ")
    edad = int(input("EDAD: "))
    prioridad = input("PRIORIDAD (Alta/Media/Baja): ")
    cuota_input = float (input("CUOTA A PAGAR: "))
    clientes.append(Cliente(nombre, edad, prioridad, cuota_input))
    print("CLIENTE AGREGADO.")

def editar_cliente(clientes):
    mostrar_clientes(clientes)
    try:
        indice = int(input("NUMERO DEL CLIENTE A EDITAR: ")) - 1
        if 0 <= indice < len(clientes):
            c = clientes[indice]
            print(f"EDITANDO A {c.nombre}")
            c.nombre = input("NUEVO NOMBRE: ") or c.nombre
            edad_input = input("NUEVA EDAD: ")
            if edad_input:
                c.edad = int(edad_input)
            c.prioridad = input("NUEVA PRIORIDAD: ") or c.prioridad
            print("CLIENTE EDITADO.")
            cuota_input = input("NUEVA CUOTA A PAGAR: ")
            if cuota_input:
                c.cuota = float(cuota_input)
                print(f"CUOTA ACTUALIZADA A ${c.cuota:.2f}.")
        else:
            print("INDICE INVALIDO.")
    except ValueError:
        print("ENTRADA INVALIDA.")

def eliminar_cliente(clientes):
    mostrar_clientes(clientes)
    try:
        indice = int(input("NUMERO DEL CLIENTE A ELIMINAR: ")) - 1
        if 0 <= indice < len(clientes):
            eliminado = clientes.pop(indice)
            print(f"CLIENTE '{eliminado.nombre}' ELIMINADO.")
        else:
            print("INDICE INVALIDO.")
    except ValueError:
        print("ENTRADA INVALIDA.")

def ingresar_clientes_manual():
    clientes = []
    print("\n--- INGRESAR CLIENTES MANUALMENTE ---")
    while True:
        nombre = input("NOMBRE: ")
        edad = int(input("EDAD: "))
        prioridad = input("PRIORIDAD (Alta/Media/Baja): ")
        cuota_input = float(input("CUOTA A PAGAR: "))
        clientes.append(Cliente(nombre, edad, prioridad, cuota_input))
        continuar = input("DESEAS INGRESAR OTRO CLIENTE? (S/N): ").strip().upper()
        if continuar != 'S':
            break
    return clientes

# MENU PRINCIPAL 
def menu_principal(clientes, archivo_origen):
    while True:
        print("\n====== MENU PRINCIPAL ======")
        print("1. DATOS SIMPLES (PRIMER CLIENTE)")
        print("2. ARREGLOS (TODOS LOS CLIENTES)")
        print("3. ADT COLA (PRIORIDAD ALTA)")
        print("4. AGREGAR CLIENTE")
        print("5. EDITAR CLIENTE")
        print("6. ELIMINAR CLIENTE")
        print("7. GUARDAR CAMBIOS")
        print("8. SALIR")

        opcion = input("SELECCIONA UNA OPCION: ")

        if opcion == "1":
            if clientes:
                print("\n--- PRIMER CLIENTE ---")
                clientes[0].mostrar()
            else:
                print("NO HAY CLIENTES.")

        elif opcion == "2":
            print("\n--- TODOS LOS CLIENTES ---")
            mostrar_clientes(clientes)

        elif opcion == "3":
            print("\n--- CLIENTES CON PRIORIDAD ALTA ---")
            cola = deque()
            for c in clientes:
                if c.prioridad.lower() == "alta":
                    cola.append(c)
            if cola:
                while cola:
                    cliente = cola.popleft()
                    cliente.mostrar()
            else:
                print("NO HAY CLIENTES CON PRIORIDAD ALTA.")

        elif opcion == "4":
            agregar_cliente(clientes)

        elif opcion == "5":
            editar_cliente(clientes)

        elif opcion == "6":
            eliminar_cliente(clientes)

        elif opcion == "7":
            nombre_salida = input("NOMBRE DEL ARCHIVO PARA GUARDAR (ENTER PARA USAR ORIGINAL): ")
            if not nombre_salida.strip():
                nombre_salida = archivo_origen
            guardar_clientes_en_json(clientes, nombre_salida)
            
        elif opcion == "8":
            print("SALIENDO DEL PROGRAMA...")
            break

        else:
            print("OPCION INVALIDA.")

# FUNCION PRINCIPAL
def main():
    print("DESEAS CARGAR CLIENTES DESDE ARCHIVO O INGRESARLOS MANUALMENTE?")
    print("1. CARGAR DESDE ARCHIVO JSON")
    print("2. INGRESAR MANUALMENTE")
    opcion = input("SELECCIONA UNA OPCION (1/2): ")

    if opcion == "1":
        archivo = input("NOMBRE DEL ARCHIVO JSON DE ENTRADA: ")
        clientes = leer_clientes_desde_json(archivo)
    elif opcion == "2":
        clientes = ingresar_clientes_manual()
        archivo = input("NOMBRE DEL ARCHIVO PARA GUARDAR ESTOS DATOS: ")
        guardar_clientes_en_json(clientes, archivo)
    else:
        print("OPCION NO VALIDA.")
        return

    menu_principal(clientes, archivo)

# INICIO DEL PROGRAMA
if __name__ == "__main__":
    main()