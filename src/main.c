#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <unistd.h>

//#include <unistd.h>
//#include <signal.h>
//#include <sys/types.h>
////#include <sys/stat.h>
//#include <syslog.h>

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
void selectCondCalif()
{
    int op;
    char *aux;
    FILE *fp;
    Calificaciones *c;
    fp = fopen("calificaciones.bin", "rb");
    printf("Elija la columna para hacer la condicion \n 1) Materia \n 2) Matricula \n 3) Calificacion \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Teclee la materia");
        scanf("%s", aux);

        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcpy(c->materia, aux) == 0)
            {
                printf("Matria: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
            }
        }
        break;
    case 2:
        printf("Teclee la matricula");
        scanf("%s", aux);
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcpy(c->matricula, aux) == 0)
            {
                printf("Matria: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
            }
        }
        break;
    case 3:
        printf("Teclee la calificacion");
        scanf("%s", aux);
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcpy(c->calificacion, aux) == 0)
            {
                printf("Matria: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
            }
        }
        break;
    }
}

void selectCondAlumn()
{
    int op;
    char *aux;
    FILE *fp;
    Alumno *a;
    fp = fopen("alumno.bin", "rb");
    printf("Elija la columna para hacer la condicion \n 1) Nombre \n 2) Apellido \n 3) Carrera \n 4) Semestre \n 5) Matricula \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Teclee el nombre");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcpy(a->nombre, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 2:
        printf("Teclee el apellido");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcpy(a->apellido, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 3:
        printf("Teclee el carrera");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcpy(a->carrera, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 4:
        printf("Teclee el semestre");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcpy(a->semestre, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 5:
        printf("Teclee el matricula");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcpy(a->matricula, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    }
    fclose(fp);
}

void selectAll()
{
    int op;
    FILE *fp;
    printf("Elija la tabla para imprimir \n 1) Alumnos \n 2) Calificaciones \n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:;
        Alumno *a;
        a = (Alumno *)malloc(sizeof(Alumno));
        fp = fopen("alumno.bin", "rb");
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
        }
        fclose(fp);
        break;

    case 2:;
        Calificaciones *c;
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        fp = fopen("calificaciones.bin", "rb");
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            printf("Materia: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
        }
        fclose(fp);
        break;
    }
}

void deleteEntry()
{
    int op;
    char *id = malloc(1024);
    FILE *fp;
    FILE *temp;
    printf("Elija la tabla para hacer delete \n 1) Alumnos \n 2) Calificaciones \n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Ingrese la matricula que quiera eliminar:\n");

        scanf("%s", id);
        Alumno *a;
        a = (Alumno *)malloc(sizeof(Alumno));
        fp = fopen("alumno.bin", "rb");
        temp = fopen("tmp.bin", "wb");
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcmp(a->matricula, id) == 0)
            {
                printf("The row has been deleted.\n\n");
            }
            else
            {
                fwrite(a, sizeof(Calificaciones), 1, temp);
            }
        }
        fclose(fp);
        fclose(temp);

        remove("alumno.bin");
        rename("tmp.bin", "alumno.bin");

        break;

    case 2:
        printf("Ingrese la matricula que quiera eliminar:\n");
        scanf("%s", id);
        Calificaciones *c;
        c = (Calificaciones *)malloc(sizeof(Calificaciones));

        fp = fopen("calificaciones.bin", "rb");
        temp = fopen("tmp.bin", "wb");
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcmp(c->matricula, id) == 0)
            {
                printf("The row has been deleted.\n\n");
            }
            else
            {
                fwrite(a, sizeof(Calificaciones), 1, temp);
            }
        }
        fclose(fp);
        fclose(temp);

        remove("calificaciones.bin");
        rename("tmp.bin", "calificaciones.bin");

        break;
    }
}

void insert()
{
    int op;
    FILE *fp;
    char *p = malloc(1024);
    Alumno *a;
    a = (Alumno *)malloc(sizeof(Alumno));
    Calificaciones *c;
    c = (Calificaciones *)malloc(sizeof(Calificaciones));

    printf("Elija la tabla para hacer insert \n 1) Alumnos \n 2) Calificaciones \n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:

        fp = fopen("alumno.bin", "ab");

        printf("Enter Student name\n");
        scanf("%s", p);
        strcpy(a->nombre, p);
        fflush(stdin);

        printf("Enter Student lastname\n");
        scanf("%s", p);
        strcpy(a->apellido, p);
        fflush(stdin);

        printf("Enter Student carrer\n");
        scanf("%s", p);
        strcpy(a->carrera, p);
        fflush(stdin);

        printf("Enter Student semester\n");
        scanf("%s", p);
        strcpy(a->semestre, p);
        fflush(stdin);

        printf("Enter Student id\n");
        scanf("%s", p);
        strcpy(a->matricula, p);
        fflush(stdin);

        fwrite(a, sizeof(Alumno), 1, fp);

        fclose(fp);

        break;

    case 2:
        printf("Holi wilis");
        fp = fopen("calificaciones.bin", "ab");

        printf("Enter Course name\n");
        scanf("%s", p);
        strcpy(c->materia, p);
        fflush(stdin);

        printf("Enter Student id\n");
        scanf("%s", p);
        strcpy(c->matricula, p);
        fflush(stdin);

        printf("Enter Course grade\n");
        scanf("%s", p);
        strcpy(c->calificacion, p);
        fflush(stdin);

        fwrite(c, sizeof(Calificaciones), 1, fp);

        fclose(fp);

        break;
    }
}

int main()
{
    /*
    printf("Starting daemonize\n");
    daemonize();
    
    struct alumno a;
    struct calificaciones c;
    */
    FILE *archivoAlumno;
    FILE *archivoCalificaciones;

    archivoAlumno = fopen("alumno.bin", "wb");
    /*
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
    */
    fclose(archivoAlumno);
    int menu = 1, aux;

    while (menu != 0)
    {
        printf("Menu: \n 1) Select all \n 2) Select con condicion \n 3) Insertar \n 4) Borrar \n 5) Join \n 0) Salir \n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            selectAll();
            break;
        case 2:
            printf("Elija la tabla en la cual quiere hacer el select: \n 1) Alumnos \n 2) Calificaciones \n");
            scanf("%d", &aux);
            switch (aux)
            {
            case 1:
                selectCondAlumn();
                break;
            case 2:
                selectCondCalif();
                break;
            }
            break;
        case 3:
            insert();
            break;
        case 4:
            deleteEntry();
            break;
        case 5:
            //join
            break;
        }
    }

    return 0;
}
