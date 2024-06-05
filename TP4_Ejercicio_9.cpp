#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

void menu(void);
void sumar(void);
void restar(void);
void multiplicar(void);
void dividir(void);
void potenciar(void);
void raiz(void);
int volver;

int main(){
	menu();
}
	
void menu(){
	volver = 0;
	int op;
	do{
		system("color A");
		printf("\n\n  ************** MENU **************  \n");
		printf("\n\t1. Suma");
		printf("\n\t2. Resta");
		printf("\n\t3. Multiplicacion");
		printf("\n\t4. Division");
		printf("\n\t5. Potencia");
		printf("\n\t6. Raiz Cuadrada");
		printf("\n\t7. Salir");
		printf("\n\n  **********************************  \n");
		printf("\n\t Elija una opcion: ");
		scanf("%d", &op);
		system("cls");
	}while(op<1 || op>7);
	system("cls");
	system("color B");
	if (op == 1) sumar();
	if (op == 2) restar();
	if (op == 3) multiplicar();
	if (op == 4) dividir();
	if (op == 5) potenciar();
	if (op == 6) raiz();
	if (op == 7) return;
}		

void sumar(){
	float a,b;
	
	printf("\n\n  ************** SUMA **************  ");
	printf("\n\n  Ingrese numero 1: ");
	scanf("%f", &a);
	printf("\n\n  Ingrese numero 2: ");
	scanf("%f", &b);
	printf("\n  El resultado de %.2f + %.2f es %.2f ", a,b,a+b);
	printf("\n\n  **********************************  \n");
	printf("\n\t 1. Volver\n\n\t Seleccione una opcion: ");
	scanf("%d", &volver);
	
	system("cls");
	if (volver==1) menu();
}

void restar(){
	float a,b;

	printf("\n\n  ************** RESTA **************  ");
	printf("\n\n  Ingrese numero 1: ");
	scanf("%f", &a);
	printf("\n\n  Ingrese numero 2: ");
	scanf("%f", &b);
	printf("\n  El resultado de %.2f - %.2f es %.2f ", a,b,a-b);
	printf("\n\n  **********************************  \n");
	printf("\n\t 1. Volver\n\n\t Seleccione una opcion: ");
	scanf("%d", &volver);

	system("cls");
	if (volver==1) menu();
}

void multiplicar(){
	float a,b;
	
	printf("\n\n  *********** MULTIPLICAR ***********  ");
	printf("\n\n  Ingrese numero 1: ");
	scanf("%f", &a);
	printf("\n\n  Ingrese numero 2: ");
	scanf("%f", &b);
	printf("\n  El resultado de %.2f * %.2f es %.2f ", a,b,a*b);
	printf("\n\n  **********************************  \n");
	printf("\n\t 1. Volver\n\n\t Seleccione una opcion: ");
	scanf("%d", &volver);
	
	system("cls");
	if (volver==1) menu();
}
	
void dividir(){
	float a,b;
	
	printf("\n\n  ************* DIVIDIR *************  ");
	printf("\n\n  Ingrese numero 1: ");
	scanf("%f", &a);
	printf("\n\n  Ingrese numero 2: ");
	scanf("%f", &b);
	printf("\n  El resultado de %.2f / %.2f es %.2f ", a,b,a/b);
	printf("\n\n  **********************************  \n");
	printf("\n\t 1. Volver\n\n\t Seleccione una opcion: ");
	scanf("%d", &volver);
	
	system("cls");
	if (volver==1) menu();
}

void potenciar(){
	float a,b;
	
	printf("\n\n  ************* POTENCIAR *************  ");
	printf("\n\n  Ingrese numero 1: ");
	scanf("%f", &a);
	printf("\n\n  Ingrese numero 2: ");
	scanf("%f", &b);
	printf("\n  El resultado de %.2f ^ %.2f es %.2f ", a,b,pow(a,b));
	printf("\n\n  **********************************  \n");
	printf("\n\t 1. Volver\n\n\t Seleccione una opcion: ");
	scanf("%d", &volver);
	
	system("cls");
	if (volver==1) menu();
}

void raiz(){
	float a;

	printf("\n\n  *************** RAIZ ***************  ");
	printf("\n\n  Ingrese 1 numeros: ");
	scanf("%f", &a);
	if (a<0)printf("\n  El resultado de la raiz cuadrada de %.2f no pertenece a los reales ", a);
	else printf("\n  El resultado de la raiz cuadrada de %.2f es %.2f ", a,sqrt(a));
	printf("\n\n  **********************************  \n");
	printf("\n\t 1. Volver\n\n\t Seleccione una opcion: ");
	scanf("%d", &volver);

	system("cls");
	if (volver==1) menu();
}
