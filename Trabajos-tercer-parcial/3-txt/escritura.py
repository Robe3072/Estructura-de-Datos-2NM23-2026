def guardar_clientes_en_txt(clientes, ruta_salida):
    with open(ruta_salida, 'w', encoding='utf-8') as archivo:
        for cliente in clientes:
            archivo.write(f"{cliente.nombre},{cliente.edad},{cliente.prioridad}\n")