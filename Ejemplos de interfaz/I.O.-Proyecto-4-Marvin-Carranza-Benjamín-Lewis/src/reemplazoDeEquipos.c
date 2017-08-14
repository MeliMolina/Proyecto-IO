#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "reemplazoDeEquipos.h"
#include "lib/matrix.c"

#define COLS_VIDA_UTIL 3 

GtkWidget *table;
GtkWidget *tableP;
GtkBuilder *builder; 
GtkWidget  *window_RDE;
GtkWidget  *window_nuevo_RDE;
GtkWidget  *window_crear_RDE;
GtkWidget  *window_resp_RDE;
GtkWidget *gridt;
GtkWidget * grid;
GtkWidget * grid2;
GtkWidget * gridr;
GtkWidget * entry_cargar_RDE;
GtkWidget *tabla_datos_RDE;
GtkWidget *tabla_sol_RDE;
GtkWidget *tabla_nuevo_RDE;
GtkWidget * plazo_RDE;
GtkWidget * vida_util_RDE;
GtkWidget * inflacion_RDE;
GtkWidget * costo_RDE;
GtkWidget *lbl_resp_RDE;


GtkWidget *folder;
GtkWidget *filenameEntry;
GtkWidget *guardar;

char *strs[50]= {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};
char *objC[10]= {"Mantenimiento","Venta","Ganancia"};
char *auxx[10]= {"t","G(t)","Próximo"};

int vida_util;
int plazo;
int precio_compra;
int inflacion;

int ** tabla_vida_util;
int ** tabla_cx;
int ** tabla_plazos;
int ** G3;

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/RDE_glade.glade", NULL);
 
	window_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "window_RDE"));
	entry_cargar_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_RDE"));
    tabla_datos_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_datos_RDE"));
    tabla_sol_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol_RDE"));
	window_nuevo_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "window_nuevo_RDE"));
	tabla_nuevo_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_nuevo_RDE"));
	window_crear_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "window_crear_RDE"));
	plazo_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "plazo_RDE"));
	costo_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "costo_RDE"));
	inflacion_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "inflacion_RDE"));
	vida_util_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "vida_util_RDE"));
	
	window_resp_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "window_resp_RDE"));
	lbl_resp_RDE = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_resp_RDE"));

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
	
	gtk_container_add (GTK_CONTAINER (tabla_datos_RDE), grid);
    gtk_widget_show (grid);

    gtk_container_add (GTK_CONTAINER (tabla_sol_RDE), grid2);
    gtk_widget_show (grid2);
    
    gtk_container_add (GTK_CONTAINER (lbl_resp_RDE), gridr);
    gtk_widget_show (gridr);
	
    gtk_builder_connect_signals(builder, NULL);   
 
    gtk_widget_show(window_RDE);                
    gtk_main();
	
	return 0;
}
	
void initialize(char * filename)
{
	vida_util = 3;
	plazo = 5;
	precio_compra = 500;
	inflacion = 0;
	// tabla vida util
	// mantenimiento | venta | ganancia

	tabla_vida_util = createMatrix(vida_util, 3);
	//tabla_vida_util[0][0] = 30;
	//tabla_vida_util[0][1] = 400;
	//tabla_vida_util[0][2] = 0;

//	tabla_vida_util[1][0] = 40;
//	tabla_vida_util[1][1] = 300;
//	tabla_vida_util[1][2] = 0;

//	tabla_vida_util[2][0] = 60;
//	tabla_vida_util[2][1] = 250;
//	tabla_vida_util[2][2] = 0;

	readFile(filename, vida_util, plazo, precio_compra, inflacion, tabla_vida_util);
	
	//drawData();
}

void drawData(){

	for(int i = -1; i < vida_util; i++)
	{
		gtk_grid_remove_row (grid, 0);
	}

	int i, j;
	for (i = -1; i < vida_util; i++)
    {
        for(j = -1; j < 3; j++)
        {
			if (i==-1){
				if(j==-1){
					GtkWidget *label = gtk_label_new ("Año");
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);			
				}
				else{
					GtkWidget *label = gtk_label_new (objC[j]);
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);
					}
			}
			else{
				if(j==-1){
					GtkWidget *label = gtk_label_new (strs[i+1]);
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
				else{
					char val[12];
					sprintf(val,"%d", tabla_vida_util[i][j]);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));

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

void drawAnswer(int G[], int G2[]){
	int i, j;

	for(int i = -1; i < plazo+1; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}
	
    for (i = -1; i < plazo+1; i++)
    {
        for(j = -1; j < 2; j++)
        {
			if (i==-1){
					GtkWidget *label = gtk_label_new (auxx[j+1]);
					gtk_widget_set_size_request(label, 470/3, 470/(plazo+2));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);			
			}
			else{
				if(j==-1){
					char val[12];
					sprintf(val,"%d", i);

					GtkWidget *label = gtk_label_new (val);
					gtk_widget_set_size_request(label, 470/3, 470/(plazo+2));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);	
				}
				else{
					if (j==0){
						char val[12];
						sprintf(val,"%d", G[i]);
						//char val2[12];
						//sprintf(val2,"%d", sackAnswers[i][j]);

						GtkWidget *label = gtk_label_new (val);
						gtk_widget_set_size_request(label, 470/3, 470/(plazo+2));

						GdkColor lcolor;
						gdk_color_parse ("white", &lcolor);
						gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

						gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
						gtk_widget_show (label);	
					}
					else{
						char val[120];
						sprintf(val,"%d",G3[i][0]);
						//int k = 1;
						for (int k=1; k < G2[i]; k++)
						{
							//printf("G[%d][%d] = %d\n", i, k, G3[i][k]);
							//printf("%d - %d\n",k,G2[i]);
							//strcpy(val, "Objeto ");
							strcat(val, ", ");
							char v[12];
							sprintf(v,"%d", G3[i][k]);
							strcat(val, v);
						}
						
						if(i==plazo){
							strcpy(val,"");
						}

						GtkWidget *label = gtk_label_new (val);
						gtk_widget_set_size_request(label, 470/3, 470/(plazo+2));

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
	
void calcularCxs (int ** tabla_cx, int** tabla_vida_util, int vida_util, int plazo, int precio_compra)
{

	int i, j, k;

	for (i = 0; i < plazo; i++)
	{
		for (j = 1; j <= vida_util; j++)
		{
			int cx = precio_compra;
			
			for (k = 0; k < j; k++)
			{
				cx -= tabla_vida_util[k][2]; // ganancia por año
				cx += tabla_vida_util[k][0]; // mantenimiento
			}

			cx -= tabla_vida_util[k-1][1]; // venta
			tabla_cx[i][i + j] = cx;

		}

	}
	// /printMatrix(tabla_cx, plazo + 1, plazo + 1);
}

void calcularG(int ** tabla_cx, int** tabla_plazos, int vida_util, int plazo, int G[], int G2[], int ** G3)
{
	int i, j;

	for (i = plazo; i >= 0; i--)
	{

		j = i + vida_util;
		if (j > plazo)
		{
			j = plazo;
		}

		int k, menor;
		menor = 0;
		for (k = i + 1; k <= j; k++)
		{

			if (tabla_cx[i][k] + G[k] == menor)
			{
				int a = G2[i];
				
				G2[i] = a + 1;
				printf("G2[%i] = %i\n", i, G2[i]);

				G3[i][a] = k;
			}

			if (menor == 0 || tabla_cx[i][k] + G[k] < menor)
			{
				menor = tabla_cx[i][k] + G[k];
				//resetArrays(G2, vida_util, i);
				G2[i] = 1;
				G3[i][0] = k;
			}
		}

		G[i] = menor;
	}
}

void resetArrays(int G2[], int vida_util)
{
	int i;
	for (i = 0; i < vida_util; i++)
	{
		G2[i] = 0;
	}
}

void writeFile(char* filename, int vida_util, int plazo, int precio_compra, int inflacion, int ** tabla_vida_util)
{

    FILE *file;
    file = fopen(filename, "w");
    
    int i = 0;
    int j = 0;

    fprintf(file, "%i\n", vida_util);
    fprintf(file, "%i\n", plazo);
    fprintf(file, "%i\n", precio_compra);
    fprintf(file, "%i\n", inflacion);
    while (i < vida_util)
    {
        while(j < 3)
        {
            fprintf(file, "%i\n", tabla_vida_util[i][j]);
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
    fscanf(file, "%i", &array[2]);
    fscanf(file, "%i", &array[3]);

    fclose(file);
}

void readFile(char* filename, int vida_util, int plazo, int precio_compra, int inflacion, int ** tabla_vida_util)
{    

    FILE *file;
    file = fopen(filename, "r");
    
    fscanf(file, "%i", &vida_util);
    fscanf(file, "%i", &plazo);
    fscanf(file, "%i", &precio_compra);
    fscanf(file, "%i", &inflacion);

    int i = 0;
    int j = 0;

    while (i < vida_util)
    {
        while(j < 3)
        {
            fscanf(file, "%i\n", &tabla_vida_util[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }

    fclose(file);
}

/*void func(int n, int G2[], int ** G3){
	if(n==plazo){
		//strcat(resp, " - 5");
		printf("%i\n", plazo);
		return;
	}
	else{
		if(n==0){
			//strcat(resp, "0");
			printf("%i",0);
		}
		else{
			//char v[12];
			//sprintf(v,"%d",n);
			//strcat(resp, " - ");
			//strcat(resp, v);
			printf("%i - ",n);
		}
		//int k = G2[n];
		int i = 0;
		for(i = 0;i < G2[n]; i++){
			func(G3[n][i], G2, G3);
		}
	}
}

void getAnswers(int G2[], int ** G3)
{
	//char * resp = "";
	func(0, G2, G3);
}*/

void on_btn_crear_RDE_clicked()
{
	gtk_widget_show(window_crear_RDE);	
}

void on_btn_aceptar_crear_clicked()
{
	const gchar *plazoS;
	plazoS = gtk_entry_get_text(GTK_ENTRY(plazo_RDE));
	int plazoAux = atoi(plazoS);
	plazo = plazoAux;
	
	const gchar *vida_utilS;
	vida_utilS = gtk_entry_get_text(GTK_ENTRY(vida_util_RDE));
	int vida_utilAux = atoi(vida_utilS);
	vida_util = vida_utilAux;
	
	const gchar *costoS;
	costoS = gtk_entry_get_text(GTK_ENTRY(costo_RDE));
	int costoAux = atoi(costoS);
	precio_compra = costoAux;
	
	const gchar *inflacionS;
	inflacionS = gtk_entry_get_text(GTK_ENTRY(inflacion_RDE));
	int inflacionAux = atoi(inflacionS);
	inflacion = inflacionAux;
	
	int i, j;
    for (i = -1; i < vida_util; i++)
    {
        for(j = -1; j < 3; j++)
		{			
			if(i==-1){
				if(j==-1){
					GtkWidget *label = gtk_label_new ("Año");
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));	
					
					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);
					
					gtk_grid_attach(GTK_GRID(gridt), label, j+1, i+1, 1, 1);
            		gtk_widget_show (label);
				}
				else{
					GtkWidget *label = gtk_label_new (objC[j]);
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);
					
					gtk_grid_attach(GTK_GRID(gridt), label, j+1, i+1, 1, 1);
            		gtk_widget_show (label);
				}
			}
			else{
				if(j==-1){
					GtkWidget *label = gtk_label_new (strs[i+1]);
					gtk_widget_set_size_request(label, 470/4, 470/(vida_util+1));

					GdkColor lcolor;
					gdk_color_parse ("white", &lcolor);
					gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

					gtk_grid_attach(GTK_GRID(gridt), label, j+1, i+1, 1, 1);
					gtk_widget_show (label);
				}
				else{
					GtkWidget *entry = gtk_entry_new ();
					gtk_widget_set_size_request(entry, 470/4, 470/(vida_util+1));
					gtk_grid_attach(GTK_GRID(gridt), entry, j+1, i+1, 1, 1);
					gtk_widget_show (entry);
				}
			}
        }
    }
	gtk_container_add (GTK_CONTAINER (tabla_nuevo_RDE), gridt);
	gtk_widget_show (gridt);
	
	gtk_widget_destroy(window_crear_RDE);
	gtk_widget_show(window_nuevo_RDE);
}

void on_btn_cancelar_crear_clicked()
{
	gtk_widget_destroy(window_crear_RDE);
}

void on_btn_cancelar_nuevo_clicked()
{
	gtk_widget_destroy(window_nuevo_RDE);
}

void on_btn_aceptar_nuevo_clicked()
{
	tabla_vida_util = createMatrix(vida_util, 3);
			
	for(int i=1;i<=vida_util;i++){	
		for(int j=1;j<=3;j++){
			const gchar *numb;
			numb = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
			int valor = atoi(numb);
			
			tabla_vida_util[i-1][j-1]=valor;
		}
	}
	
	drawData();
	gtk_widget_destroy(window_nuevo_RDE);
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_RDE);
}

void on_btn_calcular_RDE_clicked()
{
	int G[plazo + 1];
	G[plazo] = 0;

	int G2[plazo + 1];
	G2[plazo] = 1;

	G3 = createMatrix(plazo + 1, plazo + 1);
	G3[plazo][0] = 0;
	
	tabla_plazos = createMatrix(plazo + 1, 3);
	
	tabla_cx = createMatrix(plazo + 1, plazo + 1);

	calcularCxs (tabla_cx, tabla_vida_util, vida_util, plazo, precio_compra);

	printMatrix(tabla_cx, plazo + 1, plazo + 1);

	calcularG(tabla_cx, tabla_plazos, vida_util, plazo, G, G2, G3);
	
	drawAnswer(G2,G3);

	//writeFile("Prueba.txt", vida_util, plazo, precio_compra, inflacion, tabla_vida_util);


	/*int i;
	for (i = 0; i < plazo + 1; i++)
	{

		printf("G[%i] = %i\n\n", i, G[i]);

	}

	for (i = 0; i < plazo + 1; i++)
	{

		printf("G[%i] = %i\n\n", i, G2[i]);

	}
	int j = 0;
	for (i = 0; i < plazo + 1; i ++)
	{
		for (j = 0; j < G2[i]; j++)
		{

			printf("G[%i][%i] = %i\n", i, j, G3[i][j]);

		}

		printf("\n");

	}*/
	//getAnswers(G2,G3);
}

void on_btn_volver_resp_clicked()
{
	gtk_widget_destroy(window_resp_RDE);
}

void on_btn_resp_RDE_clicked()
{
}

void on_btn_cargar_RDE_clicked(){
	const gchar *filename;
    filename = gtk_file_chooser_get_filename (entry_cargar_RDE); //gtk_entry_get_text(GTK_ENTRY(entry_cargar_PM));
	
    for(int i = -1; i < vida_util; i++)
	{
		gtk_grid_remove_row (grid, 0);
	}

	for(int i = -1; i < plazo+1; i++)
	{
		gtk_grid_remove_row (grid2, 0);
	}

	initialize(filename);
	drawData();
}

void on_guardar_RDE_clicked ()
{
	char * filename[250];

	char* name = gtk_entry_get_text (filenameEntry);
	char* folderfile = gtk_file_chooser_get_filename(folder);

	sprintf(filename,"%s/%s", folderfile, name);

	writeFile(filename, vida_util, plazo, precio_compra, inflacion, tabla_vida_util);

	gtk_entry_set_text (filenameEntry, "");

}