Dia 19: Linen Layout

   - Elección del problema: 

Hemos elegido este problema ya que en el se puede observar fácilmente el funcionamiento y la utilidad de una tabla Hash

   - Estructura de datos empleada: Tablas Hash y Programación Dinámica 

El algoritmo se basa en una tabla hash que:

1. Almacena los fragmentos disponibles:
   - Cada fragmento es una clave de la tabla hash, lo que facilita su búsqueda inmediata.
2. Permite búsquedas rápidas:
   - Para cada fragmento de un diseño, se verifica rápidamente si está en la tabla.

 - Ventajas de las tablas hash:

- Eficiencia:
  - Las operaciones de búsqueda, inserción y eliminación se realizan en tiempo constante promedio.
- Facilidad de implementación:
  - Se puede manejar un conjunto dinámico de datos sin necesidad de reordenamientos.
- Versatilidad:
  - La tabla se puede ampliar fácilmente para incluir nuevas funcionalidades, como el almacenamiento de valores adicionales asociados a cada clave.

   - Resolución del problema

El problema se aborda en los siguientes pasos:

1. Lectura de datos:
   - El programa lee dos listas:
     - Fragmentos disponibles: Se almacenan en la tabla hash.
     - Diseños objetivo: Se almacenan en un vector para su procesamiento.

2. Almacenamiento en la tabla hash:
   - Los fragmentos disponibles se insertan como claves en la tabla hash utilizando la función "fill_table".

3. Verificación de patrones:
   - Para cada diseño en la lista de diseños objetivo, se utiliza una función recursiva con una memoria auxiliar (vector de enteros) para determinar si el diseño puede construirse:
     - Se intentan todas las posibles divisiones del diseño en fragmentos.
     - Si un fragmento está en la tabla hash y el resto del diseño también puede construirse, el diseño es válido.

4. Uso de programación dinámica:
   - Se utiliza un vector de memoria para evitar recalcular resultados en subproblemas ya resueltos, optimizando el tiempo de ejecución.

5. Resultado final:
   - Se cuenta el número total de patrones que pueden construirse y se muestra al usuario.
