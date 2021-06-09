#ifndef __CONTROL_LISTA_H
#define __CONTROL_LISTA_H
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    
    #define TAM_NOMBRE 100

    struct nodo{
        char palabra[TAM_NOMBRE];
        struct nodo *siguiente;
    };

    struct lista{
        struct nodo *primero;
        struct nodo *ultimo;
        int elementos;
    };

    struct lista *agregar_elemento(struct lista *L, char dato[]);
    struct nodo *crear_elemento(char dato[]);
    char* obtener_elemento(struct lista *L,int indice); 
    void ordenar_lista(struct lista *L);
    struct lista *eliminar_indice(struct lista *L, int indice);

#endif