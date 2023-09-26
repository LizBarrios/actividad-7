// Barrios Retana Lizeth 372813
// 20-sep-23/24-sep-23
//Leer una cadena y desplegarla de la siguiente manera (Realizar una funcién para cada salida)
// BRL_act7_1_932
#include <stdio.h>   // para print
#include <string.h>  // para gets y strlen
#include <stdlib.h>  // para atoi

// Declaración de funciones
void reversa(char palabra[100]);
void mayuscula(char palabra[100]);
void brinco(char palabra[100]);
void albrinco(char palabra[100]);
void columna(char palabra[100]);
void vocales(char palabra[100]);
void columnareves(char palabra[100]);
void primeraLetra(char palabra[100]);
void primeraalreves(char palabra[100]);
void consonantes(char palabra[100]);
int validar(char mensaje[], int ri, int rf);

int main()
{
    char palabra[100];
    int salida;

    // Solicitar al usuario que ingrese una palabra
    printf("Ingresa una palabra: ");
    fflush(stdin);
    gets(palabra);

    // Convertir la cadena ingresada a letras mayúsculas
    strupr(palabra);

    // Solicitar al usuario que seleccione una operación
    salida = validar("Que numero de salida quieres? \n1.Mayuscula\n2.Al reves\n3.Letra por letra\n4.Letra por letra y alreves\n5.Columna\n6.Columna al reves\n7.Columna y eliminar la primera letra\n8.Columan al reves y eliminar la primera letra\n9.Eliminar vocales\n10.Dejar vocales\n", 1, 10);

    // Ejecutar la operación seleccionada por el usuario
    switch (salida)
    {
    case 1:
        mayuscula(palabra);
        break;
    case 2:
        reversa(palabra);
        break;
    case 3:
        brinco(palabra);
        break;
    case 4:
        albrinco(palabra);
        break;
    case 5:
        columna(palabra);
        break;
    case 6:
        columnareves(palabra);
        break;
    case 7:
        primeraLetra(palabra);
        break;
    case 8:
        primeraalreves(palabra);
        break;
    case 9:
        vocales(palabra);
        break;
    case 10:
        consonantes(palabra);
        break;
    default:
        printf("NO SE ENCONTRO RESULTADO\n");
        break;
    }
    return 0;
}

// Función para mostrar la cadena en mayúsculas
void mayuscula(char palabra[100])
{
    int i, x;
    x = strlen(palabra);
    for (i = 0; i < x; i++)
    {
        printf("%c", palabra[i]);
    }
}

// Función para mostrar la cadena al revés
void reversa(char palabra[100])
{
    int i, x;
    x = strlen(palabra);
    for (i = x; i >= 0; i--)
    {
        printf("%c", palabra[i]);
    }
}

// Función para mostrar la cadena letra por letra
void brinco(char palabra[100])
{
    int i, x;
    x=strlen(palabra);
    for (i = 0; i < x; i++)
    {
        printf("%c\n", palabra[i]);
    }
}

// Función para mostrar la cadena al revés letra por letra
void albrinco(char palabra[100])
{
    int i, x;
    x = strlen(palabra);
    for (i = x; i >= 0; i--)
    {
        printf("%c\n", palabra[i]);
    }
}

// Función para mostrar la cadena en columnas
void columna(char palabra[100])
{
    int i, x, j;
    x = strlen(palabra);
    for (i = x; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}

// Función para mostrar la cadena en columnas al revés
void columnareves(char palabra[100])
{
    int i, x, j;
    x = strlen(palabra);
    for (i = 0; i < x; i++)
    {
        for (j = x; j >= i; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}

// Función para mostrar la cadena omitiendo la primera letra en cada línea
void primeraLetra(char palabra[100])
{
    int i, x, j;
    x = strlen(palabra);
    for (i = 0; i < x; i++)
    {
        for (j = i; j < x; j++)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}

// Función para mostrar la cadena omitiendo la primera letra en cada línea y en orden inverso
void primeraalreves(char palabra[100])
{
    int i, x, j;
    x = strlen(palabra) - 1;
    for (i = x; i >= 0; i--)
    {
        for (j = i; j >= 0; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}

// Función para mostrar la cadena eliminando las vocales
void vocales(char palabra[100])
{
    char vocal[] = "AEIOU";
    int i, x, j;
    x = strlen(palabra);
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (palabra[i] == vocal[j])
            {
                palabra[i] = ' ';
            }
        }
        printf("%c", palabra[i]);
    }
}

// Función para mostrar solo las consonantes de la cadena
void consonantes(char palabra[100])
{
    char vocal[] = "AEIOU";
    int i, x, j;
    x = strlen(palabra);
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (palabra[i] == vocal[j])
            {
                printf("%c ", palabra[i]);
            }
        }
    }
}

// Función para validar la entrada del usuario y garantizar un número dentro de un rango
int validar(char mensaje[], int ri, int rf)
{
    char calificacion[100];
    int num;
    do
    {
        printf("%s ", mensaje);
        fflush(stdin);
        gets(calificacion);
        num = atoi(calificacion);
        if (num < ri || num > rf)
        {
            printf("INGRESE EL NUMERO OTRA VEZ POR FAVOR\n");
        }
    } while (num < ri || num > rf);
    return num;
}
