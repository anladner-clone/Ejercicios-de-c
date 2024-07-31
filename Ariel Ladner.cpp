#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu(int *n1, int *n2);
int imparesComprendidosEntreDosNumerosIngresados(int n1, int n2);
int siguienteNumeroDelMayorAnteriorDelMenor(int n1, int n2);
int numeroPrimo(int n1, int n2);
int factorial(int n1, int n2);
int divisoresDeCadaNumero(int n1, int n2);

void mensajeNumeros(int n1, int n2);
void ingresoDeNumeros(int *n1, int *n2);

int main(){
    int num1, num2, bandera = 0;
    
    while(bandera!=6){
     bandera = menu(&num1, &num2);
     switch(bandera){
        case 1:
           bandera = imparesComprendidosEntreDosNumerosIngresados(num1, num2);
        break;
        case 2:
           bandera = siguienteNumeroDelMayorAnteriorDelMenor(num1, num2);
        break;
        case 3:
           bandera = numeroPrimo(num1, num2);
        break;
        case 4:
           bandera = factorial(num1,num2);
        break;
        case 5:
           bandera = divisoresDeCadaNumero(num1, num2);
        break;
        }
    }
    
    printf("\nPrograma Finalizado\n");
    
}

int menu(int *n1, int *n2){
    system("color F");
    int op = 1;
    ingresoDeNumeros(n1, n2);
    
    do {
        mensajeNumeros(*n1, *n2);
        printf("\n\t\t\tMenu");
        printf("\n*********************************\n");
        printf("\n     1: Impares comprendidos entre los dos números ingresados");
        printf("\n     2: Siguiente número  del mayor y anterior número  del menor");
        printf("\n     3: Número primo?");
        printf("\n     4: factorial de cada número");
        printf("\n     5: divisores de cada número");
        printf("\n     6: Salir");
        printf("\n\n*********************************\n");
      
        printf("\n\t Elija una opción: ");
        scanf("%d", &op);
        
    } while(op > 6 || op < 1);
    
    return op;
}

void ingresoDeNumeros(int *n1, int *n2){
    system("cls");
    printf("\n  *********************************\n");
    printf("\n\t Ingrese el primer numero:  ");
    scanf("%d", n1);
    printf("\n\t Ingrese el segundo numero:  ");
    scanf("%d", n2);
}

void mensajeNumeros(int n1, int n2){
    system("cls");
    printf("\n  *********************************");
    printf("\n\t Primer Numero:  %d", n1);
    printf("\n\t Segundo Numero:  %d", n2);
    printf("\n\n  *********************************\n");
}

int imparesComprendidosEntreDosNumerosIngresados(int n1, int n2){
   int op=0, aux=n1;
   system("color E");
   
   do{
      mensajeNumeros(n1, n2);
   
      printf("\n       Impares Comprendidos Entre Dos numeros\n");
      printf("\n  *********************************\n");
      if(n1>n2){
         n1=n2;
         n2= aux;
         }
      printf("\n\t Impares en el intervalo [ %d ; %d ]: \n", n1,n2);
      printf("\n\t");
      for(int i = n1; i<=n2; i++){
         if(i%2!=0) printf("   %d ;", i);
      }
      printf("\n\n  *********************************\n");
      printf("\n\t 1: Volver al menu");
      printf("\n\t 2: Salir\n");
      
      printf("\n\t Elija una opcion:   ");
      scanf("%d", &op);
      }while(op>2 || op<1);
   
   if(op == 2) op=6;
   return op;
}

int siguienteNumeroDelMayorAnteriorDelMenor(int n1, int n2){
   int op =0;
   system("color E");
   
   do{
      mensajeNumeros(n1,n2);
      
      printf("\n\t Siguiente numero del mayor: ");
      if(n1>=n2)printf(" %d\n\t", n1+1);
      else printf(" %d\n\t", n2+1);
      
      printf("\n\t Anterior numero del menor: ");
      if(n1>=n2)printf(" %d\n\t", n2-1);
      else printf(" %d\n\t", n1-1);
      
      if(n1==n2)printf("\n\t Los numeros ingresados son iguales :)");
      
      printf("\n\n  *********************************\n");
      printf("\n\t 1: Volver al menu");
      printf("\n\t 2: Salir\n");
      
      printf("\n\t Elija una opcion:   ");
      scanf("%d", &op);
      }while(op>2 || op<1);
   
   if(op == 2) op=6;
   return op;
}

int numeroPrimo(int n1, int n2){
   int op = 0;
   system("color E");
   
   do{
      mensajeNumeros(n1, n2);
      printf("\n\t\tNumero Primo\n");
      printf("\n  *********************************\n");
   
      int contadorDivisores1=0;
      for(int d = 1; d<n1 ; d++){
         if(n1%d==0) contadorDivisores1++;
         }
      printf("\n\t El numero %d, ",n1);
      if(contadorDivisores1<2 && n1>0) printf(" es primo");
      else printf(" no es primo");
      
      int contadorDivisores2=0;
      for(int d = 1; d<n2 ; d++){
         if(n2%d==0) contadorDivisores2++;
         }
      printf("\n\t El numero %d, ",n2);
      if(contadorDivisores2<2 && n2>0) printf(" es primo");
      else printf(" no es primo"); 
      
      printf("\n\n  *********************************\n");
      printf("\n\t 1: Volver al menu");
      printf("\n\t 2: Salir\n");
      
      printf("\n\t Elija una opcion:   ");
      scanf("%d", &op);
      }while(op>2 || op<1);
   
   if(op == 2) op=6;
   return op;
}

int factorial(int n1, int n2){
   int op = 0;
   int factorial1 = 1, factorial2 = 1;
   system("color E");
   
   do{
      mensajeNumeros(n1,n2);
      printf("\n\tFactorial de ambos numeros\n");
      printf("\n  *********************************\n");
      
      for(int i = n1; i>0; i--){
         factorial1= i*factorial1;
         }
      for(int i = n2; i>0; i--){
         factorial2= i*factorial2;
         }
      
      printf("\n\t %d! = ", n1);
      if(n1<0)printf(" Error de Dominio");
      else printf(" %d", factorial1);
      
       printf("\n\t %d! = ", n2);
      if(n2<0)printf(" Error de Dominio");
      else printf(" %d", factorial2);
      
      printf("\n\n  *********************************\n");
      printf("\n\t 1: Volver al menu");
      printf("\n\t 2: Salir\n");
      
      printf("\n\t Elija una opcion:   ");
      scanf("%d", &op);
      }while(op>2 || op<1);
   
   if(op == 2) op=6;
   return op;
}

int divisoresDeCadaNumero(int n1, int n2){
   int op = 0;
   system("color E");
   
   do{
      mensajeNumeros(n1,n2);
      printf("\n      Factorial de ambos numeros\n");
      printf("\n  *********************************\n");
   
      printf("\n\t Divisores de %d: ", n1);
      printf("\n\t   ");
      if(n1<0)n1=n1*(-1);
      if(n2<0)n2 =n2*(-1);
      for(int i = 1; i<=n1; i++){
         if(n1%i==0)printf("    %d  ;", i);
         }
      
      printf("\n\n\t Divisores de %d: ", n2);
      printf("\n\t   ");
      for(int i = 1; i<=n2; i++){
         if(n2%i==0)printf("    %d  ;", i);
         }
      
      printf("\n\n  *********************************\n");
      printf("\n\t 1: Volver al menu");
      printf("\n\t 2: Salir\n");
      
      printf("\n\t Elija una opcion:   ");
      scanf("%d", &op);
      }while(op>2 || op<1);
   
   if(op == 2) op = 6;
   return op;
}