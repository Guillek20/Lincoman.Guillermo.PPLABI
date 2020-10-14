#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "harcodeo.h"

#include "dataStoreMotos.h"

int harcodearTipos(eTipo tipo[], int tam, int cant)
{
    int retorno = -1;
    if(tipo != NULL && tam > 0 && cant <=tam)
    {
        retorno=0;
        for(int i =0; i< cant; i++)
        {
            tipo[i].idTipo=idTipo[i];
            strcpy(tipo[i].descripcionTipo, descTipo[i]);
            retorno++;
        }
    }
    return retorno;
}

int harcodearServicios(eServicio servicio[], int tam, int cant)
{
    int retorno = -1;
    if(servicio != NULL && tam > 0 && cant <=tam)
    {
        retorno=0;
        for(int i =0; i< cant; i++)
        {
            servicio[i].precio=precioServicios[i];
            servicio[i].idServicio=idColor[i];
            strcpy(servicio[i].descripcionServicio, nombreServicios[i]);
            retorno++;
        }
    }
    return retorno;
}

int harcodearColor(eColor color[], int tam, int cant)
{
    int retorno = -1;
    if(color != NULL && tam > 0 && cant <=tam)
    {
        retorno=0;
        for(int i =0; i< cant; i++)
        {
            color[i].idColor=idColor[i];
            strcpy(color[i].nombreColor, colores[i]);
            retorno++;
        }
    }
    return retorno;
}

int mostrarTipos(eTipo tipo[], int tam)
{
    int error=1;//comienza con un error hasta que la funcion dia lo contrario

    if(tipo!= NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
    {

        printf("      Id   |         Tipo \n");
        printf(" -------------------------\n");
        for(int i=0; i<tam; i++)//analiza el tamaño del vector
        {
            mostrarTipo(tipo[i]);
        }
        error= 0;//Una vez verificado que sea un vector de tamaño mayor a 0 devuelvo 0 errores
    }

    return error;
}

void mostrarTipo(eTipo tipo)
{

    printf("    %4d      %12s\n", tipo.idTipo ,tipo.descripcionTipo);//Imprime los datos de las motos segun su posicion en el vector
}



int mostrarColores(eColor color[], int tam)
{
    int error=1;//comienza con un error hasta que la funcion dia lo contrario

    if(color!= NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
    {

        printf("      Id     |        Color \n");
        printf(" ---------------------------\n");
        for(int i=0; i<tam; i++)//analiza el tamaño del vector
        {
            mostrarColor(color[i]);
        }
        error= 0;//Una vez verificado que sea un vector de tamaño mayor a 0 devuelvo 0 errores
    }

    return error;
}

void mostrarColor(eColor color)
{
    printf("    %5d      %12s\n", color.idColor ,color.nombreColor);//Imprime los datos de las motos segun su posicion en el vector
}

int mostrarServicios(eServicio servicio[], int tam)
{
   int error=1;//comienza con un error hasta que la funcion dia lo contrario

    if(servicio!= NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
    {

        printf("      Id     |    Servicio   |   Precio  \n");
        printf(" -------------------------------------\n");
        for(int i=0; i<tam; i++)//analiza el tamaño del vector
        {
            mostrarServicio(servicio[i]);
        }
        error= 0;//Una vez verificado que sea un vector de tamaño mayor a 0 devuelvo 0 errores
    }
    return error;
}

void mostrarServicio(eServicio servicio)
{
    printf("    %5d       %10s        %3d\n", servicio.idServicio ,servicio.descripcionServicio, servicio.precio);//Imprime los datos de la persona segun su posicion en el vector
}
