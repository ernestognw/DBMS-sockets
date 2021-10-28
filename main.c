#include <stdio.h>
#include <stdlib.h>

struct alumno
{
    char nombre, apellido;
};

struct grado {

    char semestre, carrera;

};

int  main(){

    struct alumno a;
    struct grado g;

    FILE *archivoAlumno;
    FILE *archivoGrado;

// Create an empty binary file for writing.
    archivoAlumno = fopen("testAlumno.bin","wb");
    if (!archivoAlumno){
       printf("Error! opening file");
       exit(1);
   }
   // ciclo para que 



return 0;
}