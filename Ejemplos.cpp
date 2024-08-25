#include <stdio.h>

int main(){
	int notas[3];
	for(int i = 0; i<3; i++){
	   printf("\n");
	   printf("Ingrese la nota %d: ", i);
	   scanf("%d", &notas[i]);
	   }
}