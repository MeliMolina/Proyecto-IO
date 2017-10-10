/************************************************************************
 
 Instituto Tecnológico de Costa Rica
 Investigación de Operaciones
 II Semestre 2017

 Proyecto 0.Menú de Programas de Programación Dinámica

 Profesor: Dr.Francisco J.Torres Rojas

 Melissa Molina Corrales
 Edwin Cen Xu

 ************************************************************************/

#include <gtk/gtk.h>

 


GtkBuilder      *builder_about; 
GtkWidget       *about_window;

GtkBuilder      *builder_Programa1; 
GtkWidget       *window_Programa1;

GtkWidget *Programa1;
GtkWidget *Programa2;
GtkWidget *Programa3;
GtkWidget *Programa4;
GtkWidget *Programa5;
GtkWidget *Programa6;

GtkWidget *btn_Salir;
GtkWidget *btn_About;

GtkWidget *button_1;
GtkWidget *button_2;
GtkWidget *button_3;
GtkWidget *button_4;
GtkWidget *button_5;
GtkWidget *button_6;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Menu_Principal.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);


    Programa1 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_1"));
    Programa2 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_2"));
    Programa3 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_3"));
    Programa4 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_4"));
    Programa5 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_5"));
    Programa6 = GTK_WIDGET(gtk_builder_get_object(builder, "control_fijo_6"));


    button_1 = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Programa1"));
    button_2 = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Programa2"));
    button_3 = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Programa3"));
    button_4 = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Programa4"));
    button_5 = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Programa5"));
    button_6 = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Programa6"));

    btn_Salir = GTK_WIDGET(gtk_builder_get_object(builder, "Button_Salir"));
    btn_About = GTK_WIDGET(gtk_builder_get_object(builder, "Button_info"));

    gtk_widget_set_tooltip_text(Programa1, "Dado el número de juegos de una serie, la probabilidad de ganar en casa y la probabilidad de ganar como visita del equipo A, el algoritmo calcula la probabilidad de que el equipo A gane la serie contra el equipo B.");
    gtk_widget_set_tooltip_text(Programa2, "Conocido como Algoritmo de Floyd, el cual determina determina la ruta más corta entre dos nodos cualquiera de la red.");
    gtk_widget_set_tooltip_text(Programa3, "Determina un plan de reemplazos óptimo para un equipo en un determinado tiempo a partir del costo incicial del equipo, el plazo del proyecto,la vida útil del equipo, basándose en el precio de reventa y costo del mantenimiento para cada unidad de tiempo de uso del equipo.");
    gtk_widget_set_tooltip_text(Programa4, "Conocido como Knapsack problem, el cual busca la mejor solución entre un conjunto finito de posibles soluciones a un problema. Modela una situación en la cual hay que llenar una mochila, incapaz de soportar más de un peso determinado, cada objeto a colocar en la mochila tiene un peso y valor específicos,los objetos colocados en la mochila deben maximizar el valor total sin exceder el peso máximo.");
    gtk_widget_set_tooltip_text(Programa5, "Este algoritmo indicará como hacer el árbol binario de búsqueda de costo promedio mı́nimo, a partir de una serie de llaves con un respectivo peso.");
    gtk_widget_set_tooltip_text(Programa6, "Este algoritmo indicará de que manera multiplicar una cadena de matrices mostrando una hilera con paréntesis en los lugares apropiados, a partir de un número de matrices indicado por el usuario.");
    gtk_widget_set_tooltip_text(button_1, "Dado el número de juegos de una serie, la probabilidad de ganar en casa y la probabilidad de ganar como visita del equipo A, calcula la probabilidad de que el equipo A gane la serie contra el equipo B");
    gtk_widget_set_tooltip_text(button_2, "Conocido como el algoritmo de Floyd, el cual determina determina la ruta más corta entre dos nodos cualquiera de la red.");
    gtk_widget_set_tooltip_text(button_3, "Determina un plan de reemplazos óptimo para un equipo en un determinado tiempo, a partir del costo incicial del equipo, el plazo del proyecto,la vida útil del equipo basándose en el precio de reventa y costo del mantenimiento para cada unidad de tiempo de uso del equipo.");
    gtk_widget_set_tooltip_text(button_4, "Conocido como Knapsack problem, el cual busca la mejor solución entre un conjunto finito de posibles soluciones a un problema. Modela una situación en la cual hay que llenar una mochila, incapaz de soportar más de un peso determinado, cada objeto a colocar en la mochila tiene un peso y valor específicos,los objetos colocados en la mochila deben maximizar el valor total sin exceder el peso máximo.");
    gtk_widget_set_tooltip_text(button_5, "Este algoritmo indicará como hacer el árbol binario de búsqueda de costo promedio mı́nimo, a partir de una serie de llaves con un respectivo peso.");
    gtk_widget_set_tooltip_text(button_6, "Este algoritmo indicará de que manera multiplicar una cadena de matrices mostrando una hilera con paréntesis en los lugares apropiados, a partir de un número de matrices indicado por el usuario.");

    gtk_widget_set_tooltip_text(btn_Salir, "Cierra el programa");
    gtk_widget_set_tooltip_text(btn_About, "Muestra información del programa y sus creadores");
   


  
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
    system("./Series_Deportivas &");


}

void on_Button_Programa2_clicked(){
    system("./Rutas_Optimas &");
	

}

void on_Button_Programa3_clicked(){
    system("./Reemplazo_Equipos &");

}

void on_Button_Programa4_clicked(){
    system("./Mochila &");
	

}


void on_Button_Programa5_clicked(){

	system("./Arbol &");

}

void on_Button_Programa6_clicked(){
    system("./Matrices &");
	

}


void on_Button_Salir_clicked()
{
    gtk_main_quit();
}
