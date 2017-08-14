#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "seriesDeportivas.h"
#include "lib/matrix.c"

GtkWidget *table;
GtkWidget *tableP;
GtkBuilder *builder; 
GtkWidget  *window_SD;
GtkWidget  *window_nuevo_SD;
GtkWidget  *window_crear_SD;
GtkWidget *gridt;
GtkWidget * grid;
GtkWidget * grid2;
GtkWidget * gridr;
GtkWidget * entry_cargar_SD;
GtkWidget *datos_SD;
GtkWidget *tabla_sol_SD;
GtkWidget *tabla_nuevo_SD;
GtkWidget *respuesta_SD;
GtkWidget * juegos_SD;
GtkWidget * Ph_SD;
GtkWidget * Pr_SD;


GtkWidget *folder;
GtkWidget *filenameEntry;
GtkWidget *guardar;

char *strs[50]= {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};

int numeroJuegos;
float ph;
float pr;

float ** tabla;
int * vectorVisitas;

float resp;

// ejemplos

/* 
    // Ejemplo en clases
	ph = 0.57;
	pr = 0.49;

	numeroJuegos = 7;
	//printf("%i\n", numeroJuegos/2 + 1);

	float ** tabla = createFloatMatrix(numeroJuegos/2 + 2, numeroJuegos/2 + 2);

	//printFloatMatrix(tabla, numeroJuegos/2 + 2, numeroJuegos/2 + 2);

	int * vectorVisitas = visitas(numeroJuegos);

	vectorVisitas[0] = 1;
	vectorVisitas[1] = 1;
	vectorVisitas[2] = 0;
	vectorVisitas[3] = 0;
	vectorVisitas[4] = 0;
	vectorVisitas[5] = 1;
	vectorVisitas[6] = 1;

	calcularSerie(numeroJuegos, ph, pr, vectorVisitas, tabla);

	// Quiz 6

	ph = 0.50;
	pr = 0.40;

	numeroJuegos = 5;
	//printf("%i\n", numeroJuegos/2 + 1);

	float ** tabla = createFloatMatrix(numeroJuegos/2 + 2, numeroJuegos/2 + 2);

	//printFloatMatrix(tabla, numeroJuegos/2 + 2, numeroJuegos/2 + 2);

	int * vectorVisitas = visitas(numeroJuegos);

	vectorVisitas[0] = 0;
	vectorVisitas[1] = 0;
	vectorVisitas[2] = 1;
	vectorVisitas[3] = 1;
	vectorVisitas[4] = 1;
	
	calcularSerie(numeroJuegos, ph, pr, vectorVisitas, tabla);

*/

int main (int argc, char *argv[])
{
	gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/SD_glade.glade", NULL);
 
	window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));
	entry_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_SD"));
    datos_SD = GTK_WIDGET(gtk_builder_get_object(builder, "datos_SD"));
    tabla_sol_SD = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol_SD"));
	window_nuevo_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_nuevo_SD"));
	tabla_nuevo_SD = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_nuevo_SD"));
	window_crear_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_crear_SD"));
	juegos_SD = GTK_WIDGET(gtk_builder_get_object(builder, "juegos_SD"));
	Ph_SD = GTK_WIDGET(gtk_builder_get_object(builder, "Ph_SD"));
	Pr_SD = GTK_WIDGET(gtk_builder_get_object(builder, "Pr_SD"));
	respuesta_SD = GTK_WIDGET(gtk_builder_get_object(builder, "respuesta_SD"));

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
	
	gtk_container_add (GTK_CONTAINER (datos_SD), grid);
    gtk_widget_show (grid);

    gtk_container_add (GTK_CONTAINER (tabla_sol_SD), grid2);
    gtk_widget_show (grid2);
    
    gtk_container_add (GTK_CONTAINER (tabla_nuevo_SD), gridr);
    gtk_widget_show (gridr);
	
    gtk_builder_connect_signals(builder, NULL);   
 
    gtk_widget_show(window_SD);                
    gtk_main();
	
	return 0;
}

void initialize(char * filename)
{
	ph = 0,0;
	pr = 0,0;

	numeroJuegos = 0;
	// //printf("%i\n", numeroJuegos/2 + 1);

	// -- tabla = createFloatMatrix(numeroJuegos/2 + 2, numeroJuegos/2 + 2);

	// //printFloatMatrix(tabla, numeroJuegos/2 + 2, numeroJuegos/2 + 2);

	// -- vectorVisitas = visitas(numeroJuegos);

	// -- calcularSerie(numeroJuegos, ph, pr, vectorVisitas, tabla);
	
	readFile(filename);
}

int * visitas (int numeroJuegos)
{

	int * visitas = (int *) calloc(numeroJuegos, sizeof(int));
	int i;
	
	for (i = 0; i < numeroJuegos; i++)
	{
		visitas[i] = 0;
	}

	return visitas;
}

void calcularSerie(int numeroJuegos, float ph, float pr, int* vectorVisitas, float ** tabla)
{
	int i, j;
	for (i = 1; i < numeroJuegos/2 + 2; i++)
	{
		tabla[i][0] = 0;
		tabla[0][i] = 1;
	}

	// Tabla[i][j] = Tabla[i - 1][j] * p + Tabla[i][j-1] * q;
	for (i = 1; i < numeroJuegos / 2 + 2; i++)
	{
		for(j = 1; j < numeroJuegos / 2 + 2; j++)
		{
			//printf("\n juego #: %i \n", numeroJuegos/2 + 1 - i + numeroJuegos/2 + 1 - j);
			if (vectorVisitas[numeroJuegos/2 + 1 - i + numeroJuegos/2 + 1 - j] == 1){
				tabla[i][j] = tabla[i - 1][j] * ph + tabla[i][j-1] * (1 - ph);
			} else {
				tabla[i][j] = tabla[i - 1][j] * pr + tabla[i][j-1] * (1 - pr);
			}
			resp = tabla[i][j]*100;
		}
	}
	//printf("%f",resp);
}

void drawData(){

	for(int i = 0; i < (numeroJuegos+4); i++)
	{
		gtk_grid_remove_row (grid, 0);
	}
	
	for(int i = 0; i < numeroJuegos; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}
	
	gtk_label_set_text(respuesta_SD,"");

	int i;
	for (i = 0; i < 4; i++)
    {
		char val[30];
		
		if(i==0){
			strcpy(val,"Ph = ");
			char v[12];
			sprintf(v,"%f",ph);
			strcat(val,v);	
		}
		else if(i==1){
			strcpy(val,"Pr = ");
			char v[12];
			sprintf(v,"%f",pr);
			strcat(val,v);	
		}
		else if(i==2){
			strcpy(val,"Qh = ");
			char v[12];
			sprintf(v,"%f",(1-pr));
			strcat(val,v);	
		}
		else{
			strcpy(val,"Qr = ");
			char v[12];
			sprintf(v,"%f",(1-ph));
			strcat(val,v);	
		}
		
		GtkWidget *label = gtk_label_new (val);
		gtk_widget_set_size_request(label, 470, 430/(numeroJuegos+4));

		GdkColor lcolor;
		gdk_color_parse ("white", &lcolor);
		gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

		gtk_grid_attach(GTK_GRID(grid), label, 0, i, 1, 1);
		gtk_widget_show (label);
	}
	
	for (i=0;i<numeroJuegos;i++){
		char val[50];
		strcpy(val,"Juego ");
		char v[12];
		sprintf(v,"%d",(i+1));
		strcat(val,v);
		char casa[20];
		
		if(vectorVisitas[i]==0){
			strcpy(casa, ": B Casa.");
		}
		else{
			strcpy(casa, ": A Casa.");
		}

		strcat(val,casa);	

		GtkWidget *label = gtk_label_new (val);
		gtk_widget_set_size_request(label, 470, 430/(numeroJuegos+4));

		GdkColor lcolor;
		gdk_color_parse ("white", &lcolor);
		gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

		gtk_grid_attach(GTK_GRID(grid), label, 0, (4+i), 1, 1);
		gtk_widget_show (label);
	}
}

void drawAnswer(){
	int i, j;

	/*for(int i = -1; i < plazo+1; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}*/
	
    for (i = -1; i < (numeroJuegos/2 + 2); i++)
    {
        for(j = -1; j < (numeroJuegos/2 + 2); j++)
        {
			if (i==-1){
				if(j==-1){
					GtkWidget *label = gtk_label_new ("");
					gtk_widget_set_size_request(label, 470/(numeroJuegos/2 + 3), 470/(numeroJuegos/2 + 3));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
				else{
					char val[30];
					sprintf(val,"%d", j);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/(numeroJuegos/2 + 3), 470/(numeroJuegos/2 + 3));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);		
				}
			}
			else{
				if(j==-1){
					char val[30];
					sprintf(val,"%d", i);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/(numeroJuegos/2 + 3), 470/(numeroJuegos/2 + 3));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
				else{
					if((j==0)&&(i==0)){
						GtkWidget *label = gtk_label_new ("");
						gtk_widget_set_size_request(label, 470/(numeroJuegos/2 + 3), 470/(numeroJuegos/2 + 3));

						GdkColor lcolor;
						gdk_color_parse ("white", &lcolor);
						gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

						gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
						gtk_widget_show (label);
					}
					else{
						char val[30];
						sprintf(val,"%.*f", 4, tabla[i][j]);
						//char val2[12];
						//sprintf(val2,"%d", sackAnswers[i][j]);

						GtkWidget *label = gtk_label_new (val);
						gtk_widget_set_size_request(label, 470/(numeroJuegos/2 + 3), 470/(numeroJuegos/2 + 3));

						GdkColor lcolor;
						gdk_color_parse ("white", &lcolor);
						gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

						gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
						gtk_widget_show (label);	
					}
				}
			}
		}
    }
}

void readFile(char* filename)
{    

    FILE *file;
    file = fopen(filename, "r");
    
    fscanf(file, "%i", &numeroJuegos);
    fscanf(file, "%f", &ph);
    fscanf(file, "%f", &pr);
	
	vectorVisitas = visitas(numeroJuegos);

    int i = 0;

    while (i < numeroJuegos)
    {
		fscanf(file, "%i", &vectorVisitas[i]);
        i++;
    }

    fclose(file);
}

void writeFile(char* filename)
{

    FILE *file;
    file = fopen(filename, "w");
    
    int i = 0;

    fprintf(file, "%i\n", numeroJuegos);
    fprintf(file, "%f\n", ph);
    fprintf(file, "%f\n", pr);
	
    while (i < numeroJuegos)
    {
		fprintf(file, "%i\n", vectorVisitas[i]);
        i++;
    }

    fclose(file);
}

void on_guardar_SD_clicked ()
{
	char * filename[250];

	char* name = gtk_entry_get_text (filenameEntry);
	char* folderfile = gtk_file_chooser_get_filename(folder);

	sprintf(filename,"%s/%s", folderfile, name);

	writeFile(filename);

	gtk_entry_set_text (filenameEntry, "");

}

void on_btn_cargar_SD_clicked(){
	const gchar *filename;
    filename = gtk_file_chooser_get_filename (entry_cargar_SD);
	
    /*for(int i = 0; i < ; i++)
	{
		gtk_grid_remove_row (grid, 0);
	}*/

	/*for(int i = -1; i < plazo+1; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}*/

	initialize(filename);
	drawData();
}

void on_btn_calcular_SD_clicked()
{	
	tabla = createFloatMatrix(numeroJuegos/2 + 2, numeroJuegos/2 + 2);
	
	resp = 0;
	
	calcularSerie(numeroJuegos, ph, pr, vectorVisitas, tabla);
	
	printFloatMatrix(tabla, numeroJuegos/2 + 2, numeroJuegos/2 + 2);
	
	char val[120];
	strcpy(val,"La probabilidad de que A gane la serie es de: ");
	char v[30];
	sprintf(v,"%f",resp);
	strcat(val,v);
	strcat(val,"%.");
	
	GdkColor lcolor;
	gdk_color_parse ("green", &lcolor);
	gtk_widget_modify_fg (respuesta_SD, GTK_STATE_NORMAL, &lcolor);
	
	gtk_label_set_text(respuesta_SD,val);
	
	drawAnswer();
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}

void on_btn_crear_SD_clicked()
{
	gtk_widget_show(window_crear_SD);	
}

void callback(GtkWidget *button, gpointer data)
{
    const gchar *casa;
	casa = gtk_button_get_label(gtk_grid_get_child_at (gridt,1,data));
	
	if (strcmp(casa, "A Casa")==0){
		gtk_button_set_label(gtk_grid_get_child_at (gridt,1,data),"B Casa");
	}
	else{
		gtk_button_set_label(gtk_grid_get_child_at (gridt,1,data),"A Casa");
	}
}

void on_btn_aceptar_crear_clicked()
{
	const gchar *juegosS;
	juegosS = gtk_entry_get_text(GTK_ENTRY(juegos_SD));
	int juegosAux = atoi(juegosS);
	numeroJuegos = juegosAux;
	
	const gchar *phS;
	phS = gtk_entry_get_text(GTK_ENTRY(Ph_SD));
	float phAux = atof(phS);
	ph = phAux;
	
	const gchar *prS;
	prS = gtk_entry_get_text(GTK_ENTRY(Pr_SD));
	float prAux = atof(prS);
	pr = prAux;
	
	vectorVisitas = visitas(numeroJuegos);
	
	int i, j;
    for (i = 0; i < numeroJuegos; i++)
    {		
		char val[120];
		strcpy(val,"Juego ");
		char v[30];
		sprintf(v,"%d",(i+1));
		strcat(val,v);
		strcat(val,": ");
		
		GtkWidget *label = gtk_label_new (val);
		gtk_widget_set_size_request(label, 470/2, 415/numeroJuegos);
		
		GdkColor lcolor;
		gdk_color_parse ("white", &lcolor);
		gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

		gtk_grid_attach(GTK_GRID(gridt), label, 0, i, 1, 1);
		gtk_widget_show (label);
		
		GtkWidget *button = gtk_button_new_with_label ("A Casa");
		gtk_widget_set_size_request(button, 470/2, 415/numeroJuegos);
		g_signal_connect(button, "clicked", G_CALLBACK(callback), i);
		
		gtk_grid_attach(GTK_GRID(gridt), button, 1, i, 1, 1);
		gtk_widget_show (button);
		
    }
	gtk_container_add (GTK_CONTAINER (tabla_nuevo_SD), gridt);
	gtk_widget_show (gridt);
	
	gtk_widget_destroy(window_crear_SD);
	gtk_widget_show(window_nuevo_SD);
}

void on_btn_cancelar_crear_clicked()
{
	gtk_widget_destroy(window_crear_SD);
}

void on_btn_cancelar_nuevo_clicked()
{
	gtk_widget_destroy(window_nuevo_SD);
}

void on_btn_aceptar_nuevo_clicked()
{			
	for(int i=0;i<numeroJuegos;i++){	
		const gchar *casa;
		casa = gtk_button_get_label(gtk_grid_get_child_at (gridt,1,i));
		
		//printf("%s\n",casa);
		
		if (strcmp(casa, "A Casa")==0){
			vectorVisitas[i]=1;
		}
		else{
			vectorVisitas[i]=0;
		}
	}
	
	drawData();
	gtk_widget_destroy(window_nuevo_SD);
}