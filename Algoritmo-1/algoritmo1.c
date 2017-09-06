#include <stdio.h>

int sumar(int *arreglo, int size, int ini){
    int res = 0;
    int i;
    for(i = ini; i < size; i++){
        res += arreglo[i];
    }
    return res;
}

int isHome(int *formato, int size, int terminaA, int i, int j){
    int cont = size - 1;

    while(sumar(formato,size,cont) < i + j - 1) {
        cont--;
        if(terminaA == 1){
            terminaA = 0;
        }
        else{
            terminaA = 1;
        }
    }
    return terminaA;
}

double **llenarMatriz(double pH, double pR, int *formato, int sizeFormato, int terminaA){
    int total = sumar(formato,sizeFormato,0);
    int medio = (total + 1) / 2;
    int i,j;
    double **mat = malloc( (medio + 1) * sizeof(double));
    for(i = 0; i < medio + 1; i++){
        mat[i] = malloc( (medio + 1) * sizeof(double));
        for(j = 0; j < medio + 1; j++){
            if(i == 0){
                mat[i][j] = 1;
            }
            else if(j == 0){
                mat[i][j] = 0;
            }else{
                if(isHome(formato, sizeFormato, terminaA, i, j)){
                    mat[i][j] = mat[i-1][j]*pH + mat[i][j-1]*(1-pH);
                }else{
                    mat[i][j] = mat[i-1][j]*pR + mat[i][j-1]*(1-pR);
                }
            }
            printf("%f ",mat[i][j]);
        }
        printf("\n");
    }
    return mat;
}

int main(){

    /*
    Requisitos:
    -probabilidad cuando es Host
    -probabilidad cuando es Visitante
    -El formato
    -Si termina en A
    */

    double pH = 0.57;
    double pR = 0.49;
    int terminaA = 1;

    int formato[] = {2,3,2};

    int size = sizeof(formato) / sizeof(formato[0]);

    double **mat = llenarMatriz(pH,pR,formato,size,terminaA);
    int total = sumar(formato,size,0);
    int medio = (total + 1) / 2;
    printf("La probabilidad de ganar la serie es: %f",mat[medio][medio]);

    return 0;
}
