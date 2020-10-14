#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moto.h"

int altaMoto(eMoto moto[], eColor color[], eTipo tipo[], int tam, int tam_c, int tam_t, int idMoto)
{
    int error=1;
    eMoto nuevaMoto;//auxiliar para cargar una nueva moto
    int indice;


    if(moto != NULL && color != NULL && tipo!= NULL && tam > 0 &&tam_c > 0&&tam_t>0&& idMoto>0)//validacion de datos de entrada
    {
        indice = buscarLibre(moto, tam); //se le da a indice el valor que retorna la funcion buscarLibre
        if(indice==-1)//Si indice es menor a 0
        {
            printf("No hay lugar, sistema completo\n");
        }
        else //Si no....
        {
            nuevaMoto.idMoto = idMoto;//1 Se toma el dato de nuevo id que se da al principio y se le asigna a la nueva moto

            nuevaMoto.isEmpty=0;//2 Se declara isEmpty en 0 para indicar que el indice esta cargado

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(nuevaMoto.marca);//3se guarda la marca

            mostrarTipos(tipo, tam_t);
            printf("Ingrese id Tipo (1000 a 1003): ");
            scanf("%d", &nuevaMoto.tipo.idTipo);//4se guarda el tipo
            while(nuevaMoto.tipo.idTipo < 1000 || nuevaMoto.tipo.idTipo>1003)
            {
                printf("Error, ingrese id de Tipo (1000 a 1003): ");
                scanf("%d", &nuevaMoto.tipo.idTipo);
            }

            printf("\n\n");

            mostrarColores(color, tam_c);
            printf("Ingrese un id de color (10000 a 10004): ");
            scanf("%d", &nuevaMoto.color.idColor);//5se guarda la altura
            while(nuevaMoto.color.idColor < 10000 || nuevaMoto.color.idColor>10004)
            {
                printf("Error, ingrese id de Color(10000 a 10004): ");
                scanf("%d", &nuevaMoto.color.idColor);
            }

            printf("\n\n");
            printf("Ingrese una cilindrada(50, 125, 500, 600, 750): ");
            scanf("%d", &nuevaMoto.cilindrada);
            while(nuevaMoto.cilindrada!= 50 && nuevaMoto.cilindrada != 125 && nuevaMoto.cilindrada != 500 && nuevaMoto.cilindrada != 600 && nuevaMoto.cilindrada != 750)
            {
                printf("Error, ingrese una cilindrada valida(50, 125, 500, 600, 750): ");
                scanf("%d", &nuevaMoto.cilindrada);
            }

            moto[indice]=nuevaMoto;//Se pasan todos los datos guardados en el auxiliar hacia el vector usando la variable indice para marcar la posicion en el vector
            error =0;//se retornan 0 errores
        }
    }
    return error;
}


int buscarLibre(eMoto moto[], int tam)
{
    int indice=-1;//Dentro del tamaño de la funcion el indice puede ser 0 o mayor
    if(moto!=NULL && tam>0)
    {
       for(int i=0; i<tam; i++)
        {
            if(moto[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;//retorna el valor del indice vacio en el vector
}

int inicializar(eMoto moto[], int tam)
{
    int error=1; //comienza con un error

    if(moto != NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
    {
        for(int i=0; i<tam; i++)//analiza el tamaño del vector
        {
            moto[i].isEmpty =1; //el lugar esta vacio
        }
        error= 0; //error 0 el programa funciona
    }
    return error;
}

int mostrarMotos(eMoto moto[],eColor color[], eTipo tipo[], int tam, int tam_c, int tam_t)
{
   int error=1;//comienza con un error hasta que la funcion dia lo contrario

    if(moto!= NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
    {

        printf("      Id             Marca        Color       Tipo     Cilindrada \n");
        printf(" -----------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)//analiza el tamaño del vector
        {
            mostrarMoto(moto[i], tipo, color, tam_c, tam_t);
        }
        error= 0;//Una vez verificado que sea un vector de tamaño mayor a 0 devuelvo 0 errores
    }
    return error;
}
void mostrarMoto(eMoto moto, eTipo tipo[], eColor color[], int tam_c, int tam_t)
{
        char auxColor[20];
        char auxTipo[20];

        if(cargarColoryTipo(tipo, color, auxColor, auxTipo, moto.color.idColor, moto.tipo.idTipo, tam_c, tam_t)==0)
        {
            printf("    %5d      %12s   %10s   %10s     %3d\n", moto.idMoto ,moto.marca, auxColor, auxTipo,moto.cilindrada);//Imprime los datos de la persona segun su posicion en el vector
        }else
        {
        printf("Problemas para recuperar descripciones\n\n");
        }

}

int cargarColoryTipo( eTipo tipo[], eColor color[], char auxColor[], char auxTipo[], int idC, int idT, int tam_c, int tam_t)
{
    int error=1;

        for(int i=0;i<tam_c;i++)
        {
            if(idC==color[i].idColor)
            {
                strcpy(auxColor, color[i].nombreColor);
                error=0;

            }
        }

        for(int i=0;i<tam_t;i++)
        {
            if(idT==tipo[i].idTipo)
            {
                strcpy(auxTipo, tipo[i].descripcionTipo);
                error=0;

            }
        }
    return error;
}

int modificarMoto(eMoto moto[],eColor color[],eTipo tipo[], int tam_c,int tam_t, int tam_m)
{
    int error=1;
    int indice;
    int id;
    char confirmar;
    char modificar;

    if(moto !=NULL && tam_m >0)//validacion de datos de entrada
    {
        system("cls");//Se limpia la pantalla
        printf("             ************** MODIFICAR MOTO **************\n\n");
        mostrarMotos(moto, color, tipo, tam_m, tam_c, tam_t);//Funcion MostrarPersonas para ver los numeros de legajo
        printf("Ingrese id Moto: ");
        scanf("%d", &id);
        while(id<3000)
        {
            printf("Error, ingrese id Moto: ");
            scanf("%d", &id);
        }
        indice = buscarMoto(moto, tam_m, id);//la variable indice toma el valor retornado por la funcion buscarMoto

        if(indice==-1)//Si no hay nada cargado se le da el valor -1
        {
            printf("No se encontro el id de la moto\n\n");
        }
        else
        {
            printf("a Color\n");
            printf("b Cilindrada\n");
            printf("Que desea modificiar?: ");
            fflush(stdin);
            scanf("%c", &modificar);
            modificar = tolower(modificar);
            while(modificar != 'a' && modificar != 'b')
            {
                printf("a Color\n");
                printf("b Cilindrada\n");
                printf("Ingrese una opcion valida, que desea modificiar?: ");
                fflush(stdin);
                scanf("%c", &modificar);
                modificar = tolower(modificar);
            }



            switch(modificar)
            {
            case 'a':
                mostrarColores(color, tam_c);
                printf("Ingrese id de Color(10000 a 10004): ");
                scanf("%d", &moto[indice].color.idColor);

                while(moto[indice].color.idColor < 10000 || moto[indice].color.idColor>10004)
                {
                    printf("Error, ingrese id de Color(10000 a 10004): ");
                    scanf("%d", &moto[indice].color.idColor);
                }
                break;

            case 'b':
                printf("Ingrese una nueva cilindrada(50, 125, 500, 600, 750): ");
                scanf("%d", &moto[indice].cilindrada);
                while(moto[indice].cilindrada!= 50 && moto[indice].cilindrada != 125 && moto[indice].cilindrada != 500 && moto[indice].cilindrada != 600 && moto[indice].cilindrada != 750)
                {
                    printf("Error, ingrese una cilindrada valida(50, 125, 500, 600, 750): ");
                    scanf("%d", &moto[indice].cilindrada);
                }
                break;
            }
            printf("Desea confirmar el cambio?(s=Si o n=No): ");
            fflush(stdin);
            scanf("%c", &confirmar);
            while(confirmar!='s' && confirmar!='n')
            {
                printf("Error, confirmar el cambio?(s=Si o n=No): ");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
            }
            if(confirmar=='s')
            {
                error=0;
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}

int buscarMoto(eMoto moto[], int tam, int id)
{
    int indice;//

    for(int i=0; i<tam; i++)
    {
        if(moto[i].idMoto==id&&moto[i].isEmpty==0)//se revisa los legajos del vector ingresado hasta encontrar el que es igual al numero de legajo ingresado y que el indice este cargado"0"
        {
            indice=i;//Se le da el valor a indice donde esta cargado el numero de legajo que buscamos
            break;
        }
        else
        {
            indice= -1;
        }
    }
    return indice;
}

int bajaMoto(eMoto moto[],eColor color[], eTipo tipo[], int tam_m, int tam_c, int tam_t)
{
    int error=1;
    int indice;
    int id;
    char confirma;

    if(moto != NULL && color != NULL && tipo!= NULL && tam_m > 0 &&tam_c > 0&&tam_t>0)//validacion de datos de entrada
    {

        printf("             ************** BAJA MOTO **************\n\n");
        mostrarMotos(moto, color, tipo, tam_m,tam_c,tam_t);//Funcion mostrarMoto para ver los numeros de id
        printf("Ingrese id de moto: ");
        scanf("%d", &id);
        while(id<3000)
        {
            printf("Error, ingrese id Moto: ");
            scanf("%d", &id);
        }
        indice = buscarMoto(moto, tam_m, id);//la variable indice toma el valor retornado por la funcion buscarMoto

        if(indice==-1)//Si no hay nada cargado se le da el valor -1
        {
            printf("No hay ninguna moto con ese id\n\n");
        }
        else
        {
            mostrarMoto(moto[indice], tipo, color, tam_c,tam_t);//Se muestra la moto guardada en el indice indicado
            printf("Confirma eliminar a la Moto?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma=='s')
            {
                moto[indice].isEmpty=1;//Se vacia isEmpty en el indice indicado dentro del vector
                printf("\nLa moto fue borrada\n");
                error=0;//0errores
            }
            else
            {
                error=2;//si el usuario cancela la baja devuelve un 2
            }
        }
    }
    return error;
}
