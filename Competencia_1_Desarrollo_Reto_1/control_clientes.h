#ifndef __CONTROL_CLIENTE_H
#define __CONTROL_CLIENTE_H

#include "control_entradas.h"


typedef struct Cliente{
  char nombre[100];
  char sexo;
  double saldo;
  bool ocupado;
  int activo;
} Cliente;

void setTodosDatos1(Cliente* c);
char* imprimirOcupado(bool a);
void imprimirCliente(Cliente* c,int index);
bool isOcupado(Cliente* c);
void retirarSaldo(Cliente* c, double cuanto);
bool tieneDatos(Cliente* c);
bool tieneSaldo( Cliente* c);
void abonarSaldo(Cliente* c, double cuanto);
void eliminarCliente(Cliente* c);
void cambiarNombre(Cliente* c,  char nuevoNombre[]);
void cambiarSexo(Cliente* c,char sexo);
void setOcupado(Cliente* c) ;
bool validarSaldo(double s);

#endif
