#include "datos.h"

#include <stdio.h>
#include <string.h>

void inicializarHabitaciones(THabitacion habitaciones[])
{
	habitaciones[0].id = 1;
	strcpy(habitaciones[0].descripcion,"Te encuentras en la entrada de la taberna de Melee Island. Desde aqui puedes oler los vomitos de los borrachos que vas a encontrar en su interior.");
	habitaciones[0].direcciones[0] = 4;
	habitaciones[0].direcciones[1] = 2;
	habitaciones[0].direcciones[2] = 0;
	habitaciones[0].direcciones[3] = 0;

	habitaciones[1].id = 2;
	strcpy(habitaciones[1].descripcion,"Las sombras del callejon en el que te encuentras te sobrecogen. Estas rodeado de montones de basura.");
	habitaciones[1].direcciones[0] = 0;
	habitaciones[1].direcciones[1] = 0;
	habitaciones[1].direcciones[2] = 0;
	habitaciones[1].direcciones[3] = 1;

	habitaciones[2].id = 3;
	strcpy(habitaciones[2].descripcion,"Estas en uno de los dormitorios de la taberna. Varias literas estan alineadas, permitiendo a muchos piratas dormir juntos en una misma habitacion.");
	habitaciones[2].direcciones[0] = 0;
	habitaciones[2].direcciones[1] = 0;
	habitaciones[2].direcciones[2] = 0;
	habitaciones[2].direcciones[3] = 4;

	habitaciones[3].id = 4;
	strcpy(habitaciones[3].descripcion,"El salon principal de la taberna. Decenas de piratas se encuentran aquí bebiendo, cantando, peleandose, vomitando, y metiendo mano a las doncellas del lugar. Si te diriges al norte, este u oeste podras visitar varias de las habitaciones del local.");
	habitaciones[3].direcciones[0] = 6;
	habitaciones[3].direcciones[1] = 3;
	habitaciones[3].direcciones[2] = 1;
	habitaciones[3].direcciones[3] = 5;

	habitaciones[4].id = 5;
	strcpy(habitaciones[4].descripcion,"Una gran cantidad de pucheros sucios estan amontonados en la cocina. Platos a medio comer, jarras medio llenas, y cubiertos sucios les hacen compañia.");
	habitaciones[4].direcciones[0] = 0;
	habitaciones[4].direcciones[1] = 4;
	habitaciones[4].direcciones[2] = 0;
	habitaciones[4].direcciones[3] = 0;
	
	habitaciones[5].id = 6;
	strcpy(habitaciones[5].descripcion,"Tras apartar una cortina accedes a un reservado. Es una zona exclusiva de la taberna a donde muy pocos piratas pueden acceder.");
	habitaciones[5].direcciones[0] = 0;
	habitaciones[5].direcciones[1] = 0;
	habitaciones[5].direcciones[2] = 4;
	habitaciones[5].direcciones[3] = 0;
}

void escribirDescripcion(THabitacion habitaciones, int habitacion)
{
	printf(habitaciones[habitacion].descripcion);
	printf("\n\n");
	printf("Salidas:");
	if (habitaciones[habitacion].direcciones[0] != 0) printf(" %c[4mNorte%c[24m",27,27);
	if (habitaciones[habitacion].direcciones[1] != 0) printf(" %c[4mEste%c[24m",27,27);
	if (habitaciones[habitacion].direcciones[2] != 0) printf(" %c[4mSur%c[24m",27,27);
	if (habitaciones[habitacion].direcciones[3] != 0) printf(" %c[4mOeste%c[24m",27,27);
	printf("\n\n");
	
}

void main(void)
{
	int habitacion = 0;
	int final = 0;
	char comando[250];
	int i;
	
	THabitacion habitaciones[6];
	inicializarHabitaciones(habitaciones);

	escribirDescripcion(habitaciones,habitacion);
	while (final == 0)
	{
		printf("Que hago ahora? - ");
		gets(comando);
		if (strcmp(comando,"m") == 0 || strcmp(comando,"mirar") == 0)
		{
			for (i=0;i<32;i++)
				printf("\n");
			escribirDescripcion(habitaciones,habitacion);
		}
		else if (strcmp(comando,"n") == 0 || strcmp(comando,"norte") == 0)
		{
			if (habitaciones[habitacion].direcciones[0] != 0)
			{
				habitacion = habitaciones[habitacion].direcciones[0] - 1;
				printf("\n\n");
				escribirDescripcion(habitaciones,habitacion);
			}
			else
				printf("\n\nNo puedo ir en esa direccion\n\n");

		}
		else if (strcmp(comando,"e") == 0 || strcmp(comando,"este") == 0)
		{
			if (habitaciones[habitacion].direcciones[1] != 0)
			{
				habitacion = habitaciones[habitacion].direcciones[1] - 1;
				printf("\n\n");
				escribirDescripcion(habitaciones,habitacion);
			}
			else
				printf("\n\nNo puedo ir en esa direccion\n\n");
		}
		else if (strcmp(comando,"s") == 0 || strcmp(comando,"sur") == 0)
		{
			if (habitaciones[habitacion].direcciones[2] != 0)
			{
				habitacion = habitaciones[habitacion].direcciones[2] - 1;
				printf("\n\n");
				escribirDescripcion(habitaciones,habitacion);
			}
			else
				printf("\n\nNo puedo ir en esa direccion\n\n");
		}
		else if (strcmp(comando,"o") == 0 || strcmp(comando,"oeste") == 0)
		{
			if (habitaciones[habitacion].direcciones[3] != 0)
			{
				habitacion = habitaciones[habitacion].direcciones[3] - 1;
				printf("\n\n");
				escribirDescripcion(habitaciones,habitacion);
			}
			else
				printf("\n\nNo puedo ir en esa direccion\n\n");
		}
		else
			printf("\n\nNo entiendo lo que dices\n\n");
		
	}
	

}




