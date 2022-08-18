## Trabajo Final de Seminario de Lenguajes C: PPM image processor

Este programa es un gestor de imágenes en formato [PPM de tipo P6](http://netpbm.sourceforge.net/doc/ppm.html).

La descripción completa del proyecto y los objetivos se encuentran en: https://github.com/chrodriguez/ppm-ejercicio-c

<br>

## Argumentos:
* `-i <input.ppm>`: archivo origen. Obigatorio. Debe ser además el 1er argumento.
* `-o <output.ppm>`: archivo salida. Obligatorio.
* `-n`: calcula el negativo de la imagen.
* `-r`: rota a 90° la imagen.
* `-h`: espeja horizontalmente la imagen.
* `-v`: espeja verticalmente la imagen.
* `-b NUM`: desenfoca la imagen con un radio NUM (hasta 255).
* `-?`: ayuda del programa.

<br>

## Ejemplos de uso:

### Copia una imagen

```
./images -i input.ppm -o output.ppm
```

### Espeja horizontalmente una imagen

```
./images -i input.ppm -o output.ppm -h
```

### Calcula el negativo y desenfoca la imagen

```
./images -i input.ppm -n -o output.ppm -b 3
```

<br>

## Compilación:

```
gcc main.c ppm.c ppm-operations.c tools.c -o images -Wall
```
