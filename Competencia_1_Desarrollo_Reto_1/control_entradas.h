#ifndef __CONTROL_ENTRADAS_H
#define __CONTROL_ENTRADAS_H

#define MOSTRAR_MENU_PRIN 0
#define LIMITE_PAISES 5
#define LIMITE_CLIENTES 10
#define ALTA 1
#define BAJA 2
#define MOSTRAR_TODO 3
#define MOSTRAR_ESPECIFICO 4
#define MOSTRAR_OCUPADOS 5
#define ABONAR 6
#define RETIRAR 7
#define BUSCAR_ID_VACIO_ESTRUCTURA 8
#define ESTA_LLENA_ESTRUCTURA 9
#define ESTA_VACIA_ESTRUCTURA 10
#define IMPRIMIR_NOM_PAISES 11
#define MOSTRAR_LONGITUDES 12
#define ACTUALIZAR 13
#define SALIR 14
#define ACTUALIZAR_MOSTRAR_MENU 0
#define ACTUALIZAR_NOMBRE 1
#define ACTUALIZAR_SEXO 2
#define SALIR_ACTUALIZAR 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h> //Datos tipo string
#include<stdbool.h> //Datos boolos


int entero(char mensaje[]);
void cadena(char *buffer, char mensaje[]);
double doble( char mensaje[]);
char caracter(char mensaje[]);
int validarRango(int inicio, int fin, char mensaje[]);

#endif
