void calcularCxs (int ** tabla_cx, int** tabla_vida_util, int vida_util, int plazo, int precio_compra);
void calcularG(int ** tabla_cx, int** tabla_plazos, int vida_util, int plazo, int G[], int G2[], int ** G3);
void writeFile(char* filename, int vida_util, int plazo, int precio_compra, int inflacion, int ** tabla_vida_util);
void readNumbers(char* filename, int * array);
void readFile(char* filename, int vida_util, int plazo, int precio_compra, int inflacion, int ** tabla_vida_util);
void resetArrays(int G2[], int vida_util);