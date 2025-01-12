Dia 10: Hoof It

   - Elección del problema: 

Hemos seleccionado este problema ya que pese a poder hacerse únicamente con recursividad, al usar una estructura formada por Grafos se puede realizar un código mucho mas optimo.

   -Estructura de datos empleada: Grafos

El mapa se modela como un grafo, donde:
- Cada celda es un nodo
- Las conexiones (aristas entre nodos dependen de la regla de diferencia de valor igual a 1.

   - Resolución con grafos:
1. Parte 1:
   - Un recorrido en amplitud (BFS) se utiliza para explorar el grafo desde cada celda inicial con valor 0.
   - Cada nodo alcanzado con valor 9 se agrega a un conjunto, evitando duplicados.
   - El tamaño del conjunto al final del recorrido indica la cantidad de "9" alcanzables.

2. Parte 2:
   - Se utiliza un recorrido en profundidad (DFS) con memorización para contar los caminos distintos desde cada celda inicial con valor 0 hasta las celdas con valor 9.
   - Una tabla de memoria evita recalcular resultados para los mismos estados, optimizando el tiempo de ejecución.

   - Ventajas del enfoque basado en grafos:

1. Flexibilidad:
  - Permite modelar cualquier relación entre celdas, más allá de las restricciones actuales.

2. Eficiencia:
  - El uso de BFS y DFS garantiza una exploración sistemática y evita redundancias mediante el uso de conjuntos y memorización.

3. Generalización:
  - El modelo puede adaptarse fácilmente para incluir nuevas reglas de conexión o restricciones.


   - Resolución del problema

1. Lectura de datos:
   -El programa recibe un archivo de texto que contiene el mapa, donde:
     - Cada línea representa una fila de la matriz.
     - Cada carácter en una línea representa el valor de una celda.

2. Carga del mapa:
   - El archivo de entrada se lee y convierte en una matriz de enteros.
   - Se validan las dimensiones y el contenido del archivo.

3. Cálculo del puntaje total (Parte 1):
   - Se utiliza BFS desde cada celda con valor 0 para contar las celdas con valor 9 alcanzables.

4. Cálculo de la calificación total (Parte 2):
   - Se utiliza DFS con memorización para contar los caminos distintos desde cada celda con valor 0.

5. Impresión de resultados:
   - Se muestra el puntaje y la calificación totales.
