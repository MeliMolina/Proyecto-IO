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

GtkWidget *folder;
GtkWidget *filenameEntry;
GtkWidget *guardar;
GtkWidget *tabla_input;

GtkWidget *table;
GtkWidget *SalirDelPrograma;

GtkWidget *tabla_planAux;
GtkWidget *calculos;
GtkWidget *grid1;
GtkWidget *grid2;
GtkWidget *gridt;

GtkWidget *result;

GtkWidget *plan;
GtkWidget *costo;

GtkWidget *label;
GtkWidget *box;


char *strs[100]= {"Años","Mantenimiento","Reventa"};

int ** tabla;
int ** tabla2;

int contador = 0;
int nnodos;

int costoini = 0;
int tiempototal = 0;
int vidaUtil = 1;


int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Reemplazo_Equipos.glade", NULL);
 
    window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));

    gtk_builder_connect_signals(builder, NULL);   
    entry_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_SD"));
    folder = GTK_WIDGET(gtk_builder_get_object(builder, "folder"));
    filenameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "filename"));
    guardar = GTK_WIDGET(gtk_builder_get_object(builder, "guardar_SD"));
    btn_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_cargar_SD"));
    SalirDelPrograma = GTK_WIDGET(gtk_builder_get_object(builder, "SalirDelPrograma"));

    plan = GTK_WIDGET(gtk_builder_get_object(builder, "plan"));
    costo = GTK_WIDGET(gtk_builder_get_object(builder, "costo"));
    result = GTK_WIDGET(gtk_builder_get_object(builder, "result"));
    tabla_planAux = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_planAux"));
    tabla_input = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_input"));
    calculos = GTK_WIDGET(gtk_builder_get_object(builder, "calculos"));
	
    gtk_widget_set_tooltip_text(entry_cargar_SD, "Seleccionar un archivo");
    gtk_widget_set_tooltip_text(folder, "Seleccionar un directorio");
    gtk_widget_set_tooltip_text(filenameEntry, "Nombre del archivo a guardar");
    gtk_widget_set_tooltip_text(guardar, "Guarda los datos en un archivo");
    gtk_widget_set_tooltip_text(btn_cargar_SD, "Carga el archivo seleccionado");
    gtk_widget_set_tooltip_text(SalirDelPrograma, "Cierra el programa");

    g_object_unref(builder);
    gtk_widget_show(window_SD);               
    gtk_main();
    return 0;
} 

void deleteTablesGrid(GtkWidget *widget)
{
    GList *children, *iter;

    children = gtk_container_get_children(GTK_CONTAINER(widget));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

}


int on_btn_calcular_clicked(){

	deleteTablesGrid(tabla_planAux);
	gtk_label_set_text(GTK_LABEL(calculos), "");

	tabla = createFloatMatrix(tiempototal, 2);
	//tabla2 = createFloatMatrix(tiempototal, 2);
    for(int i=1;i<=tiempototal;i++){ 
        for(int j=2;j<4;j++){
            
                const gchar *cant_nodos;
                cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
                int valor = atoi(cant_nodos);
                if(isdigit(cant_nodos[0])==FALSE){
                    gtk_label_set_text(GTK_LABEL(result), "Los valores de la tabla no pueden tener letras.");
                    return 0;
                }
                else if(valor < 0){
                    gtk_label_set_text(GTK_LABEL(result), "Los valores de la tabla tienen que ser mayor o igual que 0");
                    return 0;
                }
                else{
                    tabla[i-1][j-2] = valor;
                }
            
        }
    }
/*
	contador = 0;

	for(int i=1;i<=nnodos;i++){	
		for(int j=2;j<=nnodos;j++){
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
		
		strs[i-1] = cant_nodos;
	}
	for(int i=1;i<=nnodos;i++){	
		const gchar *cant_nodos;
		cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,i,0));
		
		strs[i-1] = cant_nodos;
	}

	char val[40];
    strcpy(val,"D(");
    char v[12];
    sprintf(v,"%d",contador+1);
    strcat(val,v);

    strcat(val,")");

    //gtk_label_set_text(GTK_LABEL(tabla_label), val);
		
	
	CrearTabla();

	for(int i = 1; i <= nnodos; i++){
		for(int j = 1; j <= nnodos; j++){
			tabla[i][j] = tabla2[i][j];
		}
	}*/
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}

void CrearTabla(){
                   
    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 1);
    gtk_grid_set_column_spacing (grid2, 1);

    for (int i = 0; i < tiempototal; i++)
    {
        for(int j = 0; j < 2; j++)
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

    gtk_container_add (GTK_CONTAINER (tabla_planAux), grid2);
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



void readFile(char* filename)
{    

    FILE *file;
    file = fopen(filename, "r");
    char array[10];
    fgets(array, sizeof(array), file);
    strip(array);
    //fscanf(file, "%i", &nnodos);
    nnodos = atoi(array);
    
    tabla = createFloatMatrix(nnodos+1, nnodos+1);
    tabla2 = createFloatMatrix(nnodos+1, nnodos+1);
    

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


void on_vidaUtil_changed(GtkWidget *widget){
    GtkComboBox *combo_box = widget;
    vidaUtil = gtk_combo_box_get_active (combo_box)+1;
}

int on_aceptPlan_clicked(){
    
    deleteTablesGrid(tabla_input);    
    gtk_label_set_text(GTK_LABEL(result), "");

    const gchar *pln;
    pln = gtk_entry_get_text(plan);
    int t = atoi(pln);
    
    pln = gtk_entry_get_text(costo);
    int c = atoi(pln);

    if(c<=0){
        gtk_label_set_text(GTK_LABEL(result), "El costo tiene que ser mayor que 0.");
        return 0;
    }
    if(t<=0){
        gtk_label_set_text(GTK_LABEL(result), "El plan tiene que ser entre 1 y 30 años.");
        return 0;
    }
    costoini = c;
    tiempototal = t;

    gridt = gtk_grid_new ();
    gtk_grid_set_row_spacing (gridt, 5);
    gtk_grid_set_column_spacing (gridt, 5);
    char v[5];

    for (int i = 0; i < t+1; i++)
    {
        
        for(int j = 0; j < 4; j++)
        {               
            if(i==0){ 
                GtkWidget *labelf = gtk_label_new (strs[j-1]);  
                gtk_grid_attach(GTK_GRID(gridt), labelf, j, 0, 1, 1);
                gtk_widget_show (labelf);}     
            if(j==1&&i!=0){              
                sprintf(v,"%d",i);
                GtkWidget *labelf = gtk_label_new (v);     
                gtk_grid_attach(GTK_GRID(gridt), labelf, 1, i, 1, 1);
                gtk_widget_show (labelf);}
            if(j>1&&i!=0){
            GtkWidget *entry = gtk_entry_new();
            gtk_entry_set_width_chars(entry,3);
            gtk_grid_attach(GTK_GRID(gridt), entry, j, i, 1, 1);
            gtk_widget_show (entry);}
        }
    }
    gtk_container_add (GTK_CONTAINER (tabla_input), gridt);
    gtk_widget_show (gridt);

   
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




