#include <stdio.h>

void main(void)
{
	char cadena[100];
	
	printf("hola\n");
	printf("Introduce un texto: ");
	gets(cadena);
	printf("TEXTO INTRODUCIDO: %s", cadena);
}

