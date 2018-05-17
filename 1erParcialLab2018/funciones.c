#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "funciones.h"


void hardcodearUsuarios(eUsuario usuario[], int tam)
{
    int i;

    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char apellido[][20]= {"Perez","Diaz","Franco","Aguirre"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    for(i=0;i<tam;i++)
    {
        strcpy(usuario[i].nombre,nombre[i]);
        strcpy(usuario[i].tarjeta,tarjeta[i]);
        strcpy(usuario[i].direccion,direccion[i]);
        strcpy(usuario[i].apellido,apellido[i]);
        usuario[i].id=id[i];

        usuario[i].estado = OCUPADO;
    }
}


int eUsuario_alta(eUsuario listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;


    indice = eUsuario_buscarLugarLibre(listado,limite);

        if(indice >= 0)
        {
            retorno = 0;
            id = eUsuario_siguienteId(listado,limite);

            printf("Ingrese nombre:");
            fflush(stdin);
            gets(listado[indice].nombre);

            printf("Ingrese tarjeta de credito (Ej. XXX-XXX):");
            fflush(stdin);
            gets(listado[indice].tarjeta);

            printf("Ingrese direccion/calle de domicilio:");
            fflush(stdin);
            gets(listado[indice].direccion);

            listado[indice].id = id;
            listado[indice].estado = OCUPADO;


        }
        else
        {
            printf("No hay lugar para ingresar un nuevo cliente\n\n");
        }

    return retorno;
}

int eUsuario_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//////////////////////////////////////


int eUsuario_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }
            }
        }
    }

    return retorno+1;
}

int inicializarUsuarios(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].id= 0;
        retorno = 0;
    }
    return retorno;
}

int eUsuario_modificacion(eUsuario listado[] ,int limite)
{
    int retorno = -1;
    int aux;
    int i;

    char auxRta;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //Devuelve -2 si lograr pedir un ID a modificar pero no puede modificar nada

        mostrarUsuarios(listado,limite);

        printf("\nIngrese su ID para poder realizar modificaciones:");
        scanf("%d",&aux);

        for(i=0;i<limite;i++)
        {
            if(listado[i].id == aux)
            {
               system("cls");
               printf("Seguro desea modificar datos de la tarj. de credito del usuario %s? S/N\n",listado[i].nombre);
               fflush(stdin);
               auxRta = getch();

               while(auxRta != 's' && auxRta != 'S' && auxRta != 'n' && auxRta != 'N')
               {
                   printf("ERROR. Ingrese S para confirmar o N para cancelar modificacion:\n");
                   fflush(stdin);
                   auxRta = getch();
               }

               if(auxRta == 's' || auxRta == 'S')
               {
                   printf("\nIngrese nuevo numero de tarj. de credito (Ej. XXX-XXX):");
                   fflush(stdin);
                   gets(listado[i].tarjeta);

                   retorno = 0;
                   printf("\nCambio realizado con exito!!\n\n");
                   break;
               }
               else
               {
                   printf("\nModificacion cancelada\n\n");
                   break;
               }
            /*
               if(auxRta != 's' || auxRta != 'S')
               {
                   printf("\nIngrese nuevo numero de tarj. de credito (Ej. XXX-XXX):");
                   fflush(stdin);
                   gets(listado[i].tarjeta);

                   printf("\nCambio realizado con exito!!\n\n");
                   break;
               }
               if(auxRta == 'N' || auxRta == 'n')
               {
                   printf("\nModificacion cancelada\n\n");
                   break;
               }
               */
            }
        }
    }

    return retorno;
}

int eUsuario_baja(eUsuario listado[],int limite)
{
    int aux;
    int i;
    int retorno = -1;
    char auxRta;

    mostrarUsuarios(listado,limite);

    printf("\nIngrese su ID para realizar la baja:");
    scanf("%d",&aux);

    for(i=0;i<limite;i++)
    {
        if(listado[i].id == aux)
        {
            system("cls");
            printf("Seguro que desea realizar la baja del usuario %s? S/N\n",listado[i].nombre);
            fflush(stdin);
            auxRta = getch();

            while(auxRta != 's' && auxRta != 'S' && auxRta != 'n' && auxRta != 'N')
               {
                   printf("ERROR. Ingrese S para confirmar o N para cancelar baja:\n");
                   fflush(stdin);
                   auxRta = getch();
               }

               if(auxRta == 's' || auxRta == 'S')
               {
                   printf("\nBaja de usuario realizada con exito!\n");
                    listado[i].estado = LIBRE;
                   retorno = 0;
                   break;
               }
               else
               {
                   printf("\nBaja cancelada\n\n");
                   break;
               }

            break;
        }
    }


    return retorno;
}

void mostrarUsuarios(eUsuario listado[],int limite)
{
    int i;

    printf("ID USUARIO\tNOMBRE\t\tDIRECCION\tNro. TARJETA\n\n");

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            printf("%d%21s%18s%17s\n",listado[i].id,listado[i].nombre,listado[i].direccion,listado[i].tarjeta);
        }
    }
}


void inicializarAutos(eAuto listado[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].idAuto = 0;
    }

}

void hardcodearAutos(eAuto listado[], int limite)
{
    int i;

    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]={1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    for(i=0;i<limite;i++)
    {
        listado[i].idAuto = id[i];
        listado[i].id = propietario[i];
        strcpy(listado[i].patente,patente[i]);
        listado[i].marca = marca[i];

        listado[i].estado = OCUPADO;
    }
}

int eAuto_alta(eAuto listadoA[],int limiteA,eUsuario listadoU[],int limiteU)
{
    int retorno = -1;
    int i;
    int flag = -1;

    int id;
    int indice;
    int aux;

    mostrarUsuarios(listadoU,limiteU);

    printf("\nIngrese ID del usuario que realizara ingreso de auto:");
    scanf("%d",&aux);

    system("cls");

    for(i=0;i<limiteU;i++)
    {
        if(listadoU[i].id == aux)
        {
            retorno = -2;
            indice = eAuto_buscarLugarLibre(listadoA,limiteA);

            if(indice >= 0)
            {
                flag = 0;
                retorno = 0;
                id = eAuto_siguienteId(listadoA,limiteA);

                printf("Ingrese patente:");
                fflush(stdin);
                gets(listadoA[indice].patente);

                printf("Ingrese marca del automovil\n\n1-Alpha Romeo\n2-Ferrari\n3-Audi\n4-Otro\n\n");
                scanf("%d",&listadoA[indice].marca);

                listadoA[indice].idAuto = id;
                listadoA[indice].estado = OCUPADO;
                listadoA[indice].id = aux;


                printf("Alta de automovil realizada!\n\n");
            }
            else
            {
                printf("\nNo hay lugar para estacionar automovil\n");

            }
        }
    }

        if(flag == -1)
        {
            printf("No se podido encontrar el usuario\n\n");
        }


    return retorno;

}

int eAuto_buscarLugarLibre(eAuto listado[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int eAuto_siguienteId(eAuto listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idAuto>retorno)
                    {
                         retorno=listado[i].idAuto;
                    }
            }
        }
    }

    return retorno+1;
}



int finalizarAuto(eUsuario listadoU[],int limiteU,eAuto listadoA[],int limiteA)
{
    int i,j,aux;
    int auxEstadia;
    int retorno = -1;
    char rta;

    int valorEstadia;

    mostrarAutos(listadoA,limiteA);

    printf("\nIngrese ID de auto que desea dar de baja:");
    scanf("%d",&aux);

    for(i=0;i<limiteA;i++)
    {
        if(listadoA[i].idAuto == aux)
        {
            retorno = -2; //ENCONTRO EL AUTO
            auxEstadia = devolverHorasEstadia();

            switch(listadoA[i].marca)
            {
                case ALPHA_ROMEO:
                    valorEstadia = auxEstadia*150;
                    break;
                case FERRARI:
                    valorEstadia = auxEstadia*175;
                    break;
                case AUDI:
                    valorEstadia = auxEstadia*200;
                    break;
                case OTRO:
                    valorEstadia = auxEstadia*250;
                    break;
            }

            for(j=0;j<limiteU;j++)
            {
                if(listadoA[i].id == listadoU[j].id)
                {
                    system("cls");
                    printf("Nombre Propietario:%s\nPatente:%s\n",listadoU[j].nombre,listadoA[i].patente);
                    switch(listadoA[i].marca)
                    {
                    case ALPHA_ROMEO:
                        printf("Marca:Alfa Romeo\n");
                        break;
                    case FERRARI:
                        printf("Marca:Ferrari\n");
                        break;
                    case AUDI:
                        printf("Marca:Audi\n");
                        break;
                    case OTRO:
                        printf("Marca:Otro\n");
                        break;
                    }
                    printf("Valor estadia: $%d\n\n",valorEstadia);

                    printf("Confirmar egreso? S/N");
                    fflush(stdin);
                    rta = getch();

                    if(rta == 's' || rta == 'S')
                    {
                        listadoA[i].estado = LIBRE;
                        printf("\n\nEgreso de auto confirmado. Gracias por elegirnos!\n\n");
                    }
                    else
                    {
                        printf("\n\nSe ha cancelado el egreso del auto.\n\n");
                    }

                    retorno = 0;

                    break;
                }
            }
        }
    }

    return retorno;

}



void mostrarAutos(eAuto listado[], int limite)
{
    int i;
    char auxString[20];

    printf("ID AUTO\t\t MARCA\t\tPATENTE\n\n");

    //DECLAR UNA AUX STRING PARA PODER ALINEAR EL STRING CON EL NOMBRE DE LA MARCA. BASICAMENTE ES SOLO UNA CUESTION DE PROLIGIDAD

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            printf("%d\t\t",listado[i].idAuto);

            switch(listado[i].marca)
            {
            case ALPHA_ROMEO:
                strcpy(auxString,"Alfa Romeo");
                printf("%10s",auxString);
                break;
            case FERRARI:
                strcpy(auxString,"Ferrari");
                printf("%10s",auxString);
                break;
            case AUDI:
                strcpy(auxString,"Audi");
                printf("%10s",auxString);
                break;
            case OTRO:
                strcpy(auxString,"Otro");
                printf("%10s",auxString);
                break;
            }

            printf("%12s\n",listado[i].patente);
        }
    }
}


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}


int recaudacionTotal(eAuto listado[],int limite)
{
    int total = 0;
    int auxEstadia;
    int aux;
    int i;

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == OCUPADO)
        {

            auxEstadia = devolverHorasEstadia();

            switch(listado[i].marca)
            {
                case ALPHA_ROMEO:
                    aux = auxEstadia*150;
                    total = aux + total;
                    break;
                case FERRARI:
                    aux = auxEstadia*175;
                    total = aux + total;
                    break;
                case AUDI:
                    aux = auxEstadia*200;
                    total = aux + total;
                    break;
                case OTRO:
                    aux = auxEstadia*250;
                    total = aux + total;
                    break;
            }
        }
    }

    return total;
}

void recaudacionTotalxMarca(eAuto listado[],int limite)
{
    int i;
    int auxEstadia;
    int aux;

    int contAudi = 0;
    int contAlfa = 0;
    int contFerrari = 0;
    int contOtros = 0;

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            auxEstadia = devolverHorasEstadia();

            switch(listado[i].marca)
            {
                case ALPHA_ROMEO:
                    aux = auxEstadia*150;
                    contAlfa = aux + contAlfa;
                    break;
                case FERRARI:
                    aux = auxEstadia*175;
                    contFerrari = aux + contFerrari;
                    break;
                case AUDI:
                    aux = auxEstadia*200;
                    contAudi = aux + contAudi;
                    break;
                case OTRO:
                    aux = auxEstadia*250;
                    contOtros = aux + contOtros;
                    break;
            }
        }
    }

    printf("Recaudacion por autos ALFA ROMEO: $%d\nRecaudacion por autos FERRARI: $%d\nRecaudacion por autos AUDI: $%d\nRecaudacion por autos de OTRAS MARCAS: $%d\n\n",contAlfa,contFerrari,contAudi,contOtros);
    printf("\nTOTAL: %d\n",recaudacionTotal(listado,limite));
}


void mostrarAutosxUsuario(eUsuario listadoU[],int limiteU,eAuto listadoA[],int limiteA)
{
    int i,j;
    int aux;

    mostrarUsuarios(listadoU,limiteU);
    printf("\nIngrese ID del usuario para observar sus autos estacionado:");
    scanf("%d",&aux);

    system("cls");

    for(i=0;i<limiteU;i++)
    {
        if(listadoU[i].estado == OCUPADO && listadoU[i].id == aux)
        {

            printf("Automoviles estacionados del propietario %s:\n\n",listadoU[i].nombre);

            for(j=0;j<limiteA;j++)
            {
                if(listadoA[j].id == listadoU[i].id)
                {
                    switch(listadoA[j].marca)
                    {
                    case ALPHA_ROMEO:
                        printf("Alfa Romeo\n");
                        break;
                    case FERRARI:
                        printf("Ferrari\n");
                        break;
                    case AUDI:
                        printf("Audi\n");
                        break;
                    case OTRO:
                        printf("Otra marca\n");
                        break;
                    }
                }
            }
        }
    }
}


void mostrarUsuariosAudi(eUsuario listadoU[],int limiteU,eAuto listadoA[],int limiteA)
{
    int i,j;

    for(i=0;i<limiteU;i++)
    {
        if(listadoU[i].estado == OCUPADO)

            for(j=0;j<limiteA;j++)
            {
                if(listadoA[j].marca == AUDI && listadoA[j].id == listadoU[i].id)
                {
                    printf("Nombre:%s\nID usuario:%d\nDireccion:%s\nNro Tarjeta:%s\n\n",listadoU[i].nombre,listadoU[i].id,listadoU[i].direccion,listadoU[i].tarjeta);
                    break;
                }
            }
    }
}

void mostrarEstacionadoConPropietario(eUsuario listadoU[],int limiteU,eAuto listadoA[],int limiteA)
{
    int i,j;
    char auxString[20];

    ordenarxPatente(listadoA,limiteA);

    printf("PROPIETARIO\t\tMARCA\t\tPATENTE\n\n");

    for(i=0;i<limiteA;i++)
    {
        if(listadoA[i].estado == OCUPADO);
        {
            for(j=0;j<limiteU;j++)
            {
                if(listadoU[j].estado == OCUPADO && listadoA[i].id == listadoU[j].id)
                {
                    printf("%s\t\t",listadoU[j].nombre);

                    switch(listadoA[i].marca)
                    {
                    case ALPHA_ROMEO:
                        strcpy(auxString,"Alfa Romeo");
                        printf("%13s",auxString);
                        break;
                    case FERRARI:
                        strcpy(auxString,"Ferrari");
                        printf("%13s",auxString);
                        break;
                    case AUDI:
                        strcpy(auxString,"Audi");
                        printf("%13s",auxString);
                        break;
                    case OTRO:
                        strcpy(auxString,"Otro");
                        printf("%13s",auxString);
                        break;
                    }

                    printf("%16s\n",listadoA[i].patente);
                }
            }
        }
    }

    printf("\n");
}

void ordenarxPatente(eAuto listadoA[],int limiteA)
{
    int i,j;
    eAuto auxStruct;

    for(i=0;i<limiteA-1;i++)
    {
        for(j=i+1;j<limiteA;j++)
        {
            if(strcmp(listadoA[i].patente,listadoA[j].patente)>0)
            {

                auxStruct = listadoA[i];
                listadoA[i] = listadoA[j];
                listadoA[j] = auxStruct;

                /*
                strcpy(auxNombre,listadoA[i].patente);
                strcpy(listadoA[i].patente,listadoA[j].patente);
                strcpy(listadoA[j].patente,auxNombre);

                aux = listadoA[i].idAuto;
                listadoA[i].idAuto = listadoA[j].idAuto;
                listadoA[j].idAuto = aux;

                aux = listadoA[i].id;
                listadoA[i].id = listadoA[j].id;
                listadoA[j].id = aux;

                aux = listadoA[i].marca;
                listadoA[i].marca= listadoA[j].marca;
                listadoA[j].marca = aux;

                aux = listadoA[i].estado;
                listadoA[i].estado= listadoA[j].estado;
                listadoA[j].estado = aux;
                */
            }
        }
    }
}

