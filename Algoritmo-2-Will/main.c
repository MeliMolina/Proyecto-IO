#include <stdio.h>
#define INF 999999
int **crearMatVacia(int tamano){
    int **matriz = (int**) malloc(tamano * sizeof(int*));
    int i;
    for(i = 0; i < tamano; i++){
        matriz[i] = (int*) malloc(tamano * sizeof(int));
    }
    return matriz;
}
void calcularRutas(int tamano,int matriz[][tamano]){
int i,j,k;
int **tablaP = crearMatVacia(tamano);
llenarCeros(tablaP,tamano);
for (k = 0; k < tamano; k++)
    {
        for (i = 0; i < tamano; i++)
        {
            for (j = 0; j < tamano; j++)
            {
                if (matriz[i][k] + matriz[k][j] < matriz[i][j]){
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                    tablaP[i][j]=k;
                }
            }
        }
    }
printSolution(tamano,matriz);
imprimirMat(tablaP,tamano);
}
void llenarCeros(int **matriz,int tamano){
    int i,j;
for (i = 0; i < tamano; i++)
        for (j = 0; j < tamano; j++)
            matriz[i][j] = 0;
}
void printSolution(int tamano,int matriz[][tamano])
{
    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            if (matriz[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", matriz[i][j]);
        }
        printf("\n");
    }
}
void imprimirMat(int **matriz, int tamano){
    int i,j;
    for(i = 0; i < tamano; i++){
        for(j = 0; j < tamano; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int tamano=5;
    int matriz[5][5] = { {0,   6,  INF, 4,7},
                        {9,0,7,INF,INF},
                        {INF,5,0,INF,14},
                        {8,1,INF,0,15},
                        {2,INF,2,19,0}
                        }
                      ;
    calcularRutas(tamano,matriz);
    return 0;
}
