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

 
GtkBuilder  *builder; 
GtkWidget  *window_SD;



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


GtkWidget *tabla_label;


GtkWidget *label;
GtkWidget *box;
char *strs[2000]= {"A","B","C","D","E","F","G","H","I","J"};
char *strsAux[20]= {"A","B","C","D","E","F","G","H","I","J"};
int ** tabla;
float resp;
int contador = 0;
int nnodos;


float mat[10][10];

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Rutas_Optimas.glade", NULL);
 
    window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));
    

    gtk_builder_connect_signals(builder, NULL);   
    entry_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_SD"));
    folder = GTK_WIDGET(gtk_builder_get_object(builder, "folder"));
    filenameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "filename"));

    btn_calcular_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_calcular_SD"));
    Nodos = GTK_WIDGET(gtk_builder_get_object(builder, "Nodos"));

    guardar = GTK_WIDGET(gtk_builder_get_object(builder, "guardar_SD"));
    btn_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_cargar_SD"));
    SalirDelPrograma = GTK_WIDGET(gtk_builder_get_object(builder, "SalirDelPrograma"));

    tabla_sol1 = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol1"));
    tabla_input = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_input"));
    tabla_sol2 = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol2"));
	tabla_label = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_label"));

    
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

void on_btn_calcular_clicked(){

	GList *children, *iter;

    children = gtk_container_get_children(GTK_CONTAINER(tabla_sol1));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

	char val[40];
    strcpy(val,"D(");
    char v[12];
    sprintf(v,"%d",contador);
    strcat(val,v);

    strcat(val,")");

    gtk_label_set_text(GTK_LABEL(tabla_label), val);

	tabla = createFloatMatrix(nnodos+1, nnodos+1);

	for(int i=1;i<=nnodos;i++){	
		for(int j=1;j<=nnodos;j++){
			if(i==j){
				tabla[i][j] = 0;
			}else{
			const gchar *cant_nodos;
			cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
			int valor = atoi(cant_nodos);
			tabla[i][j] = valor;}
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
		printf("%s\n",strs[i-1] );
	}

		
	
	CrearTabla();
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}


void CrearTabla(){
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
                    
                    gdk_color_parse( "#00BFFF", &color );
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
                    
                    gdk_color_parse( "#00BFFF", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j+1, i+1, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);
                }
                else{
                    
                    
                    
                        char val[30];
                        sprintf(val,"%d", tabla[i][j]);
                   

                        label = gtk_label_new (val);
                        gtk_widget_set_size_request(label, 470/(nnodos + 2), 470/(nnodos+ 2));

                         box = gtk_box_new(0, 0);
                        gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                        const GdkRGBA *color;
                        
                        gdk_color_parse( "#A9D0F5", &color );
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





int on_guardar_SD_clicked ()
{/*
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
    gtk_label_set_text(GTK_LABEL(result), "Se guardó exitosamente.");*/

}
void writeFile(char* filename)
{
/*
    FILE *file;
    file = fopen(filename, "w");
    
  

    fprintf(file, "%i\n", nnodos);
    fprintf(file, "%i\n", totalJuegos);
    fprintf(file, "%f\n", ph);
    fprintf(file, "%f\n", pr);
    fprintf(file, "%f\n", qh);
    fprintf(file, "%f\n", qr);
    
    for (int i = 0 ;i < totalJuegos;i++){
        fprintf(file, "%i\n", lugar_juego[i]);
    }

    fclose(file);*/
}

int on_btn_cargar_SD_clicked(){
    /*const gchar *filename;
    filename = gtk_file_chooser_get_filename (entry_cargar_SD);
    if(filename==NULL){
        gtk_label_set_text(GTK_LABEL(result), "Selecione un archivo.");
        return 0;
    }
    readFile(filename);*/
}


void readFile(char* filename)
{    
 

    /*FILE *file;
    file = fopen(filename, "r");
    
    fscanf(file, "%i", &nnodos);
    fscanf(file, "%i", &totalJuegos);
    fscanf(file, "%f", &ph);
    fscanf(file, "%f", &pr);
    fscanf(file, "%f", &qh);
    fscanf(file, "%f", &qr);
    
    

    int i = 0;

    while (i < totalJuegos)
    {
        fscanf(file, "%i", &lugar_juego[i]);
        i++;
    }

    fclose(file);

    
    if(totalJuegos==3){
        gtk_combo_box_set_active(cantJuegos,0);
    }
    if(totalJuegos==5){
        gtk_combo_box_set_active(cantJuegos,1);
    }
    if(totalJuegos==7){
        gtk_combo_box_set_active(cantJuegos,2);
    }
    if(totalJuegos==9){
        gtk_combo_box_set_active(cantJuegos,3);
    }
    if(totalJuegos==11){
        gtk_combo_box_set_active(cantJuegos,4);
    }

    gtk_combo_box_set_active(juego1,lugar_juego[0]);
    gtk_combo_box_set_active(juego2,lugar_juego[1]);
    gtk_combo_box_set_active(juego3,lugar_juego[2]);
    gtk_combo_box_set_active(juego4,lugar_juego[3]);
    gtk_combo_box_set_active(juego5,lugar_juego[4]);
    gtk_combo_box_set_active(juego6,lugar_juego[5]);
    gtk_combo_box_set_active(juego7,lugar_juego[6]);
    gtk_combo_box_set_active(juego8,lugar_juego[7]);
    gtk_combo_box_set_active(juego9,lugar_juego[8]);
    gtk_combo_box_set_active(juego10,lugar_juego[9]);
    gtk_combo_box_set_active(juego11,lugar_juego[10]);

    char array[10];

    int pht = ph*10000;
    int prt = pr*10000;
   

    snprintf(array, sizeof(array), "0.%d", pht);
    gtk_entry_set_text(GTK_ENTRY(g_Ph),array);

    snprintf(array, sizeof(array), "0.%d", prt);
    gtk_entry_set_text(GTK_ENTRY(g_Pr),array);

    char val[40];
    strcpy(val,"Ph = ");
    char v[12];
    sprintf(v,"%f",ph);
    strcat(val,v);

    strcat(val,"\n");

    strcat(val,"Pr = ");
    char v1[12];
    sprintf(v1,"%f",pr);

    strcat(val,v1);

    gtk_label_set_text(GTK_LABEL(probabilidades1), val);

    strcpy(val,"Qh = ");
    char v2[12];
    sprintf(v2,"%f",qh);
    strcat(val,v2); 

    strcat(val,"\n");

    strcat(val,"Qr = ");
    char v3[8];
    sprintf(v3,"%f",qr);
    strcat(val,v3);    

    gtk_label_set_text(GTK_LABEL(probabilidades2), val);*/


}

float stof(const char* s){
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
    /*const gchar *cant_nodos;
    cant_nodos = gtk_entry_get_text(GTK_ENTRY(cant_nodos_RMC));*/
    GtkComboBox *combo_box = widget;
    int val = gtk_combo_box_get_active (combo_box)+1;//atoi(cant_nodos);

    
    nnodos = val;
    
    
    gridt = gtk_grid_new ();
    gtk_grid_set_row_spacing (gridt, 5);
    gtk_grid_set_column_spacing (gridt, 5);
    
    int i, j;
    for (i = 1; i < val+1; i++)
    {
        //GtkWidget *label = gtk_label_new (strs[i-1]);

        /*gtk_grid_attach(GTK_GRID(gridt), label, 0, i, 1, 1);
        gtk_widget_show (label);*/

           
        /*GtkWidget *labelf = gtk_label_new (strs[i-1]);
        
        gtk_grid_attach(GTK_GRID(gridt), labelf, i, 0, 1, 1);
        gtk_widget_show (labelf);*/
        
        for(j = 1; j < val+1; j++)
        {               
        	if(i==1){ 
        		GtkWidget *entry = gtk_entry_new();
		        gtk_entry_set_width_chars(entry,3);
		        gtk_grid_attach(GTK_GRID(gridt), entry, j, 0, 1, 1);
		        gtk_entry_set_text(entry,strs[j-1]);
		        gtk_widget_show (entry);}     
        	if(j==1){
		        /*GtkWidget *entry = gtk_entry_new();
		        gtk_entry_set_width_chars(entry,3);
		        gtk_grid_attach(GTK_GRID(gridt), entry, 0, i, 1, 1);
		        gtk_entry_set_text(entry,strs[i-1]);
		        gtk_widget_show (entry);*/
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
            //gtk_container_add (GTK_CONTAINER (table), label);
            gtk_grid_attach(GTK_GRID(gridt), entry, j, i, 1, 1);
            gtk_widget_show (entry);}
        }
    }
    gtk_container_add (GTK_CONTAINER (tabla_input), gridt);
    gtk_widget_show (gridt);

    /*for(int i=0;i<=nnodos;i++){	
		for(int j=0;j<=nnodos;j++){
			if(i==j){	
				
    			gtk_entry_set_text(gtk_grid_get_child_at (gridt,j,i),"0");
				tabla[i][j] = 0;
			}
		}
	}*/
    
/*
    const gchar *phS;
    phS = gtk_entry_get_text(GTK_ENTRY(g_Ph));
    ph = stof(phS);
    const gchar *prS;
    prS = gtk_entry_get_text(GTK_ENTRY(g_Pr));
    pr = stof(prS);
    
    if(strlen(phS)==0 || strlen(prS)==0){
        gtk_label_set_text(GTK_LABEL(result), "Los campos no pueden estar vacíos.");
        return 0;
    }
    for(int i = 0 ; i <strlen(phS);i++){
 
        if(phS[i]=='.'){
            continue;
        }
    if(isdigit(phS[i])==FALSE){
            gtk_label_set_text(GTK_LABEL(result), "ph y pr tiene que ser entre 0 y 1.");
            return 0;
        }
    }
    for(int i = 0 ; i <strlen(prS);i++){
        if(prS[i]=='.'){
            continue;
        }
        if(isdigit(prS[i])==FALSE){
            gtk_label_set_text(GTK_LABEL(result), "ph y pr tiene que ser entre 0 y 1.");
            return 0;
        }
    }

    if((ph >= 0 && ph <=1)&&(pr >= 0 && pr <=1)){
        qr = 1 - ph;
        qh = 1 - pr;
        gtk_label_set_text(GTK_LABEL(result), "");
    }else{
 
        gtk_label_set_text(GTK_LABEL(result), "ph y pr tiene que ser entre 0 y 1.");
        return 0;
    }


 

    char val[40];
    strcpy(val,"Ph = ");
    char v[12];
    sprintf(v,"%f",ph);
    strcat(val,v);

    strcat(val,"\n");

    strcat(val,"Pr = ");
    char v1[12];
    sprintf(v1,"%f",pr);

    strcat(val,v1);

    gtk_label_set_text(GTK_LABEL(probabilidades1), val);

    strcpy(val,"Qh = ");
    char v2[12];
    sprintf(v2,"%f",qh);
    strcat(val,v2); 

    strcat(val,"\n");

    strcat(val,"Qr = ");
    char v3[8];
    sprintf(v3,"%f",qr);
    strcat(val,v3);    

    gtk_label_set_text(GTK_LABEL(probabilidades2), val);*/

}






