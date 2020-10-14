#ifndef HARCODEOMOTOS_H_INCLUDED
#define HARCODEOMOTOS_H_INCLUDED

typedef struct
{
    int idTipo;
    char descripcionTipo[20];
}eTipo;

typedef struct
{
    int idColor;
    char nombreColor[20];
}eColor;

typedef struct
{
    int idServicio;
    char descripcionServicio[25];
    int precio;
}eServicio;

int harcodearTipos(eTipo tipo[], int tam, int cant);
int harcodearColor(eColor color[], int tam, int cant);
int harcodearServicios(eServicio servicio[], int tam, int cant);
int mostrarTipos(eTipo tipo[], int tam);
void mostrarTipo(eTipo tipo);

int mostrarColores(eColor color[], int tam);
void mostrarColor(eColor color);

int mostrarServicios(eServicio servicio[], int tam);
void mostrarServicio(eServicio servicio);
#endif // HARCODEOMOTOS_H_INCLUDED
