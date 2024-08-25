#include <stdio.h>

int main(){
	int n = 2; // Cantidad de alumnos
	int m = 3; // Cantidad de asignaturas
	int notas[n][m];
	for(int i = 0; i<n; i++){
	   for(int j = 0; j<m; j++){
	      printf("\n");
	      printf("Ingrese la nota del alumno %d, asignatura %d: ", i,j);
   	   scanf("%d", &notas[i][j]);
	      }
	   }
}