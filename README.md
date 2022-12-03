# EstructuraDatos2
## El problema de las 8 reinas

El problema de las ocho reinas es un dilema basado en el juego de ajedrez y la pieza de la reina, la cual se puede desplazar horizontalmente, verticalmente o diagonalmente tantas casillas como se desee. El ejercicio consiste en colocar 8 reinas en el tablero sin que se amenacen entre ellas. 

--------------------

> Existen 8C64 Posibles combinaciones de 8 reinas en un tablero de 64 casillas
>
> 8C64 =  64! / (8!56!) = 4,426,165,368

En nuestro algoritmo de fuerza bruta se utiliza la regla que elige solo una reina por fila

> Existen 8^8 posibles combinaciones de reinas sin tener 2 en la misma fila
>
> 8^8 = 16,777,216

------------------

La forma en que queremos resolver este problema es utilizando 2 diferentes algoritmos, uno en el que utilizaremos una búsqueda de fuerza bruta donde probamos todas las posibles soluciones del problema y una búsqueda con paralelismo, donde utilizamos varios hilos para dividir el problema y que cada hilo busque en una parte de todas las posibilidades.

Además de los 2 algoritmos también se calcula el tiempo de ejecución de cada uno de ellos, utilizando el reloj del procesador para calcular la diferencia entre estos 2 algoritmos en tiempo real.

Para la realización de este proyecto se utilizaron 4 diferentes librerías: stdio.h, stdint.h, time.h, y pthread.h. Estas se utilizaron para imprimir los resultados a archivos, utilizar el tipo de entero de 64 bits, obtener el tiempo de ejecución, y utilizar hilos en paralelismo.

Para la realización de estos algoritmos en el menor tiempo posible elegimos utilizar un número entero de 64 bits para representar el tablero y cada uno de los bits representa si existe o no una reina en la posición del tablero. Esto nos permite realizar las operaciones de comparación con operaciones de bits; como bitshifts, bitwise ands y bitwise ors. Estas operaciones con bits son mucho más rápidas ya que son definidas directamente en la arquitectura de un procesador.

Imprimimos los resultados de nuestros algoritmos en 2 archivos diferentes: brute.txt, y multi.txt. En estos archivos se pueden ver todas las posibles soluciones para nuestro problema de las 8 reinas.

--------------

### Algoritmo de Fuerza Bruta

1. Si el número de reinas en el tablero es menor a 8:
    1. Mover la reina a la columna del tablero donde la quieras agregar.
    2. Colocar la reina en todas las posiciones de la columna.
        1. Volver a realizar el algoritmo para la siguiente reina.
2. Si el número de reinas en el tablero es 8:
    1. Recorrer todo el tablero.
        1. Si hay una reina en la posición actual:
            1. Si hay 2 reinas en la misma fila, columna o diagonal:
                1. El tablero es inválido.
    2. Si el tablero es válido:
        1. Abrir un archivo donde se quiere imprimir la solución.
        2. Imprimir el tablero con las reinas en las posiciones adecuadas.
        3. Cerrar el archivo.

### Algoritmo con Paralelismo

> Se divide el proceso en 8 diferentes hilos, cada uno con un número que lo identifica de 1 a 8:
1. Si el número de reinas en el tablero es 0:
    1. Colocar la primera reina en la fila 1, columna del número del hilo.
2. Si el número de reinas en el tablero es menor a 8:
    1. Mover la reina a la columna del tablero donde la quieras agregar.
    2. Colocar la reina en todas las posiciones de la columna.
        1. Volver a realizar el algoritmo para la siguiente reina.
3. Si el número de reinas en el tablero es 8:
    1. Recorrer todo el tablero.
        1. Si hay una reina en la posición actual:
            1. Si hay 2 reinas en la misma fila, columna o diagonal:
                1. El tablero es inválido.
    2. Si el tablero es válido:
        1. Abrir un archivo donde se quiere imprimir la solución.
        2. Imprimir el tablero con las reinas en las posiciones adecuadas.
        3. Cerrar el archivo.

----------------

### Tiempo de ejecucion de los algoritmos
![Output](https://user-images.githubusercontent.com/93450752/205466593-9a300b40-a0d8-4016-8df8-9e09fa83d4e2.png)

### Ejemplo de un archivo creado por el algoritmo
![File](https://user-images.githubusercontent.com/93450752/205466625-97c3b0d1-0763-4bb0-b60a-cb0aafd3f2b5.png)
