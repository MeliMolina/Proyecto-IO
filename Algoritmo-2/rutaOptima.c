void rutaOptima(int **tablaP,int i,int j){
    if (i == j)
        printf(i);
    else if (tablaP[i][j] == 0 )
        printf("No hay ruta");
    else
        printf("%d %d %d",i,tablaP[i][j],j);
}
