#ifndef ALTAMOTOS_H_INCLUDED
#define ALTAMOTOS_H_INCLUDED
#include "harcodeo.h"


typedef struct
{
    int idMoto;
    char marca[20];
    eTipo tipo;
    eColor color;
    int isEmpty;
    int cilindrada;
}eMoto;


int altaMoto(eMoto moto[], eColor color[], eTipo tipo[], int tam, int tam_c, int tam_t, int idMoto);

int buscarLibre(eMoto moto[], int tam);

int inicializar(eMoto moto[], int tam);

int mostrarMotos(eMoto moto[],eColor color[], eTipo tipo[], int tam, int tam_c, int tam_t);


void mostrarMoto(eMoto moto, eTipo tipo[], eColor color[], int tam_c, int tam_t);

int cargarColoryTipo( eTipo tipo[], eColor color[], char auxColor[], char auxTipo[], int idC, int idT, int tam_c, int tam_t);

int modificarMoto(eMoto moto[],eColor color[],eTipo tipo[], int tam_c,int tam_t, int tam_m);
int bajaMoto(eMoto moto[],eColor color[], eTipo tipo[], int tam_m, int tam_c, int tam_t);
int buscarMoto(eMoto moto[], int tam, int id);
#endif // ALTAMOTOS_H_INCLUDED
