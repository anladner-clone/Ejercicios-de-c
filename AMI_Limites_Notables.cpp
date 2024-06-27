#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void menuPrincipal(int opcion);
void limite(int opcion);
double limite_e_x_menos_1_sobre_x(double x);
double limite_ln_1_mas_x_sobre_x(double x);
double limite_1_menos_cos_x_sobre_x(double x);
void cabezera();

int main(){
    menuPrincipal(-1);
}

void menuPrincipal(int opcion){
   system("cls");  // Limpia la consola
   
   while(opcion < 0 || opcion > 3){
       system("color A");  // Cambia el color de la consola
       printf("\n\n  *********  LIMITES NOTABLES  *********  \n");
       
       printf("\n\t 1. lim [(e^x) - 1] / x ");
       printf("\n\t    X->0 \n");
       printf("\n\t 2. lim [ ln(1+x) / x ]");
       printf("\n\t    X->0 \n");
       printf("\n\t 3. lim [ (1 - cos(x)) / x² ]");
       printf("\n\t    X->0 \n");
       printf("\n\t 0. Salir");
       
       printf("\n\n  *************************************  \n");
       printf("\n\t Elija una opcion: ");
       scanf("%d", &opcion);
       system("cls");
   }
   if(opcion != 0) limite(opcion);  // Si la opción no es salir, llama a la función 'limite'
}

void limite(int opcion){
   system("color F");
   double x = 1, epsilon;
   double resultado;
   
   do{
       system("cls");
       cabezera();
       if(x == 0) printf("\n\tEl valor de x no puede ser 0.\n");
       printf("\n\tIngrese el valor inicial de x: ");
       scanf("%lf", &x);
   } while(x == 0);
   
   do {
       system("cls");
       cabezera();
       printf("\n\tIngrese el valor de la distancia que elige entre f(x) y el limite (epsilon) (Entre 0 y 1): ");
       scanf("%lf", &epsilon);
   } while(epsilon<=0 || epsilon >= 1);
   
   while(fabs(x) > epsilon){  // Bucle mientras x sea mayor que epsilon en valor absoluto
       if(opcion == 1){
           resultado = limite_e_x_menos_1_sobre_x(x);
           printf("\nx :  %.5f \t (e^x)-1 / x :   %.5f\n", x, resultado);
       }
       if(opcion == 2){
           resultado = limite_ln_1_mas_x_sobre_x(x);
           printf("\nx :  %.5f \t ln(1+x) / x :   %.5f\n", x, resultado);
       }
       if(opcion == 3){
           resultado = limite_1_menos_cos_x_sobre_x(x);
           printf("\nx :  %.5f \t 1-cos(x) / x² :   %.5f\n", x, resultado);
       }
       
       x /= 2;
   }
}

// Funciones que calculan los límites notables
double limite_e_x_menos_1_sobre_x(double x){
   return ((pow(M_E, x) - 1) / x);  // Calcula [(e^x) - 1] / x
}

double limite_ln_1_mas_x_sobre_x(double x){
   return (log(1 + x) / x);  // Calcula ln(1+x) / x
}

double limite_1_menos_cos_x_sobre_x(double x){
   return ((1 - cos(x)) / (pow(x, 2)));  // Calcula (1 - cos(x)) / x²
}

void cabezera(){
   printf("\n\t LIMITES NOTABLES \n");
   printf("\n*********************************\n");
}