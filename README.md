# EstructuraDatos2
## El problema de las 8 reinas

El problema de las ocho reinas es un pasatiempo que consiste en poner ocho reinas en el tablero de ajedrez sin que se amenacen.

El juego de las 8 reinas consiste en poner sobre un tablero de ajedrez ocho reinas sin que estas se amenacen entre ellas.

> Existen 8C64 Posibles combinaciones de 8 reinas en un tablero de 64 casillas
>
> 8C64 =  64! / (8!56!) = 4,426,165,368

En nuestro algoritmo de fuerza bruta se utiliza la regla que elige solo una reina por fila

> Existen 8^8 posibles combinaciones de reinas sin tener 2 en la misma fila
>
> 8^8 = 16,777,216
