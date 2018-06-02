#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 20

int main()
{
    EPersona persona[TAM];
    EPersona* pPersona;

    char seguir='s';
    int opcion=0;
    int i;
    int contMenor18 = 0, cont19a35 = 0, contMayor35 = 0;

    pPersona = persona;

    inicializarPersona(pPersona, TAM); // INICIA TODOS LAS POSICIONES EN 0(ESTAN VACIAS LOGICAMENTE)
    jarcodear(pPersona);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre (De A hasta Z)\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaPersona(pPersona, TAM);
                system("cls");
                break;

            case 2:
                system("cls");
                borrarPersona(pPersona,TAM);
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                ordenarPersonas(pPersona,TAM);
                printf("\n"); //<---------- PRINTF para manterner orden;
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                for(i=0; i<TAM; i++)
                {
                    if((persona+i)->estado==1)
                    {
                            if((persona+i)->edad<19)
                            {
                                contMenor18++;
                            }
                                else
                                {
                                    if((persona+i)->edad>18 && (persona+i)->edad< 35)
                                    {
                                        cont19a35++;
                                    }
                                    else
                                    {
                                        contMayor35++;
                                    }
                                }
                    }
                }

                graficoEdades(contMenor18,cont19a35,contMayor35);

                contMenor18 = 0;
                cont19a35 = 0;
                contMayor35 = 0;

                system("cls");

                break;

            case 5:
                seguir = 'n';
                break;

            default:
                system("cls");
                printf("Opcion inexistente. Ingrese nuevamente una opcion.");
                system("pause");
                system("cls");
                break;
        }
    }

    return 0;
}
