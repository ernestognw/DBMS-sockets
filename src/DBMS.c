#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./definitions.c"

typedef struct alumno
{
    char nombre[COL_SIZE], apellido[COL_SIZE], carrera[COL_SIZE], semestre[COL_SIZE], matricula[COL_SIZE];
} Alumno;

typedef struct calificaciones
{
    char materia[COL_SIZE], matricula[COL_SIZE], calificacion[COL_SIZE];
} Calificaciones;

void selectCondCalif()
{
    int op;
    char *aux = malloc(1024);
    FILE *fp;
    Calificaciones *c;
    fp = fopen(GRADES_TABLE, "rb");
    printf("Elija la columna para hacer la condicion \n 1) Materia \n 2) Matricula \n 3) Calificacion \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Teclee la materia\n");
        scanf("%s", aux);

        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcmp(c->materia, aux) == 0)
            {
                printf("Materia: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
            }
        }
        break;
    case 2:
        printf("Teclee la matricula\n");
        scanf("%s", aux);
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcmp(c->matricula, aux) == 0)
            {
                printf("Materia: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
            }
        }
        break;
    case 3:
        printf("Teclee la calificacion\n");
        scanf("%s", aux);
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        while (fread(c, sizeof(Calificaciones), 1, fp))
        {
            if (strcmp(c->calificacion, aux) == 0)
            {
                printf("Materia: %s Matricula: %s Calificacion: %s \n", c->materia, c->matricula, c->calificacion);
            }
        }
        break;
    }
}

void selectCondAlumn()
{
    int op;
    char *aux = malloc(1024);
    FILE *fp;
    Alumno *a;
    fp = fopen(STUDENTS_TABLE, "rb");
    printf("Elija la columna para hacer la condicion \n 1) Nombre \n 2) Apellido \n 3) Carrera \n 4) Semestre \n 5) Matricula \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Teclee el nombre\n");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcmp(a->nombre, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 2:
        printf("Teclee el apellido\n");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcmp(a->apellido, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 3:
        printf("Teclee el carrera\n");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcmp(a->carrera, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 4:
        printf("Teclee el semestre\n");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcmp(a->semestre, aux) == 0)
            {
                printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
            }
        }
        break;
    case 5:
        printf("Teclee la matricula\n");
        scanf("%s", aux);
        a = (Alumno *)malloc(sizeof(Alumno));
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            if (strcmp(a->matricula, aux) == 0)
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
        fp = fopen(STUDENTS_TABLE, "rb");
        while (fread(a, sizeof(Alumno), 1, fp))
        {
            printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s \n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula);
        }
        fclose(fp);
        break;

    case 2:;
        Calificaciones *c;
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        fp = fopen(GRADES_TABLE, "rb");
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
        fp = fopen(STUDENTS_TABLE, "rb");
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

        remove(STUDENTS_TABLE);
        rename("tmp.bin", STUDENTS_TABLE);

        break;

    case 2:
        printf("Ingrese la matricula que quiera eliminar:\n");
        scanf("%s", id);
        Calificaciones *c;
        c = (Calificaciones *)malloc(sizeof(Calificaciones));
        fp = fopen(GRADES_TABLE, "rb");
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

        remove(GRADES_TABLE);
        rename("tmp.bin", GRADES_TABLE);

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

        fp = fopen(STUDENTS_TABLE, "ab");

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
        fp = fopen(GRADES_TABLE, "ab");
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

void join()
{
    FILE *fpStudents;
    FILE *fpGrades;
    char *aux = malloc(1024);
    Alumno *a;
    a = (Alumno *)malloc(sizeof(Alumno));
    Calificaciones *c;
    c = (Calificaciones *)malloc(sizeof(Calificaciones));

    fpStudents = fopen(STUDENTS_TABLE, "rb");

    printf("Teclee la matricula\n");
    scanf("%s", aux);
    while (fread(a, sizeof(Alumno), 1, fpStudents))
    {
        if (strcmp(a->matricula, aux) == 0)
        {
            fpGrades = fopen(GRADES_TABLE, "rb");
            while (fread(c, sizeof(Calificaciones), 1, fpGrades))
            {
                if (strcmp(c->matricula, aux) == 0)
                {
                    printf("Nombre: %s Apellido: %s Carrera: %s Semestre: %s Matricula: %s Materia: %s Calificacion: %s \n\n", a->nombre, a->apellido, a->carrera, a->semestre, a->matricula, c->materia, c->calificacion);
                }
            }
        }
    }
}

int main()
{
    FILE *archivoAlumno;
    FILE *archivoCalificaciones;
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
            join();
            break;
        }
    }

    return 0;
}
