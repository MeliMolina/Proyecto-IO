#include <gtk/gtk.h>
#include "biolo.h"
#include <stdlib.h>

GtkWidget *box_madre, *box_padre, *radio, *radio2, *radio3, *viewport, *window_cruce, *tabla_cruce, *grid, *grid2;
GtkBuilder      *builder; 
GtkWidget       *window;
GtkWidget       *lista_probabilidades, *tabla_probabilidades;
char *padre, *madre;
char* colores[200];
#include "colores.h"

char* desc_colores[200];
char* colores_des[200];
int dif_des[200];
int cant_dif_des = 0;
int cant_colores = 0;
int cant_desc_colores = 0;


int estaEnLista(char* c){
    int resultado = 0;
    for (int i = 0; i < cant_desc_colores; ++i)
    {   
        //printf("VAMOS A COMPARAR %s Y %s\n", desc_colores[i], c);
        if(strcmp(desc_colores[i],c) == 0){
            resultado = 1;
            dif_des[i]++;
        }
    }
    //printf("EL RESULTADO EEEEESSSS %d\n", resultado);
    return resultado;
}


void cargarDifDescen(int GoF){
    int r;
    char* caract;
    char* color;
    cant_desc_colores = 0;
    cant_colores = 0;
    for (int i = 0; i < cantidadescendientes; ++i)
    {   
        if(GoF == 0){
            caract = ColaDescendientes[i].info; //genotipo
        }else{
            caract = ColaDescendientes[i].descripcion;
        }
        if(estaEnLista(caract) == 0){
            //printf("ESTOY EN EL IF DE CARGARDIFDESCEN\n");
            desc_colores[cant_desc_colores] = caract;
            cant_desc_colores++;
            
            r = (int)(rand() % 200);
            printf("r = %d\n color = %s\n", r, colores[r]);

            color = colores[r];
            colores_des[cant_colores] = color;
            printf("r = %d\n color = %s\n color_des = ", r, colores[r], colores_des[cant_colores]);
            cant_colores++;

            dif_des[i] = 1;
            cant_dif_des++;
        }
    }
}

char* buscarColor(char* c){
    char* resultado;
    for (int i = 0; i < cant_desc_colores; ++i)
    {
        if(strcmp(desc_colores[i],c) == 0){
            resultado = colores_des[i];
            i = cant_desc_colores;
        }
    }
    return resultado;
}

asignar_valor_padre(GtkWidget* widget, gpointer data){
    padre = (char*)data;
}


asignar_valor_madre(GtkWidget* widget, gpointer data){
    madre = (char*)data;
}


void traer_caract_desde_archivo(){
    FILE *fp;

    fp = fopen ( "info_caract.txt", "r" );
    char sDom[5];
    char sRec[5];
    char dDom[50];
    char dRec[50];

    char* nombrearchivo = "info_caract.txt";
    char buffer[20];

    fp = fopen("info_caract.txt", "r");
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        insertarCaracteristica(sDom[0], sRec[0], dDom, dRec); 
    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        insertarCaracteristica(sDom[0], sRec[0], dDom, dRec); 
    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        insertarCaracteristica(sDom[0], sRec[0], dDom, dRec); 
    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        insertarCaracteristica(sDom[0], sRec[0], dDom, dRec); 
    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        insertarCaracteristica(sDom[0], sRec[0], dDom, dRec); 
    }

    fclose(fp);

    remove("info_caract.txt");
}


void agregar_radio_buttons(){
    //Primero padre
    radio = gtk_radio_button_new_with_label(NULL, ColaGenotipos[0].info);
    gtk_box_pack_start(GTK_BOX(box_padre), radio, 0,0,0);
    gtk_widget_show(radio);
    gtk_widget_set_tooltip_text(radio, ColaGenotipos[0].fenotipo);
    g_signal_connect(radio, "toggled", G_CALLBACK(asignar_valor_padre), (gpointer)ColaGenotipos[0].info);
    padre = ColaGenotipos[0].info;


    //Primero madre
    radio2 = gtk_radio_button_new_with_label(NULL, ColaGenotipos[0].info);
    gtk_box_pack_start(GTK_BOX(box_madre), radio2, 0,0,0);
    gtk_widget_show(radio2);
    gtk_widget_set_tooltip_text(radio2, ColaGenotipos[0].fenotipo);
    g_signal_connect(radio2, "toggled", G_CALLBACK(asignar_valor_madre), (gpointer)ColaGenotipos[0].info);
    madre = ColaGenotipos[0].info;


    for (int i = 1; i < contadorglobal; ++i)
    {
        radio3 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), ColaGenotipos[i].info);
        gtk_box_pack_start(GTK_BOX(box_padre), radio3, 0,0,0);
        gtk_widget_show(radio3);
        gtk_widget_set_tooltip_text(radio3, ColaGenotipos[i].fenotipo);
        g_signal_connect(radio3, "toggled", G_CALLBACK(asignar_valor_padre), ColaGenotipos[i].info);
    }

    for (int i = 1; i < contadorglobal; ++i)
    {
        radio3 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio2)), ColaGenotipos[i].info);
        gtk_box_pack_start(GTK_BOX(box_madre), radio3, 0,0,0);
        gtk_widget_show(radio3);
        gtk_widget_set_tooltip_text(radio3, ColaGenotipos[i].fenotipo);
        g_signal_connect(radio3, "toggled", G_CALLBACK(asignar_valor_madre), ColaGenotipos[i].info);
    }
}

int main(int argc, char *argv[])
{
    
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/radio_lists.glade", NULL);
	
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_radio_lists"));
    gtk_builder_connect_signals(builder, NULL);
	
    box_madre = GTK_WIDGET(gtk_builder_get_object(builder, "box_madre"));
    box_padre = GTK_WIDGET(gtk_builder_get_object(builder, "box_padre"));


    window_cruce = GTK_WIDGET(gtk_builder_get_object(builder, "window_cruce"));
    tabla_cruce = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_cruce"));

    lista_probabilidades = GTK_WIDGET(gtk_builder_get_object(builder, "lista_probabilidades"));
    tabla_probabilidades = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_probabilidades"));

    traer_caract_desde_archivo();
    crearGenotipos();
    agregar_fenotipos();
    agregar_radio_buttons();

    g_object_unref(builder);    
    gtk_widget_show(window);                
    gtk_main();
	
    return 0;
} 


void on_btn_test_clicked(){
    
    /*printf("MADRE %s\n", madre);
    printf("PADRE %s\n", padre);*/
    /*char* pagina = "./cruce ";
    char str[80];
    strcpy(str, pagina);
    strcat(str, padre);
    strcat(str, " ");
    strcat(str, madre);
    system(str);*/

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/radio_lists.glade", NULL);

    
    window_cruce = GTK_WIDGET(gtk_builder_get_object(builder, "window_cruce"));
    tabla_cruce = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_cruce"));

    lista_probabilidades = GTK_WIDGET(gtk_builder_get_object(builder, "lista_probabilidades"));
    tabla_probabilidades = GTK_WIDGET(gtk_builder_get_object(builder, "tabla_probabilidades"));
    crearTabla();
    crearTabla2();

}



void crearTabla2()
{
    
    

    //printf("%d\n", strcmp("AAsBb","AABb"));

    grid = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid, 5);
    gtk_grid_set_column_spacing (grid, 5);
    
    int i, j;

    for (i = 0; i < cant_desc_colores; i++)
    {

        GtkWidget *labelf = gtk_label_new (ColaDescendientes[i].info);

        gtk_grid_attach(GTK_GRID(grid), labelf, 0, i, 1, 1);
        gtk_widget_show (labelf);
        
        //double num = 123412341234.123456789; 
        float num = (dif_des[i]*100)/cant_desc_colores;
        char output[50];

        snprintf(output, 50, "%f", num);

        //printf("PROBABILIDAD: %f\n", num);
        GtkWidget *label = gtk_label_new (output);
        GtkWidget *box = gtk_box_new(0, 0);
        gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  

        gtk_grid_attach(GTK_GRID(grid), box, 1, i, 1, 1);

        gtk_widget_show (label);
        gtk_widget_show (box);

        
    }


    gtk_container_add (GTK_CONTAINER (tabla_probabilidades), grid);
    gtk_widget_show (grid);
    gtk_widget_show(window_cruce);

    /*
    for (int t = 0; t < cant_desc_colores; ++t)
    {
        printf("Descendiente %s\n COLOR %s\n Número %d\n", desc_colores[t], colores_des[t], dif_des[t]);
    }*/
}

void crearTabla()
{
    

    int val;
    val = 2;
    
    crearFilas(padre);

    printf("CANTIDAD FILAS %d\n", cantidadfilas);
    crearColumnas(madre);
    //verlistaFila();
    //verlistaColumna();

    hacerCruce();
    verDescendientes();

    printf("LOS DIFERENTES HIJOS\n");
    cargarDifDescen(0);
    for (int i = 0; i < cant_desc_colores; ++i)
    {
        printf("Descendiente = %s\n", desc_colores[i]);
        printf("Color Descendiente = %s\n", colores_des[i]);
    }

    //printf("%d\n", strcmp("AAsBb","AABb"));

    grid = gtk_grid_new ();
    gtk_grid_set_row_spacing (grid, 5);
    gtk_grid_set_column_spacing (grid, 5);
    
    int i, j, cont;

    cont = 0;
    for (i = 1; i < cantidadfilas+1; i++)
    {
        GtkWidget *label = gtk_label_new (ColaFila[i - 1].info);

        gtk_grid_attach(GTK_GRID(grid), label, 0, i, 1, 1);
        gtk_widget_show (label);
        
        
        
        for(j = 1; j < cantidadcolumnas+1; j++)
        {       
            GtkWidget *labelf = gtk_label_new (ColaColumna[j-1].info);
        
            gtk_grid_attach(GTK_GRID(grid), labelf, j, 0, 1, 1);
            gtk_widget_show (labelf);

            GtkWidget *label = gtk_label_new (ColaDescendientes[cont].info);
            GtkWidget *box = gtk_box_new(0, 0);
            gtk_box_pack_start(GTK_BOX(box), label, 0,0,0);  
            const GdkRGBA *color;
            //gdk_color_parse( "#00F0FF", &color );
            printf("COLOR DEL DESCENDIENTE: %s\n", buscarColor(ColaDescendientes[cont].info));
            gdk_color_parse( buscarColor(ColaDescendientes[cont].info), &color );
            gtk_widget_set_tooltip_text(label, ColaDescendientes[cont].descripcion);
            gtk_widget_modify_bg(box, GTK_STATE_NORMAL, &color);
            gtk_grid_attach(GTK_GRID(grid), box, j, i, 1, 1);

            gtk_widget_show (label);
            gtk_widget_show (box);

            cont++;
        }
    }


    gtk_container_add (GTK_CONTAINER (tabla_cruce), grid);
    gtk_widget_show (grid);
    gtk_widget_show(window_cruce);

}

char* averiguar_fenotipo_letra(char letra){
    char* fenotipo;
    for (int i = 0; i < cantcaracteristicas; ++i)
    {
        if(ColaCaracteristicas[i].dominante == letra){
            fenotipo = ColaCaracteristicas[i].descripcionDom;
            i = cantcaracteristicas;
        }

        if(ColaCaracteristicas[i].recesivo == letra){
            fenotipo = ColaCaracteristicas[i].descripcionRec;
            i = cantcaracteristicas;
        }
    }
    return fenotipo;
}

void agregar_fenotipos(){
    char buffer[100];
    for (int i = 0; i < contadorglobal; ++i)
    {
        char fenotipo[100];
        char* genotipo = ColaGenotipos[i].info;
        int bandera = 0;
        for (int j = 0; genotipo[j] != '\0'; j+=2)
        {
            char* fenotipo_letra = averiguar_fenotipo_letra(genotipo[j]);
            if(bandera == 0){
                strcpy(fenotipo, fenotipo_letra);
                bandera = 1;
            }else{
                strcat(fenotipo, fenotipo_letra);
            }

        }
        strcpy(ColaGenotipos[i].fenotipo, fenotipo);
        strcpy(fenotipo, buffer);
    }
}


void on_window_radio_lists_destroy()
{
    gtk_main_quit();
}

void on_window_cruce_destroy(){
    gtk_main_quit();
}