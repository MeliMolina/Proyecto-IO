/************************************************************************
 
 Instituto Tecnológico de Costa Rica
 Investigación de Operaciones
 II Semestre 2017

 Proyecto 0.Menú de Programas de Programación Dinámica

 Profesor: Dr.Francisco J.Torres Rojas

 Melissa Molina Corrales
 Edwin Cen Xu
 Willian Espinoza
 Cristian León

 ************************************************************************/

#include <glib.h>
#include <gtk/gtk.h>
#include "lib/matrix.c"
#define INF 999999
#define MAX_INT +2147483647
 
GtkBuilder  *builder; 
GtkWidget  *window_SD;
GtkWidget  *window_RO;



GtkWidget * btn_cargar_SD;
GtkWidget *entry_cargar_SD;
GtkWidget *btn_calcular_SD;
GtkWidget *folder;
GtkWidget *filenameEntry;
GtkWidget *guardar;
GtkWidget *tabla_input;

GtkWidget *table;
GtkWidget *SalirDelPrograma;

GtkWidget *tabla_sol1;
GtkWidget *tabla_sol2;
GtkWidget *grid1;
GtkWidget *grid2;
GtkWidget *gridt;
GtkWidget *Nodos;

GtkWidget *ciudad1;
GtkWidget *ciudad2;
GtkWidget *resultRuta;

GtkWidget *result;
GtkWidget *tabla_label;


GtkWidget *label;
GtkWidget *box;
char *strs[2000]= {"A","B","C","D","E","F","G","H","I","J"};
char *strsAux[20]= {"A","B","C","D","E","F","G","H","I","J"};
int ** tabla;
int ** tabla2;
int ** tablaCambios;
float resp;
int contador = 0;
int nnodos;
int dummy = 0;

int *pases[20];
int *rutaOptima[20];

char val[2000];

float mat[10][10];



int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Rutas_Optimas.glade", NULL);
 
    window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));
    window_RO = GTK_WIDGET(gtk_builder_get_object(builder, "window_RO"));
    

    gtk_builder_connect_signals(builder, NULL);   
    entry_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_SD"));
    folder = GTK_WIDGET(gtk_builder_get_object(builder, "folder"));
    filenameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "filename"));

    btn_calcular_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_calcular_SD"));
    Nodos = GTK_WIDGET(gtk_builder_get_object(builder, "Nodos"));

    guardar = GTK_WIDGET(gtk_builder_get_object(builder, "guardar_SD"));
    btn_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_cargar_SD"));
    SalirDelPrograma = GTK_WIDGET(gtk_builder_get_object(builder, "SalirDelPrograma"));
    result = GTK_WIDGET(gtk_builder_get_object(builder, "result"));
    tabla_sol1 = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol1"));
    tabla_input = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_input"));
    tabla_sol2 = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol2"));
	tabla_label = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_label"));

    ciudad1 = GTK_WIDGET(gtk_builder_get_object(builder, "ciudad1"));
    ciudad2 = GTK_WIDGET(gtk_builder_get_object(builder, "ciudad2"));
    resultRuta = GTK_WIDGET(gtk_builder_get_object(builder, "resultRuta"));
    
    gtk_widget_set_tooltip_text(entry_cargar_SD, "Seleccionar un archivo");
    gtk_widget_set_tooltip_text(btn_calcular_SD, "Calcula la tabla con las probabilidades de A y B");
    gtk_widget_set_tooltip_text(folder, "Seleccionar un directorio");
    gtk_widget_set_tooltip_text(filenameEntry, "Nombre del archivo a guardar");
    gtk_widget_set_tooltip_text(guardar, "Guarda los datos en un archivo");
    gtk_widget_set_tooltip_text(btn_cargar_SD, "Carga el archivo seleccionado");
    gtk_widget_set_tooltip_text(SalirDelPrograma, "Cierra el programa");

    grid1 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid1, 10);
    gtk_grid_set_column_spacing (grid1, 10);

    gtk_container_add (GTK_CONTAINER (tabla_input), grid1);
    gtk_widget_show (grid1);




    g_object_unref(builder);

   
    gtk_widget_show(window_SD);
                              
    gtk_main();
    return 0;
} 
 
void llenarCeros(int **matriz,int tamano){
    int i,j;
for (i = 0; i < tamano; i++)
        for (j = 0; j < tamano; j++)
            matriz[i][j] = 0;
}

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
}

int ***crearCubVacio(int size){
    int ***cubo = malloc((size+1)*sizeof(int**));
    int i;
    for(i = 0; i < size+1; i++){
        cubo[i] = crearMatVacia(size);
    }
    return cubo;
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

void on_tablaCambios_clicked(){
	int i, j;              
    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 1);
    gtk_grid_set_column_spacing (grid2, 1);

    for (i = 0; i <=(nnodos); i++)
    {
        for(j = 0; j <=(nnodos); j++)
        {
        	if(i==0&&j==0){continue;}
            if (i==0){

                    char val[30];
                    sprintf(val,"%s", strs[j-1]);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#467DD9", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);      
                
            }
            else{
                if(j==0){
                    char val[30];
                    sprintf(val,"%s", strs[i-1]);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#467DD9", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);
                }
                else{
                    
                    
                    
                        char val[30];
                    
                        if(tablaCambios[i][j]==-1){
                        	sprintf(val,"%s", "-");
                        }
                        else{
                        	sprintf(val,"%d", tablaCambios[i][j]);
                    	}
                   

                        label = gtk_label_new (val);
                        gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                         box = gtk_box_new(0, 0);
                        gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                        const GdkRGBA *color;
                        
                        gdk_color_parse( "#AFC6EE", &color );
                        gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                        gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                        gtk_widget_show (label);
                        gtk_widget_show (box);   
                    
                }
            }
        }
    }

    gtk_container_add (GTK_CONTAINER (tabla_sol1), grid2);
    gtk_widget_show (grid2);

}

void on_tablaActual_clicked(){
int i, j;              
    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 1);
    gtk_grid_set_column_spacing (grid2, 1);

    for (i = 0; i <=(nnodos); i++)
    {
        for(j = 0; j <=(nnodos); j++)
        {
            if(i==0&&j==0){continue;}
            if (i==0){

                    char val[30];
                    sprintf(val,"%s", strs[j-1]);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#467DD9", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);      
                
            }
            else{
                if(j==0){
                    char val[30];
                    sprintf(val,"%s", strs[i-1]);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#467DD9", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);
                }
                else{
    
                        char val[30];
                    
                        if(tabla[i][j]==-1){
                            sprintf(val,"%s", "-");
                            label = gtk_label_new (val);
                            gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                            box = gtk_box_new(0, 0);
                            gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                            const GdkRGBA *color;
                                
                            gdk_color_parse( "#AFC6EE", &color );
                            gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                            gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                            gtk_widget_show (label);
                            gtk_widget_show (box); 
                        }
                        else{
                            sprintf(val,"%d", tabla[i][j]);


                            if(tabla2[i][j] != tabla[i][j]){

                                label = gtk_label_new (val);
                                gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                                 box = gtk_box_new(0, 0);
                                gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                                const GdkRGBA *color;
                                    
                                gdk_color_parse( "#EDE040", &color );
                                gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                                gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                                gtk_widget_show (label);
                                gtk_widget_show (box);

                            }
                            else{
                                 label = gtk_label_new (val);
                                 gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                                  box = gtk_box_new(0, 0);
                                  gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                                  const GdkRGBA *color;
                                        
                                  gdk_color_parse( "#AFC6EE", &color );
                                  gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                                  gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                                  gtk_widget_show (label);
                                  gtk_widget_show (box);  
                            }
                        } 
                    
                }
            }
        }
    }

    gtk_container_add (GTK_CONTAINER (tabla_sol1), grid2);
    gtk_widget_show (grid2);

}

void floyd(){

	for(int i = 1; i <= nnodos; i++){
		tabla2[contador+1][i]=tabla[contador+1][i];
		tabla2[i][contador+1]=tabla[i][contador+1];
	}
	contador++;
	int u = 0;
	int temp = 0;
	int tempAux = 0;
	for(int i = 1; i <= nnodos; i++){
		if(contador == i){
			continue;
		}
		
		u = tabla[i][contador];
		for(int j = 1; j <= nnodos;j++){
			if(i==j||j == contador){
				continue;
			}
			
				temp = u + tabla2[contador][j];
				tempAux = u*tabla2[contador][j];
                if(temp == -2){
                    tabla2[i][j]=tabla[i][j];
                    continue;
                }
				if(tempAux < 0){
					tabla2[i][j]=tabla[i][j];
					continue;
				}
				else if(tabla[i][j]==-1){
					tabla2[i][j] = temp;
					tablaCambios[i][j]= contador;
				}
				else if(temp < tabla[i][j]){
					tabla2[i][j] = temp;
					tablaCambios[i][j]= contador;
				}
				else{
					tabla2[i][j]=tabla[i][j];
				}
			
		}
	}


}
void deleteTablesGrid()
{
    /*grid1 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid1, 10);
    gtk_grid_set_column_spacing (grid1, 10);*/
    GList *children, *iter;

    children = gtk_container_get_children(GTK_CONTAINER(tabla_input));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

}

void on_salirRO_clicked(){
    gtk_widget_destroy(window_RO);
}

int on_mostrarRuta_clicked(){
    gtk_label_set_text(GTK_LABEL(resultRuta), "");

    char *nodo1;
    nodo1 = gtk_entry_get_text(GTK_ENTRY(ciudad1));

    char *nodo2;
    nodo2 = gtk_entry_get_text(GTK_ENTRY(ciudad2));

    if(strlen(nodo1)==0||strlen(nodo2)==0){
        gtk_label_set_text(GTK_LABEL(resultRuta), "Falta el nombre de un nodo");
        return 0;
    }

    int pos1 = -1;
    int pos2 = -1;
    for(int i = 0; i < nnodos;i++){
        if(strcmp(nodo1,strs[i])==0){
            pos1 = i;
            break;
        }
    }

    for(int i = 0; i < nnodos;i++){
        if(strcmp(nodo2,strs[i])==0){
            pos2 = i;
            break;
        }
    }

    if(pos1 ==-1||pos2 ==-1){
        gtk_label_set_text(GTK_LABEL(resultRuta), "Uno de los nodos no existe.");
        return 0;
    }

    pos1 += 1;
    pos2 += 1;

    
    strcpy(val,"Ruta: ");

    //recursionRutaOptima(pos1,pos2,0);
    getOptimalPath(pos1,pos2);
    gtk_label_set_text (GTK_LABEL(resultRuta),val);
/*
    for(int i = 0; i < 20; i++){
        pases[i]=-1;
        rutaOptima[i]=0;
    }
    printf("pos1: %d\n",pos1 );
    printf("pos2: %d\n",pos2 );

   
    
    char val[2000];
    strcpy(val,"Ruta: ");
    int t = rutaOptima[0];
    strcat(val,strs[t-1]);


    for(int i = 1; i < 15;i++){
        if(rutaOptima[i]==pos1){
            rutaOptima[i]=0;
        }
        if(rutaOptima[i]==0){
            continue;
        }
        strcat(val,"->");
        t = rutaOptima[i];
        strcat(val,strs[t-1]);
        
    }
    gtk_label_set_text(GTK_LABEL(resultRuta), val);
    printf("%s\n",val );
    
    return 0;*/

}

int revisar(int ind){

    for(int i = 0; i < 20; i++){
        if(pases[i]==ind){
            return 1;
        }
    }
    return 0;
}

void getOptimalPath(int begin,int end){
    char arrow[7] = " --> ";
    //printf("%s\n", gtk_entry_get_text(GTK_ENTRY(tableP[begin][end])));
    int medium = tablaCambios[begin][end];
    strcat(val, strs[begin-1]);
    if (medium == 0){
        //printf("Ruta directa de %d a %d \n",begin,end);
        
        strcat(val,arrow);
        strcat(val, strs[end-1]);
    }
    else{
        strcat(val,arrow);
        printf("Tome %d y pase por %d \n",begin,medium);
        getOptimalPath(medium,end);
    }
    
}


int recursionRutaOptima(int ciud1, int ciud2,int indice){
    /*if(pivote == ciud2){
        return 0;
    }*/
    
    if(indice > nnodos){
        return 0;
    }
    if(revisar(ciud1)==1){
        return 0;
    }
    rutaOptima[indice]=ciud1;
    indice++;
    if(tablaCambios[ciud1][ciud2]==0){
        rutaOptima[indice]=ciud2;
        return 0;
    }
    pases[indice-1]=ciud1;
    int t;
    for(int i = 1;i <= nnodos; i++){
        if(tablaCambios[ciud1][i]==0){
            continue;
        }
        t = tablaCambios[ciud1][i];
        
        if(tablaCambios[ciud1][i] == ciud2){
            //gtk_label_set_text(GTK_LABEL(resultRuta), "Lo encontro, pero no se como lo hizo");
            rutaOptima[indice]=t;
            return 0;
            break;
        }
        recursionRutaOptima(t,ciud2,indice);

        
    }
        
    return 0;
}

int on_next_clicked(){

	if(contador==0){
		gtk_label_set_text(GTK_LABEL(result), "Hacer click en calcular primero.");
		return 0;
	}

	if(nnodos <= contador){
		gtk_label_set_text(GTK_LABEL(result), "Esta es la última tabla.");
		return 0;
	}
	GList *children, *iter;

    children = gtk_container_get_children(GTK_CONTAINER(tabla_sol1));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

	char val[40];
    strcpy(val,"D(");
    char v[12];
    sprintf(v,"%d",contador+1);
    strcat(val,v);

    strcat(val,")");

    gtk_label_set_text(GTK_LABEL(tabla_label), val);

    CrearTabla();

	for(int i = 1; i <= nnodos; i++){
		for(int j = 1; j <= nnodos; j++){
			tabla[i][j] = tabla2[i][j];
		}
	}
}

int on_rutas_optimas_clicked(){
    if(contador < nnodos){
        gtk_label_set_text(GTK_LABEL(result), "Tiene que llegar a la última tabla primero.");
        return 0;
    }
    gtk_widget_show(window_RO);
}

void on_window_RO_destroy()
{
    gtk_widget_destroy(window_RO);
}

int on_btn_calcular_clicked(){

	GList *children, *iter;

    children = gtk_container_get_children(GTK_CONTAINER(tabla_sol1));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

	

	tabla = createFloatMatrix(nnodos+1, nnodos+1);
	tabla2 = createFloatMatrix(nnodos+1, nnodos+1);
	tablaCambios = createFloatMatrix(nnodos+1, nnodos+1);

	contador = 0;

	for(int i=1;i<=nnodos;i++){	
		for(int j=1;j<=nnodos;j++){
			if(i==j){
				tabla[i][j] = 0;
				tabla2[i][j] = 0;
			}else{
				const gchar *cant_nodos;
				cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
				int valor = atoi(cant_nodos);
				if(cant_nodos[0] == '-'){
					tabla[i][j] = -1;
				}
				else if(isdigit(cant_nodos[0])==FALSE){
		            gtk_label_set_text(GTK_LABEL(result), "Los valores de la tabla no pueden tener letras.");
		            return 0;
		        }
		        else if(valor < 1){
		            gtk_label_set_text(GTK_LABEL(result), "Los valores de la tabla tienen que ser mayor o igual que 1");
		            return 0;
		        }
				else{
					tabla[i][j] = valor;
				}
			}
		}
		const gchar *cant_nodos;
		cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,i,0));
		if(strlen(cant_nodos)==0){
			strs[i-1] = strsAux[i-1];
		}else{
		strs[i-1] = cant_nodos;}
	}
	for(int i=1;i<=nnodos;i++){	
		const gchar *cant_nodos;
		cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,i,0));
		if(strlen(cant_nodos)==0){
			strs[i-1] = strsAux[i-1];
		}else{
		strs[i-1] = cant_nodos;}
	}

	char val[40];
    strcpy(val,"D(");
    char v[12];
    sprintf(v,"%d",contador+1);
    strcat(val,v);

    strcat(val,")");

    gtk_label_set_text(GTK_LABEL(tabla_label), val);
		
	
	CrearTabla();

	for(int i = 1; i <= nnodos; i++){
		for(int j = 1; j <= nnodos; j++){
			tabla[i][j] = tabla2[i][j];
		}
	}
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}


void CrearTabla(){
    int i, j;
    floyd();                
    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 1);
    gtk_grid_set_column_spacing (grid2, 1);

    for (i = 0; i <=(nnodos); i++)
    {
        for(j = 0; j <=(nnodos); j++)
        {
            if(i==0&&j==0){continue;}
            if (i==0){

                    char val[30];
                    sprintf(val,"%s", strs[j-1]);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#467DD9", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);      
                
            }
            else{
                if(j==0){
                    char val[30];
                    sprintf(val,"%s", strs[i-1]);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#467DD9", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);
                }
                else{
                    
                    
                    
                        char val[30];
                    
                        if(tabla2[i][j]==-1){
                            sprintf(val,"%s", "-");

                            label = gtk_label_new (val);
                            gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                            box = gtk_box_new(0, 0);
                            gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                            const GdkRGBA *color;
                                
                            gdk_color_parse( "#AFC6EE", &color );
                            gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                            gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                            gtk_widget_show (label);
                            gtk_widget_show (box);  
                        }
                        else{

                            sprintf(val,"%d", tabla2[i][j]);

                            if(tabla2[i][j] != tabla[i][j]){

                                label = gtk_label_new (val);
                                gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                                 box = gtk_box_new(0, 0);
                                gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                                const GdkRGBA *color;
                                    
                                gdk_color_parse( "#EDE040", &color );
                                gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                                gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                                gtk_widget_show (label);
                                gtk_widget_show (box);

                            }
                            else{
                                 label = gtk_label_new (val);
                                 gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                                  box = gtk_box_new(0, 0);
                                  gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                                  const GdkRGBA *color;
                                        
                                  gdk_color_parse( "#AFC6EE", &color );
                                  gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                                  gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                                  gtk_widget_show (label);
                                  gtk_widget_show (box);  
                            }

                        }

                }
            }
        }
    }

    gtk_container_add (GTK_CONTAINER (tabla_sol1), grid2);
    gtk_widget_show (grid2);   
    
}






int on_guardar_SD_clicked ()
{
    if(contador==0){
    	gtk_label_set_text(GTK_LABEL(result), "Hay que crear una tabla primero.");
        return 0;
    }

    char * filename[250];

    char* name = gtk_entry_get_text (filenameEntry);

    if(strlen(name)==0){
        gtk_label_set_text(GTK_LABEL(result), "Escriba el nombre del archivo.");
        return 0;
    }

    char* folderfile = gtk_file_chooser_get_filename(folder);
    if(folderfile==NULL){
        gtk_label_set_text(GTK_LABEL(result), "Selecione un folder.");
        return 0;
    }

    sprintf(filename,"%s/%s", folderfile, name);

    writeFile(filename);

    gtk_entry_set_text (filenameEntry, "");
    gtk_label_set_text(GTK_LABEL(result), "Se guardó exitosamente.");

}

void writeFile(char* filename)
{

    FILE *file;
    file = fopen(filename, "w");
    
  

    fprintf(file, "%i\n", nnodos);
	const gchar *cant_nodos;
    for (int i = 1 ;i <= nnodos;i++){
    	for(int j = 1; j <= nnodos; j++){
            if(i==j){
                continue;
            }
            const gchar *cant_nodos;
            cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
            int valor = atoi(cant_nodos);
    		fprintf(file, "%i\n", valor);
    	}
    }
    for (int i = 1 ;i <= nnodos;i++){
        const gchar *cant_nodos;
        cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,i,0));
        fprintf(file, "%s\n", cant_nodos);
    }

    fclose(file);
}

int on_btn_cargar_SD_clicked(){
    const gchar *filename;
    filename = gtk_file_chooser_get_filename (entry_cargar_SD);
    if(filename==NULL){

        gtk_label_set_text(GTK_LABEL(result), "Selecione un archivo.");
        return 0;
    }
    readFile(filename);
}

void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
        if(*s != '\t' && *s != '\n') {
            *p2++ = *s++;
        } else {
            ++s;
        }
    }
    *p2 = '\0';
}


void readFile(char* filename)
{    

    FILE *file;
    file = fopen(filename, "r");
    char array[10];
    fgets(array, sizeof(array), file);
    strip(array);
    //fscanf(file, "%i", &nnodos);
    nnodos = atoi(array);
    gtk_combo_box_set_active(Nodos,nnodos-1);
    

    tabla = createFloatMatrix(nnodos+1, nnodos+1);
	tabla2 = createFloatMatrix(nnodos+1, nnodos+1);
	tablaCambios = createFloatMatrix(nnodos+1, nnodos+1);

    

	for (int i = 1 ;i <= nnodos;i++){
    	for(int j = 1; j <= nnodos; j++){
            if(i==j){
                continue;
            }

            fgets(array, sizeof(array), file);
            strip(array); //Quita espacios null
            if(atoi(array) == 0){
                gtk_entry_set_text(gtk_grid_get_child_at(gridt,j,i),"-");
            }else{
    		  gtk_entry_set_text(gtk_grid_get_child_at(gridt,j,i),array);
            }
    	}
    }
    for(int i = 1; i <= nnodos; i++){
        char array[20];
        fgets(array, sizeof(array), file);
        strip(array);
        gtk_entry_set_text(gtk_grid_get_child_at(gridt,i,0),array);
    }
    fclose(file);
    
 
}

float stof(char* s){
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};



int on_Nodos_changed(GtkWidget *widget){
    for(int i=1;i<=nnodos;i++){	
		strs[i-1]=strsAux[i-1];
	}
    deleteTablesGrid();
    
    GtkComboBox *combo_box = widget;
    int val = gtk_combo_box_get_active (combo_box)+1;//atoi(cant_nodos);

    
    nnodos = val;
    
    
    gridt = gtk_grid_new ();
    gtk_grid_set_row_spacing (gridt, 5);
    gtk_grid_set_column_spacing (gridt, 5);
    
    int i, j;
    for (i = 1; i < val+1; i++)
    {
        
        for(j = 1; j < val+1; j++)
        {               
        	if(i==1){ 
        		GtkWidget *entry = gtk_entry_new();
		        gtk_entry_set_width_chars(entry,3);
		        gtk_grid_attach(GTK_GRID(gridt), entry, j, 0, 1, 1);
		        gtk_entry_set_text(entry,strs[j-1]);
		        gtk_widget_show (entry);}     
        	if(j==1){
		       
		        GtkWidget *labelf = gtk_label_new (strs[i-1]);
        
		        gtk_grid_attach(GTK_GRID(gridt), labelf, 0, i, 1, 1);
		        gtk_widget_show (labelf);

		        }
        	if(i==j){
        		GtkWidget *labelf = gtk_label_new ("0");
        		gtk_grid_attach(GTK_GRID(gridt), labelf, i, j, 1, 1);
        		gtk_widget_show (labelf);

        	}else{
            GtkWidget *entry = gtk_entry_new();
            gtk_entry_set_width_chars(entry,3);
            gtk_grid_attach(GTK_GRID(gridt), entry, j, i, 1, 1);
            gtk_widget_show (entry);}
        }
    }
    gtk_container_add (GTK_CONTAINER (tabla_input), gridt);
    gtk_widget_show (gridt);

   
}






