#include <stdio.h>

//Libreria para generar numeros aleatorios
#include <time.h>
#include <stdlib.h>

int main()
{
    int arregloNum[15];
    int icont = 0;
    int jcont = 0;
    int suma = 0;

    srand(time(0));
    icont = 0;
    while(icont < 15)
    {
        arregloNum[icont] = rand() % 31;
        icont = icont + 1;
    }
    icont = 0;
    printf("El arreglo es: ");
    for (icont = 0; icont < 15; icont++) 
    {
        printf("%i" ,arregloNum[icont]);
        printf(",");
    }
    printf("\n");
    printf("\n");
    for (icont = 0; icont < 15; icont++)
    {
        suma = 0;
        for (jcont = 1; jcont < arregloNum[icont]; jcont++)
        {
            if (arregloNum[icont] % jcont == 0) {
                suma += jcont;
            }
        }
        if (suma < arregloNum[icont]) 
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