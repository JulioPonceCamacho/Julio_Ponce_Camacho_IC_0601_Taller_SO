#include <stdio.h>

int main(){
	printf("\n\t||||||||||| Ejercicio practico numero 1 en C |||||||||||||");
	//Paso1
	int x;
	int *p;
	//paso2
	int y;
	int *puntero;
	//paso3
	x=10;
	//paso4
	p=&x;
	//paso5
	printf("\nContenido del puntero p= %d",*p);
	//paso6
	*p=*p+1;
	//paso7
	printf("\nContenido del puntero p= %d",*p);
	//paso8
	*p=*p+2;
	//paso9
	printf("\nContenido del puntero p= %d",*p);
	//paso10
	y=20;
	//paso11
	puntero=&y;
	//pas12
	printf("\nContenido del puntero 'puntero'= %d\n\n",*puntero);

	printf("\n\t||||||||||| Ejercicio practico numero 2 en C |||||||||||||");
	//paso1
	int arrayInt[5];
	//paso2
	int i;
	for(i=0;i<=5;i++){
		arrayInt[i]=i;
	}
	//paso3
	int *punteroInt;
	punteroInt=&arrayInt[0];
	//paso4
	int *punteroIntDos;
	punteroIntDos=&arrayInt[0];
	//paso5
	printf("\nContenido del primer elemento del array 'arrayInt'= %d",arrayInt[0]);
	//paso6
	printf("\nContenido del primer elemento del puntero 'punteroInt'= %d",*punteroInt);
	//paso7
	printf("\nContenido del primer elemento del puntero 'punteroIntDos'= %d",*punteroIntDos);
	//paso8
	printf("\nContenido del quinto elemento del array 'arrayInt'= %d",arrayInt[5]);
	//paso9
	punteroInt+=5;
	printf("\nContenido del quinto elemento del puntero 'punteroInt'= %d",*punteroInt);
	//paso10
	punteroIntDos+=5;
	printf("\nContenido del quinto elemento del puntero 'punteroIntDos'= %d",*punteroIntDos);
	//paso11
	printf("\n\nContenido del 'punteroIntDos'");
	punteroIntDos-=5;
	for (i=0; i<=5; i++ )
		{
		printf("\n-->Contenido del %i elemento = %d",i,*punteroIntDos);
		punteroIntDos++;
		}
	//paso12
	i=0;
	punteroIntDos=&arrayInt[0];
	printf("\n\nContenido del 'punteroIntDos'");
	while (i<=5)
		{
		printf("\n-->Contenido del %i elemento = %d",i,*punteroIntDos);
		punteroIntDos++;
		i++;
		}
	printf("\n");
	return 0;
}
