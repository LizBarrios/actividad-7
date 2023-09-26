#include <stdio.h>
#include <string.h>
char* validar(char mensaje[],char cadena[]);

char* validar(char mensaje[],char cadena[])
{
    int x, i,salida;
    printf("%s", mensaje);
    do
    {
        salida = 0;
        fgets(cadena, 256, stdin);
        cadena[strcspn(cadena, "\n")] = 0;
        x = strlen(cadena);
        for (i = 0; i < x; i++)
        {
            if (cadena[i] == ' ' && cadena[i + 1] == ' ')
            {
                printf("HAY DOBLE ESPACIO\n");
                salida = 1;
                 break;
            }
            if (cadena[i] >= '0' && cadena[i] <= '9')
            {
                printf("HAY NUMEROS\n");
                salida = 1;
                break;
            }
        }
    } while (salida == 1);
    strupr(cadena);
    return cadena;
}