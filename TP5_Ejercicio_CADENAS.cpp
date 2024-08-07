#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <cstring>

int PASSWORD();

int main(){
	system("title PROGRAMA SUPER SEGURO");
	system("color b");
	
	if(PASSWORD() == 0)printf("\n\tAcceso Permitido");
	else printf("\n\tAcceso Denegado");
	
}
int PASSWORD(){
	char cadena[55];
	char cadena2[]= "ariel";
	
	printf("\n\tIngrese la contraseña: ");
	gets(cadena);
	
	int validar = strcmp(cadena, cadena2);
	return validar;
}
