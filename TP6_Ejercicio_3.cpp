#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <cstring>
#include <time.h>

int main(){
	int matrizN[5][5], vectorCantidadPares[5];
	srand(time(NULL));
	
	for(int fila = 0; fila < 5; fila++){
		vectorCantidadPares[fila] = 0;
		for(int columna = 0; columna < 5; columna++){
			matrizN[fila][columna] = 1 + rand() % (99);
		}
	}
	
	for(int fila = 0; fila < 5; fila++){
		printf("\n");
		for(int columna = 0; columna < 5; columna++){
			if(matrizN[fila][columna]%2 == 0){
				matrizN[fila][columna] = -1;
				vectorCantidadPares[fila]++;
			}
			printf("\t%2.d", matrizN[fila][columna]);
		}
		printf("\n");
	}
	
	printf("\n\t");
	for(int i=0; i<20;i++)printf("--");
	printf("\n\t");
	
	for(int fila = 0; fila<5; fila++){
		printf("\n\t En la fila %d hay %d numeros pares", fila, vectorCantidadPares[fila]);
	}
}