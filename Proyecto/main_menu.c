#include <gtk/gtk.h>

GtkBuilder      *builder_about; 
GtkWidget       *about_window;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Menu_Principal.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

  

    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}

// called when window is closed
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



}

void on_Button_Programa2_clicked(){

	

}

void on_Button_Programa3_clicked(){

	

}

void on_Button_Programa4_clicked(){

	

}


void on_Button_Programa5_clicked(){

	

}


void on_Button_Salir_clicked()
{
    gtk_main_quit();
}
