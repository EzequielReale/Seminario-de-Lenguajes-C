#include <stdio.h>
#include <string.h>

typedef struct 
{
    unsigned short dia, mes, anio;
} fecha;

typedef struct
{
    char nombre[128], apellido[128], tipo_doc;
    fecha f_nacimiento;
    long legajo, num_doc;
} alumno;

int main()
{
    alumno alum1;
    strcpy(alum1.nombre, "Juan");
    strcpy(alum1.apellido, "Perez");
    alum1.tipo_doc = 'D';
    alum1.f_nacimiento.dia = 20;
    alum1.f_nacimiento.mes = 6;
    alum1.f_nacimiento.anio = 2002;
    alum1.legajo = 187964;
    alum1.num_doc = 42687951;

    alumno alum2 = alum1;

    printf("Alumno 1:\n\tNombre: %s\n\tApellido: %s\n\tFecha de nacimiento: %d / %d / %d\n\t"
           "Numero de legajo: %ld\n\tTipo de documento: %c\n\tNumero de documento: %ld\n", alum1.nombre,
           alum1.apellido, alum1.f_nacimiento.dia, alum1.f_nacimiento.mes, alum1.f_nacimiento.anio,
           alum1.legajo, alum1.tipo_doc, alum1.num_doc);
    printf("Alumno 2:\n\tNombre: %s\n\tApellido: %s\n\tFecha de nacimiento: %d / %d / %d\n\t"
           "Numero de legajo: %ld\n\tTipo de documento: %c\n\tNumero de documento: %ld\n", alum2.nombre,
           alum2.apellido, alum2.f_nacimiento.dia, alum2.f_nacimiento.mes, alum2.f_nacimiento.anio,
           alum2.legajo, alum2.tipo_doc, alum2.num_doc);

    puts("\nCambio el nombre del alumno 2\n");
    strcpy(alum2.nombre, "Pepe");

    printf("Alumno 1:\n\tNombre: %s\n\tApellido: %s\n\tFecha de nacimiento: %d / %d / %d\n\t"
           "Numero de legajo: %ld\n\tTipo de documento: %c\n\tNumero de documento: %ld\n", alum1.nombre,
           alum1.apellido, alum1.f_nacimiento.dia, alum1.f_nacimiento.mes, alum1.f_nacimiento.anio,
           alum1.legajo, alum1.tipo_doc, alum1.num_doc);
    printf("Alumno 2:\n\tNombre: %s\n\tApellido: %s\n\tFecha de nacimiento: %d / %d / %d\n\t"
           "Numero de legajo: %ld\n\tTipo de documento: %c\n\tNumero de documento: %ld\n", alum2.nombre,
           alum2.apellido, alum2.f_nacimiento.dia, alum2.f_nacimiento.mes, alum2.f_nacimiento.anio,
           alum2.legajo, alum2.tipo_doc, alum2.num_doc);
    return 0;
}