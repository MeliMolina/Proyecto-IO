#include <gtk/gtk.h>

GtkBuilder      *builder_about; 
GtkWidget       *about_window;

GtkBuilder      *builder_Programa1; 
GtkWidget       *window_Programa1;

GtkWidget *btn_Programa1;
GtkWidget *btn_Programa2;
GtkWidget *btn_Programa3;
GtkWidget *btn_Programa4;
GtkWidget *btn_Programa5;
GtkWidget *btn_Salir;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Menu_Principal.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);


    btn_Programa1 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_1"));
    btn_Programa2 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_2"));
    btn_Programa3 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_3"));
    btn_Programa4 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_4"));
    btn_Programa5 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_5"));

    gtk_widget_set_tooltip_text(btn_Programa1, "Descripción del Programa 1");
    gtk_widget_set_tooltip_text(btn_Programa2, "Descripción del Programa 2");
    gtk_widget_set_tooltip_text(btn_Programa3, "Descripción del Programa 3");
    gtk_widget_set_tooltip_text(btn_Programa4, "Descripción del Programa 4");
    gtk_widget_set_tooltip_text(btn_Programa5, "Descripción del Programa 5");



   
  

    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}


void on_window_main_destroy()
{
    gtk_main_quit();
}

void on_Button_info_clicked()
{
    builder_about = gtk_builder_new();
    gtk_builder_add_from_file (builder_about, "glade/Menu_Principal.glade", NULL);
 
    about_window = GTK_WIDGET(gtk_builder_get_object(builder_about, "window_info"));
    gtk_builder_connect_signals(builder_about, NULL);

    g_object_unref(builder_about);
 
    gtk_widget_show(about_window); 
    gtk_main();
}

void on_Button_cerrar_clicked(){

	gtk_widget_destroy(about_window);

}

void on_Button_Programa1_clicked(){
    system("./Pending &");


}

void on_Button_Programa2_clicked(){
    system("./Pending &");
	

}

void on_Button_Programa3_clicked(){

	system("./Pending &");

}

void on_Button_Programa4_clicked(){
    system("./Pending &");
	

}


void on_Button_Programa5_clicked(){

	system("./Pending &");

}


void on_Button_Salir_clicked()
{
    gtk_main_quit();
}
