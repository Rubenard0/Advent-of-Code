Dia 11: Plutonian Pebbles

   - Elección del problema

El problema fue seleccionado porque ilustra un caso práctico donde las transformaciones de datos dependen de sus estados previos. Esto es típico en problemas que requieren optimización secuencial, simulaciones y procesamiento iterativo, los cuales se benefician de un enfoque eficiente como el que ofrece la Programación Dinámica.

   - Técnica empleada: Programación Dinámica

La técnica de Programación Dinámica se utiliza aquí para:

1. Evitar cálculos repetidos
   - Las transformaciones de las piedras dependen de su valor y estructura numérica, lo que puede llevar a operaciones redundantes. Al reutilizar resultados de subproblemas previos, el algoritmo optimiza el tiempo de ejecución.
   
2. Resolver subproblemas interdependientes
   - Cada piedra se transforma basándose en reglas que dependen de su valor actual. Las transformaciones acumulativas se gestionan eficientemente mediante un enfoque iterativo.

3. Recursividad con memorización implícita
   - Aunque el algoritmo se presenta como recursivo, los resultados de transformaciones previas se aplican directamente a las piedras, optimizando el proceso.

   - Ventajas:
- Reducción del tiempo de ejecución Evita cálculos redundantes en cada iteración.
- Eficiencia en memoria Solo se almacenan los datos necesarios en cada paso.
- Escalabilidad Maneja listas dinámicas de manera eficiente.

 - Resolución del problema

El problema se aborda en los siguientes pasos:

1. Lectura de datos:
   - El usuario introduce una lista de números que representan piedras. Los valores se almacenan en una lista para facilitar las operaciones dinámicas.

2. Transformaciones iterativas:
   - Durante cada parpadeo (hasta un máximo definido por "blinks"), las piedras se transforman siguiendo estas reglas:
     1. Si una piedra es 0, se transforma en 1.
     2. Si el número de cifras del valor de la piedra es par se divide en dos mitades:
        - La parte superior se inserta como una nueva piedra.
        - La parte inferior reemplaza el valor original.
     3. Si el número de cifras es impar el valor se multiplica por 2024.

3. Resolución recursiva:
   - La función "blink" aplica las reglas a todas las piedras de la lista y llama recursivamente a sí misma para los parpadeos restantes. Este enfoque aprovecha los estados intermedios acumulados en cada iteración.

4. Resultado final:
   - Al completar el número de parpadeos, el programa devuelve el número total de piedras resultantes.
