#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


GtkWidget *cant_nodos_RMC;
GtkWidget       *window_RMC;
GtkBuilder      *builder; 
GtkWidget       *window_RMC_datos;

GtkWidget       *window_datosD0;
GtkWidget *label_datosD0;
GtkWidget *btn_aceptar_datosD0;
GtkWidget *entry_datosD0;

GtkWidget *tabla00;
GtkWidget *tabla01;
GtkWidget *tabla02;
GtkWidget *tabla03;
GtkWidget *tabla04;
GtkWidget *tabla05;
GtkWidget *tabla06;
GtkWidget *tabla07;
GtkWidget *tabla08;
GtkWidget *tabla09;
GtkWidget *tabla010;

GtkWidget *tabla10;
GtkWidget *tabla11;
GtkWidget *tabla12;
GtkWidget *tabla13;
GtkWidget *tabla14;
GtkWidget *tabla15;
GtkWidget *tabla16;
GtkWidget *tabla17;
GtkWidget *tabla18;
GtkWidget *tabla19;
GtkWidget *tabla110;

GtkWidget *tabla20;
GtkWidget *tabla21;
GtkWidget *tabla22;
GtkWidget *tabla23;
GtkWidget *tabla24;
GtkWidget *tabla25;
GtkWidget *tabla26;
GtkWidget *tabla27;
GtkWidget *tabla28;
GtkWidget *tabla29;
GtkWidget *tabla210;

GtkWidget *tabla30;
GtkWidget *tabla31;
GtkWidget *tabla32;
GtkWidget *tabla33;
GtkWidget *tabla34;
GtkWidget *tabla35;
GtkWidget *tabla36;
GtkWidget *tabla37;
GtkWidget *tabla38;
GtkWidget *tabla39;
GtkWidget *tabla310;

GtkWidget *tabla40;
GtkWidget *tabla41;
GtkWidget *tabla42;
GtkWidget *tabla43;
GtkWidget *tabla44;
GtkWidget *tabla45;
GtkWidget *tabla46;
GtkWidget *tabla47;
GtkWidget *tabla48;
GtkWidget *tabla49;
GtkWidget *tabla410;

GtkWidget *tabla50;
GtkWidget *tabla51;
GtkWidget *tabla52;
GtkWidget *tabla53;
GtkWidget *tabla54;
GtkWidget *tabla55;
GtkWidget *tabla56;
GtkWidget *tabla57;
GtkWidget *tabla58;
GtkWidget *tabla59;
GtkWidget *tabla510;

GtkWidget *tabla60;
GtkWidget *tabla61;
GtkWidget *tabla62;
GtkWidget *tabla63;
GtkWidget *tabla64;
GtkWidget *tabla65;
GtkWidget *tabla66;
GtkWidget *tabla67;
GtkWidget *tabla68;
GtkWidget *tabla69;
GtkWidget *tabla610;

GtkWidget *tabla70;
GtkWidget *tabla71;
GtkWidget *tabla72;
GtkWidget *tabla73;
GtkWidget *tabla74;
GtkWidget *tabla75;
GtkWidget *tabla76;
GtkWidget *tabla77;
GtkWidget *tabla78;
GtkWidget *tabla79;
GtkWidget *tabla710;

GtkWidget *tabla80;
GtkWidget *tabla81;
GtkWidget *tabla82;
GtkWidget *tabla83;
GtkWidget *tabla84;
GtkWidget *tabla85;
GtkWidget *tabla86;
GtkWidget *tabla87;
GtkWidget *tabla88;
GtkWidget *tabla89;
GtkWidget *tabla810;

GtkWidget *tabla90;
GtkWidget *tabla91;
GtkWidget *tabla92;
GtkWidget *tabla93;
GtkWidget *tabla94;
GtkWidget *tabla95;
GtkWidget *tabla96;
GtkWidget *tabla97;
GtkWidget *tabla98;
GtkWidget *tabla99;
GtkWidget *tabla910;

GtkWidget *tabla100;
GtkWidget *tabla101;
GtkWidget *tabla102;
GtkWidget *tabla103;
GtkWidget *tabla104;
GtkWidget *tabla105;
GtkWidget *tabla106;
GtkWidget *tabla107;
GtkWidget *tabla108;
GtkWidget *tabla109;
GtkWidget *tabla1010;

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/RMC_glade.glade", NULL);
 
    window_RMC_datos = GTK_WIDGET(gtk_builder_get_object(builder, "window_RMC_datos"));
    gtk_builder_connect_signals(builder, NULL);
	
	cant_nodos_RMC = GTK_WIDGET(gtk_builder_get_object(builder, "cant_nodos_RMC"));
	
	window_RMC = GTK_WIDGET(gtk_builder_get_object(builder, "window_RMC"));
	
	window_datosD0 = GTK_WIDGET(gtk_builder_get_object(builder, "window_datosD0"));
	label_datosD0 = GTK_WIDGET(gtk_builder_get_object(builder, "label_datosD0"));
	entry_datosD0 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_datosD0"));
	
	tabla00 = GTK_WIDGET(gtk_builder_get_object(builder, "label00"));
	tabla01 = GTK_WIDGET(gtk_builder_get_object(builder, "label01"));
	tabla02 = GTK_WIDGET(gtk_builder_get_object(builder, "label02"));
	tabla03 = GTK_WIDGET(gtk_builder_get_object(builder, "label03"));
	tabla04 = GTK_WIDGET(gtk_builder_get_object(builder, "label04"));
	tabla05 = GTK_WIDGET(gtk_builder_get_object(builder, "label05"));
	tabla06 = GTK_WIDGET(gtk_builder_get_object(builder, "label06"));
	tabla07 = GTK_WIDGET(gtk_builder_get_object(builder, "label07"));
	tabla08 = GTK_WIDGET(gtk_builder_get_object(builder, "label08"));
	tabla09 = GTK_WIDGET(gtk_builder_get_object(builder, "label09"));
	tabla010 = GTK_WIDGET(gtk_builder_get_object(builder, "label010"));
	
	tabla10 = GTK_WIDGET(gtk_builder_get_object(builder, "label10"));
	tabla11 = GTK_WIDGET(gtk_builder_get_object(builder, "label11"));
	tabla12 = GTK_WIDGET(gtk_builder_get_object(builder, "label12"));
	tabla13 = GTK_WIDGET(gtk_builder_get_object(builder, "label13"));
	tabla14 = GTK_WIDGET(gtk_builder_get_object(builder, "label14"));
	tabla15 = GTK_WIDGET(gtk_builder_get_object(builder, "label15"));
	tabla16 = GTK_WIDGET(gtk_builder_get_object(builder, "label16"));
	tabla17 = GTK_WIDGET(gtk_builder_get_object(builder, "label17"));
	tabla18 = GTK_WIDGET(gtk_builder_get_object(builder, "label18"));
	tabla19 = GTK_WIDGET(gtk_builder_get_object(builder, "label19"));
	tabla110 = GTK_WIDGET(gtk_builder_get_object(builder, "label110"));
	
	tabla20 = GTK_WIDGET(gtk_builder_get_object(builder, "label20"));
	tabla21 = GTK_WIDGET(gtk_builder_get_object(builder, "label21"));
	tabla22 = GTK_WIDGET(gtk_builder_get_object(builder, "label22"));
	tabla23 = GTK_WIDGET(gtk_builder_get_object(builder, "label23"));
	tabla24 = GTK_WIDGET(gtk_builder_get_object(builder, "label24"));
	tabla25 = GTK_WIDGET(gtk_builder_get_object(builder, "label25"));
	tabla26 = GTK_WIDGET(gtk_builder_get_object(builder, "label26"));
	tabla27 = GTK_WIDGET(gtk_builder_get_object(builder, "label27"));
	tabla28 = GTK_WIDGET(gtk_builder_get_object(builder, "label28"));
	tabla29 = GTK_WIDGET(gtk_builder_get_object(builder, "label29"));
	tabla210 = GTK_WIDGET(gtk_builder_get_object(builder, "label210"));
	
	tabla30 = GTK_WIDGET(gtk_builder_get_object(builder, "label30"));
	tabla31 = GTK_WIDGET(gtk_builder_get_object(builder, "label31"));
	tabla32 = GTK_WIDGET(gtk_builder_get_object(builder, "label32"));
	tabla33 = GTK_WIDGET(gtk_builder_get_object(builder, "label33"));
	tabla34 = GTK_WIDGET(gtk_builder_get_object(builder, "label34"));
	tabla35 = GTK_WIDGET(gtk_builder_get_object(builder, "label35"));
	tabla36 = GTK_WIDGET(gtk_builder_get_object(builder, "label36"));
	tabla37 = GTK_WIDGET(gtk_builder_get_object(builder, "label37"));
	tabla38 = GTK_WIDGET(gtk_builder_get_object(builder, "label38"));
	tabla39 = GTK_WIDGET(gtk_builder_get_object(builder, "label39"));
	tabla310 = GTK_WIDGET(gtk_builder_get_object(builder, "label310"));
	
	tabla40 = GTK_WIDGET(gtk_builder_get_object(builder, "label40"));
	tabla41 = GTK_WIDGET(gtk_builder_get_object(builder, "label41"));
	tabla42 = GTK_WIDGET(gtk_builder_get_object(builder, "label42"));
	tabla43 = GTK_WIDGET(gtk_builder_get_object(builder, "label43"));
	tabla44 = GTK_WIDGET(gtk_builder_get_object(builder, "label44"));
	tabla45 = GTK_WIDGET(gtk_builder_get_object(builder, "label45"));
	tabla46 = GTK_WIDGET(gtk_builder_get_object(builder, "label46"));
	tabla47 = GTK_WIDGET(gtk_builder_get_object(builder, "label47"));
	tabla48 = GTK_WIDGET(gtk_builder_get_object(builder, "label48"));
	tabla49 = GTK_WIDGET(gtk_builder_get_object(builder, "label49"));
	tabla410 = GTK_WIDGET(gtk_builder_get_object(builder, "label410"));
	
	tabla50 = GTK_WIDGET(gtk_builder_get_object(builder, "label50"));
	tabla51 = GTK_WIDGET(gtk_builder_get_object(builder, "label51"));
	tabla52 = GTK_WIDGET(gtk_builder_get_object(builder, "label52"));
	tabla53 = GTK_WIDGET(gtk_builder_get_object(builder, "label53"));
	tabla54 = GTK_WIDGET(gtk_builder_get_object(builder, "label54"));
	tabla55 = GTK_WIDGET(gtk_builder_get_object(builder, "label55"));
	tabla56 = GTK_WIDGET(gtk_builder_get_object(builder, "label56"));
	tabla57 = GTK_WIDGET(gtk_builder_get_object(builder, "label57"));
	tabla58 = GTK_WIDGET(gtk_builder_get_object(builder, "label58"));
	tabla59 = GTK_WIDGET(gtk_builder_get_object(builder, "label59"));
	tabla510 = GTK_WIDGET(gtk_builder_get_object(builder, "label510"));
	
	tabla60 = GTK_WIDGET(gtk_builder_get_object(builder, "label60"));
	tabla61 = GTK_WIDGET(gtk_builder_get_object(builder, "label61"));
	tabla62 = GTK_WIDGET(gtk_builder_get_object(builder, "label62"));
	tabla63 = GTK_WIDGET(gtk_builder_get_object(builder, "label63"));
	tabla64 = GTK_WIDGET(gtk_builder_get_object(builder, "label64"));
	tabla65 = GTK_WIDGET(gtk_builder_get_object(builder, "label65"));
	tabla66 = GTK_WIDGET(gtk_builder_get_object(builder, "label66"));
	tabla67 = GTK_WIDGET(gtk_builder_get_object(builder, "label67"));
	tabla68 = GTK_WIDGET(gtk_builder_get_object(builder, "label68"));
	tabla69 = GTK_WIDGET(gtk_builder_get_object(builder, "label69"));
	tabla610 = GTK_WIDGET(gtk_builder_get_object(builder, "label610"));
	
	tabla70 = GTK_WIDGET(gtk_builder_get_object(builder, "label70"));
	tabla71 = GTK_WIDGET(gtk_builder_get_object(builder, "label71"));
	tabla72 = GTK_WIDGET(gtk_builder_get_object(builder, "label72"));
	tabla73 = GTK_WIDGET(gtk_builder_get_object(builder, "label73"));
	tabla74 = GTK_WIDGET(gtk_builder_get_object(builder, "label74"));
	tabla75 = GTK_WIDGET(gtk_builder_get_object(builder, "label75"));
	tabla76 = GTK_WIDGET(gtk_builder_get_object(builder, "label76"));
	tabla77 = GTK_WIDGET(gtk_builder_get_object(builder, "label77"));
	tabla78 = GTK_WIDGET(gtk_builder_get_object(builder, "label78"));
	tabla79 = GTK_WIDGET(gtk_builder_get_object(builder, "label79"));
	tabla710 = GTK_WIDGET(gtk_builder_get_object(builder, "label710"));
	
	tabla80 = GTK_WIDGET(gtk_builder_get_object(builder, "label80"));
	tabla81 = GTK_WIDGET(gtk_builder_get_object(builder, "label81"));
	tabla82 = GTK_WIDGET(gtk_builder_get_object(builder, "label82"));
	tabla83 = GTK_WIDGET(gtk_builder_get_object(builder, "label83"));
	tabla84 = GTK_WIDGET(gtk_builder_get_object(builder, "label84"));
	tabla85 = GTK_WIDGET(gtk_builder_get_object(builder, "label85"));
	tabla86 = GTK_WIDGET(gtk_builder_get_object(builder, "label86"));
	tabla87 = GTK_WIDGET(gtk_builder_get_object(builder, "label87"));
	tabla88 = GTK_WIDGET(gtk_builder_get_object(builder, "label88"));
	tabla89 = GTK_WIDGET(gtk_builder_get_object(builder, "label89"));
	tabla810 = GTK_WIDGET(gtk_builder_get_object(builder, "label810"));
	
	tabla90 = GTK_WIDGET(gtk_builder_get_object(builder, "label90"));
	tabla91 = GTK_WIDGET(gtk_builder_get_object(builder, "label91"));
	tabla92 = GTK_WIDGET(gtk_builder_get_object(builder, "label92"));
	tabla93 = GTK_WIDGET(gtk_builder_get_object(builder, "label93"));
	tabla94 = GTK_WIDGET(gtk_builder_get_object(builder, "label94"));
	tabla95 = GTK_WIDGET(gtk_builder_get_object(builder, "label95"));
	tabla96 = GTK_WIDGET(gtk_builder_get_object(builder, "label96"));
	tabla97 = GTK_WIDGET(gtk_builder_get_object(builder, "label97"));
	tabla98 = GTK_WIDGET(gtk_builder_get_object(builder, "label98"));
	tabla99 = GTK_WIDGET(gtk_builder_get_object(builder, "label99"));
	tabla910 = GTK_WIDGET(gtk_builder_get_object(builder, "label910"));
	
	tabla100 = GTK_WIDGET(gtk_builder_get_object(builder, "label100"));
	tabla101 = GTK_WIDGET(gtk_builder_get_object(builder, "label101"));
	tabla102 = GTK_WIDGET(gtk_builder_get_object(builder, "label102"));
	tabla103 = GTK_WIDGET(gtk_builder_get_object(builder, "label103"));
	tabla104 = GTK_WIDGET(gtk_builder_get_object(builder, "label104"));
	tabla105 = GTK_WIDGET(gtk_builder_get_object(builder, "label105"));
	tabla106 = GTK_WIDGET(gtk_builder_get_object(builder, "label106"));
	tabla107 = GTK_WIDGET(gtk_builder_get_object(builder, "label107"));
	tabla108 = GTK_WIDGET(gtk_builder_get_object(builder, "label108"));
	tabla109 = GTK_WIDGET(gtk_builder_get_object(builder, "label109"));
	tabla1010 = GTK_WIDGET(gtk_builder_get_object(builder, "label1010"));
	
 
    g_object_unref(builder);    
 
    gtk_widget_show(window_RMC_datos);                
    gtk_main();
 
    return 0;
} 
 
// called when window is closed
void on_window_RMC_datos_destroy()
{
    gtk_widget_destroy(window_RMC_datos);
}

void on_window_RMC_destroy()
{
    gtk_widget_destroy(window_RMC);
}

void on_SalirDelPrograma_clicked()
{
    gtk_widget_destroy(window_RMC);
}

void on_btn_cancelar_RMC_datos_clicked()
{
     gtk_widget_destroy(window_RMC_datos);
}

void on_btn_aceptar_datosD0_clicked()
{
     gtk_widget_destroy(window_datosD0);
}

void on_btn_calcular_RMC_clicked()
{
   // ------------------------------
}   

void on_btn_aceptar_RMC_datos_clicked()
{	
	const gchar *cant_nodos;
	cant_nodos = gtk_entry_get_text(GTK_ENTRY(cant_nodos_RMC));
	int val = atoi(cant_nodos);

	/*for (int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			
			char pos[12];
			char aux[12];

			char vali[12];
			char valj[12];
			
			sprintf(vali,"%d", i);
			sprintf(valj,"%d", j);

		    strcpy(pos, "label");
		    strcpy(aux, vali);
		    strcat(pos, aux);
			
			strcpy(aux, valj);
			strcat(pos, aux);

			tabla00 = GTK_WIDGET(gtk_builder_get_object(builder, pos));
			gtk_label_set_text(GTK_LABEL(tabla00), cant_nodos);
		}
	}*/

	gtk_widget_destroy(window_RMC_datos);
	
	if(val>=2 && val<=10){
		if (val == 2){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			
					
			gtk_label_set_text(GTK_LABEL(label_datosD0), "Valor de 0,0?");
			gtk_widget_show(window_datosD0);
			system("pause");
			gchar *val00 = gtk_entry_get_text(GTK_ENTRY(entry_datosD0));
			
			gtk_label_set_text(GTK_LABEL(tabla11), val00);
			gtk_label_set_text(GTK_LABEL(tabla12), val00);
			gtk_label_set_text(GTK_LABEL(tabla21), val00);
			gtk_label_set_text(GTK_LABEL(tabla22), val00);
		}
		else if (val == 3){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
		}
		else if (val == 4){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
		}
		else if (val == 5){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla05), "E");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			gtk_label_set_text(GTK_LABEL(tabla50), "E");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla15), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla25), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla35), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
			gtk_label_set_text(GTK_LABEL(tabla45), "0");
			gtk_label_set_text(GTK_LABEL(tabla51), "0");
			gtk_label_set_text(GTK_LABEL(tabla52), "0");
			gtk_label_set_text(GTK_LABEL(tabla53), "0");
			gtk_label_set_text(GTK_LABEL(tabla54), "0");
			gtk_label_set_text(GTK_LABEL(tabla55), "0");
		}
		else if (val == 6){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla05), "E");
			gtk_label_set_text(GTK_LABEL(tabla06), "F");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			gtk_label_set_text(GTK_LABEL(tabla50), "E");
			gtk_label_set_text(GTK_LABEL(tabla60), "F");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla15), "0");
			gtk_label_set_text(GTK_LABEL(tabla16), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla25), "0");
			gtk_label_set_text(GTK_LABEL(tabla26), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla35), "0");
			gtk_label_set_text(GTK_LABEL(tabla36), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
			gtk_label_set_text(GTK_LABEL(tabla45), "0");
			gtk_label_set_text(GTK_LABEL(tabla46), "0");
			gtk_label_set_text(GTK_LABEL(tabla51), "0");
			gtk_label_set_text(GTK_LABEL(tabla52), "0");
			gtk_label_set_text(GTK_LABEL(tabla53), "0");
			gtk_label_set_text(GTK_LABEL(tabla54), "0");
			gtk_label_set_text(GTK_LABEL(tabla55), "0");
			gtk_label_set_text(GTK_LABEL(tabla56), "0");
			gtk_label_set_text(GTK_LABEL(tabla61), "0");
			gtk_label_set_text(GTK_LABEL(tabla62), "0");
			gtk_label_set_text(GTK_LABEL(tabla63), "0");
			gtk_label_set_text(GTK_LABEL(tabla64), "0");
			gtk_label_set_text(GTK_LABEL(tabla65), "0");
			gtk_label_set_text(GTK_LABEL(tabla66), "0");
		}
		else if (val == 7){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla05), "E");
			gtk_label_set_text(GTK_LABEL(tabla06), "F");
			gtk_label_set_text(GTK_LABEL(tabla07), "G");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			gtk_label_set_text(GTK_LABEL(tabla50), "E");
			gtk_label_set_text(GTK_LABEL(tabla60), "F");
			gtk_label_set_text(GTK_LABEL(tabla70), "G");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla15), "0");
			gtk_label_set_text(GTK_LABEL(tabla16), "0");
			gtk_label_set_text(GTK_LABEL(tabla17), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla25), "0");
			gtk_label_set_text(GTK_LABEL(tabla26), "0");
			gtk_label_set_text(GTK_LABEL(tabla27), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla35), "0");
			gtk_label_set_text(GTK_LABEL(tabla36), "0");
			gtk_label_set_text(GTK_LABEL(tabla37), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
			gtk_label_set_text(GTK_LABEL(tabla45), "0");
			gtk_label_set_text(GTK_LABEL(tabla46), "0");
			gtk_label_set_text(GTK_LABEL(tabla47), "0");
			gtk_label_set_text(GTK_LABEL(tabla51), "0");
			gtk_label_set_text(GTK_LABEL(tabla52), "0");
			gtk_label_set_text(GTK_LABEL(tabla53), "0");
			gtk_label_set_text(GTK_LABEL(tabla54), "0");
			gtk_label_set_text(GTK_LABEL(tabla55), "0");
			gtk_label_set_text(GTK_LABEL(tabla56), "0");
			gtk_label_set_text(GTK_LABEL(tabla57), "0");
			gtk_label_set_text(GTK_LABEL(tabla61), "0");
			gtk_label_set_text(GTK_LABEL(tabla62), "0");
			gtk_label_set_text(GTK_LABEL(tabla63), "0");
			gtk_label_set_text(GTK_LABEL(tabla64), "0");
			gtk_label_set_text(GTK_LABEL(tabla65), "0");
			gtk_label_set_text(GTK_LABEL(tabla66), "0");
			gtk_label_set_text(GTK_LABEL(tabla67), "0");
			gtk_label_set_text(GTK_LABEL(tabla71), "0");
			gtk_label_set_text(GTK_LABEL(tabla72), "0");
			gtk_label_set_text(GTK_LABEL(tabla73), "0");
			gtk_label_set_text(GTK_LABEL(tabla74), "0");
			gtk_label_set_text(GTK_LABEL(tabla75), "0");
			gtk_label_set_text(GTK_LABEL(tabla76), "0");
			gtk_label_set_text(GTK_LABEL(tabla77), "0");
		}
		else if (val == 8){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla05), "E");
			gtk_label_set_text(GTK_LABEL(tabla06), "F");
			gtk_label_set_text(GTK_LABEL(tabla07), "G");
			gtk_label_set_text(GTK_LABEL(tabla08), "H");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			gtk_label_set_text(GTK_LABEL(tabla50), "E");
			gtk_label_set_text(GTK_LABEL(tabla60), "F");
			gtk_label_set_text(GTK_LABEL(tabla70), "G");
			gtk_label_set_text(GTK_LABEL(tabla80), "H");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla15), "0");
			gtk_label_set_text(GTK_LABEL(tabla16), "0");
			gtk_label_set_text(GTK_LABEL(tabla17), "0");
			gtk_label_set_text(GTK_LABEL(tabla18), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla25), "0");
			gtk_label_set_text(GTK_LABEL(tabla26), "0");
			gtk_label_set_text(GTK_LABEL(tabla27), "0");
			gtk_label_set_text(GTK_LABEL(tabla28), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla35), "0");
			gtk_label_set_text(GTK_LABEL(tabla36), "0");
			gtk_label_set_text(GTK_LABEL(tabla37), "0");
			gtk_label_set_text(GTK_LABEL(tabla38), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
			gtk_label_set_text(GTK_LABEL(tabla45), "0");
			gtk_label_set_text(GTK_LABEL(tabla46), "0");
			gtk_label_set_text(GTK_LABEL(tabla47), "0");
			gtk_label_set_text(GTK_LABEL(tabla48), "0");
			gtk_label_set_text(GTK_LABEL(tabla51), "0");
			gtk_label_set_text(GTK_LABEL(tabla52), "0");
			gtk_label_set_text(GTK_LABEL(tabla53), "0");
			gtk_label_set_text(GTK_LABEL(tabla54), "0");
			gtk_label_set_text(GTK_LABEL(tabla55), "0");
			gtk_label_set_text(GTK_LABEL(tabla56), "0");
			gtk_label_set_text(GTK_LABEL(tabla57), "0");
			gtk_label_set_text(GTK_LABEL(tabla58), "0");
			gtk_label_set_text(GTK_LABEL(tabla61), "0");
			gtk_label_set_text(GTK_LABEL(tabla62), "0");
			gtk_label_set_text(GTK_LABEL(tabla63), "0");
			gtk_label_set_text(GTK_LABEL(tabla64), "0");
			gtk_label_set_text(GTK_LABEL(tabla65), "0");
			gtk_label_set_text(GTK_LABEL(tabla66), "0");
			gtk_label_set_text(GTK_LABEL(tabla67), "0");
			gtk_label_set_text(GTK_LABEL(tabla68), "0");
			gtk_label_set_text(GTK_LABEL(tabla71), "0");
			gtk_label_set_text(GTK_LABEL(tabla72), "0");
			gtk_label_set_text(GTK_LABEL(tabla73), "0");
			gtk_label_set_text(GTK_LABEL(tabla74), "0");
			gtk_label_set_text(GTK_LABEL(tabla75), "0");
			gtk_label_set_text(GTK_LABEL(tabla76), "0");
			gtk_label_set_text(GTK_LABEL(tabla77), "0");
			gtk_label_set_text(GTK_LABEL(tabla78), "0");
			gtk_label_set_text(GTK_LABEL(tabla81), "0");
			gtk_label_set_text(GTK_LABEL(tabla82), "0");
			gtk_label_set_text(GTK_LABEL(tabla83), "0");
			gtk_label_set_text(GTK_LABEL(tabla84), "0");
			gtk_label_set_text(GTK_LABEL(tabla85), "0");
			gtk_label_set_text(GTK_LABEL(tabla86), "0");
			gtk_label_set_text(GTK_LABEL(tabla87), "0");
			gtk_label_set_text(GTK_LABEL(tabla88), "0");
		}
		else if (val == 9){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla05), "E");
			gtk_label_set_text(GTK_LABEL(tabla06), "F");
			gtk_label_set_text(GTK_LABEL(tabla07), "G");
			gtk_label_set_text(GTK_LABEL(tabla08), "H");
			gtk_label_set_text(GTK_LABEL(tabla09), "I");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			gtk_label_set_text(GTK_LABEL(tabla50), "E");
			gtk_label_set_text(GTK_LABEL(tabla60), "F");
			gtk_label_set_text(GTK_LABEL(tabla70), "G");
			gtk_label_set_text(GTK_LABEL(tabla80), "H");
			gtk_label_set_text(GTK_LABEL(tabla90), "I");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla15), "0");
			gtk_label_set_text(GTK_LABEL(tabla16), "0");
			gtk_label_set_text(GTK_LABEL(tabla17), "0");
			gtk_label_set_text(GTK_LABEL(tabla18), "0");
			gtk_label_set_text(GTK_LABEL(tabla19), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla25), "0");
			gtk_label_set_text(GTK_LABEL(tabla26), "0");
			gtk_label_set_text(GTK_LABEL(tabla27), "0");
			gtk_label_set_text(GTK_LABEL(tabla28), "0");
			gtk_label_set_text(GTK_LABEL(tabla29), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla35), "0");
			gtk_label_set_text(GTK_LABEL(tabla36), "0");
			gtk_label_set_text(GTK_LABEL(tabla37), "0");
			gtk_label_set_text(GTK_LABEL(tabla38), "0");
			gtk_label_set_text(GTK_LABEL(tabla39), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
			gtk_label_set_text(GTK_LABEL(tabla45), "0");
			gtk_label_set_text(GTK_LABEL(tabla46), "0");
			gtk_label_set_text(GTK_LABEL(tabla47), "0");
			gtk_label_set_text(GTK_LABEL(tabla48), "0");
			gtk_label_set_text(GTK_LABEL(tabla49), "0");
			gtk_label_set_text(GTK_LABEL(tabla51), "0");
			gtk_label_set_text(GTK_LABEL(tabla52), "0");
			gtk_label_set_text(GTK_LABEL(tabla53), "0");
			gtk_label_set_text(GTK_LABEL(tabla54), "0");
			gtk_label_set_text(GTK_LABEL(tabla55), "0");
			gtk_label_set_text(GTK_LABEL(tabla56), "0");
			gtk_label_set_text(GTK_LABEL(tabla57), "0");
			gtk_label_set_text(GTK_LABEL(tabla58), "0");
			gtk_label_set_text(GTK_LABEL(tabla59), "0");
			gtk_label_set_text(GTK_LABEL(tabla61), "0");
			gtk_label_set_text(GTK_LABEL(tabla62), "0");
			gtk_label_set_text(GTK_LABEL(tabla63), "0");
			gtk_label_set_text(GTK_LABEL(tabla64), "0");
			gtk_label_set_text(GTK_LABEL(tabla65), "0");
			gtk_label_set_text(GTK_LABEL(tabla66), "0");
			gtk_label_set_text(GTK_LABEL(tabla67), "0");
			gtk_label_set_text(GTK_LABEL(tabla68), "0");
			gtk_label_set_text(GTK_LABEL(tabla69), "0");
			gtk_label_set_text(GTK_LABEL(tabla71), "0");
			gtk_label_set_text(GTK_LABEL(tabla72), "0");
			gtk_label_set_text(GTK_LABEL(tabla73), "0");
			gtk_label_set_text(GTK_LABEL(tabla74), "0");
			gtk_label_set_text(GTK_LABEL(tabla75), "0");
			gtk_label_set_text(GTK_LABEL(tabla76), "0");
			gtk_label_set_text(GTK_LABEL(tabla77), "0");
			gtk_label_set_text(GTK_LABEL(tabla78), "0");
			gtk_label_set_text(GTK_LABEL(tabla79), "0");
			gtk_label_set_text(GTK_LABEL(tabla81), "0");
			gtk_label_set_text(GTK_LABEL(tabla82), "0");
			gtk_label_set_text(GTK_LABEL(tabla83), "0");
			gtk_label_set_text(GTK_LABEL(tabla84), "0");
			gtk_label_set_text(GTK_LABEL(tabla85), "0");
			gtk_label_set_text(GTK_LABEL(tabla86), "0");
			gtk_label_set_text(GTK_LABEL(tabla87), "0");
			gtk_label_set_text(GTK_LABEL(tabla88), "0");
			gtk_label_set_text(GTK_LABEL(tabla89), "0");
			gtk_label_set_text(GTK_LABEL(tabla91), "0");
			gtk_label_set_text(GTK_LABEL(tabla92), "0");
			gtk_label_set_text(GTK_LABEL(tabla93), "0");
			gtk_label_set_text(GTK_LABEL(tabla94), "0");
			gtk_label_set_text(GTK_LABEL(tabla95), "0");
			gtk_label_set_text(GTK_LABEL(tabla96), "0");
			gtk_label_set_text(GTK_LABEL(tabla97), "0");
			gtk_label_set_text(GTK_LABEL(tabla98), "0");
			gtk_label_set_text(GTK_LABEL(tabla99), "0");
		}
		else if (val == 10){
			gtk_label_set_text(GTK_LABEL(tabla01), "A");
			gtk_label_set_text(GTK_LABEL(tabla02), "B");
			gtk_label_set_text(GTK_LABEL(tabla03), "C");
			gtk_label_set_text(GTK_LABEL(tabla04), "D");
			gtk_label_set_text(GTK_LABEL(tabla05), "E");
			gtk_label_set_text(GTK_LABEL(tabla06), "F");
			gtk_label_set_text(GTK_LABEL(tabla07), "G");
			gtk_label_set_text(GTK_LABEL(tabla08), "H");
			gtk_label_set_text(GTK_LABEL(tabla09), "I");
			gtk_label_set_text(GTK_LABEL(tabla010), "J");
			gtk_label_set_text(GTK_LABEL(tabla10), "A");
			gtk_label_set_text(GTK_LABEL(tabla20), "B");
			gtk_label_set_text(GTK_LABEL(tabla30), "C");
			gtk_label_set_text(GTK_LABEL(tabla40), "D");
			gtk_label_set_text(GTK_LABEL(tabla50), "E");
			gtk_label_set_text(GTK_LABEL(tabla60), "F");
			gtk_label_set_text(GTK_LABEL(tabla70), "G");
			gtk_label_set_text(GTK_LABEL(tabla80), "H");
			gtk_label_set_text(GTK_LABEL(tabla90), "I");
			gtk_label_set_text(GTK_LABEL(tabla100), "J");
			
			gtk_label_set_text(GTK_LABEL(tabla11), "0");
			gtk_label_set_text(GTK_LABEL(tabla12), "0");
			gtk_label_set_text(GTK_LABEL(tabla13), "0");
			gtk_label_set_text(GTK_LABEL(tabla14), "0");
			gtk_label_set_text(GTK_LABEL(tabla15), "0");
			gtk_label_set_text(GTK_LABEL(tabla16), "0");
			gtk_label_set_text(GTK_LABEL(tabla17), "0");
			gtk_label_set_text(GTK_LABEL(tabla18), "0");
			gtk_label_set_text(GTK_LABEL(tabla19), "0");
			gtk_label_set_text(GTK_LABEL(tabla110), "0");
			gtk_label_set_text(GTK_LABEL(tabla21), "0");
			gtk_label_set_text(GTK_LABEL(tabla22), "0");
			gtk_label_set_text(GTK_LABEL(tabla23), "0");
			gtk_label_set_text(GTK_LABEL(tabla24), "0");
			gtk_label_set_text(GTK_LABEL(tabla25), "0");
			gtk_label_set_text(GTK_LABEL(tabla26), "0");
			gtk_label_set_text(GTK_LABEL(tabla27), "0");
			gtk_label_set_text(GTK_LABEL(tabla28), "0");
			gtk_label_set_text(GTK_LABEL(tabla29), "0");
			gtk_label_set_text(GTK_LABEL(tabla210), "0");
			gtk_label_set_text(GTK_LABEL(tabla31), "0");
			gtk_label_set_text(GTK_LABEL(tabla32), "0");
			gtk_label_set_text(GTK_LABEL(tabla33), "0");
			gtk_label_set_text(GTK_LABEL(tabla34), "0");
			gtk_label_set_text(GTK_LABEL(tabla35), "0");
			gtk_label_set_text(GTK_LABEL(tabla36), "0");
			gtk_label_set_text(GTK_LABEL(tabla37), "0");
			gtk_label_set_text(GTK_LABEL(tabla38), "0");
			gtk_label_set_text(GTK_LABEL(tabla39), "0");
			gtk_label_set_text(GTK_LABEL(tabla310), "0");
			gtk_label_set_text(GTK_LABEL(tabla41), "0");
			gtk_label_set_text(GTK_LABEL(tabla42), "0");
			gtk_label_set_text(GTK_LABEL(tabla43), "0");
			gtk_label_set_text(GTK_LABEL(tabla44), "0");
			gtk_label_set_text(GTK_LABEL(tabla45), "0");
			gtk_label_set_text(GTK_LABEL(tabla46), "0");
			gtk_label_set_text(GTK_LABEL(tabla47), "0");
			gtk_label_set_text(GTK_LABEL(tabla48), "0");
			gtk_label_set_text(GTK_LABEL(tabla49), "0");
			gtk_label_set_text(GTK_LABEL(tabla410), "0");
			gtk_label_set_text(GTK_LABEL(tabla51), "0");
			gtk_label_set_text(GTK_LABEL(tabla52), "0");
			gtk_label_set_text(GTK_LABEL(tabla53), "0");
			gtk_label_set_text(GTK_LABEL(tabla54), "0");
			gtk_label_set_text(GTK_LABEL(tabla55), "0");
			gtk_label_set_text(GTK_LABEL(tabla56), "0");
			gtk_label_set_text(GTK_LABEL(tabla57), "0");
			gtk_label_set_text(GTK_LABEL(tabla58), "0");
			gtk_label_set_text(GTK_LABEL(tabla59), "0");
			gtk_label_set_text(GTK_LABEL(tabla510), "0");
			gtk_label_set_text(GTK_LABEL(tabla61), "0");
			gtk_label_set_text(GTK_LABEL(tabla62), "0");
			gtk_label_set_text(GTK_LABEL(tabla63), "0");
			gtk_label_set_text(GTK_LABEL(tabla64), "0");
			gtk_label_set_text(GTK_LABEL(tabla65), "0");
			gtk_label_set_text(GTK_LABEL(tabla66), "0");
			gtk_label_set_text(GTK_LABEL(tabla67), "0");
			gtk_label_set_text(GTK_LABEL(tabla68), "0");
			gtk_label_set_text(GTK_LABEL(tabla69), "0");
			gtk_label_set_text(GTK_LABEL(tabla610), "0");
			gtk_label_set_text(GTK_LABEL(tabla71), "0");
			gtk_label_set_text(GTK_LABEL(tabla72), "0");
			gtk_label_set_text(GTK_LABEL(tabla73), "0");
			gtk_label_set_text(GTK_LABEL(tabla74), "0");
			gtk_label_set_text(GTK_LABEL(tabla75), "0");
			gtk_label_set_text(GTK_LABEL(tabla76), "0");
			gtk_label_set_text(GTK_LABEL(tabla77), "0");
			gtk_label_set_text(GTK_LABEL(tabla78), "0");
			gtk_label_set_text(GTK_LABEL(tabla79), "0");
			gtk_label_set_text(GTK_LABEL(tabla710), "0");
			gtk_label_set_text(GTK_LABEL(tabla81), "0");
			gtk_label_set_text(GTK_LABEL(tabla82), "0");
			gtk_label_set_text(GTK_LABEL(tabla83), "0");
			gtk_label_set_text(GTK_LABEL(tabla84), "0");
			gtk_label_set_text(GTK_LABEL(tabla85), "0");
			gtk_label_set_text(GTK_LABEL(tabla86), "0");
			gtk_label_set_text(GTK_LABEL(tabla87), "0");
			gtk_label_set_text(GTK_LABEL(tabla88), "0");
			gtk_label_set_text(GTK_LABEL(tabla89), "0");
			gtk_label_set_text(GTK_LABEL(tabla810), "0");
			gtk_label_set_text(GTK_LABEL(tabla91), "0");
			gtk_label_set_text(GTK_LABEL(tabla92), "0");
			gtk_label_set_text(GTK_LABEL(tabla93), "0");
			gtk_label_set_text(GTK_LABEL(tabla94), "0");
			gtk_label_set_text(GTK_LABEL(tabla95), "0");
			gtk_label_set_text(GTK_LABEL(tabla96), "0");
			gtk_label_set_text(GTK_LABEL(tabla97), "0");
			gtk_label_set_text(GTK_LABEL(tabla98), "0");
			gtk_label_set_text(GTK_LABEL(tabla99), "0");
			gtk_label_set_text(GTK_LABEL(tabla910), "0");
			gtk_label_set_text(GTK_LABEL(tabla101), "0");
			gtk_label_set_text(GTK_LABEL(tabla102), "0");
			gtk_label_set_text(GTK_LABEL(tabla103), "0");
			gtk_label_set_text(GTK_LABEL(tabla104), "0");
			gtk_label_set_text(GTK_LABEL(tabla105), "0");
			gtk_label_set_text(GTK_LABEL(tabla106), "0");
			gtk_label_set_text(GTK_LABEL(tabla107), "0");
			gtk_label_set_text(GTK_LABEL(tabla108), "0");
			gtk_label_set_text(GTK_LABEL(tabla109), "0");
			gtk_label_set_text(GTK_LABEL(tabla1010), "0");
		}
		
		gtk_widget_show(window_RMC);
	}
	else{
		//Mostrar mensaje de que se digitó un número fuera del rango
		printf("Se debe digitar un número entre 2 y 10");
		//Por alguna razón no imprime en consola
	}

}