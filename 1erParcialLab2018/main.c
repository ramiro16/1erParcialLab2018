#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "funciones.h"


int main()
{
    eUsuario usuario[TamU];
    eAuto automovil[TamA];

    char seguir='s';
    int opcion=0;
    int aux;

    inicializarUsuarios(usuario,TamU);
    inicializarAutos(automovil,TamA);
    hardcodearUsuarios(usuario,4);
    hardcodearAutos(automovil,10);

    while(seguir=='s')
    {
        printf("1- Alta de usuario\n");
        printf("2- Modificar datos de usuario\n");
        printf("3- Baja de usuario\n");
        printf("4- Ingreso de automovil\n");
        printf("5- Egreso de automovil\n");
        printf("6- Recaudacion total de estacionamiento\n");
        printf("7- Recaudacion total de estacionamiento por marca de auto\n");
        printf("8- Listar autos de usuario\n");
        printf("9- Mostrar datos de usuarios con Audi\n");
        printf("10- Mostrar propietario y auto, ordenados x patente\n\n");

        printf("11- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                aux = eUsuario_alta(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                eUsuario_modificacion(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                eUsuario_baja(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                eAuto_alta(automovil,TamA,usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                finalizarAuto(usuario,TamU,automovil,TamA);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                aux = recaudacionTotal(automovil,TamA);
                printf("La recaudacion total es:$%d\n\n",aux);
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                recaudacionTotalxMarca(automovil,TamA);
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                mostrarAutosxUsuario(usuario,TamU,automovil,TamA);
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                mostrarUsuariosAudi(usuario,TamU,automovil,TamA);
                system("pause");
                system("cls");
                break;
            case 10:
                system("cls");
                mostrarEstacionadoConPropietario(usuario,TamU,automovil,TamA);
                system("pause");
                system("cls");
                    break;
            case 11:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
