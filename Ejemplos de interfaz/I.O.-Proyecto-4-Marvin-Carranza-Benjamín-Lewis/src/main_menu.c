#include <gtk/gtk.h>
 
GtkWidget *btn_RutasMasCortas;
GtkWidget *btn_ProblemaDeLaMochila;
GtkWidget *btn_ReemplazoDeEquipos;
GtkWidget *btn_ArbolesBinariosdeBusquedaOptimos;
GtkWidget *btn_SeriesDeportivas;
GtkWidget *btn_MultiplicacionDeMatrices;
GtkWidget *btn_SalirDelPrograma;

GtkBuilder      *builder_about; 
GtkWidget       *about_window;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/main_menu backup.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    btn_RutasMasCortas = GTK_WIDGET(gtk_builder_get_object(builder, "cont_fijo_rmc"));
    btn_ProblemaDeLaMochila = GTK_WIDGET(gtk_builder_get_object(builder, "cont_fijo_pm"));
    btn_ReemplazoDeEquipos = GTK_WIDGET(gtk_builder_get_object(builder, "cont_fijo_re"));
    btn_ArbolesBinariosdeBusquedaOptimos = GTK_WIDGET(gtk_builder_get_object(builder, "cont_fijo_abbo"));
    btn_SeriesDeportivas = GTK_WIDGET(gtk_builder_get_object(builder, "cont_fijo_sd"));
    btn_MultiplicacionDeMatrices = GTK_WIDGET(gtk_builder_get_object(builder, "cont_fijo_mm"));
    btn_SalirDelPrograma = GTK_WIDGET(gtk_builder_get_object(builder, "SalirDelPrograma"));

    gtk_widget_set_tooltip_text(btn_RutasMasCortas, "En informática, el algoritmo de Floyd-Warshall, descrito en 1959 por Bernard Roy, es un algoritmo de análisis sobre grafos para encontrar el camino mínimo en grafos dirigidos ponderados. El algoritmo encuentra el camino entre todos los pares de vértices en una única ejecución. El algoritmo de Floyd-Warshall es un ejemplo de programación dinámica.\nObtiene las rutas óptimas entre cualquier par de nodos en un grafo ponderado con distancias.");
    gtk_widget_set_tooltip_text(btn_ProblemaDeLaMochila, "Dado un set de objetos cada uno con un peso y valor y cantidad máxima, determina el número de cada objeto a ser incluido en el saco (capacidad finita) para que el peso total es menor o igual al limite del saco y el valor total es el más grande posible. (knapsack bounded, unbounded y 0/1)");
    gtk_widget_set_tooltip_text(btn_ReemplazoDeEquipos, "Algoritmo de Remplazo de Equipos");
    gtk_widget_set_tooltip_text(btn_ArbolesBinariosdeBusquedaOptimos, "Algoritmo de Árboles Binarios de Búsqueda");
    gtk_widget_set_tooltip_text(btn_SeriesDeportivas, "Dado el número de juegos de una serie, la probabilidad de ganar en casa y la probabilidad de ganar como visita del esquipo A, calcula la probabilidad de que el equipo A gane la serie contra el equipo B");
    gtk_widget_set_tooltip_text(btn_MultiplicacionDeMatrices, "Algoritmo de Multiplicación de Matrices");
    gtk_widget_set_tooltip_text(btn_SalirDelPrograma, "Cierra el Programa");
 
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

void on_about_clicked()
{

	builder_about = gtk_builder_new();
    gtk_builder_add_from_file (builder_about, "glade/main_menu backup.glade", NULL);
 
    about_window = GTK_WIDGET(gtk_builder_get_object(builder_about, "about_window"));
    gtk_builder_connect_signals(builder_about, NULL);

    g_object_unref(builder_about);
 
    gtk_widget_show(about_window); 
    gtk_main();
    
}

void on_cerrar_clicked()
{
 	gtk_widget_destroy(about_window);
}

void on_RutasMasCortas_clicked()
{
    int run = system("./shortestPaths &");
}

void on_ProblemaDeLaMochila_clicked()
{
    system("./knapsack &");
}

void on_ReemplazoDeEquipos_clicked()
{
    system("./reemplazoDeEquipos &");
}

void on_ArbolesBinariosdeBusquedaOptimos_clicked()
{
    system("./pending &");
}

void on_SeriesDeportivas_clicked()
{
    system("./seriesDeportivas &");
}

void on_MultiplicacionDeMatrices_clicked()
{
    system("./pending &");
}

void on_SalirDelPrograma_clicked()
{
    gtk_main_quit();
}
