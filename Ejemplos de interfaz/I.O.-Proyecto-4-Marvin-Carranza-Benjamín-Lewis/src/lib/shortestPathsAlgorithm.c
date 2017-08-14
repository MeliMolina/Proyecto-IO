#include "matrix.h"
#include "shortestPathsAlgorithm.h"

void shortestPathsAlgorithm(int **D, int **P,  int nodes)
{
    // Ecuación de Bellman: min (D[i][j], D[i][k] + D [k][j])

    printf("Matriz D(%i)\n", 0);
    printMatrix(D, nodes, nodes);
    printf("\n\n\n");

    char d[15];
    sprintf(d,"src/temp/D%d", 0);

    writeDToFile(d, D, nodes);

    char p[10];
    sprintf(p,"src/temp/P%d", 0);

    writeDToFile(p, P, nodes);

    int i, j, k;
    for (k = 0; k < nodes; k++){
        for(i = 0 ;i < nodes; i++){
            for (j = 0; j < nodes; j++){
                if (D[i][k] + D[k][j] < D[i][j]){
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }

        char d[15];
        sprintf(d,"src/temp/D%d", k + 1);

        writeDToFile(d, D, nodes);

        char p[10];
        sprintf(p,"src/temp/P%d", k + 1);

        writeDToFile(p, P, nodes);

        printf("Matriz D(%i)\n", k + 1);
        printMatrix(D, nodes, nodes);
        printf("\n\n\n");
            
    }

    printf("Matriz P\n");
    printMatrix(P, nodes, nodes);
}

void createP(int** P, int nodes)
{
    
    int i;
    int j;

    for (i = 0; i < nodes; i++){
        for(j = 0; j < nodes; j++){
            P[i][j] = 0;
        }
    }
}

void writeDToFile(char* filename, int **D, int nodes)
{
    /* Writes matrix D to a file with name as the parameter filename */

    FILE *file;
    file = fopen(filename, "w");
    
    int i = 0;
    int j = 0;

    fprintf(file, "%i\n", nodes);

    while (i < nodes)
    {
        while(j < nodes) // poner condicion que si es EOF se salga.
        {
            fprintf(file, "%i\n", D[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }

    fclose(file);
}

int readNumberOfNodes(char* filename){

    /* Return number of nodes in file with name as the parameter filename*/

    FILE *file;
    int nodes;

    file = fopen(filename, "r");
    fscanf(file, "%i", &nodes);

    //printf("nodes = %i\n", nodes);

    fclose(file);

    return nodes;
}

void readDFromFile(char* filename, int ** D, int ** P, int nodes){
    
    /* Read matrix D from file with name as the parameter filename, then calculates the shortest paths between any nodes */

    FILE *file;
    file = fopen(filename, "r");
    
    fscanf(file, "%i", &nodes);

    int i = 0;
    int j = 0;


    while (i < nodes)
    {
        while(j < nodes) // poner condicion que si es EOF se salga.
        {
            fscanf(file, "%i\n", &D[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }

    fclose(file);

}
