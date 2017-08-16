#include <gtk/gtk.h>
 
GtkWidget *btn_pending;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/pending.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);
 
    g_object_unref(builder);    
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
} 
 
// called when window is closed
void on_window_pending_destroy()
{
    gtk_main_quit();
}

void on_btn_pending_clicked()
{
     gtk_main_quit();
}