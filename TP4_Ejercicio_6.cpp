/*
Escribir un programa que lea un conjunto de ternas hasta la terna (0,0,0) y para cada
uno determine mediante una función tipo booleana (que devuelva true o false) si los
tres valores son iguales. Por fin de proceso mostrar la cantidad de ternas que
hicieron verdadera la función en el programa principal. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cabecera(void);
bool validarDatos(int n1, int n2, int n3);

int main(){
	int v1 = 1,v2 = 1,v3 = 1;
	system("color A");
	cabecera();
	while(v1!=0 && v2!=0 && v3!=0) {
		printf("\n\t Ingrese el valor 1: ");
		scanf("%d", &v1);
		
		printf("\n\t Ingrese el valor 2: ");
		scanf("%d", &v2);
		
		printf("\n\t Ingrese el valor 3: ");
		scanf("%d", &v3);
		
		cabecera();
		if(validarDatos(v1,v2,v3)){
			printf("\n\t La terna (%d, %d, %d) tiene los 3 numeros iguales! \n",v1,v2,v3);
			printf("\n\t *********************************** \n");
		}
		else{
			printf("\n\t La terna (%d, %d, %d) tiene los 3 numeros no son iguales! \n",v1,v2,v3);
			printf("\n\t *********************************** \n");
		}
	}	
}

void cabecera(void){
	system("cls");
	printf("\n\t\t TP 4 - Ejercicio 5");
	printf("\n\n\t *********************************** \n");
}

bool validarDatos(int n1, int n2, int n3){
	if (n1==n2 && n2==n3) return true;
	return false;
}
