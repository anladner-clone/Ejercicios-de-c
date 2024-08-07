#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

int vectorDeEstadistica[10];

int main(){
	system("color b");
	int num,indice;
	srand(time(NULL)); // inicializar n° aleat.   
	for(int i = 0; i < 80; i++){
		num = 1 + rand() % (99);
		indice = num/10;
		vectorDeEstadistica[indice]+=1;
	}
	
	for(int linea = 0; linea < 10; linea++){
		for(int caracter = 0; caracter < vectorDeEstadistica[linea]; caracter++){
			if(caracter==0)printf("\n\t%d0 - %2.d   |  ", linea, (linea*10)+9);
			printf(" * ");
		}
	}
	
}
