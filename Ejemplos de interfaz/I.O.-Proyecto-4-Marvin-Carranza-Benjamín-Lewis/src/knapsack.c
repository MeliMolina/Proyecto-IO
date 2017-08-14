#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "knapsack.h"
#include "lib/matrix.c"

 
// objeto costo valor y cantidad (infinito -> -1)
// capacidad máxima de la mochila, cantidad de objetos.

/* 

	object´s table 
	| value | cost | quantity |


	sack´s table
	capacity | object 0 | object 1 |...

*/

GtkWidget *table;
GtkWidget *tableP;
GtkBuilder *builder; 
GtkWidget  *window_PM;
GtkWidget  *window_nuevo;
GtkWidget  *window_crear;
GtkWidget  *window_resp;
GtkWidget *gridt;
GtkWidget * grid;
GtkWidget * grid2;
GtkWidget * gridr;
GtkWidget * entry_cargar_PM;
GtkWidget *tabla_datos_PM;
GtkWidget *tabla_sol_PM;
GtkWidget *tabla_nuevo_PM;
GtkWidget * cant_objetos_PM;
GtkWidget * cap_mochila_PM;
GtkWidget *lbl_resp;


GtkWidget *folder;
GtkWidget *filenameEntry;
GtkWidget *guardar;

int ** objects;
int ** sack;
int ** sackAnswers;
int sackCapacity;
int numberOfObjects;
int array[2];

char * objectNames = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
char *strs[50]= {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
char *objC[10]= {"Valor","Costo","Cantidad"};

int main(int argc, char *argv[])
{
	
	gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/PM_glade.glade", NULL);
 
	window_PM = GTK_WIDGET(gtk_builder_get_object(builder, "window_PM"));
	entry_cargar_PM = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_PM"));
    tabla_datos_PM = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_datos_PM"));
    tabla_sol_PM = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol_PM"));
	window_nuevo = GTK_WIDGET(gtk_builder_get_object(builder, "window_nuevo"));
	tabla_nuevo_PM = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_nuevo_PM"));
	window_crear = GTK_WIDGET(gtk_builder_get_object(builder, "window_crear"));
	cant_objetos_PM = GTK_WIDGET(gtk_builder_get_object(builder, "cant_objetos_PM"));
	cap_mochila_PM = GTK_WIDGET(gtk_builder_get_object(builder, "cap_mochila_PM"));
	
	window_resp = GTK_WIDGET(gtk_builder_get_object(builder, "window_resp"));
	lbl_resp = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_resp"));

	folder = GTK_WIDGET(gtk_builder_get_object(builder, "folder"));
    filenameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "filename"));

    grid = gtk_grid_new ();
    //gtk_grid_set_row_spacing (grid, 10);

    grid2 = gtk_grid_new ();
    //gtk_grid_set_row_spacing (grid2, 10);
    //gtk_grid_set_column_spacing (grid2, 10);
	
	gridt = gtk_grid_new ();
	//gtk_grid_set_column_spacing (gridt, 10);
	
	gridr = gtk_grid_new ();	
	
	//gtk_container_add (GTK_CONTAINER (tabla_nuevo_PM), gridt);
    //gtk_widget_show (gridt);
	
	gtk_container_add (GTK_CONTAINER (tabla_datos_PM), grid);
    gtk_widget_show (grid);

    gtk_container_add (GTK_CONTAINER (tabla_sol_PM), grid2);
    gtk_widget_show (grid2);
    
    gtk_container_add (GTK_CONTAINER (lbl_resp), gridr);
    gtk_widget_show (gridr);
	
    gtk_builder_connect_signals(builder, NULL);   
 
    gtk_widget_show(window_PM);                
    gtk_main();
	
    return 0;

}	

void initialize(char * filename)
{
	//char * filename = "src/ejm1.txt";
	//int array[2];
	readNumbers(filename, array);
	
	sackCapacity = array[0];
	numberOfObjects = array[1];

	objects = createMatrix(numberOfObjects, 3);
	sack = createMatrix(sackCapacity, numberOfObjects);
	sackAnswers = createMatrix(sackCapacity, numberOfObjects);

	readFile(filename, objects, sackCapacity, numberOfObjects);
//	writeFile("ejm3.txt", sackCapacity, objects, numberOfObjects);

}

void on_btn_crear_PM_clicked(){
	gtk_widget_show(window_crear);	
}

void on_btn_aceptar_crear_clicked(){
	const gchar *cant_objetos;
	cant_objetos = gtk_entry_get_text(GTK_ENTRY(cant_objetos_PM));
	int cant = atoi(cant_objetos);
	numberOfObjects = cant;
	
	const gchar *cap_mochila;
	cap_mochila = gtk_entry_get_text(GTK_ENTRY(cap_mochila_PM));
	int cap = atoi(cap_mochila);
	sackCapacity = cap + 1;
	
	int i, j;
    for (i = -1; i < numberOfObjects; i++)
    {
        for(j = -1; j < 3; j++)
		{			
			if(i==-1){
				if(j==-1){
					GtkWidget *label = gtk_label_new ("Objeto");
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));	
					
					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);
					
					gtk_grid_attach(GTK_GRID(gridt), label, j+1, i+1, 1, 1);
            		gtk_widget_show (label);
				}
				else{
					GtkWidget *label = gtk_label_new (objC[j]);
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);
					
					gtk_grid_attach(GTK_GRID(gridt), label, j+1, i+1, 1, 1);
            		gtk_widget_show (label);
				}
			}
			else{
				if(j==-1){
					GtkWidget *label = gtk_label_new (strs[i]);
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(gridt), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);
				}
				else{
					GtkWidget *entry = gtk_entry_new ();
					gtk_widget_set_size_request(entry, 470/4, 470/(numberOfObjects+1));
					gtk_grid_attach(GTK_GRID(gridt), entry, j+1, i+1, 1, 1);
					gtk_widget_show (entry);
				}
			}
        }
    }
	gtk_container_add (GTK_CONTAINER (tabla_nuevo_PM), gridt);
	gtk_widget_show (gridt);
	
	gtk_widget_destroy(window_crear);
	gtk_widget_show(window_nuevo);
}

void on_btn_cancelar_crear_clicked(){
	gtk_widget_destroy(window_crear);
}

void on_btn_cancelar_nuevo_clicked(){
	gtk_widget_destroy(window_nuevo);
}

void on_btn_aceptar_nuevo_clicked(){
	objects = createMatrix(numberOfObjects, 3);
	sack = createMatrix(sackCapacity, numberOfObjects);
	sackAnswers = createMatrix(sackCapacity, numberOfObjects);
			
	for(int i=1;i<=numberOfObjects;i++){	
		for(int j=1;j<=3;j++){
			const gchar *numb;
			numb = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
			int valor = atoi(numb);
			
			objects[i-1][j-1]=valor;
		}
	}
	
	drawData();
	gtk_widget_destroy(window_nuevo);
}

void drawData(){

	for(int i = -1; i < numberOfObjects; i++)
	{
		gtk_grid_remove_row (grid, 0);
	}

	int i, j;
	for (i = -1; i < numberOfObjects; i++)
    {
        for(j = -1; j < 3; j++)
        {
			if (i==-1){
				if(j==-1){
					GtkWidget *label = gtk_label_new ("");
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);			
				}
				else{
					GtkWidget *label = gtk_label_new (objC[j]);
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);
					}
			}
			else{
				if(j==-1){
					GtkWidget *label = gtk_label_new (strs[i]);
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
				else{
					char val[12];
					sprintf(val,"%d", objects[i][j]);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/4, 470/(numberOfObjects+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
			}
		}
	}
}

void drawAnswer (int ** sack, int sackCapacity, int numberOfObjects, int ** sackAnswers){
	int i, j;

	for(int i = -1; i < sackCapacity; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}
	
    for (i = -1; i < sackCapacity; i++)
    {
        for(j = -1; j < numberOfObjects; j++)
        {
			if (i==-1){
				if(j==-1){
					GtkWidget *label = gtk_label_new ("");
					gtk_widget_set_size_request(label, 470/(numberOfObjects+1), 470/(sackCapacity+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);			
				}
				else{
					GtkWidget *label = gtk_label_new (strs[j]);
					gtk_widget_set_size_request(label, 470/(numberOfObjects+1), 470/(sackCapacity+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);
				}
			}
			else{
				if(j==-1){
					char val[12];
					sprintf(val,"%d", i);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/(numberOfObjects+1), 470/(sackCapacity+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
				else{
					char val[12];
					sprintf(val,"%d", sack[i][j]);
					char val2[12];
					sprintf(val2,"%d", sackAnswers[i][j]);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/(numberOfObjects+1), 470/(sackCapacity+1));

					GdkColor lcolor;
					if (sackAnswers[i][j] == 0)
					{
						gdk_color_parse ("red", &lcolor);
					} 
					else {
						gdk_color_parse ("green", &lcolor);
					}
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
			}
        }
    }
}


void knapsack(int ** sack, int ** sackAnswers, int ** objects, int sackCapacity, int numberOfObjects)
{
	// table[i][j] = max([i][j], vj + [i - cj][j-1])
	// object cost: 			objects[j][1]
	// object value: 			objects[j][0]
	// object max quantity:		objects[j][2]

	int i, j, q, value;											// i -> sack capacity, j -> object, q -> number of copies of an object, value -> value of bringing q copies + value of last column
	
	for (j = 0; j < numberOfObjects; j++)						// each object column 
	{
		for(i = 0; i < sackCapacity; i++)						// each sack capacity
		{
			q = 0;
			while (q * objects[j][1] <= i) 						// each number of copies that can be 
			{
				
				value = q * objects[j][0];
				if (j > 0) 										// not the first column
				{
					value += sack[i - q * objects[j][1]][j - 1];// adds value of last column in the index [i - q * objects[j][1]][j - 1]
				}
				if (value > sack[i][j]) 						// if value is greater than before
				{
					sackAnswers[i][j] = q; 						// number of copies brought
					sack[i][j] = value;    						// greater value saved in matrix
				}
				q++;
				if (q > objects[j][2] && objects[j][2] != -1)	// if q is greater than object quantity and quantity isn´t infinity
				{
					break;										// break cicle of object
				}
			}
		}
	}

	printf("sack matrix\n\n");
	printMatrix(sack, sackCapacity, numberOfObjects);
	drawAnswer(sack, sackCapacity, numberOfObjects, sackAnswers);

	printf("\n\nsackAnswers matrix\n\n");
	printMatrix(sackAnswers, sackCapacity, numberOfObjects);

}

void getAnswer (int ** sackAnswers, int ** objects, int sackCapacity, int numberOfObjects)
{
	int j = numberOfObjects - 1;
	int i = sackCapacity - 1;

	int numberOfCopies;
	
	while (j >= 0)
	{
		numberOfCopies = sackAnswers[i][j];
		printf("Objeto %c llevar: %i copias\n", objectNames[j], numberOfCopies);
		i = i - numberOfCopies * objects[j][1];
		j--;
	
	}
}

void writeFile(char* filename, int sackCapacity, int ** objects, int numberOfObjects)
{

    FILE *file;
    file = fopen(filename, "w");
    
    int i = 0;
    int j = 0;

    fprintf(file, "%i\n", sackCapacity);
    fprintf(file, "%i\n", numberOfObjects);
    while (i < numberOfObjects)
    {
        while(j < 3)
        {
            fprintf(file, "%i\n", objects[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }

    fclose(file);
}

void readNumbers(char* filename, int * array)
{

    FILE *file;

    file = fopen(filename, "r");
    fscanf(file, "%i", &array[0]);
    fscanf(file, "%i", &array[1]);

    fclose(file);
}

void readFile(char* filename, int ** objects, int sackCapacity, int numberOfObjects)
{    

    FILE *file;
    file = fopen(filename, "r");
    
    fscanf(file, "%i", &sackCapacity);
    fscanf(file, "%i", &numberOfObjects);

    int i = 0;
    int j = 0;


    while (i < numberOfObjects)
    {
        while(j < 3)
        {
            fscanf(file, "%i\n", &objects[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }

    fclose(file);

}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_PM);
}

void on_btn_calcular_PM_clicked()
{
	knapsack(sack, sackAnswers, objects, sackCapacity, numberOfObjects);

	printf("\n\n");
	getAnswer(sackAnswers, objects, sackCapacity, numberOfObjects);
}

void on_btn_volver_resp_clicked()
{
	gtk_widget_destroy(window_resp);
}

void on_btn_resp_clicked()
{
	int j = numberOfObjects - 1;
	int i = sackCapacity - 1;

	int numberOfCopies;
	
	while (j >= 0)
	{
		numberOfCopies = sackAnswers[i][j];
		
		char resp[120];
		char nCopias[10];
		sprintf(nCopias,"%d", numberOfCopies);
        strcpy(resp, "Objeto ");
		strcat(resp, strs[j]);
		strcat(resp, " llevar: ");
		strcat(resp, nCopias);
		strcat(resp, " copia(s).");
		
		GtkWidget *label = gtk_label_new ("");
		gtk_label_set_text (label, resp);
		gtk_widget_set_size_request(label, 420-20, 420/numberOfObjects);

		GdkColor lcolor;
		gdk_color_parse ("white", &lcolor);
		gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

		gtk_grid_attach(GTK_GRID(gridr), label, 0, j, 1, 1);
		gtk_widget_show (label);
		//printf("Objeto %c llevar: %i copias\n", objectNames[j], numberOfCopies);
		i = i - numberOfCopies * objects[j][1];
		j--;
	
	}
	//for(int i=0;i<numberOfObjects;i++){
	//}
	gtk_widget_show(window_resp);
}

void on_btn_cargar_PM_clicked(){
	const gchar *filename;
    filename = gtk_file_chooser_get_filename (entry_cargar_PM); //gtk_entry_get_text(GTK_ENTRY(entry_cargar_PM));
	
    for(int i = -1; i < numberOfObjects; i++)
	{
		gtk_grid_remove_row (grid, 0);
	}

	for(int i = -1; i < sackCapacity; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}


	initialize(filename);
	drawData();
}

void on_guardar_clicked ()
{

	char * filename[250];

	char* name = gtk_entry_get_text (filenameEntry);
	char* folderfile = gtk_file_chooser_get_filename(folder);

	sprintf(filename,"%s/%s", folderfile, name);

	
	//gtk_entry_set_text (filenameEntry, filename);

	writeFile(filename, sackCapacity, objects, numberOfObjects);

	gtk_entry_set_text (filenameEntry, "");

}