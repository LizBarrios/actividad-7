// Barrios Retana Lizeth 372813
// 20-sep-23/24-sep-23
/*
Leer una cadena y desplegarla de la siguiente manera
(Realizar una funcién para cada salida)
*/
// BRL_act7_2_932
#include <stdio.h>  //para print
#include <string.h> //para gets
#include <stdlib.h>
#include <ctype.h>

void mayuscula(char palabra[100]);
void reversa(char palabra[100]);
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
    printf("Ingresa una palabra: ");
    fflush(stdin);
    gets(palabra);
    salida = validar("Que numero de funcion quieres? \n1.Mayuscula\n2.Al reves\n3.Letra por letra\n4.Letra por letra y alreves\n5.Columna\n6.Columna al reves\n7.Columna y eliminar la primera letra\n8.Columan al reves y eliminar la primera letra\n9.Eliminar vocales\n10.Dejar vocales\n", 1, 10);
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

void mayuscula(char palabra[100])
{
    int i = 0;
    while (palabra[i])
    {
        if (islower(palabra[i]))
        {
            palabra[i] = toupper(palabra[i]) + 32;
        }
        i++;
    }
    printf("%c", palabra[i]);
}
void reversa(char palabra[100])
{
    int i, x;
    x = strlen(palabra);
    for (i = x; i >= 0; i--)
    {
        printf("%c", palabra[i]);
    }
}
void brinco(char palabra[100])
{
    int i, x;
    for (i = 0; i < x; i++)
    {
        printf("%c\n", palabra[i]);
    }
}
void albrinco(char palabra[100])
{
    int i, x;
    x = strlen(palabra);
    for (i = x; i >= 0; i--)
    {
        printf("%c\n", palabra[i]);
    }
}
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
void columnareves(char palabra[100])
{
    int i, x, j;
    x = strlen(palabra); // ya funciona, ya no le muevo :)
    for (i = 0; i < x; i++)
    {
        for (j = x; j >= i; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}
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
void primeraalreves(char palabra[100])
{
    int i, x, j;
    x = strlen(palabra) - 1; // dame 2
    for (i = x; i >= 0; i--) // 4-0 es aqui vdd?
    {
        for (j = i; j >= 0; j--) //
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}
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
int validar(char mensaje[], int ri, int rf)
{
    char palabra[100];
    int num;
    do
    {
        printf("%s ", mensaje);
        fflush(stdin);
        gets(palabra);
        num = atoi(palabra);
        if (num < ri || num > rf)
        {
            system("cls");

            printf("INGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf);
    return num;
}