#include <stdio.h>
#include <string.h>

struct alumno
{
    int matriculo;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
};

int main()
{
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
            /* code */
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