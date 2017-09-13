#include <stdio.h>
#define MAX_INT +2147483647

void imprimirMat(int **mat, int size){
    int i,j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void freeMat(int **mat,int size){
    int i,j;
    for(i = 0; i < size; i++){
        free(mat[i]);
    }
    free(mat);
}

int **crearMatVacia(int size){
    int **mat = (int**) malloc(size * sizeof(int*));
    int i;
    for(i = 0; i < size; i++){
        mat[i] = (int*) malloc(size * sizeof(int));
    }
    return mat;
}

int ***crearCubVacio(int size){
    int ***cubo = malloc((size+1)*sizeof(int**));
    int i;
    for(i = 0; i < size+1; i++){
        cubo[i] = crearMatVacia(size);
    }
    return cubo;
}

void llenarCeros(int **mat, int size){
    int i,j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            mat[i][j] = 0;
        }
    }
}

void algoritmo2_aux(int **matP, int ***registro, int **matActual, int size, int cont){
    registro[cont] = matActual;
    if(size == cont){

    }else{
        int i,j;
        int **matNueva = crearMatVacia(size);

        for(i = 0; i < size ; i++){
            for(j = 0; j < size; j++){

                int infinito = 0;

                if(matActual[i][cont] == MAX_INT || matActual[cont][j] == MAX_INT){
                    infinito = 1;
                }

                if(matActual[i][j] > (matActual[i][cont] + matActual[cont][j]) && !infinito){
                    matNueva[i][j] = matActual[i][cont] + matActual[cont][j];
                    matP[i][j] = cont + 1;
                }else{
                    matNueva[i][j] = matActual[i][j];
                }
            }
        }
        algoritmo2_aux(matP,registro,matNueva,size,cont+1);
    }
}

void algoritmo2(int **matP, int ***registro, int **matActual, int size){
    algoritmo2_aux(matP,registro,matActual,size,0);
}

int **matIni(){
    int size = 5;
    int **mat = crearMatVacia(size);
    mat[0][0] = 0;
    mat[0][1] = 6;
    mat[0][2] = MAX_INT;
    mat[0][3] = 4;
    mat[0][4] = 7;
    mat[1][0] = 9;
    mat[1][1] = 0;
    mat[1][2] = 7;
    mat[1][3] = MAX_INT;
    mat[1][4] = MAX_INT;
    mat[2][0] = MAX_INT;
    mat[2][1] = 5;
    mat[2][2] = 0;
    mat[2][3] = MAX_INT;
    mat[2][4] = 14;
    mat[3][0] = 8;
    mat[3][1] = 1;
    mat[3][2] = MAX_INT;
    mat[3][3] = 0;
    mat[3][4] = 15;
    mat[4][0] = 2;
    mat[4][1] = MAX_INT;
    mat[4][2] = 2;
    mat[4][3] = 19;
    mat[4][4] = 0;

    return mat;

}

int main(){

    /*
    Parametros de la funcion
    -matP:      una matriz para guardar la matriz P
    -registro:  una matriz de matrices para guardar las matrices que se iran creando
    -mat:       la matriz original transiciones
    -size:      la cantidad de nodos
    */

    int i, size = 5;
    int ***registro = crearCubVacio(size);
    int **matP = crearMatVacia(size);
    int **mat = matIni();
    algoritmo2(matP,registro,mat,size);

    //imprime las matrices anteriores
    for(i = 0; i < size+1; i++){
        printf("G(%d) = \n",i);
        imprimirMat(registro[i],size);
        printf("\n");
    }
    //imprime la matriz P
    printf("P=\n");
    imprimirMat(matP,size);
    return 0;
}
