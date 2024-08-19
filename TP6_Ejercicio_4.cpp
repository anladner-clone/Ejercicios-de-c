#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_CAMPOS 4
#define CANT_ZONAS 3

int main(){
    int campos[CANT_CAMPOS][CANT_ZONAS]; // Matriz de lluvia
    
    srand(time(NULL));
    
    // Llenar la matriz con valores aleatorios y mostrarla
    printf("\n\tMatriz de lluvia:\n\n");
    printf("\t Campos:  ");
    for(int columna = 0; columna < CANT_ZONAS; columna++){
        printf("\t Zona %.1d  ", columna + 1);
    }
    printf("\n");

    for(int fila = 0; fila < CANT_CAMPOS; fila++){	
        printf("\n\tCampo %.1d:", fila + 1);
        for(int columna = 0; columna < CANT_ZONAS; columna++){
            campos[fila][columna] = 1 + rand() % 99;
            printf("\t%.2d mm;   ", campos[fila][columna]);
        }
        printf("\n");
    }

    int promedioZonas[CANT_ZONAS] = {0};
    int promedioCampos[CANT_CAMPOS] = {0};
    int totalLluvia = 0;

    // Calcular promedios por zona, campo y total
    for(int fila = 0; fila < CANT_CAMPOS; fila++){
        for(int columna = 0; columna < CANT_ZONAS; columna++){
            promedioZonas[columna] += campos[fila][columna];
            promedioCampos[fila] += campos[fila][columna];
            totalLluvia += campos[fila][columna];
        }
    }

    printf("\n");
    for(int i = 0; i < CANT_ZONAS; i++){
        printf("\n\tPromedio de la zona %d: %d mm", i + 1, promedioZonas[i] / CANT_CAMPOS);
    }

    printf("\n");
    for(int i = 0; i < CANT_CAMPOS; i++){
        printf("\n\tPromedio del campo %d: %d mm", i + 1, promedioCampos[i] / CANT_ZONAS);
    }

    // Encontrar el campo y la zona con la mayor precipitación
    int campoMayor = 0, zonaMayor = 0;
    int mayor = campos[0][0];
    
    for(int fila = 0; fila < CANT_CAMPOS; fila++){
        for(int columna = 0; columna < CANT_ZONAS; columna++){
            if(campos[fila][columna] > mayor){
                mayor = campos[fila][columna];
                campoMayor = fila;
                zonaMayor = columna;
            }
        }
    }

    printf("\n\n\tEl campo %d tuvo la mayor precipitación con %d mm, en la zona %d", campoMayor + 1, mayor, zonaMayor + 1);
    
    // Promedio total de todas las precipitaciones
    int promedioTotal = totalLluvia / (CANT_CAMPOS * CANT_ZONAS);
    printf("\n\n\tEl promedio de todas las precipitaciones es de %d mm\n", promedioTotal);

}