//4- Cargar una lista con N números enteros (positivos, negativos y nulos), mostrar:
//	- La cantidad de elementos nulos.
//	- La suma de los elementos positivos.
//	- El promedio de los elementos positivos.
//	- La cantidad de elementos negativos. 

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

void carga(int d);
void mostrar();
int contarNulos();
int contarPositivos();
int contarNegativos();

float promedioPositivos;

struct lista{
	int valor;
	struct lista *sig;
}*L,*p;

int main(){
	int n, sumaPos, nulos, negativos;
	printf("\n\tIngrese el numero a digitar:");
	scanf("%d",&n);
	L=NULL; //Creacion de lista vacia//
	carga(n);
	system("cls");
	mostrar();
	printf("\n");
	
	nulos = contarNulos();
	sumaPos = contarPositivos();
	negativos = contarNegativos();
	
	printf("\n\tHay %d numeros nulos", nulos);
	printf("\n\tLa suma de los numeros positivos es: %d", sumaPos);
	printf("\n\tEl promedio de los numeros positivos es de: %.2f", promedioPositivos);
	printf("\n\tHay %d numeros negativos", negativos);
}

void carga(int d){
	for (int i=0;i<d;i++) {
		int num;
		printf("\n\tIngrese numero: ");
		scanf("%d",&num);
		p = (struct lista *) malloc(sizeof(struct lista));
		
		p->valor = num;
		p->sig = L;
		L = p;
		
	}
}
void mostrar(){
	printf("\n\tLa lista es: ");
	p = L;
	while (p != NULL) {
		printf("[ %d ]-> ", p->valor);
		p = p->sig;
	}
	
}

int contarNulos(){
	int cantidadNulos = 0;
	p = L;
	while (p != NULL) {
		if(p->valor == 0){
			cantidadNulos++;
		}
		p = p->sig;
	}
	return cantidadNulos;
}

int contarPositivos(){
	int cantidadPositivos = 0;
	float sumaPositivos = 0.0;
	p = L;
	while (p != NULL) {
		if(p->valor > 0){
			sumaPositivos+=p->valor;
			cantidadPositivos++;
		}
		p = p->sig;
	}
	promedioPositivos = sumaPositivos/cantidadPositivos;
	return sumaPositivos;
}
	
int contarNegativos(){
	int cantidadNegativos = 0;
	p = L;
	while (p != NULL) {
		if(p->valor < 0){
			cantidadNegativos++;
		}
		p = p->sig;
	}
	return cantidadNegativos;
}