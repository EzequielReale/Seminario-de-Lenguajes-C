# Tic-Tac-Toe en C

Una implementación clásica del juego Tic-Tac-Toe (Tres en Raya) en lenguaje C con una IA que utiliza el algoritmo Minimax para tomar decisiones óptimas.

## Descripción

Este proyecto implementa el clásico juego de Tic-Tac-Toe, Ta-Te-Tí o Tres en Raya como una aplicación de consola en C. El juego incluye:

- Interfaz de texto para terminal
- IA competente que usa el algoritmo Minimax para decisiones óptimas
- Variabilidad estratégica en el primer movimiento de la IA

El jugador humano usa 'X' y la computadora usa 'O'. El juego comprueba automáticamente si hay un ganador después de cada movimiento o si se produce un empate.

## Requisitos

- Compilador de C (GCC, Clang, etc.)
- Terminal o consola de comandos

## Estructura del Proyecto

```
.
├── ai.c         # Implementación de la IA y lógica del juego
├── ai.h         # Cabecera para la IA
├── board.c      # Funciones relacionadas con el tablero
├── board.h      # Cabecera para las funciones del tablero
├── const.h      # Constantes y definiciones
└── main.c       # Main del programa
```

## Compilación

Para compilar el juego, utiliza el siguiente comando en tu terminal:

```bash
gcc -o tictactoe main.c ai.c board.c -Wall -Wextra
```

## Cómo Jugar

1. Ejecuta el programa compilado:
   ```bash
   ./tictactoe
   ```

2. Cuando sea tu turno, se te pedirá que ingreses las coordenadas de tu movimiento:
   - Primero ingresa el número de fila (1-3)
   - Luego ingresa el número de columna (1-3)

3. El juego muestra el tablero después de cada movimiento:
   ```
    X |   |   
   ---|---|---
      | O |   
   ---|---|---
      |   |   
   ```

4. El juego continúa hasta que:
   - Tú ganas (tres 'X' en línea)
   - La computadora gana (tres 'O' en línea)
   - El tablero se llena sin un ganador (empate)

5. Al final de cada partida, se te preguntará si deseas jugar de nuevo.

## Estrategia

La IA utiliza el algoritmo Minimax para determinar el mejor movimiento posible, lo que hace que sea muy difícil ganarle. Sin embargo, la IA está programada para tener cierta variabilidad en su primer movimiento, dándote una pequeña ventana de oportunidad.

¡Buena suerte (la vas a necesitar)!