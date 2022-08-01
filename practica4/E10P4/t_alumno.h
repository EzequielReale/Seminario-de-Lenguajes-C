#ifndef t_alumno_h
#define t_alumno_h

    #include "t_fecha.h"
    
    struct s_alumno
    {
        char nombre[128], apellido[128];
        t_fecha f_nacimiento;
        unsigned int legajo;
    };
    
    typedef struct s_alumno *t_alumno;


    char inicializar_alumno(t_alumno *alumno, char nombre[], char apellido[], unsigned short d, 
                            unsigned short m, unsigned short a, unsigned int legajo);
        //Reserva espacio para el alumno e inicializa sus campos. Si pudo devuelve 1, si no
        //no habia lugar en la memoria principal devuelve 0
       
    char *to_string(char *str, t_alumno alumno);
        //Convierte los datos del alumno en un string (util para imprimir en pantalla)

    char alumnocmp(t_alumno a1, t_alumno a2);
        //Devuelve 0 si los nombres no coinciden 
        //Devuelve 1 si los structs son iguales 
        //Devuelve -1 si solo coincide el nombre y apellido

    void destruir_alumno(t_alumno *alumno);
        //Libera la memoria ocupada por el alumno
    
#endif