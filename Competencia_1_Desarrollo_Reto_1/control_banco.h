#ifndef __CONTROL_BANCO_H
#define __CONTROL_BANCO_H

#include "control_clientes.h"


typedef struct Banco{
     	char nombrePais[100] ;
			Cliente clientes[10];
} Banco;

void BancoI(Banco* b, char nombrePais[], int tam_clientes);
void construirClientes(Banco* b,int tm);
void getNombrePais(char *buffer,Banco* banco);
void introducirPaises(Banco *banco);
void pedirNombrePais(char *buffer, char mensaje[]);
bool isTodoOcupado(Banco* banco);
bool isTodoDesocupado(Banco* banco);
int indiceVacio(Banco *banco);
void imprimirPaises(int i, Banco *banco);
bool printSoloOcupados(Banco* banco,int pais);
bool existeEspacioOcupado(Banco* banco);
void printTodosClientes(Banco *banco,int pais);
void setEspecificoCliente(Banco *banco, int index,Cliente cliente);
void mostrarLongitudes(Banco* banco);
int getTotalClientes(Banco* banco);



#endif
