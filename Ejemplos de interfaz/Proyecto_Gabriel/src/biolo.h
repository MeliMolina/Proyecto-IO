
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>


/*-------  Struct de la Caracteristica -----*/
struct caracteristica{
	char dominante;
	char recesivo;
	char descripcionDom[50];
	char descripcionRec[50];
	
};

struct genotipo{
	char info[12];
	char fenotipo[100];
};

struct descendiente{
	char info[12];
	char descripcion[500];
};

struct cambiosBoolean{
	bool cambiado;
};

/* Aqui definimos la lista de las caracteristicas
 * ingresadas por el usuario */
typedef struct caracteristica Caracteristicas;
typedef struct genotipo Genotipos;
typedef struct cambiosBoolean cambiosBooleanos;
typedef struct descendiente Descendientes;


Caracteristicas ColaCaracteristicas[500];
Genotipos ColaGenotipos[1000];
Genotipos ColaFila[500];
Genotipos ColaColumna[500];
cambiosBooleanos ColaCambiosBooleanos[500];
Descendientes ColaDescendientes[10000];

int cantcaracteristicas = 0;
int contadorglobal = 0;
char caractIndividuales[1000];

int cantidadfilas = 0;
int cantidadcolumnas = 0;
int cantidadescendientes = 0;


/*---------- PROTOTIPO DE FUNCIONES ----------------*/


void insertarCaracteristica (char pdominante, char precesivo,  char pDescipcionD[],char pDescripcionR[]);
void crearGenotipos();
void crearlistaBooleanos();
void verlistaBooleanos();
void insertarGenotipo( char pInfogenotipo[]);
void verlistaGenotipos();
void setBooltoFalse();

void crearFilas(char pGenotipoFila[]);
void insertarFila(char pGenotipoFila[] );
void verlistaFila();

void crearColumnas(char pGenotipoColumna[]);
void insertarColumna(char pGenotipoColumna[]);
void verlistaColumna();

void hacerCruce();
void insertarDescendiente(char pInfoDesc[]);
void verDescendientes();

/*--------------- MAIN ------------------------*/
//int main(int argc , char *argv[]){
	

		/*------------ ESTAS SON LAS CARACTERISTICAS------------------*/
		//CARACTERISTICA 1
		/*char string[50] = "Tallo alto";
		char string2[50] = "Tallo bajo";
		
		insertarCaracteristica('A','a',string,string2);
		
		
		printf("Dominante: %c \n",ColaCaracteristicas[0].dominante );
		printf("Descripcion: %s \n",ColaCaracteristicas[0].descripcionDom);
		printf("Recesivo: %c \n",ColaCaracteristicas[0].recesivo);
		printf("Descripcion: %s \n",ColaCaracteristicas[0].descripcionRec);
		*/
		/*
		//CARACTERISTICA 2
		char string3[50] = "Color Rojo";
		char string4[50] = "Color Blanco";
		
		insertarCaracteristica('B','b',string3,string4);
		
		printf("Dominante: %c \n",ColaCaracteristicas[1].dominante );
		printf("Descripcion: %s \n",ColaCaracteristicas[1].descripcionDom);
		printf("Recesivo: %c \n",ColaCaracteristicas[1].recesivo);
		printf("Descripcion: %s \n",ColaCaracteristicas[1].descripcionRec);
		
		
		//CARACTERISTICA 3
		char string5[50] = "Hojas grandes";
		char string6[50] = "Hojas pequenas";
		
		insertarCaracteristica('Q','q',string5,string6);
		
		printf("Dominante: %c \n",ColaCaracteristicas[2].dominante );
		printf("Descripcion: %s \n",ColaCaracteristicas[2].descripcionDom);
		printf("Recesivo: %c \n",ColaCaracteristicas[2].recesivo);
		printf("Descripcion: %s \n",ColaCaracteristicas[2].descripcionRec);
		
		
		 //CARACTERISTICA 4
		char string7[50] = "Puntos morados";
		char string8[50] = "Puntos blancos";
		
		insertarCaracteristica('G','g',string7,string8);
		
		printf("Dominante: %c \n",ColaCaracteristicas[3].dominante );
		printf("Descripcion: %s \n",ColaCaracteristicas[3].descripcionDom);
		printf("Recesivo: %c \n",ColaCaracteristicas[3].recesivo);
		printf("Descripcion: %s \n",ColaCaracteristicas[3].descripcionRec);
		
		//CARACTERISTICA 5
		char string9[50] = "Frutos grandes";
		char string10[50] = "Frutos pequenios";
		
		insertarCaracteristica('T','t',string9,string10);
		
		printf("Dominante: %c \n",ColaCaracteristicas[4].dominante );
		printf("Descripcion: %s \n",ColaCaracteristicas[4].descripcionDom);
		printf("Recesivo: %c \n",ColaCaracteristicas[4].recesivo);
		printf("Descripcion: %s \n",ColaCaracteristicas[4].descripcionRec);
		
		*/
		
		/*--------------------------------------------------------------------------------*/
		/*--------------------------------------------------------------------------------*/
		
		/* AQUI CREA LA LISTA CON LOS GENOTIPOS*/
		/* Todos van a quedar en ColaGenotipos, lo que es una lista.
		 * Si quiere acceder al primero de esa lista nada mas 
		 * le da ColaGenotipos[0].info y le tira el string
		 * */
		//crearGenotipos();
		
		/* AQUI CREA LAS FILAS Y LAS COLUMNAS DE LA TABLA PERO ME HACE FALTA TODAVIA*/
		//crearFilas(ColaGenotipos[0].info);
		//crearColumnas(ColaGenotipos[1].info);
		//verlistaFila();
		//verlistaColumna();
		//hacerCruce();
		//verDescendientes();
//}



void insertarCaracteristica (char pDominante, char pRecesivo, char pDescipcionD[],char pDescripcionR[]){
	
		
		struct caracteristica caracteristicanueva;
		
	
		caracteristicanueva.dominante = pDominante;
		caracteristicanueva.recesivo = pRecesivo;
		strcpy(caracteristicanueva.descripcionDom, pDescipcionD);
		strcpy(caracteristicanueva.descripcionRec, pDescripcionR);
		
		ColaCaracteristicas[cantcaracteristicas] = caracteristicanueva;
		cantcaracteristicas++;
	
	
}


void hacerCruce(){

	
	cantidadescendientes = 0;
	for (int fila = 0; fila<cantidadfilas ; fila++){
		for (int columna = 0; columna < cantidadcolumnas ; columna++ ){
			
			
			char valorCaractFila[50]=  "";
			char valorCaractColum[50] = "";
			char valorFinal[50] = "";
			
			strcpy(valorCaractFila, ColaFila[fila].info);
			strcpy(valorCaractColum, ColaColumna[columna].info);
			
			//Aqui recorremos los valores ya extraidos de la Tabla
			int j = 0;
			for(int i = 0; i<cantcaracteristicas ;i++){
				char caracterFila = valorCaractFila[i];
				char caracterColumna = valorCaractColum[i];
				
				//SI el caracter fila es mayuscula
				if (caracterFila >= 65 && caracterFila <= 90){
					valorFinal[j] = caracterFila;
					valorFinal[j+1] = caracterColumna;
				}
			    else{
					valorFinal[j] = caracterColumna;
					valorFinal[j+1] = caracterFila;
				}
				j = j+2;
					
			}

			insertarDescendiente(valorFinal);
			cantidadescendientes++;
		}
			
		
	}

	
	
}

void insertarDescendiente(char pInfoDesc[]){
		struct descendiente descendientenuevo;
		
		strcpy(descendientenuevo.info, pInfoDesc);
		
		/*REALIZAMOS EL CALCULO DEL GENOTIPO DEL DESCENDIENTE*/
		char descrGenotipo[500] = "";
		
		int i = 0;
		int finalcaract = (cantcaracteristicas*2);
		for (int contador = 0; contador< finalcaract ; contador+=2){
			
			char caracter1 = pInfoDesc[contador];
			char caracter2 = pInfoDesc[contador+1];
			
			//SI el caracter fila es mayuscula
			if (caracter1 >= 65 && caracter1 <= 90){
				strcat(descrGenotipo, ColaCaracteristicas[i].descripcionDom);
				char coma[2] = ",";
				strcat(descrGenotipo,coma);
			}
			else{
				
				if (caracter2 >= 65 && caracter2 <= 90){
					strcat(descrGenotipo, ColaCaracteristicas[i].descripcionDom);
					char coma[2] = ",";
					strcat(descrGenotipo,coma);
				}
				else{
					strcat(descrGenotipo, ColaCaracteristicas[i].descripcionRec);
					char coma[2] = ",";
					strcat(descrGenotipo,coma);
				}
			}
			i++;
			
		}
		
		printf("INSERTE: \n");
		printf("Info: %s \n",descendientenuevo.info);
		strcpy(descendientenuevo.descripcion, descrGenotipo);
		
		ColaDescendientes[cantidadescendientes] = descendientenuevo;

	
	
}


/*----------------------------------------------------------------------------------------------------*/
/*---------------------------------------CREA LOS GENOTIPOS-------------------------------------------*/
/*----------------------------------------------------------------------------------------------------*/
void crearGenotipos(){
	
	int j = 0;
	printf("CARACT : %i \n", cantcaracteristicas );
	for (int i = 0; i < cantcaracteristicas ;i++ ){
		
		caractIndividuales[j]= ColaCaracteristicas[i].dominante;
		caractIndividuales[j+1]= ColaCaracteristicas[i].recesivo;
		j = j+2;
	}
	printf("j final %i \n", j );
	
	for (int i = 0; i < cantcaracteristicas*2 ;i++ ){
		
		printf("LISTA: %c \n", caractIndividuales[i] );

		
	}
	/* AQUI REALIZAMOS EL CALCULO DE TODOS LOS POSIBLES GENOTIPOS */
	
	int division = j/2;
	int contadorAsesTOTALES = pow (3, division) ;
	int contadorcambioCaract = contadorAsesTOTALES/3;
	
	
	int cambioAs = 3;
	crearlistaBooleanos();
	int contador2 = 0;
	int cambioUltimo = 3;
	int contadorpara5 = 0;
	
	int division5 = (j-1)/2;
	int contadorAsesTOTALES5 = pow (3, division5) ;
	int contadorcambioCaract5 = contadorAsesTOTALES5/3;
	int cambio5caract = contadorcambioCaract5;
	
	for(int contador = 0; contador<cambioAs ; contador++){
		for (contador2 = 0; contador2 < contadorcambioCaract; contador2++){
			
			char unioncaracteres[50] = "";
			
			
			/* ESTOS IF SON PARA AGREGAR LAS PRIMERAS 2 LETRAS DEL GENOTIPO*/
			if(contador == 0){
				char string1;
				char string2;
				
				string1 = caractIndividuales[0];
				string2 = caractIndividuales[0];
				
				
				unioncaracteres[0] = string1;
				unioncaracteres[1] = string2;
				
			}
			else if (contador == 1){
				char string1;
				char string2;
				
				string1 = caractIndividuales[0];
				string2 = caractIndividuales[1];
				
				unioncaracteres[0] = string1;
				unioncaracteres[1] = string2;
				

			}
			else if(contador == 2){
				char string1;
				char string2;
				
				string1 = caractIndividuales[1];
				string2 = caractIndividuales[1];
				
				unioncaracteres[0] = string1;
				unioncaracteres[1] = string2;
				
			}
			
			int ultimoparcaract = j-2;
			
			/* ESTE FOR ES PARA RECORRER LOS N-2 CARACTERISTICAS QUE NECESITAMOS EN EL GENOTIPO */
			for (int k = 2; k < j  ; k+=2){
				
				
				
				int cambiador = contador*contadorcambioCaract;
				int cambiador2 = contadorpara5*cambio5caract;
				verlistaBooleanos();
				
				if ( ((j/2) == 5) && (k == 2) ){
					
					
					if ( (ColaCambiosBooleanos[k+2].cambiado == true && ColaCambiosBooleanos[k+4].cambiado == true && ColaCambiosBooleanos[k+6].cambiado == true) ){
						
						char string1 = '\0';
						char string2 = '\0';
						verlistaBooleanos();
						
						string1 = caractIndividuales[k];
						string2 = caractIndividuales[k];
						
						if (ColaCambiosBooleanos[k+1].cambiado == false && ColaCambiosBooleanos[k].cambiado == false ){
						string2 = caractIndividuales[k+1];
						ColaCambiosBooleanos[k+1].cambiado = true;
						}
						else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == false){
							string1 = caractIndividuales[k+1];
							string2 = caractIndividuales[k+1];
							ColaCambiosBooleanos[k].cambiado = true;
							
						}
						else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == true){
							ColaCambiosBooleanos[k+1].cambiado = false;
							ColaCambiosBooleanos[k].cambiado = false;
						}
						cambioUltimo = 3;
						ColaCambiosBooleanos[k+2].cambiado = false;
						ColaCambiosBooleanos[k+3].cambiado = false;
						ColaCambiosBooleanos[k+4].cambiado = false;
						ColaCambiosBooleanos[k+5].cambiado = false;
						ColaCambiosBooleanos[k+6].cambiado = false;
						ColaCambiosBooleanos[k+7].cambiado = false;
						ColaCambiosBooleanos[k+8].cambiado = false;
						contadorpara5++;
						unioncaracteres[k] = string1;
						unioncaracteres[k+1] = string2;
						
						
						
					}
					else{
						
						char string1 = '\0';
						char string2 = '\0';
						verlistaBooleanos();
						
						string1 = caractIndividuales[k];
						string2 = caractIndividuales[k];
						
						if (ColaCambiosBooleanos[k+1].cambiado == true && ColaCambiosBooleanos[k].cambiado == false ){
							string2 = caractIndividuales[k+1];
						}
						else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == true){
							string1 = caractIndividuales[k+1];
							string2 = caractIndividuales[k+1];
						}
						
						unioncaracteres[k] = string1;
						unioncaracteres[k+1] = string2;
						
					}
					
				
				}
				
				else if ( (j/2) == 5 && k == 8 && contadorglobal == cambiador2 ){
					char string1 = '\0';
					char string2 = '\0';
					verlistaBooleanos();
					
					string1 = caractIndividuales[k];
					string2 = caractIndividuales[k];
					
					if (ColaCambiosBooleanos[k+1].cambiado == true && ColaCambiosBooleanos[k].cambiado == false ){
						string2 = caractIndividuales[k+1];
					}
					else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == true){
						string1 = caractIndividuales[k+1];
						string2 = caractIndividuales[k+1];
					}
					unioncaracteres[k] = string1;
					unioncaracteres[k+1] = string2;
					
				}
			
				else if ((cambioUltimo == 0 && ColaCambiosBooleanos[k+2].cambiado == true) || (k == ultimoparcaract && contadorglobal != cambiador )){
					char string1;
					char string2;
					
					string1 = caractIndividuales[k];
					string2 = caractIndividuales[k];
					
					if (ColaCambiosBooleanos[k+1].cambiado == false && ColaCambiosBooleanos[k].cambiado == false ){
						string2 = caractIndividuales[k+1];
						ColaCambiosBooleanos[k+1].cambiado = true;
					}
					else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == false){
						string1 = caractIndividuales[k+1];
						string2 = caractIndividuales[k+1];
						ColaCambiosBooleanos[k].cambiado = true;
					}
					else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == true){
						ColaCambiosBooleanos[k+1].cambiado = false;
						ColaCambiosBooleanos[k].cambiado = false;
						cambioUltimo = 3;
					}
					verlistaBooleanos();
					
					unioncaracteres[k] = string1;
					unioncaracteres[k+1] = string2;
					
				}else {
					char string1 = '\0';
					char string2 = '\0';
					verlistaBooleanos();
					
					string1 = caractIndividuales[k];
					string2 = caractIndividuales[k];
					
					if (ColaCambiosBooleanos[k+1].cambiado == true && ColaCambiosBooleanos[k].cambiado == false ){
						string2 = caractIndividuales[k+1];
					}
					else if (ColaCambiosBooleanos[k+1].cambiado == true &&  ColaCambiosBooleanos[k].cambiado == true){
						string1 = caractIndividuales[k+1];
						string2 = caractIndividuales[k+1];
					}
					
					unioncaracteres[k] = string1;
					unioncaracteres[k+1] = string2;
				}
					
			}
			insertarGenotipo( unioncaracteres);			
			contadorglobal++;
			cambioUltimo--;

		}
		contador2 = 0;
		cambioUltimo = 3;
		contadorpara5++;
		setBooltoFalse();
	}
	

	verlistaGenotipos();

}

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void crearFilas(char pGenotipoFila[]){
	cantidadfilas = 0;
	for (int i = 0; i < cantcaracteristicas*2 ;i++ ){
		
		printf("LISTA PRUEBA: %c \n", pGenotipoFila[i] );

		
	}
	printf("\n ============================================================= \n");
	/* AQUI REALIZAMOS EL CALCULO DE TODOS LOS POSIBLES GENOTIPOS */
	int cantidadmenos = cantcaracteristicas-1;
	int cantidadcombinaciones = pow (2, cantidadmenos ) ;
	
	 
	
	int contadorcaract2 = -1;
	int contadorcaract3 = -1;
	int contadorcaract4 = -1;
	int contadorcaract5 = -1;
	
	bool boolcaract2 = false;
	bool boolcaract3 = false;
	bool boolcaract4 = false;
	
	if (cantcaracteristicas == 2){
		
		contadorcaract2 = pow (2, (cantidadmenos-1) ) ;
		
	}
	else if (cantcaracteristicas == 3){
		contadorcaract2 = pow (2, (cantidadmenos-1) );
		contadorcaract3 = pow (2, (cantidadmenos-2) );
		
	}
	else if (cantcaracteristicas == 4){
		
		contadorcaract2 = pow (2, (cantidadmenos-1) );
		contadorcaract3 = pow (2, (cantidadmenos-2) );
		contadorcaract4 = pow (2, (cantidadmenos-3) );
		
		}
	else if (cantcaracteristicas == 5){
		
		contadorcaract2 = pow (2, (cantidadmenos-1) );
		contadorcaract3 = pow (2, (cantidadmenos-2) );
		contadorcaract4 = pow (2, (cantidadmenos-3) );
		contadorcaract5 = pow (2, (cantidadmenos-4) );
		
		}
	
	int contador2 = 0;
	
	for(int contador = 0; contador<2 ; contador++){
		for (contador2 = 0; contador2 < cantidadcombinaciones; contador2++){
			
			char unioncaracteres[50] = "";
			
			/* ESTOS IF SON PARA AGREGAR LA PRIMERA CARACTERISTICA*/
			if(contador == 0){
				char string1;
				
				string1 = pGenotipoFila[0];
				
				unioncaracteres[0] = string1;
				
			}
			else if(contador == 1){
				char string1;
				printf("ENTRE AQUI: \n");
				string1 = pGenotipoFila[1];
				
				unioncaracteres[0] = string1;
				

			}
			
			// CARACTERISTICA 2
			if(contadorcaract2 > 0 && boolcaract2 == false){
				char string1;
				string1 = pGenotipoFila[2];
				unioncaracteres[1] = string1;
				contadorcaract2--;
				
			}
			else if (contadorcaract2 > 0 && boolcaract2 == true ){
				char string1;
				string1 = pGenotipoFila[3];
				unioncaracteres[1] = string1;
				contadorcaract2--;
			}
			else if(contadorcaract2 == 0){
				char string1;
				string1 = pGenotipoFila[3];
				unioncaracteres[1] = string1;
				contadorcaract2 = pow (2, (cantidadmenos-1) ) -1;
				
				if (boolcaract2 == false){
					boolcaract2 = true;
				}
				else {
					boolcaract2 = false;
				}
			
			}
			
			// CARACTERISTICA 3
			if(contadorcaract3 > 0 && boolcaract3 == false){
				char string1;
				string1 = pGenotipoFila[4];
				unioncaracteres[2] = string1;
				contadorcaract3--;
				
			}
			else if (contadorcaract3 > 0 && boolcaract3 == true ) {
				char string1;
				string1 = pGenotipoFila[5];
				unioncaracteres[2] = string1;
				contadorcaract3--;
			}
			else if(contadorcaract3 == 0){
				char string1;
				string1 = pGenotipoFila[5];
				unioncaracteres[2] = string1;
				if (contadorcaract4 == -1){
					contadorcaract3 = 1;
				}
				else {
					contadorcaract3 = pow (2, (cantidadmenos-2) ) -1;
					if (boolcaract3 == false){
						boolcaract3 = true;
					}
					else {
						boolcaract3 = false;
					};
				}
				
				

			}
		
			
			// CARACTERISTICA 4
			if(contadorcaract4 > 0 && boolcaract4 == false){
				char string1;
				string1 = pGenotipoFila[6];
				unioncaracteres[3] = string1;
				contadorcaract4--;
				
			}
			else if (contadorcaract4 > 0 && boolcaract4 == true ){
				char string1;
				string1 = pGenotipoFila[7];
				unioncaracteres[3] = string1;
				contadorcaract4--;
			}
			else if(contadorcaract4 == 0){
				char string1;
				string1 = pGenotipoFila[7];
				unioncaracteres[3] = string1;
				
				if (contadorcaract5 == -1){
					contadorcaract4 = 1;
				}
				else{
					contadorcaract4 = pow (2, (cantidadmenos-3) )-1;
					
					if (boolcaract4 == false){
						boolcaract4 = true;
					}
					else {
						boolcaract4 = false;
					}
				}
			}
			
			
			// CARACTERISTICA 5
			if(contadorcaract5 > 0  ){
				char string1;
				string1 = pGenotipoFila[8];
				unioncaracteres[4] = string1;
				contadorcaract5--;
				
			}
			else if(contadorcaract5 == 0){
				char string1;
				string1 = pGenotipoFila[9];
				unioncaracteres[4] = string1;
				contadorcaract5 = pow (2, (cantidadmenos-4) );
				

			}
			
			
			insertarFila(unioncaracteres);
			
	
		}//SALIDA DEL FOR ADENTRO
		
		
		if (cantcaracteristicas == 2){
			
			contadorcaract2 = pow (2, (cantidadmenos-1) ) ;
			
		}
		else if (cantcaracteristicas == 3){
			contadorcaract2 = pow (2, (cantidadmenos-1) );
			contadorcaract3 = pow (2, (cantidadmenos-2) );
			
		}
		else if (cantcaracteristicas == 4){
			contadorcaract2 = pow (2, (cantidadmenos-1) );
			contadorcaract3 = pow (2, (cantidadmenos-2) );
			contadorcaract4 = pow (2, (cantidadmenos-3) );
			
			}
		else if (cantcaracteristicas == 5){
			
			contadorcaract2 = pow (2, (cantidadmenos-1) );
			contadorcaract3 = pow (2, (cantidadmenos-2) );
			contadorcaract4 = pow (2, (cantidadmenos-3) );
			contadorcaract5 = pow (2, (cantidadmenos-4) );
			
			}
		contador2 = 0;
		boolcaract2 = false;
		boolcaract3 = false;
		boolcaract4 = false;
		
	} //SALIDA DEL FOR AFUERA
	
}


void insertarFila(char pGenotipoFila[] ){
	
	
	struct genotipo genotiponuevo;
	
	
	if (cantidadfilas == 0){
		
		strcpy(genotiponuevo.info, pGenotipoFila);
		ColaFila[cantidadfilas] = genotiponuevo;
		cantidadfilas++;
	
	}
	else if (cantcaracteristicas == 1) {
		
		strcpy(genotiponuevo.info, pGenotipoFila);
		ColaFila[cantidadfilas] = genotiponuevo;
		cantidadfilas++;
			
	}
	else {
		
		bool encontroigual = false;
		
		for (int i = 0; i< cantidadfilas ; i++ ){
			
			if (strcmp(ColaFila[i].info, pGenotipoFila) == 0){
				encontroigual = true;
				
			}
			
		}
		
		if (encontroigual == false){
			strcpy(genotiponuevo.info, pGenotipoFila);
			ColaFila[cantidadfilas] = genotiponuevo;
			cantidadfilas++;
			
		}

	
	}


}

void crearColumnas(char pGenotipoColumna[]){
	cantidadcolumnas = 0;
	for (int i = 0; i < cantcaracteristicas*2 ;i++ ){
		
		printf("LISTA PRUEBA: %c \n", pGenotipoColumna[i] );

		
	}
		printf("\n ============================================================= \n");
	/* AQUI REALIZAMOS EL CALCULO DE TODOS LOS POSIBLES GENOTIPOS */
	int cantidadmenos = cantcaracteristicas-1;
	int cantidadcombinaciones = pow (2, cantidadmenos ) ;
	
	 
	
	int contadorcaract2 = -1;
	int contadorcaract3 = -1;
	int contadorcaract4 = -1;
	int contadorcaract5 = -1;
	
	bool boolcaract2 = false;
	bool boolcaract3 = false;
	bool boolcaract4 = false;
	
	if (cantcaracteristicas == 2){
		
		contadorcaract2 = pow (2, (cantidadmenos-1) ) ;
		
	}
	else if (cantcaracteristicas == 3){
		contadorcaract2 = pow (2, (cantidadmenos-1) );
		contadorcaract3 = pow (2, (cantidadmenos-2) );
		
	}
	else if (cantcaracteristicas == 4){
		
		contadorcaract2 = pow (2, (cantidadmenos-1) );
		contadorcaract3 = pow (2, (cantidadmenos-2) );
		contadorcaract4 = pow (2, (cantidadmenos-3) );
		
		}
	else if (cantcaracteristicas == 5){
		
		contadorcaract2 = pow (2, (cantidadmenos-1) );
		contadorcaract3 = pow (2, (cantidadmenos-2) );
		contadorcaract4 = pow (2, (cantidadmenos-3) );
		contadorcaract5 = pow (2, (cantidadmenos-4) );
		
		}
	
	int contador2 = 0;
	
	for(int contador = 0; contador<2 ; contador++){
		for (contador2 = 0; contador2 < cantidadcombinaciones; contador2++){
			
			char unioncaracteres[50] = "";
			
			/* ESTOS IF SON PARA AGREGAR LA PRIMERA CARACTERISTICA*/
			if(contador == 0){
				char string1;
				
				string1 = pGenotipoColumna[0];
				
				unioncaracteres[0] = string1;
				
			}
			else if(contador == 1){
				char string1;
				
				string1 = pGenotipoColumna[1];
				
				unioncaracteres[0] = string1;
				

			}
			
			// CARACTERISTICA 2
			if(contadorcaract2 > 0 && boolcaract2 == false){
				char string1;
				string1 = pGenotipoColumna[2];
				unioncaracteres[1] = string1;
				contadorcaract2--;
				
			}
			else if (contadorcaract2 > 0 && boolcaract2 == true ){
				char string1;
				string1 = pGenotipoColumna[3];
				unioncaracteres[1] = string1;
				contadorcaract2--;
			}
			else if(contadorcaract2 == 0){
				char string1;
				string1 = pGenotipoColumna[3];
				unioncaracteres[1] = string1;
				contadorcaract2 = pow (2, (cantidadmenos-1) ) -1;
				
				if (boolcaract2 == false){
					boolcaract2 = true;
				}
				else {
					boolcaract2 = false;
				}
			
			}
			
			// CARACTERISTICA 3
			if(contadorcaract3 > 0 && boolcaract3 == false){
				char string1;
				string1 = pGenotipoColumna[4];
				unioncaracteres[2] = string1;
				contadorcaract3--;
				
			}
			else if (contadorcaract3 > 0 && boolcaract3 == true ) {
				char string1;
				string1 = pGenotipoColumna[5];
				unioncaracteres[2] = string1;
				contadorcaract3--;
			}
			else if(contadorcaract3 == 0){
				char string1;
				string1 = pGenotipoColumna[5];
				unioncaracteres[2] = string1;
				if (contadorcaract4 == -1){
					contadorcaract3 = 1;
				}
				else {
					contadorcaract3 = pow (2, (cantidadmenos-2) ) -1;
					if (boolcaract3 == false){
						boolcaract3 = true;
					}
					else {
						boolcaract3 = false;
					};
				}
				
				

			}
		
			
			// CARACTERISTICA 4
			if(contadorcaract4 > 0 && boolcaract4 == false){
				char string1;
				string1 = pGenotipoColumna[6];
				unioncaracteres[3] = string1;
				contadorcaract4--;
				
			}
			else if (contadorcaract4 > 0 && boolcaract4 == true ){
				char string1;
				string1 = pGenotipoColumna[7];
				unioncaracteres[3] = string1;
				contadorcaract4--;
			}
			else if(contadorcaract4 == 0){
				char string1;
				string1 = pGenotipoColumna[7];
				unioncaracteres[3] = string1;
				
				if (contadorcaract5 == -1){
					contadorcaract4 = 1;
				}
				else{
					contadorcaract4 = pow (2, (cantidadmenos-3) )-1;
					
					if (boolcaract4 == false){
						boolcaract4 = true;
					}
					else {
						boolcaract4 = false;
					}
				}
			}
			
			
			// CARACTERISTICA 5
			if(contadorcaract5 > 0  ){
				char string1;
				string1 = pGenotipoColumna[8];
				unioncaracteres[4] = string1;
				contadorcaract5--;
				
			}
			else if(contadorcaract5 == 0){
				char string1;
				string1 = pGenotipoColumna[9];
				unioncaracteres[4] = string1;
				contadorcaract5 = pow (2, (cantidadmenos-4) );
				

			}
			
			
			insertarColumna(unioncaracteres);
			
	
		}//SALIDA DEL FOR ADENTRO
		
		
		if (cantcaracteristicas == 2){
			
			contadorcaract2 = pow (2, (cantidadmenos-1) ) ;
			
		}
		else if (cantcaracteristicas == 3){
			contadorcaract2 = pow (2, (cantidadmenos-1) );
			contadorcaract3 = pow (2, (cantidadmenos-2) );
			
		}
		else if (cantcaracteristicas == 4){
			contadorcaract2 = pow (2, (cantidadmenos-1) );
			contadorcaract3 = pow (2, (cantidadmenos-2) );
			contadorcaract4 = pow (2, (cantidadmenos-3) );
			
			}
		else if (cantcaracteristicas == 5){
			
			contadorcaract2 = pow (2, (cantidadmenos-1) );
			contadorcaract3 = pow (2, (cantidadmenos-2) );
			contadorcaract4 = pow (2, (cantidadmenos-3) );
			contadorcaract5 = pow (2, (cantidadmenos-4) );
			
			}
		contador2 = 0;
		boolcaract2 = false;
		boolcaract3 = false;
		boolcaract4 = false;
		
	} //SALIDA DEL FOR AFUERA
	
}


void insertarColumna(char pGenotipoColumna[]){
	
	
	struct genotipo genotiponuevo;
	
	
	if (cantidadcolumnas == 0){
		
		strcpy(genotiponuevo.info, pGenotipoColumna);
		ColaColumna[cantidadcolumnas] = genotiponuevo;
		cantidadcolumnas++;
	
	}
	else if (cantcaracteristicas == 1) {
		
		strcpy(genotiponuevo.info, pGenotipoColumna);
		ColaColumna[cantidadcolumnas] = genotiponuevo;
		cantidadcolumnas++;
			
	}
	else {
		
		bool encontroigual = false;
		
		for (int i = 0; i< cantidadcolumnas ; i++ ){
			
			if (strcmp(ColaColumna[i].info, pGenotipoColumna) == 0){
				encontroigual = true;
				
			}
			
		}
		
		if (encontroigual == false){
			strcpy(genotiponuevo.info, pGenotipoColumna);
			ColaColumna[cantidadcolumnas] = genotiponuevo;
			cantidadcolumnas++;
			
		}

	}
	
	
}


void verlistaFila(){
	
	printf(" FILA FINAL!!: \n");
	for(int j = 0; j < cantidadfilas; j++){
		
		char *genotipoprint = ColaFila[j].info;
		printf(" FILA %i: %s \n", j ,genotipoprint);
			

	}
	
}


void verlistaColumna(){
	
	printf(" COlUMNA FINAL!!: \n");
	for(int j = 0; j < cantidadcolumnas; j++){
		
		char *genotipoprint = ColaColumna[j].info;
		printf(" COLUMNA %i: %s \n", j ,genotipoprint);
			

	}
	
}

void verDescendientes(){
	
	printf("\n DESCENDIENTES: \n");
	for(int j = 0; j < cantidadfilas*cantidadcolumnas; j++){
		char *genotipoprint = ColaDescendientes[j].info;
		char *genotipoprint2 = ColaDescendientes[j].descripcion;
		printf(" Descendiente %i: %s  - %s \n", j ,genotipoprint,genotipoprint2 );
			

	}
	
}




void insertarGenotipo( char pInfogenotipo[]){
	
	
	struct genotipo genotiponuevo;
	strcpy(genotiponuevo.info, pInfogenotipo);
	printf(" METI EL GENOTIPO: %s \n", pInfogenotipo);
	ColaGenotipos[contadorglobal] = genotiponuevo;
			
			
	
}


void verlistaGenotipos(){
	
	for(int j = 0; j < contadorglobal; j++){
		
		char *genotipoprint = ColaGenotipos[j].info;
		printf(" Genotipo %i: %s \n", j ,genotipoprint);
			

	}
	
}



void crearlistaBooleanos(){
	
	int cantidad = (cantcaracteristicas *2);
	
	for (int i = 0; i<cantidad ; i++){
		struct cambiosBoolean booleano;
		booleano.cambiado = false;
		ColaCambiosBooleanos[i] = booleano;

	}
	
	
}


void setBooltoFalse(){
	
	int cantidad = (cantcaracteristicas *2);
	for (int i = 0; i < cantidad ; i++){
		ColaCambiosBooleanos[i].cambiado =false;


	}
	
}


void verlistaBooleanos(){
	
	int cantidad = (cantcaracteristicas *2);
	printf(" [ ");
	for(int j = 0; j < cantidad; j++){
		
		if (ColaCambiosBooleanos[j].cambiado == true){
			printf(" True, ");
			
		}
		else {
			
			printf("False, ");
		}
		
	}
	
	printf(" ] \n");
}



