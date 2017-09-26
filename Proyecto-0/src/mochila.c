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
GtkWidget *tabla_solucion;

GtkWidget *table;
GtkWidget *SalirDelPrograma;


GtkWidget *grid1;
GtkWidget *grid2;
GtkWidget *gridt;

GtkWidget *cantObj;
GtkWidget *capacidad;

GtkWidget *result;
GtkWidget *resultadoFinal;


GtkWidget *label;
GtkWidget *box;
char *strs[50]= {"Objeto ","Valor","Peso","Cantidad"};
char *strsAux[20]= {"A","B","C","D","E","F","G","H","I","J","K","L","M","N"};
char *strs2[50]= {"t","G(t)","Próximo"};

int ** tablaColumnaAnterior;
int ** tablaColores;
int ** tablaResultado;
int ** tabla;
int capacidadMochila = 1;
int cantidadObjetos = 1;
int mayor;
int ** cantidadCombinaciones;

char val[300];

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Mochila.glade", NULL);
 
    window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));

    gtk_builder_connect_signals(builder, NULL);   
    entry_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_SD"));
    folder = GTK_WIDGET(gtk_builder_get_object(builder, "folder"));
    filenameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "filename"));

    btn_calcular_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_calcular_SD"));
    cantObj = GTK_WIDGET(gtk_builder_get_object(builder, "cantObj"));

    guardar = GTK_WIDGET(gtk_builder_get_object(builder, "guardar_SD"));
    btn_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "btn_cargar_SD"));
    SalirDelPrograma = GTK_WIDGET(gtk_builder_get_object(builder, "SalirDelPrograma"));
    result = GTK_WIDGET(gtk_builder_get_object(builder, "result"));
    resultadoFinal = GTK_WIDGET(gtk_builder_get_object(builder, "resultadoFinal"));
    tabla_solucion = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_solucion"));
    tabla_input = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_input"));
   
    capacidad = GTK_WIDGET(gtk_builder_get_object(builder, "capacidad"));
   
    gtk_widget_set_tooltip_text(entry_cargar_SD, "Seleccionar un archivo");
    gtk_widget_set_tooltip_text(btn_calcular_SD, "Calcula la tabla con las probabilidades de A y B");
    gtk_widget_set_tooltip_text(folder, "Seleccionar un directorio");
    gtk_widget_set_tooltip_text(filenameEntry, "Nombre del archivo a guardar");
    gtk_widget_set_tooltip_text(guardar, "Guarda los datos en un archivo");
    gtk_widget_set_tooltip_text(btn_cargar_SD, "Carga el archivo seleccionado");
    gtk_widget_set_tooltip_text(SalirDelPrograma, "Cierra el programa");


    gtk_label_set_text(GTK_LABEL(result), "Utilice \"-\" para indicar cantidad infinito.");
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
    deleteTablesGrid(tabla_solucion);
    gtk_label_set_text(GTK_LABEL(resultadoFinal), "");
    gtk_label_set_text(GTK_LABEL(result), "");
	
    tabla = createFloatMatrix(cantidadObjetos, 3);
    tablaColores = createFloatMatrix(capacidadMochila+1, cantidadObjetos);
    tablaResultado = createFloatMatrix(capacidadMochila+1, cantidadObjetos);
    tablaColumnaAnterior = createFloatMatrix(capacidadMochila+1, 1);
    cantidadCombinaciones = createFloatMatrix(cantidadObjetos, 1);

    for(int i=1;i<=cantidadObjetos;i++){ 
        for(int j=2;j<5;j++){
            
                const gchar *cant_nodos;
                cant_nodos = gtk_entry_get_text(gtk_grid_get_child_at (gridt,j,i));
                int valor = atoi(cant_nodos);
                if(cant_nodos[0]== '-'){
                    tabla[i-1][j-2] = -1;
                }
                else if(valor==0){
                    gtk_label_set_text(GTK_LABEL(result), "Los valores de la tabla no pueden tener letras y tienen que ser mayor que 0.");
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
    knapsack();
    CrearTabla();
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}

void knapsack(){
    int valor = 0;
    for(int i = 0; i < cantidadObjetos; i++){
        for(int j = 0; j <= capacidadMochila;j++){
            if(i <= tabla[i][1]){
                for(int r = 0; r < tabla[i][2];r++){
                    valor += tabla[i][0];
                }
                tablaResultado[i][j]= valor;
            }
        }
    }

}

void CrearTabla(){
    grid2 = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid2, 1);
    gtk_grid_set_column_spacing (grid2, 1);

    for (int i = 0; i <= capacidadMochila+1; i++)
    {
        for(int j = 0; j <= cantidadObjetos; j++)
        {   

            if(i==0){
                if(j!=cantidadObjetos){
                char val[30];
                sprintf(val,"%s", strsAux[j]);
                label = gtk_label_new (val);
                gtk_widget_set_size_request(label, 470/(cantidadObjetos + 2), 470/(cantidadObjetos + 2));
                box = gtk_box_new(0, 0);
                gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                const GdkRGBA *color;
                    
                gdk_color_parse( "#467DD9", &color );
                gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                gtk_grid_attach(GTK_GRID(grid2), box, j+1, i, 1, 1);

                gtk_widget_show (label);
                gtk_widget_show (box); } 
            }
            else{
                if(j==0){
                    char val[30];
                    sprintf(val,"%d", i-1);

                    label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(cantidadObjetos + 2), 470/(cantidadObjetos + 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    gdk_color_parse( "#AFC6EE", &color );
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j, i, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);
                }
            
                else {
                    char v[100];
                    sprintf(v,"%d", tablaResultado[i-1][j-1]);
                 
                    label = gtk_label_new (v);
                    gtk_widget_set_size_request(label, 470/(cantidadObjetos + 2), 470/(cantidadObjetos+ 2));

                    box = gtk_box_new(0, 0);
                    gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
                    const GdkRGBA *color;
                    
                    if(tablaResultado[i-1][j-1]==0){ 
                    gdk_color_parse( "#40AD3B", &color );}
                    else{
                        gdk_color_parse( "#AFC6EE", &color );
                    }
                    gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
                    gtk_grid_attach(GTK_GRID(grid2), box, j, i, 1, 1);

                    gtk_widget_show (label);
                    gtk_widget_show (box);  
                }
      
            }
        }
    }

    gtk_container_add (GTK_CONTAINER (tabla_solucion), grid2);
    gtk_widget_show (grid2); 
}


int on_guardar_SD_clicked ()
{
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

void on_cantObj_changed(GtkWidget *widget){
    GtkComboBox *combo_box = widget;
    cantidadObjetos = gtk_combo_box_get_active (combo_box)+1;
}

int on_acept_clicked(){
    
    deleteTablesGrid(tabla_input);    
    gtk_label_set_text(GTK_LABEL(result), "");

    const gchar *pln;
    
    pln = gtk_entry_get_text(capacidad);
    capacidadMochila = atoi(pln);

    if(capacidadMochila<=0){
        gtk_label_set_text(GTK_LABEL(result), "La capacidad tiene que ser mayor que 0.");
        return 0;
    }

    gridt = gtk_grid_new ();
    gtk_grid_set_row_spacing (gridt, 5);
    gtk_grid_set_column_spacing (gridt, 5);
    char v[5];

    for (int i = 0; i < cantidadObjetos+1; i++)
    {
        
        for(int j = 0; j < 5; j++)
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


