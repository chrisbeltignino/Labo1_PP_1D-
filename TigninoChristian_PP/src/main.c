#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perro.h"

int main(void) {
	setbuf(stdout, NULL);

	ePerro lista[TAM];
	int opcion;
	int cantidadPerros = 3;
	int ultimoId = 100000;

	inicializarArray(lista, TAM);
	hardcodearPerro(lista, TAM);

	do
	{
		pedirEntero(&opcion, "-------------------------------------\n"
							 "1. RESERVAR ESTADIA\n"
							 "2. MODIFICAR ESTADIA\n"
							 "3. CANCELAR ESTADÍA\n"
							 "4. LISTAR ESTADÍAS\n"
							 "5. LISTAR PERROS\n"
							 "6. Promedio de edad de los perros\n"
							 "7. SALIR\n"
							 "-------------------------------------\n"
							 "Ingrese una opcion: ",
							 "-------------------------------------\n"
							 "1. RESERVAR ESTADIA\n"
							 "2. MODIFICAR ESTADIA\n"
							 "3. CANCELAR ESTADÍA\n"
							 "4. LISTAR ESTADÍAS\n"
							 "5. LISTAR PERROS\n"
							 "6. Promedio de edad de los perros\n"
							 "7. SALIR\n"
							 "-------------------------------------\n"
							 "Opcion invalida, reingrese: ", 1, 7);

		switch(opcion)
		{
			case 1:
			if (!producto_agregarProducto(lista, TAM, ultimoId))
				{
					cantidadPerros++;
					ultimoId++;
				}
				system("pause");
				break;
			case 2:
				producto_mostrarTodos(lista, TAM);
				if(!producto_borrarUno(lista, TAM))
				{
					cantidadPerros--;
				}
				system("pause");
				break;
			case 3:
				producto_mostrarTodos(lista, TAM);
				producto_subMenuModificarUno(lista, TAM);
				system("pause");
				break;
			case 4:
				if(cantidadPerros > 0)
				{
					producto_mostrarTodos(lista, TAM);
				}
				else
				{
					printf("\nNo hay lista cargados en el sistema.\n\n");
				}
				system("pause");
				break;
			case 5:
				if(cantidadPerros > 0)
				{
					producto_ordenarlistaPorPrecioAsc(lista, TAM);
				}
				else
				{
					printf("\nNo hay lista cargados en el sistema.\n\n");
				}
				system("pause");
				break;
			case 6:
				if(cantidadPerros > 0)
				{
					producto_ordenarlistaPorDescripcionAsc(lista, TAM);
				}
				else
				{
					printf("\nNo hay lista cargados en el sistema.\n\n");
				}
				system("pause");
				break;
			case 7:
				printf("\nSaliendo...\nPrograma terminado.\n");
				break;
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}
