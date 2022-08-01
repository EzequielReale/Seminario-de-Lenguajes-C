# Trabajo Práctico Integrador de "Seminario de Lenguajes C"

El trabajo consiste en implementar la funcionalidad de los programas de Unix `Head` y `Tail`.

El funcionamiento principal de estos comandos es mostrar, respectivamente, las *primeras o últimas* N líneas de un archivo de texto. Mediante el uso de los siguientes argumentos se puede personalizar dicho funcionamiento:

<br>

## Head
* `-l <cantidad_lineas> o --lines <cantidad_lineas>`: Muestra en pantalla la cantidad de lineas ingresadas. Si se omite la cantidad se muestran 5 lineas por defecto (cantidad modificable en compilación).
* `-b <cantidad_bytes> o --bytes <cantidad_bytes>`: Muestra en pantalla la cantidad de bytes ingresados. No puede omitirse la cantidad.
* `<archivo> (como último argumento)`: Abre el archivo indicado. Si se omite usa la entrada estándar.
* `-h o --help`: Muestra una ayuda.

#### ACLARACIÓN: los argumentos -l y -b son mutuamente excluyentes entre si. Además, líneas tiene prioridad, por lo que si se omiten ambos se imprimen por defecto 5 líneas.

<br>

## Tail
* `-l <cantidad_lineas> o --lines <cantidad_lineas>`: Muestra en pantalla la cantidad de lineas ingresadas. Si se omite la cantidad se muestran 5 lineas por defecto.
* `-r o --reverse`: Muestra las lineas en orden inverso. Es decir, a partir la última línea. 
* `<archivo> (como último argumento)`: Abre el archivo indicado. Si se omite se usa la entrada estándar.
* `-h o --help`: Muestra una ayuda.

<br>

## Compilación
Ambos programas se compilan por separado.

<br>

*Puede definirse, o no, la cantidad de lineas por default en tiempo de compilación.*

<br>

* El comando para no definirlas (es decir, dejarlas en 5) es:
```
gcc head.c tools.c programs.c errors.c t_lista_generica.c -o head -Wall
```
```
gcc tail.c tools.c programs.c errors.c t_lista_generica.c -o tail -Wall
```

* Por su parte, el comando para definirlas es:
```
gcc head.c tools.c programs.c errors.c t_lista_generica.c -DDEFAULT=<cantidad_lineas> -o head -Wall
```
```
gcc tail.c tools.c programs.c errors.c t_lista_generica.c -DDEFAULT=<cantidad_lineas> -o tail -Wall
```

<br/>

## Ejemplos de uso

### Imprimir las primeras 5 lineas del archivo "cancion"

```
./head cancion
```

### Imprimir los primeros 35 bytes del archivo "cancion"

```
./head --bytes 35 cancion
```

### Imprimir las últimas 10 líneas ingresadas por teclado en sentido inverso

```
./tail -l 10 --reverse
```

<br>

## Particularidades de diseño
* En lugar de utilizar la función de C getopt, el manejo de argumentos se hace de forma manual. Esto puede resultar en que el programa sea menos escalable en el futuro si se quieren agregar funcionalidades. Sin embargo, me resultaba interesante hacerlo de esta manera para implementar casi todas las herramientas principales que se usan a mano. Además, al ser programas simples y específicos, su función ya está acotada a pocas tareas.

* Para poder reutilizar dicha función, se utilizan argumentos variables para recibir --bytes (en Head) o --reverse (en Tail). Ya que son las funcionalidades exclusivas de cada uno.

* Por cuestiones de facilidad de uso de los programas, si bien comparten librerias, funcionan como dos entes independientes uno del otro. Podría haberse implementado hacer un único main que recibiera como parámetro la función a ejecutar, pero consideré más cómodo para el usuario tener dos programas específicos.

* El manejo de errores se maneja en una librería específica, para mayor prolijidad y facilidad de entendimiento del código. Los errores posibles son tres (más el código de no error):
    * `Sin error (E_OK 0):` si toda la ejecución del programa funcionó de forma correcta.
    * `Error por argumento inválido (E_INVALID_ARG 1):` si se introduce un argumento que no está contemplado en el programa.
    * `Error de apertura del archivo (E_OPEN_FILE 2):` si se ingresa el nombre de un archivo pero no pudo abrirse.
    * `Error de alocación de memoria (E_ALOC 3):` si no hay espacio en la heap para alocar la memoria necesaria. 

<mbr>

* Se utilizan tres typedef para mayor expresividad (exceptuando el *t_comparador de la lista, que no se le da uso en este caso):
    * `t_lista_generica:` que es el typedef para el 1er nodo genérico de la lista.
    * `t_error:` que es un tipo short, que maneja los distintos códigos de error posibles.
    * `bool:` que es un tipo char. Dado que solamente va a almacenar valores de 0 o 1, usar un tipo entero para dicha función sería un gasto innecesario de 3 bytes extras.

<mbr>

* Tail está implementado leyendo el archivo en reversa byte a byte hasta que encuentra las N líneas pedidas o llega al principio. Esto se hace así por razones de eficiencia en archivos con muchas líneas, donde leerlo completo tal vez sería muy costoso.

* Para que Tail funcione por la entrada estándar como en el programa original, se utiliza una lista genérica que funciona de manera similar a una pila (agregando los elementos adelante) y dos arreglos de punteros a char. De otra manera funcionaría igual que Head, lo cual no era lo buscado.

* En lugar de utilizar cadenas de chars y fgets, se utilizan punteros y un "fgets dinámico" que aloca memoria progresivamente. Esto para:
    * No desperdiciar tanta memoria de la Stack.
    * Que el programa no esté limitado a solo poder leer líneas más cortas que el tamaño del buffer.