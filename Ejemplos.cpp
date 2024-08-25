#include <stdio.h>

int main(){
	int edades[5];
	for(int i = 0; i<3; i++){
	   printf("\n");
	   printf("Ingrese la edad %d: ", i);
	   scanf("%d", &edades[i]);
	   }
}