Dia 1: Historian Hysteria

 - Elección del problema

Se ha seleccionado este problema porque se pueden aplicar fácilmente las técnicas de Divide y Vencerás.

 - Técnica empleada: 

Para este problema usamos la técnica de Divide y Vencerás para las siguientes funciones:

1. Quick Sort: 
   - Se divide la lista en dos sublistas según un pivote y se ordenan de forma recursiva.
   - Combina las sublistas ordenadas para obtener el resultado final.

2. Binary Search:
   - Divide repetidamente el espacio de búsqueda en mitades para localizar elementos de manera eficiente.

- Resolución del problema

El problema se resuelve siguiendo los siguientes pasos:

1. Lectura de datos:
   - Se utilizan dos listas de números introducidas por el usuario. Cada lista se almacena en un vector.

2. Ordenación:
   - Las listas se ordenan utilizando el algoritmo Quick Sort en orden ascendente.

3. Cálculo de la distancia entre listas:
   - Se calcula la suma de las diferencias absolutas entre los elementos correspondientes de las dos listas.

4. Búsqueda de elementos similares:
   - Se emplea la búsqueda binaria para localizar elementos en una lista de forma eficiente.
   - Una vez localizado un elemento, se cuenta cuántas veces aparece en posiciones adyacentes.

5. Cálculo del puntaje de similitud
   - Se calcula un puntaje de similitud multiplicando los valores de una lista por la cantidad de ocurrencias de esos valores en la otra lista.

6. Visualización de resultados:
   - El programa muestra las listas originales, las listas ordenadas, la distancia entre listas y el puntaje de similitud.
