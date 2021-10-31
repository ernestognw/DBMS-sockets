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

typedef struct calificaciones
{

    char materia[colSize], matricula[colSize], calificacion[colSize];
} Calificaciones;

//crear socket para recibir conexiones

//creo el cliente que se conecta a ese deamon

// que entre el servidor y cliente se empiecen a conectar

// tengo que definir bien el protocolo de comunicación

//------------------------------------------------------------
//hacer otra funcion para la otra tabla
//acabar el switch con los otros casos
void selectCondAlumn(char *cond)
{
    int op;
    char *aux;
    FILE *fp;
    fp = fopen("alumno.bin", "rb");
    printf("Elija la columna para hacer la condicion \n 1) Nombre \n 2) Apellido \n 3) Carrera \n 4) Semestre \n 5) Matricula");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Teclee el nombre");
        scanf("%s", &aux);
        Alumno *a;
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcpy(a->nombre, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }

        break;

    default:
        break;
    }
    fclose(fp);
}

void selectAll()
{
    int op;
    printf("Elija la tabla para imprimir \n 1) Alumnos \n 2) Calificaciones");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        Alumno *a;
        a = (Alumno *)malloc(sizeof(Alumno));
        int value;

        FILE *fp;
        fp = fopen("alumno.bin", "rb");
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
        }
        fclose(fp);
        break;

    case 2:
        Calificaciones *c;
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        int value;

        FILE *fp;
        fp = fopen("alumno.bin", "rb");
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            printf("Materia: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
        }
        fclose(fp);
        break;
    }
}

//----------------------------------------------
//Cambiar structs
void deleteEntry(char *name)
{
    Entry *e;
    e = (Entry *)malloc(sizeof(Entry));
    FILE *fp;
    FILE *temp;
    fp = fopen("myentries.bin", "rb");
    temp = fopen("tmp.bin", "wb");
    while (fread(e, sizeof(Entry), 1, fp))
    {
        if (strcmp(e->name, name) == 0)
        {
            printf("A record with requested name found and deleted.\n\n");
        }
        else
        {
            fwrite(e, sizeof(Entry), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove("myentries.bin");
    rename("tmp.bin", "myentries.bin");
}

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