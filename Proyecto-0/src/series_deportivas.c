/************************************************************************
 
 Instituto Tecnológico de Costa Rica
 Investigación de Operaciones
 II Semestre 2017

 Proyecto 0.Menú de Programas de Programación Dinámica

 Profesor: Dr.Francisco J.Torres Rojas

 Melissa Molina Corrales
 Edwin Cen Xu

 ************************************************************************/

#include <glib.h>
#include <gtk/gtk.h>
#include "lib/matrix.c"
 
GtkBuilder  *builder; 
GtkWidget  *window_SD;
GtkWidget *cantJuegos;
GtkWidget *g_Ph;
GtkWidget *g_Pr;
GtkWidget *Acept;

GtkWidget *juego1;
GtkWidget *juego2;
GtkWidget *juego3;
GtkWidget *juego4;
GtkWidget *juego5;
GtkWidget *juego6;
GtkWidget *juego7;
GtkWidget *juego8;
GtkWidget *juego9;
GtkWidget *juego10;
GtkWidget *juego11;

GtkWidget *probabilidades1;
GtkWidget *probabilidades2;
GtkWidget *result;
GtkWidget *entry_cargar_SD;
GtkWidget *btn_calcular_SD;
GtkWidget *calcProbabilidad;
GtkWidget *folder;
GtkWidget *filenameEntry;
GtkWidget *guardar;


GtkWidget *SalirDelPrograma;

GtkWidget *datos_SD;
GtkWidget *tabla_sol_SD;
GtkWidget *tabla_nuevo_SD;
GtkWidget *gridt;
GtkWidget * grid;
GtkWidget * grid2;
GtkWidget * gridr;

int CantidadDeJuegos = 0;
int CantidadDeJuegos2 = 0;
int juegosganar = 0;
float ph = 0;
float pr = 0;
float qh = 0;
float qr = 0;

float ** tabla;
float resp;


int lugar_juego[11];

float mat[10][10];

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Series_Deportivas.glade", NULL);
 
    window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));
    

    gtk_builder_connect_signals(builder, NULL);   
    g_Ph = GTK_WIDGET(gtk_builder_get_object(builder, "Ph"));
    g_Pr = GTK_WIDGET(gtk_builder_get_object(builder, "Pr"));
    probabilidades1 = GTK_WIDGET(gtk_builder_get_object(builder, "probabilidades1"));
    probabilidades2 = GTK_WIDGET(gtk_builder_get_object(builder, "probabilidades2"));
    entry_cargar_SD = GTK_WIDGET(gtk_builder_get_object(builder, "entry_cargar_SD"));
    result = GTK_WIDGET(gtk_builder_get_object(builder, "result"));
    folder = GTK_WIDGET(gtk_builder_get_object(builder, "folder"));
    filenameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "filename"));
    cantJuegos = GTK_WIDGET(gtk_builder_get_object(builder, "cantJuegos"));

    juego1 = GTK_WIDGET(gtk_builder_get_object(builder, "juego1"));
    juego2 = GTK_WIDGET(gtk_builder_get_object(builder, "juego2"));
    juego3 = GTK_WIDGET(gtk_builder_get_object(builder, "juego3"));
    juego4 = GTK_WIDGET(gtk_builder_get_object(builder, "juego4"));
    juego5 = GTK_WIDGET(gtk_builder_get_object(builder, "juego5"));
    juego6 = GTK_WIDGET(gtk_builder_get_object(builder, "juego6"));
    juego7 = GTK_WIDGET(gtk_builder_get_object(builder, "juego7"));
    juego8 = GTK_WIDGET(gtk_builder_get_object(builder, "juego8"));
    juego9 = GTK_WIDGET(gtk_builder_get_object(builder, "juego9"));
    juego10 = GTK_WIDGET(gtk_builder_get_object(builder, "juego10"));
    juego11 = GTK_WIDGET(gtk_builder_get_object(builder, "juego11"));

    datos_SD = GTK_WIDGET(gtk_builder_get_object(builder, "datos_SD"));
    tabla_sol_SD = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_sol_SD"));

    tabla_nuevo_SD = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_nuevo_SD"));


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

    g_object_unref(builder);
 
    
    //gtk_builder_connect_signals(builder, NULL); 

   
    gtk_widget_show(window_SD);
                              
    gtk_main();
    return 0;
} 
 

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}




void drawAnswer(){
    int i, j;


    for (i = -1; i < (CantidadDeJuegos); i++)
    {
        for(j = -1; j < (CantidadDeJuegos); j++)
        {
            if (i==-1){
                if(j==-1){
                    GtkWidget *label = gtk_label_new ("");
                    gtk_widget_set_size_request(label, 470/(CantidadDeJuegos+ 2), 470/(CantidadDeJuegos+ 2));

                    GdkColor lcolor;
                    gdk_color_parse ("black", &lcolor);
                    gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

                    gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
                    gtk_widget_show (label);    
                }
                else{
                    char val[30];
                    sprintf(val,"%d", j);

                    GtkWidget *label = gtk_label_new (val);
                    gtk_widget_set_size_request(label, 470/(CantidadDeJuegos + 2), 470/(CantidadDeJuegos + 2));

                    GdkColor lcolor;
                    gdk_color_parse ("black", &lcolor);
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
                    gtk_widget_set_size_request(label, 470/(CantidadDeJuegos + 2), 470/(CantidadDeJuegos + 2));

                    GdkColor lcolor;
                    gdk_color_parse ("black", &lcolor);
                    gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

                    gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
                    gtk_widget_show (label);    
                }
                else{
                    if((j==0)&&(i==0)){
                        GtkWidget *label = gtk_label_new ("");
                        gtk_widget_set_size_request(label, 470/(CantidadDeJuegos + 2), 470/(CantidadDeJuegos + 2));

                        GdkColor lcolor;
                        gdk_color_parse ("black", &lcolor);
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
                        gtk_widget_set_size_request(label, 470/(CantidadDeJuegos + 2), 470/(CantidadDeJuegos + 2));

                        GdkColor lcolor;
                        gdk_color_parse ("black", &lcolor);
                        gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &lcolor);

                        gtk_grid_attach(GTK_GRID(grid2), label, j+1, i+1, 1, 1);
                        gtk_widget_show (label);    
                    }
                }
            }
        }
    }
}

void on_btn_calcular_SD_clicked()
{   

	tabla = createFloatMatrix(CantidadDeJuegos, CantidadDeJuegos);


    for (int i=0;i<CantidadDeJuegos;i++){
        for( int j = 0;j<CantidadDeJuegos;j++){
            if(j==0){
                tabla[i][j]=0;
                continue;
            }
            if(i==0){
                tabla[i][j]=1;
                continue;
            }
            if(lugar_juego[CantidadDeJuegos2-1-(i+j-2)] == 1){
                tabla[i][j]=ph*tabla[i-1][j]+qr*tabla[i][j-1];}

            if(lugar_juego[CantidadDeJuegos2-1-(i+j-2)] == 2){
                tabla[i][j]=pr*tabla[i-1][j]+qh*tabla[i][j-1];
            }
            
           //printf("%f\n",tabla[i][j]);
        }

    }

    printFloatMatrix(tabla, CantidadDeJuegos, CantidadDeJuegos);

    /*for (int i=0;i<=CantidadDeJuegos2;i++){
       printf("%d\n",lugar_juego[i]);

    }*/
    //printf("%f\n",mat[CantidadDeJuegos-1][CantidadDeJuegos-1]);

    char val[120];
    strcpy(val,"La probabilidad de que A gane la serie es de: ");
    char v[30];
    sprintf(v,"%f",tabla[CantidadDeJuegos-1][CantidadDeJuegos-1]);
    strcat(val,v);

   drawAnswer();
 
   
    gtk_label_set_text(GTK_LABEL(result), val);
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
void writeFile(char* filename)
{

    FILE *file;
    file = fopen(filename, "w");
    
  

    fprintf(file, "%i\n", CantidadDeJuegos);
    fprintf(file, "%i\n", CantidadDeJuegos2);
    fprintf(file, "%f\n", ph);
    fprintf(file, "%f\n", pr);
    fprintf(file, "%f\n", qh);
    fprintf(file, "%f\n", qr);
    
    for (int i = 0 ;i < CantidadDeJuegos2;i++){
        fprintf(file, "%i\n", lugar_juego[i]);
    }

    fclose(file);
}

void on_btn_cargar_SD_clicked(){
    const gchar *filename;
    filename = gtk_file_chooser_get_filename (entry_cargar_SD);
    readFile(filename);
}


void readFile(char* filename)
{    

    FILE *file;
    file = fopen(filename, "r");
    
    fscanf(file, "%i", &CantidadDeJuegos);
    fscanf(file, "%i", &CantidadDeJuegos2);
    fscanf(file, "%f", &ph);
    fscanf(file, "%f", &pr);
    fscanf(file, "%f", &qh);
    fscanf(file, "%f", &qr);
    
    

    int i = 0;

    while (i < CantidadDeJuegos2)
    {
        fscanf(file, "%i", &lugar_juego[i]);
        i++;
    }

    fclose(file);

    
    if(CantidadDeJuegos2==3){
        gtk_combo_box_set_active(cantJuegos,0);
    }
    if(CantidadDeJuegos2==5){
        gtk_combo_box_set_active(cantJuegos,1);
    }
    if(CantidadDeJuegos2==7){
        gtk_combo_box_set_active(cantJuegos,2);
    }
    if(CantidadDeJuegos2==9){
        gtk_combo_box_set_active(cantJuegos,3);
    }
    if(CantidadDeJuegos2==11){
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
    snprintf(array, sizeof(array), "%f", ph);
    gtk_entry_set_text(GTK_ENTRY(g_Ph),array);

    snprintf(array, sizeof(array), "%f", pr);
    gtk_entry_set_text(GTK_ENTRY(g_Pr),array);



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

void on_Acept_clicked(){

    const gchar *phS;
    phS = gtk_entry_get_text(GTK_ENTRY(g_Ph));
    ph = stof(phS);
    
    const gchar *prS;
    prS = gtk_entry_get_text(GTK_ENTRY(g_Pr));
    pr = stof(prS);

    qh = 1 - pr;
    qr = 1 - ph;

    
   

}





void on_Acept2_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept3_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept4_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept5_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept6_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept7_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept8_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept9_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept10_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}
void on_Acept11_clicked(GtkWidget *widget,GtkWidget *widget2){
    gtk_widget_set_sensitive (widget2, FALSE);
}



void on_juego2_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    if(CantidadDeJuegos2 >=3){
    gtk_widget_set_sensitive (widget2, TRUE);
        }

      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[1] = gtk_combo_box_get_active (combo_box);
}
void on_juego3_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=4){
    gtk_widget_set_sensitive (widget2, TRUE);}

      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[2] = gtk_combo_box_get_active (combo_box);
}
void on_juego4_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=5){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
    lugar_juego[3] = gtk_combo_box_get_active (combo_box);
}
void on_juego5_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=6){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[4] = gtk_combo_box_get_active (combo_box);
}
void on_juego6_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=7){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[5] = gtk_combo_box_get_active (combo_box);
}
void on_juego7_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=8){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[6] = gtk_combo_box_get_active (combo_box);
}
void on_juego8_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=9){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[7] = gtk_combo_box_get_active (combo_box);
}
void on_juego9_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
   if(CantidadDeJuegos2 >=10){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[8] = gtk_combo_box_get_active (combo_box);
}
void on_juego10_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos2 >=11){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
      lugar_juego[9] = gtk_combo_box_get_active (combo_box);
}

void on_juego11_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    
    lugar_juego[10] = gtk_combo_box_get_active (combo_box);
}

void on_juego1_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    gtk_widget_set_sensitive (widget2, TRUE);
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }
    /*gint pos = gtk_combo_box_get_active (combo_box);
    gint first = 0;
    gtk_widget_get_active(widget);*/
    /*if(pos != first){
        gtk_widget_set_sensitive (widget2, TRUE);
    }*/
      lugar_juego[0] = gtk_combo_box_get_active (combo_box);


}

void on_calcProbabilidad_clicked(){
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

    gtk_label_set_text(GTK_LABEL(probabilidades2), val);


}

void on_cantJuegos_changed (GtkWidget *widget)
{
  //gtk_widget_set_sensitive (widget2, TRUE);
    CantidadDeJuegos=3;
    GtkComboBox *combo_box = widget;
    switch (gtk_combo_box_get_active (combo_box)){
        case 0:
            CantidadDeJuegos=3;
            break;
        case 1:
            CantidadDeJuegos=4;
            break;
        case 2:
            CantidadDeJuegos=5;
            break;
        case 3:
            CantidadDeJuegos=6;
            break;
        case 4:
            CantidadDeJuegos=7;
            break;
    
    }
    switch (gtk_combo_box_get_active (combo_box)){
        case 0:
            CantidadDeJuegos2=3;
            break;
        case 1:
            CantidadDeJuegos2=5;
            break;
        case 2:
            CantidadDeJuegos2=7;
            break;
        case 3:
            CantidadDeJuegos2=9;
            break;
        case 4:
            CantidadDeJuegos2=11;
            break;
    
    }
    juegosganar = CantidadDeJuegos-1;
    printf("%d\n",CantidadDeJuegos );
}