// Barrios Retana Lizeth 372813
// 20-sep-23/24-sep-23
/*
PARTE 2
1.-Función que reciba como parámetro una cadena y la convierta a MAYUSCULAS
2.-Función Que reciba como parámetro una cadena y la convierta a MINUSCULAS
3.-Función que reciba como parámetro una cadena y la convierta a CAPITAL
4.-Función que reciba como parámetro una cadena y retorne la cantidad de caracteres que tiene la cadena.
5.-Función que reciba como parámetro una cadena y retorne una cadena con sus caracteres acomodados de forma inversa (al reves)
6.-Función que reciba como parámetro una cadena y genere una nueva cadena basada en la origina pero sin espacios.
7.-Función que sirva para leer una cadena y solo permita caracteres alfabéticos (A...Z) y el espacio, donde una cadena no puede comenzar o terminar con espacio, no debe tener dos espacios seguidos. retornar la cadena ya sea como parámetro o variable.
8.-Función que reciba como parámetro una cadena, y utilizando las funciones anteriores, imprima en MAYUSCULAS, MINUSCULAS , CAPITAL, SIN ESPACIOS, ALREVES la cadena original.
9.-Función que reciba como parámetro una cadena, y desplegar la leyenda si la cadena es un palíndromo SI o NO
 (VALIDADA AL 100% NO NUMEROS, NO DOBLES ESPACIOS Y SOLO MAYUSCULAS ENLA CADENA)
*/
// BRL_act7_1_932
#include <stdio.h>  //para el printf
#include <string.h> //para cadena

// Funciones
int validarNumero(char mensaje[], int ri, int rf);
void validarYConvertirAMayusculas(char mensaje[], char cadena[]);
void convertirAMinusculas(char cadena[]);
void convertirACapital(char cadena[]);
int contarCaracteres(char cadena[]);
void invertirCadena(char cadena[]);
void eliminarEspacios(char cadena[]);
void validarCadenaConRestricciones(char mensaje[], char cadena[]);
int esPalindromo(char cadena[]);


int main()
{
    int opcion;
    char cadena[256];

    printf("Bienvenido a la herramienta de procesamiento de cadenas.\n");

    do
    {
        printf("\nElija una opcion:\n");
        printf("1. Convertir una cadena a MAYUSCULAS\n");
        printf("2. Convertir una cadena a minúsculas\n");
        printf("3. Convertir una cadena a Capital\n");
        printf("4. Contar caracteres de una cadena\n");
        printf("5. Invertir una cadena\n");
        printf("6. Eliminar espacios de una cadena\n");
        printf("7. Validar y modificar cadena con restricciones\n");
        printf("8. Verificar si una cadena es un palindromo\n");
        printf("0. Salir\n");
        opcion = validarNumero("Ingrese el numero de la opcion: ", 0, 8);

        switch (opcion)
        {
        case 1:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            printf("Cadena en MAYUSCULAS: %s\n", cadena);
            break;
        case 2:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            convertirAMinusculas(cadena);
            printf("Cadena en minusculas: %s\n", cadena);
            break;
        case 3:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            convertirACapital(cadena);
            printf("Cadena en Capital: %s\n", cadena);
            break;
        case 4:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            printf("La cadena tiene %d caracteres.\n", contarCaracteres(cadena));
            break;
        case 5:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            invertirCadena(cadena);
            printf("Cadena invertida: %s\n", cadena);
            break;
        case 6:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            eliminarEspacios(cadena);
            printf("Cadena sin espacios: %s\n", cadena);
            break;
        case 7:
            validarYConvertirAMayusculas("Ingrese una cadena: ", cadena);
            printf("Cadena validada: %s\n", cadena);
            break;
        case 8:
            validarCadenaConRestricciones("Ingrese una cadena: ", cadena);
            if (esPalindromo(cadena))
            {
                printf("La cadena es un palindromo.\n");
            }
            else
            {
                printf("La cadena no es un palindromo.\n");
            }
            break;
        default:
            break;
        }
    } while (opcion != 0);

    return 0;
}

// Función para validar un número en un rango [ri, rf]
int validarNumero(char mensaje[], int ri, int rf)
{
    int num;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &num);
        if (num < ri || num > rf)
        {
            printf("Ingrese un numero valido en el rango [%d, %d].\n", ri, rf);
        }
    } while (num < ri || num > rf);
    return num;
}

// Función para validar una cadena y convertirla a mayúsculas
void validarYConvertirAMayusculas(char mensaje[], char cadena[])
{
    int i, x;
    int tieneNumeros = 0;

    do
    {
        tieneNumeros = 0;
        printf("%s", mensaje);
        scanf(" %s", cadena);
        x = strlen(cadena);

        // Verificar si la cadena contiene números
        for (i = 0; i < x; i++)
        {
            if (cadena[i] >= '0' && cadena[i] <= '9')
            {
                tieneNumeros = 1;
                break;
            }
        }

        if (tieneNumeros)
        {
            printf("La cadena no debe contener nameros. Intente de nuevo.\n");
        }
    } while (tieneNumeros);

    // Convertir la cadena a mayúsculas
    for (i = 0; i < x; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
}

// Función para convertir una cadena a minúsculas
void convertirAMinusculas(char cadena[])
{
    int i, x;
    x = strlen(cadena);

    for (i = 0; i < x; i++)
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] = cadena[i] + 32;
        }
    }
}

// Función para convertir una cadena a capital
void convertirACapital(char cadena[])
{
    int i, x;
    x = strlen(cadena);

    // Convertir toda la cadena a minúsculas
    convertirAMinusculas(cadena);

    // Capitalizar la primera letra y la letra después de un espacio
    for (i = 0; i < x; i++)
    {
        if (i == 0 || (i > 0 && cadena[i - 1] == ' '))
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
}

// Función para contar los caracteres de una cadena
int contarCaracteres(char cadena[])
{
    return strlen(cadena);
}

// Función para invertir una cadena
void invertirCadena(char cadena[])
{
    int i, con, j;
    con = strlen(cadena) - 1;

    for (i = 0; i < con; i++, con--)
    {
        char temp = cadena[i];
        cadena[i] = cadena[con];
        cadena[con] = temp;
    }
}

// Función para eliminar espacios de una cadena
void eliminarEspacios(char cadena[])
{
    int i, con, j;
    con = strlen(cadena);

    for (i = 0; i < con; i++)
    {
        if (cadena[i] == ' ')
        {
            for (j = i; j < con; j++)
            {
                cadena[j] = cadena[j + 1];
            }
        }
    }
}

// Función para validar una cadena y cumplir ciertas restricciones
void validarCadenaConRestricciones(char mensaje[], char cadena[])
{
    int x, i, tieneNumeros = 0;
    printf("%s", mensaje);

    do
    {
        tieneNumeros = 0;
        fgets(cadena, 256, stdin);
        cadena[strcspn(cadena, "\n")] = 0;
        x = strlen(cadena);

        // Verificar si la cadena contiene números
        for (i = 0; i < x; i++)
        {
            if (cadena[i] == ' ' && cadena[i + 1] == ' ')
            {
                printf("No debe haber dobles espacios. Intente de nuevo.\n");
                tieneNumeros = 1;
                break;
            }
            if (i == 0 && cadena[i] == ' ')
            {
                printf("La cadena no debe comenzar con espacio. Intente de nuevo.\n");
                tieneNumeros = 1;
                break;
            }
            if (i == x - 1 && cadena[i] == ' ')
            {
                printf("La cadena no debe terminar con espacio. Intente de nuevo.\n");
                tieneNumeros = 1;
                break;
            }
            if (cadena[i] >= '0' && cadena[i] <= '9')
            {
                printf("La cadena no debe contener números. Intente de nuevo.\n");
                tieneNumeros = 1;
                break;
            }
        }
    } while (tieneNumeros);
}

// Función para verificar si una cadena es un palíndromo
int esPalindromo(char cadena[])
{
    int i, con;
    con = strlen(cadena) - 1;

    for (i = 0; i < con; i++, con--)
    {
        if (cadena[i] != cadena[con])
        {
            return 0; // No es palíndromo
        }
    }
    return 1; // Es palíndromo
}