#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moto.h"
#include "harcodeo.h"

#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_M 3
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;



typedef struct
{
    int idTrabajo;
    eMoto moto;
    eServicio servicio;
    eFecha fechaTrabajo;
}eTrabajo;
//COMIENZO ABM MOTOS SERVICE

char menu();
int main()
{


    char seguir = 's';
    char confirma;
    int idProxMoto=3000;
    int proximoIdTipo=1000;
    int proximoIdColor=10000;
    int proximoIdServicio=20000;
    int banderaAlta=0;
    eTipo tipo[TAM_T];
    eColor color[TAM_C];
    eServicio servicio[TAM_S];
    eMoto moto[TAM_M];
    proximoIdTipo+=harcodearTipos(tipo, TAM_T, 4);
    proximoIdColor+=harcodearColor(color, TAM_C, 5);
    proximoIdServicio+=harcodearServicios(servicio, TAM_S, 4);
    inicializar(moto, TAM_M);


    do
    {
        switch(menu())
        {

        case 'a':
            if(altaMoto(moto,color,tipo, TAM_M,TAM_C,TAM_T, idProxMoto)==0)
            {
                idProxMoto++;
                banderaAlta=1;
                printf("Alta exitosa!!!!\n\n");
            }
            else
            {
                printf("Problema al realizar el alta.....\n");
            }
            break;
        case 'b':
            if(banderaAlta==1)
            {
                modificarMoto(moto, color, tipo, TAM_C,TAM_T,TAM_M);
            }else{
                printf("No se puede mostrar las motos sin antes dar el alta\n");
            }

            break;
        case 'c':
            if(banderaAlta==1)
            {
                bajaMoto(moto,color,tipo,TAM_M,TAM_C,TAM_T);
            }else{
                printf("No se puede mostrar las motos sin antes dar el alta\n");
            }
            break;
        case 'd':
            if(banderaAlta==1)
            {
               mostrarMotos(moto,color,tipo,TAM_M,TAM_C,TAM_T);
            }else{
                printf("No se puede mostrar las motos sin antes dar el alta\n");
            }
            break;
        case 'e':
            mostrarTipos(tipo, TAM_T);
            break;
        case 'f':
            mostrarColores(color, TAM_C);
            break;
        case 'g':
            mostrarServicios(servicio, TAM_S);
            break;
        case 'h':

            break;
        case 'i':

            break;

        case 'x':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    char opcion;
    system("cls");

    printf(" -----SERVICE MOTOS------\n");
    printf(" |                      |\n");
    printf(" | a ALTA MOTO          |\n");
    printf(" | b MODIFICAR MOTO     |\n");
    printf(" | c BAJA MOTO          |\n");
    printf(" | d LISTAR MOTOS       |\n");
    printf(" | e LISTAR TIPOS       |\n");
    printf(" | f LISTAR COLORES     |\n");
    printf(" | g LISTAR SERVICIOS   |\n");
    printf(" | h ALTA TRABAJO       |\n");
    printf(" | i LISTAR TRABAJO     |\n");
    printf(" | X Salir              |\n");
    printf(" |                      |\n");
    printf(" ------------------------\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    while(opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd' && opcion != 'e' && opcion != 'f' && opcion != 'g' && opcion != 'h' && opcion != 'i' && opcion != 'x')
    {
        printf("Error, ingrese opcion: ");
        fflush(stdin);
        opcion = tolower(getchar());
    }
    return opcion;
}
