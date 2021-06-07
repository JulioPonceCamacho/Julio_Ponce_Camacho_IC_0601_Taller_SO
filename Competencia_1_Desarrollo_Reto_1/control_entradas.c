#include "control_entradas.h"

//Entrada de datos

int entero(char mensaje[]){
     int entero = -1;
     printf("\n %s ",mensaje);
     scanf("%d",&entero);
		  getchar();
     return entero;}
char caracter(char mensaje[]){
	char c[100];
	printf("\n %s ",mensaje);
	scanf("%s",c);
	getchar();
	return c[0];
}
void cadena(char *buffer, char mensaje[]){
     printf("\n  %s  ",mensaje);
     char cadena[100];
     //scanf("%s",cadena);
		 fgets(cadena,100,stdin);
		 if ((strlen(cadena) > 0) && (cadena[strlen(cadena) - 1] == '\n'))
    {
        cadena[strlen(cadena) - 1] = '\0';
    }
		 strcpy(buffer,cadena);
 }
double doble( char mensaje[]){
     double doble = -1.0;
     printf("\n  %s  ",mensaje);
     scanf("%lf",&doble);
		  getchar();
     return doble;
 }
int validarRango(int inicio, int fin, char mensaje[]){
         int numero = entero(mensaje);
         while(numero < inicio || numero > fin){
             if(numero < inicio || numero > fin){
                 printf("\n\t\tNo esta dentro del Rango...");
                 printf("\n\t\t\t-. El rango va de %d a %d", inicio,fin);
             }
             numero = entero(mensaje);
 				}
         return numero;
     }
