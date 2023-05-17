#include <stdio.h>

//Libreria para generar numeros aleatorios
#include <time.h>
#include <stdlib.h>

int main()
{
    int arregloNum[15];//creacion de un arreglos de 15 numeros
    int icont = 0;//variable para ubicar cada numero del arreglo
    int jcont = 0;//variable para controlar la suma de divisores
    int suma = 0;//variable para almacenar la suma de divisores

    srand(time(0));
    icont = 0;
    while(icont < 15)//iterativa para asignar un valor menor que 31 a los 15 numeros aleatorios
    {
        arregloNum[icont] = rand() % 31;
        icont = icont + 1;
    }
    icont = 0;
    printf("El arreglo es: ");//sentencia para imprimir los 15 numeros en pantalla
    for (icont = 0; icont < 15; icont++)
    {
        printf("%i" ,arregloNum[icont]);
        printf(",");
    }
    printf("\n");
    printf("\n");
    for (icont = 0; icont < 15; icont++)////sentencia para hallar la suma de divisores de cada numero
    {
        suma = 0;
        for (jcont = 1; jcont < arregloNum[icont]; jcont++)
        {
            if (arregloNum[icont] % jcont == 0) {
                suma += jcont;
            }
        }
        if (suma < arregloNum[icont])//sentencia para clasificar la suma de divisores de cada numero 
            {
            printf("%i - Deficiente\n",arregloNum[icont]);
            } 
            else if (suma == arregloNum[icont]) 
            {
            printf("%i - Perfecto\n",arregloNum[icont]);
            }
            else 
            {
            printf("%i - Abundante\n",arregloNum[icont]);
            } 
    } 

    return 0;         
}