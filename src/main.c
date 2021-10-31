#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

#define colSize 20

typedef struct alumno
{
    char nombre[colSize], apellido[colSize], carrera[colSize], semestre[colSize], matricula[colSize];
} Alumno;

struct calificaciones
{

    char materia[colSize], matricula[colSize], calificacion[colSize];
};

//crear socket para recibir conexiones

//creo el cliente que se conecta a ese deamon

// que entre el servidor y cliente se empiecen a conectar

// tengo que definir bien el protocolo de comunicación

int main()
{

    printf("Starting daemonize\n");
    daemonize();

    struct alumno a;
    struct calificaciones c;

    FILE *archivoAlumno;
    FILE *archivoCalificaciones;

    archivoAlumno = fopen("alumno.bin", "wb");

    // ESTO ES PARA INICIAR EL ARCHIVO alumno.bin ---> Ya ustedes hacen en insert y demás
    strcpy(a.nombre, "Karina");
    strcpy(a.apellido, "Amador");
    strcpy(a.carrera, "ITC");
    strcpy(a.semestre, "septimo");
    strcpy(a.matricula, "1");
    fwrite(&a, sizeof(struct alumno), 1, archivoAlumno);
    fclose(archivoAlumno);

    Alumno *al;
    al = (Alumno *)malloc(sizeof(Alumno));
    FILE *fp;
    if (access("alumno.bin", F_OK) != 0)
    {
        printf("There are no entries. \n");
    }
    fp = fopen("alumno.bin", "rb");
    while (fread(al, sizeof(Alumno), 1, fp))

    {
        printf("=========== ALUMNOS ===========\n");
        printf("- %s ", al->nombre);
        printf("%s ", al->apellido);
        printf("%s ", al->carrera);
        printf("%s ", al->semestre);
        printf("%s ", al->matricula);
    }
    fclose(archivoAlumno);

    return 0;
}