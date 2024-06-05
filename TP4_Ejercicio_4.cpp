/*
Un asilo factura a sus pacientes de acuerdo a su sexo y edad. El importe facturado a
un hombre es de $15000 por semana si su edad supera los 70 años y un extra, por
única vez, de $25000 si pasa de 75 años; si es mujer se le factura $14500 por
semana si la edad pasa de 60 con un extra, por única vez, de $25000 si pasa de 65
años.
Escribir un programa que lea el sexo (‘F’ o ‘M’) y la edad de una persona e imprima
cuanto debe abonar al cabo de P semanas.
Si la edad de las personas está por debajo de las consideradas debe imprimirse un
mensaje de error. Utilizar funciones como crea conveniente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cabecera(void);
float validacionDeCliente(int edad, char sexo, int cantSemana);

int main(){
	char s;
	int e, cantidadDeSemana;
	float importe;
	system("color A");

	do{ //Validar el sexo.
		cabecera();
		printf("\n\t Ingrese su sexo ('F', 'M'): ");
		scanf(" %c", &s);
	}while(s!='F' && s!='f' && s!='M' && s!='m');

	do{ //Validar para que edad no sea negativa.
		cabecera();
		printf("\n\t Ingrese su edad: ");
		scanf("%d", &e);
	}while(e<0);
	
	do{ //Validar para que cantidadDeSemana no sea negativa.
		cabecera();
		printf("\n\t Ingrese la cantidad de semana/s: ");
		scanf("%d", &cantidadDeSemana);
	}while(cantidadDeSemana<0);
	
	cabecera();
	importe = validacionDeCliente(e,s,cantidadDeSemana);
	
	printf("\n\t El importe total es: $%.2f", importe);
	
}

void cabecera(void){
	system("cls");
	printf("\n\t\t Programa UTN");
	printf("\n\n\t **************************** \n");
}

float validacionDeCliente(int edad, char sexo, int cantSemana){
	float importe;
	if((sexo=='M' || sexo=='m') && edad>70){
		importe = 15000*cantSemana;
		if(edad>75) importe += 25000;
	}else{
		importe = 14500*cantSemana;
		if(edad>65) importe += 25000;
	}
	return importe;
}
