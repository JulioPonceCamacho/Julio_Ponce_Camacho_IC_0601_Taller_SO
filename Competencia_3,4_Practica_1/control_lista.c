#include "control_lista.h"

struct lista *agregar_elemento(struct lista *L, char dato[]){
    if(L != NULL){
        struct nodo *e = crear_elemento(dato);
        //Agregando elementos a la lista ligada si esta no esta inicializada
        L->ultimo->siguiente=e;
        L->ultimo=e;
        L->elementos++;
        return L;
    }  
    else {
        struct nodo *e=crear_elemento(dato);
        struct lista *l = calloc(sizeof(struct lista),1);
        //Agregando elementos cuando la lista ligada ya esta creada
        l->primero = e;
        l->ultimo=e;
        l->elementos++;
        return l;
    } 

}
struct nodo *crear_elemento(char dato[]){
    struct nodo *e = calloc(sizeof(struct nodo),1);
    strcpy(e->palabra,dato);
    e->siguiente=NULL;
    return e;
}
char* obtener_elemento(struct lista *L,int indice){
    if(L!=NULL){
        if(indice <= L->elementos){
            struct nodo *aux=NULL;
            int cont=1;
            aux=L->primero;
            while(cont<indice){
                aux=aux->siguiente;
                cont++;
            }
            return aux->palabra;
        }
        else {printf("\n----x Elemento fuera de rango");
        return NULL;
        }
    } else {
        printf("\n La lista no esta inicializada");
        return NULL;}
}
struct lista *eliminar_indice(struct lista *L, int indice){
    if(L!= NULL){
        if(indice <= L->elementos && indice > 0){
            struct nodo *anterior = L->primero;
            struct nodo *pivote =L-> primero;
            int i=1;
            while(i<indice){
                anterior=pivote;
                pivote=pivote->siguiente;
                i++;
            }
            //pivote tiene el elemento a eliminar
            if(pivote->siguiente != NULL){
                //no es el ultimo elemento
                if(pivote != L->primero){
                    // no es el primero
                    anterior->siguiente=pivote->siguiente;
                    free(pivote);
                }
                else if(pivote == L->primero) {
                    //Es el primero
                    L->primero=pivote->siguiente;
                    free(pivote);
                    }
                }
                else {
                    // es el ultimo elemento
                    if(pivote != L ->primero){
                        anterior->siguiente=NULL;
                        free(pivote);
                    }
                }
                L->elementos--;
                if(L->elementos == 0){
                    printf("\n--->>Lista ligada eliminada..");
                    free(L);
                    return NULL;
                }
                else{
                    return L;
                }
            }
        else{
            printf("\n----x = El indice pedido es mayor que los elementos");
            return L;
        }
    }
    else {
        printf("\n NO se pueden eliminar elementos de una lista no inicializada");
        return NULL;
    }
}


void ordenar_lista(struct lista *L){
    if(L!= NULL){
        struct nodo *pivote=NULL, *actual=NULL;
        char tmp[TAM_NOMBRE];
        char aux1[TAM_NOMBRE];
        char aux2[TAM_NOMBRE];
        int indice;
        pivote=L->primero;
        while(pivote != L->ultimo){
            actual=pivote->siguiente;
            while(actual!=NULL){
                //almacena las cadenas en variables auxiliares
                strcpy(aux1,pivote->palabra);
                strcpy(aux2,actual->palabra);
                //Convierte las dos cadenas a minuscula para que tener mayusculas o minusculas no interfieran en el orden
                for(indice=0; aux1[indice] != '\0';indice++) aux1[indice]=toupper(aux1[indice]);
                for(indice=0; aux2[indice] != '\0';indice++) aux2[indice]=toupper(aux2[indice]);
                if(strcmp(aux1,aux2)>0){
                    strcpy(tmp,pivote->palabra);
                    strcpy(pivote->palabra,actual->palabra);
                    strcpy(actual->palabra,tmp);
                }
            actual=actual->siguiente;
            }
            pivote=pivote->siguiente;
        }
    }
    else{
        printf("\n No se puede ordenar una lista no inicializada");
    }

}
