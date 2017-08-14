#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

#include "shortestPaths.h"
#include "lib/matrix.c"
#include "lib/shortestPathsAlgorithm.c"
 
GtkWidget *table;
GtkWidget *tableP;
GtkWidget *** matrix;
GtkWidget *** matrixP;
GtkBuilder *builder; 
GtkWidget  *window_RMC;
GtkWidget  *window_RMC_datos;
GtkWidget *cant_nodos_RMC;
GtkWidget *window_datosD0;
GtkWidget *tabla_datosD0;
GtkWidget *gridt;
GtkWidget * grid;
GtkWidget * grid2;
GtkWidget * entry_consultar_RMC;
GtkWidget * window_routes;
GtkWidget * entryA;
GtkWidget * entryDe;
GtkWidget * entryRespuestaRoute;


int ** D, ** P; // D and P matrix

int nnodos;

int nodes;
int dnumber;

char * defaultNames = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
char *strs[50]= {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

int main(int argc, char *argv[])
{

 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/RMC_glade.glade", NULL);
	
	cant_nodos_RMC = GTK_WIDGET(gtk_builder_get_object(builder, "cant_nodos_RMC"));
 
	window_RMC = GTK_WIDGET(gtk_builder_get_object(builder, "window_RMC"));
    table = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_RMC"));
    tableP = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_RMC1"));
	window_RMC_datos = GTK_WIDGET(gtk_builder_get_object(builder, "window_RMC_datos"));
	
	window_datosD0 = GTK_WIDGET(gtk_builder_get_object(builder, "window_datosD0"));
	tabla_datosD0 = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_datosD0"));
	
    entry_consultar_RMC = GTK_WIDGET(gtk_builder_get_object(builder, "entry_consultar_RMC"));

    window_routes = GTK_WIDGET(gtk_builder_get_object(builder, "window_routes"));


    entryA =  GTK_WIDGET(gtk_builder_get_object(builder, "entryA"));
    entryDe =  GTK_WIDGET(gtk_builder_get_object(builder, "entryDe"));
    entryRespuestaRoute =  GTK_WIDGET(gtk_builder_get_object(builder, "entryRespuestaRoute"));
    grid = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid, 10);
    gtk_grid_set_column_spacing (grid, 10);

    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 10);
    gtk_grid_set_column_spacing (grid2, 10);


    //showDTable(matrix, D, nodes);
    //showDTable(matrixP, P, nodes);


    //GtkWidget *label = gtk_label_new ("asdfasdf");
    gtk_container_add (GTK_CONTAINER (table), grid);
    gtk_widget_show (grid);

    gtk_container_add (GTK_CONTAINER (tableP), grid2);
    gtk_widget_show (grid2);
    
    
    gtk_builder_connect_signals(builder, NULL);
 
    //g_object_unref(builder);    
 
    gtk_widget_show(window_RMC_datos);                
    gtk_main();

    return 0;
}

void initialize(char * filename)
{

    nodes = readNumberOfNodes(filename);

    D = createMatrix(nodes, nodes);
    P = createMatrix(nodes, nodes);

    dnumber = 0;

    createP(P, nodes);

    readDFromFile(filename, D, P, nodes);
    //writeDToFile("input2.txt" , D, nodes);

    shortestPathsAlgorithm(D, P, nodes);

    matrix = createTable(nodes, nodes);
    matrixP = createTable(nodes, nodes);


    createTablesGrid(nodes, matrix, matrixP);

}


void on_btn_consultar_RMC_clicked ()
{

    const gchar *filename;
    filename = gtk_entry_get_text(GTK_ENTRY(entry_consultar_RMC));

    gtk_label_set_text (matrix[0][0], filename);
    
    int i;
    for(i = 0; i < nodes; i++)
    {
        gtk_grid_remove_row (grid, 0);
        gtk_grid_remove_row (grid2, 0);
    }



    nodes = readNumberOfNodes(filename);

    D = createMatrix(nodes, nodes);
    P = createMatrix(nodes, nodes);

    dnumber = 0;

    createP(P, nodes);

    readDFromFile(filename, D, P, nodes);
    //writeDToFile("input2.txt" , D, nodes);

    shortestPathsAlgorithm(D, P, nodes);


    matrix = createTable(nodes, nodes);
    matrixP = createTable(nodes, nodes);


    createTablesGrid(nodes, matrix, matrixP);

}

void deleteTablesGrid()
{
    grid = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid, 10);
    gtk_grid_set_column_spacing (grid, 10);

    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 10);
    gtk_grid_set_column_spacing (grid2, 10);

}


void createTablesGrid(int nodes, GtkWidget *** matrix, GtkWidget *** matrixP){

    //matrix = createTable(nodes, nodes);
    //matrixP = createTable(nodes, nodes);

    //int nodes = 5;
    int i, j;
    for (i = 0; i < nodes; i++)
    {
        /*
        GtkWidget *label = gtk_label_new (strs[i-1]);

        gtk_grid_attach(GTK_GRID(grid), label, 0, i, 1, 1);
        gtk_widget_show (label);
        
        GtkWidget *labelf = gtk_label_new (strs[i-1]);
        
        gtk_grid_attach(GTK_GRID(grid), labelf, i, 0, 1, 1);
        gtk_widget_show (labelf);



        label = gtk_label_new (strs[i-1]);

        gtk_grid_attach(GTK_GRID(grid2), label, 0, i, 1, 1);
        gtk_widget_show (label);
        
        labelf = gtk_label_new (strs[i-1]);
        
        gtk_grid_attach(GTK_GRID(grid2), labelf, i, 0, 1, 1);
        gtk_widget_show (labelf);
*/

        for(j = 0; j < nodes; j++)
        {
            //char number[12];
            //sprintf(number,"%d", D[i][j]);
            
            GtkWidget *label = gtk_label_new ("");
            
            GdkColor lcolor;
            gdk_color_parse ("white", &lcolor);
            gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);
            
            //gtk_container_add (GTK_CONTAINER (table), label);
            gtk_grid_attach(GTK_GRID(grid), label, j, i, 1, 1);
            gtk_widget_show (label);

            matrix[i][j] = label;
            
            GtkWidget *labelp = gtk_label_new ("");
            
            GdkColor lcolorp;
            gdk_color_parse ("white", &lcolorp);
            gtk_widget_modify_fg (labelp, GTK_STATE_NORMAL, &lcolorp);
            
            //gtk_container_add (GTK_CONTAINER (table), label);
            gtk_grid_attach(GTK_GRID(grid2), labelp, j, i, 1, 1);
            gtk_widget_show (labelp);

            matrixP[i][j] = labelp;

        }
    }

    on_btn_calcular_RMC_clicked();

}

GtkWidget*** createTable(int rows, int columns)
{
    int i;

    GtkWidget *** matrix = (GtkWidget ***) calloc(rows, sizeof(GtkWidget **));    
    for (i = 0; i < rows; i++)
    {
        matrix[i] = (GtkWidget **) calloc(columns, sizeof(GtkWidget *));
    }

    return matrix;
}

 
// called when window is closed
void on_window_RMC_datos_destroy()
{
    gtk_widget_destroy(window_RMC_datos);
}

void on_window_RMC_destroy()
{
    gtk_widget_destroy(window_RMC);
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_RMC);
}

void on_btn_cancelar_RMC_datos_clicked()
{
     gtk_widget_destroy(window_RMC_datos);
}

void on_btn_calcular_RMC_clicked()
{
   // ------------------------------
    //shortestPathsAlgorithm(D, P, nodes);
    //dnumber++;
    if(dnumber <= nodes) 
    {
        char d[15];
        sprintf(d,"src/temp/D%d", dnumber);

        char p[10];
        sprintf(p,"src/temp/P%d", dnumber);

        readDFromFile(d, D, P, nodes);
        readDFromFile(p, P, P, nodes);

        showDTable(matrix, D, nodes);
        showDTable(matrixP, P, nodes);

        dnumber++;

    } else {
        gtk_widget_show(window_routes);
    }
    


}

/*
void optimunpath(int x, int y, char* buffer)
{
    if (P[x][y] == 0)
    {
        char number[5];
        sprintf(number,"%d->", x + 1);
        strcat(buffer, number);
    } 
    else
    {
        optimunpath(x, P[x][y], buffer);
        optimunpath(P[x][y], y, buffer);
    }
}

void path(int x, int y, char* ruta){
    char number[5];
    sprintf(number,"%d->", a);
    strcpy(ruta, number);

    a = P[a-1][y-1];

        while (a > 0)
        {   
            sprintf(number,"%d->", a);
            strcat(ruta, number);
            a = P[a-1][y-1];
        }

        sprintf(number,"%d", y);
        strcat(ruta, number);

}
*/

void on_btn_calcular_ruta_clicked()
{
    //entryA
    //entryDe
    // entryRespuestaRoute

    const gchar *de;
    de = gtk_entry_get_text(GTK_ENTRY(entryDe));
    int valDe = atoi(de);

    const gchar *a;
    a = gtk_entry_get_text(GTK_ENTRY(entryA));
    int valA = atoi(a);


    if(valA > nodes || valDe > nodes || a == de)
    {

    } else 
    {
        //char str[80];
        //strcpy(str, "these ");
        
        int ruta_lenght = 2 * nodes;
        char ruta[ruta_lenght];
        char number[5];

        int a = valDe;
        int y = valA;

        sprintf(number,"%d->", a);
        strcpy(ruta, number);

        a = P[a-1][y-1];

        while (a > 0)
        {   
            sprintf(number,"%d->", a);
            strcat(ruta, number);
            a = P[a-1][y-1];
        }

        sprintf(number,"%d", y);
        strcat(ruta, number);
        

        //char* ruta[50];
        //strcpy(ruta, "");
        //valA--;
        //valDe--;
        //optimunpath(valDe, valA, ruta);
        gtk_label_set_text (entryRespuestaRoute, ruta);
    }

}


/*void on_btn_aceptar_RMC_datos_clicked()
{
	const gchar *cant_nodos;
	cant_nodos = gtk_entry_get_text(GTK_ENTRY(cant_nodos_RMC));
	int val = atoi(cant_nodos);
	
	nnodos = val;
	
	gtk_widget_destroy(window_RMC_datos);
	gridt = gtk_grid_new ();
	gtk_grid_set_row_spacing (gridt, 10);
    gtk_grid_set_column_spacing (gridt, 10);
	
    gtk_grid_set_column_homogeneous (gridt,1);
    gtk_grid_set_row_homogeneous (gridt,1);   
	
    int i, j;
    for (i = 0; i < val; i++)
    {
        for(j = 0; j < val; j++)
		{						
            GtkWidget *entry = gtk_entry_new ();
            //gtk_container_add (GTK_CONTAINER (table), label);
            gtk_entry_set_width_chars(entry,5);
            gtk_grid_attach(GTK_GRID(gridt), entry, j, i, 1, 1);
            gtk_widget_show (entry);
        }
    }

	gtk_container_add (GTK_CONTAINER (tabla_datosD0), gridt);
	gtk_widget_show (gridt);
	gtk_widget_show(window_datosD0);

}*/

void on_btn_aceptar_RMC_datos_clicked()
{
    const gchar *cant_nodos;
    cant_nodos = gtk_entry_get_text(GTK_ENTRY(cant_nodos_RMC));
    int val = atoi(cant_nodos);
    
    nnodos = val;
    
    gtk_widget_destroy(window_RMC_datos);
    gridt = gtk_grid_new ();
    gtk_grid_set_row_spacing (gridt, 5);
    gtk_grid_set_column_spacing (gridt, 5);
    
    int i, j;
    for (i = 1; i < val+1; i++)
    {
        GtkWidget *label = gtk_label_new (strs[i-1]);

        gtk_grid_attach(GTK_GRID(gridt), label, 0, i, 1, 1);
        gtk_widget_show (label);
        
        GtkWidget *labelf = gtk_label_new (strs[i-1]);
        
        gtk_grid_attach(GTK_GRID(gridt), labelf, i, 0, 1, 1);
        gtk_widget_show (labelf);
        
        for(j = 1; j < val+1; j++)
        {                       
            GtkWidget *entry = gtk_entry_new();
            gtk_entry_set_width_chars(entry,5);
            //gtk_container_add (GTK_CONTAINER (table), label);
            gtk_grid_attach(GTK_GRID(gridt), entry, j, i, 1, 1);
            gtk_widget_show (entry);
        }
    }
    gtk_container_add (GTK_CONTAINER (tabla_datosD0), gridt);
    gtk_widget_show (gridt);
    gtk_widget_show(window_datosD0);

}

void on_window_datosD0_destroy()
{
	
}

void on_btn_aceptar_datosD0_clicked()
{
	FILE *file;
	file = fopen("prueba.txt", "w");
	
	fprintf(file, "%i\n", nnodos);
	
	for(int i=1;i<=nnodos;i++){	
		for(int j=1;j<=nnodos;j++){
			const gchar *cant_nodos;
			cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
			int valor = atoi(cant_nodos);
			
			fprintf(file, "%i\n", valor);
		}
	}
	
	fclose(file);
	
	gtk_widget_destroy(window_datosD0);
	gtk_widget_show(window_RMC);

    initialize("prueba.txt");

}

void showDTable(GtkWidget*** matrix, int **D, int nodes)
{

    //int nodes = 5;
    int i, j;
    for (i = 0; i < nodes; i++)
    {
        for(j = 0; j < nodes; j++)
        {

            char number[12];
            sprintf(number,"%d", D[i][j]);

            char * t = gtk_label_get_text (matrix[i][j]);

            int rc = strcmp(t, number);
            if(rc != 0) {

                GdkColor lcolor;
                gdk_color_parse ("yellow", &lcolor);
                gtk_widget_modify_fg (matrix[i][j], GTK_STATE_NORMAL, &lcolor);

                gtk_label_set_text (matrix[i][j], number);

            } else {

                GdkColor lcolor;
                gdk_color_parse ("white", &lcolor);
                gtk_widget_modify_fg (matrix[i][j], GTK_STATE_NORMAL, &lcolor);

                gtk_label_set_text (matrix[i][j], number);

            }

            

        }
    }

}