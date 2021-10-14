#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#define TAM 5

typedef struct
{
    int id;
    char nombre[21];
    char raza[21];
    int edad;
    int estado;
} ePerro;

void producto_inicializarArray(ePerro lista[], int tam);
void hardcodearPerro(ePerro lista[], int tam);
