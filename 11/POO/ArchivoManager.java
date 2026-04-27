import java.io.*;
import java.util.*;

public class ArchivoManager {
    public static void escribirCSV(String ruta, List<String[]> datos) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(ruta))) {
            for (String[] fila : datos) {
                writer.println(String.join(",", fila));
            }
            System.out.println("Archivo guardado en: " + ruta);
        } catch (IOException e) {
            System.out.println("Error al escribir el archivo: " + e.getMessage());
        }
    }

    public static List<String[]> leerCSV(String ruta) {
        List<String[]> datos = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(ruta))) {
            String linea;
            while ((linea = reader.readLine()) != null) {
                String[] fila = linea.split(",");
                datos.add(fila);
            }
            System.out.println("Archivo leído correctamente.");
        } catch (IOException e) {
            System.out.println("Error al leer el archivo: " + e.getMessage());
        }
        return datos;
    }
}
