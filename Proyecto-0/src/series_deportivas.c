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
 
GtkBuilder  *builder; 
GtkWidget  *window_SD;
GtkWidget *cantJuegos;
GtkWidget *Ph;
GtkWidget *Pr;
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

GtkWidget *entry_cargar_SD;
GtkWidget *btn_calcular_SD;
GtkWidget *calcProbabilidad;
GtkWidget *folder;
GtkWidget *filename;
GtkWidget *guardar_SD;

GtkWidget *SalirDelPrograma;

int CantidadDeJuegos = 0;


int main(int argc, char *argv[])
{
    
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Series_Deportivas.glade", NULL);
 
    window_SD = GTK_WIDGET(gtk_builder_get_object(builder, "window_SD"));
    

    gtk_builder_connect_signals(builder, NULL);   
    
    gtk_widget_show(window_SD);   
                              
    gtk_main();
    return 0;
} 
 

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_SD);
}

void on_btn_crear_SD_clicked()
{
    
}

void on_btn_calcular_SD_clicked()
{   
    
}

void on_btn_cargar_SD_clicked(){
 
}

void on_guardar_SD_clicked ()
{


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
    if(CantidadDeJuegos >=3){
    gtk_widget_set_sensitive (widget2, TRUE);
        }

      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego3_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=4){
    gtk_widget_set_sensitive (widget2, TRUE);}

      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego4_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=5){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego5_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=6){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego6_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=7){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego7_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=8){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego8_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=9){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego9_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
   if(CantidadDeJuegos >=10){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

}
void on_juego10_changed(GtkWidget *widget,GtkWidget *widget2){

    GtkComboBox *combo_box = widget;
    
    if(CantidadDeJuegos >=11){
    gtk_widget_set_sensitive (widget2, TRUE);}
      if (gtk_combo_box_get_active (combo_box) == 0) {
        gtk_widget_set_sensitive (widget2, FALSE);
      }

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



}

void on_cantJuegos_changed (GtkWidget *widget)
{
  //gtk_widget_set_sensitive (widget2, TRUE);
    CantidadDeJuegos=0;
    GtkComboBox *combo_box = widget;
    while(CantidadDeJuegos<=gtk_combo_box_get_active (combo_box)){
            CantidadDeJuegos++;
    }

    
    g_print ("You chose %d\n", CantidadDeJuegos);


}