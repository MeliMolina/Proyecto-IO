#include <gtk/gtk.h>
#include <stdio.h>;
#include <ctype.h>;
#define num_letras 27

GtkWidget *entry_Sdom_1;
GtkWidget *entry_Ddom_1;
GtkWidget *entry_Drec_1;
GtkWidget *entry_Sdom_2;
GtkWidget *entry_Ddom_2;
GtkWidget *entry_Drec_2;
GtkWidget *entry_Sdom_3;
GtkWidget *entry_Ddom_3;
GtkWidget *entry_Drec_3;
GtkWidget *entry_Sdom_4;
GtkWidget *entry_Ddom_4;
GtkWidget *entry_Drec_4;
GtkWidget *entry_Sdom_5;
GtkWidget *entry_Ddom_5;
GtkWidget *entry_Drec_5;
GtkWidget *file_ch_btn;
GtkWidget *entry_guardar;
GtkWidget *lbl_confirmacion;

GtkWidget       *window, *window_guardar;

int argumento;

char *letras_M[num_letras]= {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
char *letras_m[num_letras]= {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"};
char* nombreArchivo = "info_caract.txt";

void activarCampos(int num){
	if(num >= 1){
		gtk_editable_set_editable(entry_Sdom_1,TRUE);
		gtk_entry_set_text (entry_Sdom_1, "A");
		gtk_editable_set_editable(entry_Ddom_1,TRUE);
		//gtk_entry_set_text (entry_Ddom_1, "Pies Grandes");
		gtk_editable_set_editable(entry_Drec_1,TRUE);
		//gtk_entry_set_text (entry_Drec_1, "Pies Pequeños");
	}
	if(num >= 2){
		gtk_editable_set_editable(entry_Sdom_2,TRUE);
		gtk_entry_set_text (entry_Sdom_2, "B");
		gtk_editable_set_editable(entry_Ddom_2,TRUE);
		//gtk_entry_set_text (entry_Ddom_2, "Manos Pequeñas");
		gtk_editable_set_editable(entry_Drec_2,TRUE);
		//gtk_entry_set_text (entry_Drec_2, "Manos grandes");
	}
	if(num >= 3){
		gtk_editable_set_editable(entry_Sdom_3,TRUE);
		gtk_entry_set_text (entry_Sdom_3, "C");
		gtk_editable_set_editable(entry_Ddom_3,TRUE);
		//gtk_entry_set_text (entry_Ddom_3, "Pelo Grueso");
		gtk_editable_set_editable(entry_Drec_3,TRUE);
		//gtk_entry_set_text (entry_Drec_3, "Pelo fino");
	}
	if(num >= 4){
		gtk_editable_set_editable(entry_Sdom_4,TRUE);
		gtk_entry_set_text (entry_Sdom_4, "D");
		gtk_editable_set_editable(entry_Ddom_4,TRUE);
		//gtk_entry_set_text (entry_Ddom_4, "ojos cafes");
		gtk_editable_set_editable(entry_Drec_4,TRUE);
		//gtk_entry_set_text (entry_Drec_4, "ojos celestes");
	}
	if(num >= 5){
		gtk_editable_set_editable(entry_Sdom_5,TRUE);
		gtk_entry_set_text (entry_Sdom_5, "E");
		gtk_editable_set_editable(entry_Ddom_5,TRUE);
		//gtk_entry_set_text (entry_Ddom_5, "peludo");
		gtk_editable_set_editable(entry_Drec_5,TRUE);
		//gtk_entry_set_text (entry_Drec_5, "lampiño");
	}
	
}

int verificar_minuscula(char* letra)
{
	int resultado = 0;
	for (int i = 0; i < num_letras; ++i)
	{
		if(strcmp(letras_m[i], letra) == 0){
			i = num_letras;
			resultado = 1;
		}
	}
	return resultado;
}

int verificar_mayuscula(char* letra)
{
	int resultado = 0;
	for (int i = 0; i < num_letras; ++i)
	{
		if(strcmp(letras_M[i], letra) == 0){
			i = num_letras;
			resultado = 1;
		}
	}
	return resultado;
}

int verificar_simbolo(char* letra){
	int resultado = 0;
	if(verificar_mayuscula(letra) == 0 && verificar_minuscula(letra) == 0){
		GtkWidget *dialog;

        dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"No se permiten símbolos");
        gtk_window_set_title(GTK_WINDOW(dialog),"Entrada inválida");
        gtk_dialog_run(GTK_DIALOG(dialog));

        gtk_widget_destroy(dialog);

        resultado = 1;
	}

	return resultado;
}

char* cambiar_a_mayuscula(char* letra)
{
	char* c;
	for (int i = 0; i < num_letras; ++i)
	{
		if(strcmp(letras_m[i], letra) == 0){
			c = letras_M[i];
		}
	}
	return c;
}

char* cambiar_a_minuscula(char* letra)
{
	char* c;
	for (int i = 0; i < num_letras; ++i)
	{
		if(strcmp(letras_M[i], letra) == 0){
			c = letras_m[i];
		}
	}
	return c;
}

void guardar_info(char* letras[]){
	FILE *info = fopen(nombreArchivo, "w");
	//fprintf(info, "holis");
	if(argumento >= 1){
		fprintf(info, "%s\n", letras[0]);
		fprintf(info, "%s\n", cambiar_a_minuscula(letras[0]));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Ddom_1));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Drec_1));
	}
	if(argumento >= 2){	
		fprintf(info, "%s\n", letras[1]);
		fprintf(info, "%s\n", cambiar_a_minuscula(letras[1]));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Ddom_2));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Drec_2));
	}
	if(argumento >= 3){	
		fprintf(info, "%s\n", letras[2]);
		fprintf(info, "%s\n", cambiar_a_minuscula(letras[2]));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Ddom_3));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Drec_3));
	}
	if(argumento >= 4){	
		fprintf(info, "%s\n", letras[3]);
		fprintf(info, "%s\n", cambiar_a_minuscula(letras[3]));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Ddom_4));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Drec_4));
	}
	if(argumento >= 5){	
		fprintf(info, "%s\n", letras[4]);
		fprintf(info, "%s\n", cambiar_a_minuscula(letras[4]));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Ddom_5));
		fprintf(info, "%s\n", gtk_entry_get_text(entry_Drec_5));
	}
	nombreArchivo = "info_caract.txt";
	fclose(info);
}

void verificar_letras(char* letras[]){
	int seguir = 1;
	char* c;
	for (int i = 0; i < argumento; ++i)
	{
		if(verificar_simbolo(letras[i]) == 0){
			if(verificar_minuscula(letras[i]) == 1){
				letras[i] = cambiar_a_mayuscula(letras[i]);
			}

		}else{
			seguir = 0;
		}
	}

	if(seguir == 1)
		guardar_info(letras);
		//system("./radio_lists");
}

void guardar_letras(){
	char *letras[argumento];

	if(argumento >= 1){
		letras[0] = gtk_entry_get_text(entry_Sdom_1);
	}
	if(argumento >= 2){	
		letras[1] = gtk_entry_get_text(entry_Sdom_2);
	}
	if(argumento >= 3){	
		letras[2] = gtk_entry_get_text(entry_Sdom_3);
	}
	if(argumento >= 4){	
		letras[3] = gtk_entry_get_text(entry_Sdom_4);
	}
	if(argumento >= 5){	
		letras[4] = gtk_entry_get_text(entry_Sdom_5);
	}

	
	verificar_letras(letras);
}

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/characteristics.glade", NULL);
	
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_characteristics"));
    gtk_builder_connect_signals(builder, NULL);
	
    entry_Sdom_1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Sdom_1"));
    entry_Ddom_1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Ddom_1"));
    entry_Drec_1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Drec_1"));
    entry_Sdom_2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Sdom_2"));
    entry_Ddom_2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Ddom_2"));
    entry_Drec_2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Drec_2"));
    entry_Sdom_3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Sdom_3"));
    entry_Ddom_3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Ddom_3"));
    entry_Drec_3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Drec_3"));
    entry_Sdom_4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Sdom_4"));
    entry_Ddom_4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Ddom_4"));
    entry_Drec_4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Drec_4"));
    entry_Sdom_5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Sdom_5"));
    entry_Ddom_5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Ddom_5"));
    entry_Drec_5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_Drec_5"));
    
    file_ch_btn = GTK_WIDGET(gtk_builder_get_object(builder, "file_ch_btn"));

    window_guardar = GTK_WIDGET(gtk_builder_get_object(builder, "window_guardar"));
    entry_guardar = GTK_WIDGET(gtk_builder_get_object(builder, "entry_guardar"));
    lbl_confirmacion = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_confirmacion"));
    g_object_unref(builder);    
	
	//gtk_editable_set_editable(entry_Sdom_1,FALSE);
	
	//int n = *argv[1] - 48; //paso la cantidad de caracteristicas por parametro
	argumento = *argv[1] - 48;
	activarCampos(argumento);
    gtk_widget_show(window);                
    gtk_main();
	
	
    return 0;
} 


void on_btn_generar_clicked()
{
	guardar_letras();
	system("./radio_lists");
}


void limpiarEspacios(){
	if(argumento >= 1){
		gtk_entry_set_text(entry_Sdom_1,"");
		gtk_entry_set_text(entry_Ddom_1,"");
		gtk_entry_set_text(entry_Drec_1,"");
	}
	if(argumento >= 2){	
		gtk_entry_set_text(entry_Sdom_2,"");
		gtk_entry_set_text(entry_Ddom_2,"");
		gtk_entry_set_text(entry_Drec_2,"");
	}
	if(argumento >= 3){	
		gtk_entry_set_text(entry_Sdom_3,"");
		gtk_entry_set_text(entry_Ddom_3,"");
		gtk_entry_set_text(entry_Drec_3,"");
	}
	if(argumento >= 4){	
		gtk_entry_set_text(entry_Sdom_4,"");
		gtk_entry_set_text(entry_Ddom_4,"");
		gtk_entry_set_text(entry_Drec_4,"");
	}
	if(argumento >= 5){	
		gtk_entry_set_text(entry_Sdom_5,"");
		gtk_entry_set_text(entry_Ddom_5,"");
		gtk_entry_set_text(entry_Drec_5,"");
	}
}

void desactivarCampos(int num){
	if(num >= 1){
		gtk_editable_set_editable(entry_Sdom_1,FALSE);
		gtk_editable_set_editable(entry_Ddom_1,FALSE);
		gtk_editable_set_editable(entry_Drec_1,FALSE);
	}
	if(num >= 2){
		gtk_editable_set_editable(entry_Sdom_2,FALSE);
		gtk_editable_set_editable(entry_Ddom_2,FALSE);
		gtk_editable_set_editable(entry_Drec_2,FALSE);
	}
	if(num >= 3){
		gtk_editable_set_editable(entry_Sdom_3,FALSE);
		gtk_editable_set_editable(entry_Ddom_3,FALSE);
		gtk_editable_set_editable(entry_Drec_3,FALSE);
	}
	if(num >= 4){
		gtk_editable_set_editable(entry_Sdom_4,FALSE);
		gtk_editable_set_editable(entry_Ddom_4,FALSE);
		gtk_editable_set_editable(entry_Drec_4,FALSE);
	}
	if(num >= 5){
		gtk_editable_set_editable(entry_Sdom_5,FALSE);
		gtk_editable_set_editable(entry_Ddom_5,FALSE);
		gtk_editable_set_editable(entry_Drec_5,FALSE);
	}
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

void llenarDesdeArchivo(char* nombreArchivo){
	argumento = 0;
	FILE *fp;

    fp = fopen ( nombreArchivo, "r" );
    char sDom[5];
    char sRec[5];
    char dDom[50];
    char dRec[50];
    char *ret;

    fp = fopen(nombreArchivo, "r");
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        
        strip(dDom);
        strip(dRec);
        
        gtk_entry_set_text(entry_Sdom_1,sDom);
		gtk_entry_set_text(entry_Ddom_1,dDom);
		gtk_entry_set_text(entry_Drec_1,dRec);
		argumento++;

    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        
        strip(dDom);
        strip(dRec);
        
        gtk_entry_set_text(entry_Sdom_2,sDom);
		gtk_entry_set_text(entry_Ddom_2,dDom);
		gtk_entry_set_text(entry_Drec_2,dRec);
		argumento++;

    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        
        strip(dDom);
        strip(dRec);
        
        gtk_entry_set_text(entry_Sdom_3,sDom);
		gtk_entry_set_text(entry_Ddom_3,dDom);
		gtk_entry_set_text(entry_Drec_3,dRec);
		argumento++;

    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        
        strip(dDom);
        strip(dRec);
        
        gtk_entry_set_text(entry_Sdom_4,sDom);
		gtk_entry_set_text(entry_Ddom_4,dDom);
		gtk_entry_set_text(entry_Drec_4,dRec);
		argumento++;

    }
    if (fgets(sDom, sizeof(sDom), fp)){ 
        fgets(sRec, sizeof(sRec), fp); 
        fgets(dDom, sizeof(dDom), fp); 
        fgets(dRec, sizeof(dRec), fp);
        
        strip(dDom);
        strip(dRec);
        
        gtk_entry_set_text(entry_Sdom_5,sDom);
		gtk_entry_set_text(entry_Ddom_5,dDom);
		gtk_entry_set_text(entry_Drec_5,dRec);
		argumento++;

    }

    fclose(fp);
}

void habilitarCampos(){
	//fprintf(info, "holis");
	if(argumento >= 1){
		gtk_editable_set_editable(entry_Sdom_1,TRUE);
		gtk_editable_set_editable(entry_Ddom_1,TRUE);
		gtk_editable_set_editable(entry_Drec_1,TRUE);
	}
	if(argumento >= 2){
		gtk_editable_set_editable(entry_Sdom_2,TRUE);
		gtk_editable_set_editable(entry_Ddom_2,TRUE);
		gtk_editable_set_editable(entry_Drec_2,TRUE);
	}
	if(argumento >= 3){
		gtk_editable_set_editable(entry_Sdom_3,TRUE);
		gtk_editable_set_editable(entry_Ddom_3,TRUE);
		gtk_editable_set_editable(entry_Drec_3,TRUE);
	}
	if(argumento >= 4){
		gtk_editable_set_editable(entry_Sdom_4,TRUE);
		gtk_editable_set_editable(entry_Ddom_4,TRUE);
		gtk_editable_set_editable(entry_Drec_4,TRUE);
	}
	if(argumento >= 5){
		gtk_editable_set_editable(entry_Sdom_5,TRUE);
		gtk_editable_set_editable(entry_Ddom_5,TRUE);
		gtk_editable_set_editable(entry_Drec_5,TRUE);
	}
}

void on_btn_cargar_clicked(){
	const gchar *filename;
    filename = gtk_file_chooser_get_filename (file_ch_btn); //gtk_entry_get_text(GTK_ENTRY(entry_cargar_PM));
	if(filename == NULL){
		GtkWidget *dialog;

        dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Debe elegir un archivo para cargar");
        gtk_window_set_title(GTK_WINDOW(dialog),"Sin Archivo");
        gtk_dialog_run(GTK_DIALOG(dialog));

        gtk_widget_destroy(dialog);
	}else{
		limpiarEspacios();
		desactivarCampos(argumento);
		llenarDesdeArchivo(filename);
		habilitarCampos();
	}
	
}


void on_btn_guardar_clicked(){
	gtk_widget_show(window_guardar);
}

void on_window_characteristics_destroy()
{
    gtk_main_quit();
}

void on_btn_confirmar_clicked()
{
	char* nombre = gtk_entry_get_text(entry_guardar);
	nombreArchivo = nombre;
	guardar_letras();
    gtk_label_set_text(GTK_LABEL(lbl_confirmacion), "Archivo Guardado");
}

void on_btn_cancelar_clicked()
{
    gtk_widget_destroy(window_guardar);
}


