Dia 7: Bridge Repair

   - Elección del problema

Hemos elegido este problema ya que demuestra como la estructura de Arboles puede ser útil en escenarios donde se busca un resultado especifico a partir de decisiones binarias (en este caso, suma o multiplicación)

   - Estructura de datos empleada: Árbol Binario

Se ha utilizado un árbol binario para representar todas las posibles combinaciones de operaciones aritméticas que se pueden realizar en una lista de números. Cada nodo del árbol almacena un valor intermedio y tiene dos hijos:

1. Hijo izquierdo: Representa el resultado de sumar el número actual al valor acumulado.

2. Hijo derecho: Representa el resultado de multiplicar el número actual por el valor acumulado.

Esta estructura permite explorar todas las posibles combinaciones de operaciones mediante un recorrido del árbol.

 - Resolución del problema

1. Lectura de la Entrada:
   -Se procesa cada línea para extraer el objetivo y la lista de números.

2. Construcción del Árbol:
   -Utilizando la función buildTree, se construye un árbol binario donde cada nodo representa un valor intermedio calculado mediante suma o multiplicación.
   -La raíz del árbol se inicializa con el primer número, y las operaciones se aplican recursivamente a los siguientes números.

3. Búsqueda en el Árbol:
   -La función searchTree recorre el árbol para determinar si existe una hoja cuyo valor sea igual al objetivo.
   -Si se encuentra una hoja con el valor objetivo, se considera que la combinación de operaciones es válida.

4. Acumulación del Resultado:
   -Si el objetivo es alcanzable para una línea dada, se suma al total acumulado.

5. Liberación de Memoria:
   -Una vez completada la búsqueda, el árbol se libera mediante la función freeTree para evitar fugas de memoria.
