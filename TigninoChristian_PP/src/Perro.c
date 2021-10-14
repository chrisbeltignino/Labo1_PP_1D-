#include <stdio.h>
#include <stdlib.h>
#include "Perro.h"
#include "EstadiaDiaria.h"
#include <string.h>
#include <ctype.h>

void inicializarArray(ePerro lista[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		lista[i].estado = LIBRE;
	}
}

void hardcodearPerro(ePerro lista[], int tam)
{
    int i;
    int ids[]= {7000, 7001, 7002};
    char nombres[][21]= {"Lobo", "Sheila", "Reina"};
    char razas[][21] = {"Sharpei", "Golden", "Galgo"};
    int edades[] = {2, 12, 13};

    for(i=0; i<tam; i++)
    {
        lista[i].id = ids[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].raza, razas[i]);
        lista[i].edad = edades[i];
        lista[i].estado = OCUPADO;
    }
}

int producto_cargarPerro(ePerro lista[], int i, int ultimoId)
{
	int retorno = -1;

	lista[i].id = ultimoId + 1;
	pedirCadena(lista[i].nombre, "Ingrese la descripcion: ", "Descripcion invalida, hasta 21 caracteres, reingrese: ", 51);
	pedirCadena(lista[i].nombre, "Ingrese la descripcion: ", "Descripcion invalida, hasta 21 caracteres, reingrese: ", 51);
	pedirCadena(lista[i].raza, "Ingrese la nacionalidad (EEUU = 0, CHINA = 1, OTRO = 2): ", "Ingrese una nacionalidad valida  (EEUU = 0, CHINA = 1, OTRO = 2): ", 0, 2);
	pedirEntero(&lista[i].edad, "Ingrese el tipo (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", "Ingrese un tipo valido (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", 0, 3);

	printf("\nProducto a agregar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
	producto_mostrarUno(lista[i]);

	if(!producto_verificarConfirmacion("\nIngrese 's' para confirmar el alta del producto: "))
	{
		lista[i].estado = OCUPADO;
		retorno = 0;
	}
	return retorno;
}

int pedirTelefono(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
