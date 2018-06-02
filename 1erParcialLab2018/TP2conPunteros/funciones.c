#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void inicializarPersona(EPersona* pPersona, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        (pPersona+i)->estado = 0;
    }
}


void mostrarPersona(EPersona* persona, int tam)
{
    int i;

    printf("NOMBRE\t\t\t\tEDAD\t\t\t\tDNI\n\n");

    for(i=0;i<tam;i++)
    {
        if((persona+i)->estado == 1)
        {
            printf("%s\t\t\t\t%d\t\t\t\t%ld\n",(persona+i)->nombre,(persona+i)->edad,(persona+i)->dni);
        }
    }
}


int obtenerEspacioLibre(EPersona* pPersona, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if((pPersona+i)->estado == 0)
        {
            return i;
        }
    }
    return -1;
}

int altaPersona(EPersona* pPersona, int tam)
{
    int i, espacioLibre;
    int retorno = -1;
    int aux;
    long int auxDni;

    espacioLibre = obtenerEspacioLibre(pPersona, tam);

    for(i=0;i<tam;i++)
    {
        if(espacioLibre != -1)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets((pPersona+espacioLibre)->nombre);

            printf("Ingrese edad: ");
            scanf("%d",&aux);

            while(aux <= 0 || aux >= 100)
            {
                printf("\nEdad Invalida. Reingrese edad <1-99>: ");
                scanf("%d",&aux);
                system("cls");
            }

            (pPersona+espacioLibre)->edad = aux;

            printf("Ingrese DNI: ");
            scanf("%ld",&auxDni);

            while(auxDni <= 1000000)
            {
                printf("\nDNI Invalido. Reingrese DNI: ");
                scanf("%ld",&auxDni);
                system("cls");
            }

            (pPersona+espacioLibre)->dni = auxDni;

            (pPersona+espacioLibre)->estado = 1;

            retorno = 0;
            break;
        }
        else
        {
            printf("No hay espacio para agregar persona!\n\n");
            system("pause");
            break;
        }
    }


    return retorno;
}

int buscarPorDni(EPersona* persona,int dni)
{
    int i;
    int pos = -1;

    for(i=0;i<20;i++)
    {
        if((persona+i)->dni == dni)
        {
            pos = i;
        }
    }

    return pos;
}

int borrarPersona(EPersona* persona, int tam)
{
    int dni, pos,retorno = -1;
    char respuesta;

    printf("Ingrese DNI de la persona que desea borrar: ");
    scanf("%d",&dni);

    pos = buscarPorDni(persona, dni);

    if(pos != -1)
        {
            printf("\nSeguro que desea eliminar?...\n\nNombre:%s\tEdad:%d\tDNI:%ld\n\n",persona[pos].nombre,persona[pos].edad,persona[pos].dni);
            printf("\nIngrese S para confirmar, N para cancelar");
            fflush(stdin);
            respuesta=tolower(getch());
            while(respuesta != 's' && respuesta!= 'n')
                {
                    printf("\nRespuesta incorrecta. Reingrese respuesta: ");
                    fflush(stdin);
                    respuesta=getche();
                }
            if(respuesta =='s')
                {
                    printf("\nSe han borrado los datos.\n");
                    (persona+pos)->estado = 0;
                    retorno = 0;
                }
            else
                {
                    printf("\nNo se han eliminado los datos.\n");
                }
        }
        if(pos == -1)
        {
            printf("No se ha encontrado el DNI.\n");
        }

        return retorno;
}

void ordenarPersonas(EPersona* persona, int tam)
{
    int i,j;

    EPersona auxPersona;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp((persona+i)->nombre,(persona+j)->nombre) == 1)
            {
                auxPersona = *(persona+i);
                *(persona+i) = *(persona+j);
                *(persona+j) = auxPersona;
            }
        }
    }

    mostrarPersona(persona, tam);
}

void graficoEdades(int contMenor18, int cont19a35, int contMayor35)
{
    int i;
    int j;
    int max=0;
    int valor[3]={contMenor18,cont19a35,contMayor35};

    for (i = 0; i < 3; i++)
    {
        if (valor[i] > max)
        {
            max = valor[i];
        }
    }
    printf("\n");
    for (i = max; i > 0; i--)
    {
        printf("F%d",i);
        for (j = 0; j < 3; j++)
        {

            if (valor[j] >= i)
            {
                printf("\t  *");
            }
            else
            {
                printf("\t ");
            }
        }
        printf("\n");
    }
    printf("\t<19\t19-35\t >35\n");
    system("pause");
    system("cls");
}

void jarcodear(EPersona* persona)
{
    int i;

    int edad[5]={22,31,12,14,8};
    char nombre[5][25]={"ccccc","eeeee","zzzzz","aaaaaa","hhhhhh"};
    int estado[5] = {1,1,1,1,1};
    long int deEneI[5]={1111111,2222222,3333333,4444444,5555555};

    for(i=0;i<5;i++)
    {
        (persona+i)->edad = edad[i];
        (persona+i)->estado = estado[i];
        strcpy((persona+i)->nombre,nombre[i]);
        (persona+i)->dni = deEneI[i];
    }
}
