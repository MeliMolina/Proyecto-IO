#include <gtk/gtk.h>
#include "string.h"

GtkWidget *entry_num;
GtkWidget       *window;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
 
    entry_num = GTK_WIDGET(gtk_builder_get_object(builder, "entry_num_caracteristicas"));
	
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}
void on_btn_siguiente_clicked(){
    int num = atoi(gtk_entry_get_text(entry_num));
	if(num >= 1 && num <= 5)
    {
        char* pagina = "./characteristics ";
        char* entry_text = gtk_entry_get_text(entry_num);
        char str[80];
        strcpy(str, pagina);
        strcat(str, entry_text);
        gtk_widget_destroy(window);
        system(str);
        //gtk_widget_destroy(window);
    }else{
        GtkWidget *dialog;

        dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Debe ser un número entero del 1 al 5");
        gtk_window_set_title(GTK_WINDOW(dialog),"Entrada inválida");
        gtk_dialog_run(GTK_DIALOG(dialog));

        gtk_widget_destroy(dialog);
    }
    

}
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
