#include <stdio.h>
#include <string.h>

#define Maxalumnos 50

struct InformacionAlumnos // Se creo una estructura llamada alumno donde en esta va a ir lo que esta contendra como: matricula, nombre, direccion, materia, nota
{
    int matricula;      // Variable de tipo entero
    char nombre[50];    // Variable de tipo caracter
    char direccion[50]; // Variable de tipo caracter
    char materia[50];   // Variable de tipo caracter
    float nota;         // Variable de tipo decimal
};

void DatosAlumnos(struct InformacionAlumnos alumnos[], int *AlumnoNum);

int main()
{
    struct InformacionAlumnos alumnos[Maxalumnos];
    int AlumnoNum = 0;
    int opcion;
    do
    {
        printf("Menu de opciones\n");
        printf("1-Ingresar informacion\n");
        printf("2-Mostrar alumnos\n");
        printf("3-Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            DatosAlumnos(alumnos, &AlumnoNum); // Se creo una funcion donde la llamaremos para ingresar datos de los alumnos y se pueda guardar esa informacion
            break;
        case 2:
            break;
        case 3:
            printf("Ha salido del programa\n");
            break;
        default:
            if ((opcion > 3) || (opcion < 1))
            {
                printf("Opcion no valida\n");
            }
            break;
        }
    } while (opcion != 3);

    return 0;
}

void DatosAlumnos(struct InformacionAlumnos alumnos[], int *AlumnoNum)
{
    if (*AlumnoNum < Maxalumnos)
    {
        printf("Ingrese el nombre de este alumno: ");
        fflush(stdin); // Aqui agregamos la funcion fflush para limpiar el buffer y no nos marque error con las funciones gets y puts
        gets(alumnos[*AlumnoNum].nombre);

        printf("\nIngrese la matricula correspondiente: ");
        scanf("%d", &alumnos[*AlumnoNum].matricula);

        printf("Ingrese: Direccion: ");
        fflush(stdin);
        gets(alumnos[*AlumnoNum].direccion);

        printf("Ingrese: Nombre Materia : ");
        fflush(stdin);
        gets(alumnos[*AlumnoNum].materia);

        printf("Ingrese: Nota ");
        scanf("%f", &alumnos[*AlumnoNum].nota);

        (*AlumnoNum)++;
        printf("\tDatos guardados.\n");
    }
    else
    {
        printf("Se alcanzo el limite.\n"); // Se indica que impprima si es que ya se alcanzo el limite preestabecido al principio
    }
}

void guardarDatos(struct InformacionAlumnos alumnos[], int AlumnoNum)
{
    FILE *archivo;
    char unCaracter;
    archivo = fopen("Datos.txt", "w");

    if (archivo != NULL)
    {
        // Imprimir encabezados de tabla
        fprintf(archivo, "Nombre\tMatricula\tDireccion\tCarrera\tPromedio\n");

        for (int i = 0; i < AlumnoNum; i++)
        {
            // Usar tabuladores como separadores
            fprintf(archivo, "%s\t%d\t%s\t%s\t%.2f\n",
                    alumnos[i].nombre, alumnos[i].matricula,
                    alumnos[i].direccion, alumnos[i].materia,
                    alumnos[i].nota);
        }

        fclose(archivo);
        printf("Datos guardados en el archivo.\n");
    }
}