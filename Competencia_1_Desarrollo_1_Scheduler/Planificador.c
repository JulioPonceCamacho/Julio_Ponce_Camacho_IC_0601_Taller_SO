#include<stdio.h>
#include<stdlib.h>

typedef struct Proceso {
	int PID;
	int Ciclo;
	int Tiempo;
	struct Proceso *proximo;
} Proceso;

Proceso *primero=NULL;
Proceso *ultimo=NULL;

void Agregar(Proceso* proceso);
Proceso* Ejecucion();
void imprimir();

int main(){
		printf("\t\t ---------------------------------------\n");
		printf("\t\t ||||||  Planificador de Procesos ||||||\n");
		printf("\t\t ---------------------------------------\n");

	Proceso* Process[32];
	int h=0;
	while(h<12)
	{
		Process[h]=malloc(sizeof(Process[h]));
			Process[h]->PID=h;
			Process[h]->Ciclo=0;
			Process[h]->Tiempo=rand()%201;
			Agregar(Process[h]);
		h=h+1;
	}
	Proceso* i;
	while(i != NULL){
		imprimir();
		i=Ejecucion();
		sleep(1);
	}
	printf("\n\t________ ||  Procesos Terminados  || ________\n\n");
}
void imprimir(){
	if(primero!=NULL){
	printf("\n\t<<-------------------------------------------------------------------------------------->>\n");
	Proceso* reco=primero->proximo;
	int i=0;
	while(reco!=NULL){i=i+1; reco=reco->proximo;}
	printf("PROCESOS EN ESPERA %i\n <- ",i);
	reco=primero->proximo;
	while(reco!=NULL){
		printf("[%i]",reco->PID);
		reco=reco->proximo;
	}}
}

void Agregar(Proceso* proceso){
        proceso -> proximo = NULL;
        //Comprobar que la cola esta vacia
        if(primero==NULL){
                primero= proceso;
                ultimo=proceso;
        }
        else{
               ultimo-> proximo = proceso;
               ultimo = proceso;
        }
}

Proceso* Ejecucion(){
        if(primero==NULL){
                return NULL;    
        }else{  

        Proceso* retorno = primero;
        retorno->Ciclo=retorno->Ciclo+1;
	printf("\t ||| En ejecución PID=[%i]  Ciclo=%i T=%i |||",retorno->PID, retorno->Ciclo, retorno->Tiempo);
        primero = primero -> proximo;
	 retorno->Tiempo=retorno->Tiempo-50;
	if(retorno->Tiempo<0) retorno->Tiempo=0;
        if((retorno->Tiempo)>0){
		printf("\n");
                Agregar(retorno);
        }
	else printf("\t--->>>|Proceso PID=[%i] Finalizado en %i ciclo(s)|<<<---\n",retorno->PID,retorno->Ciclo);
        return retorno;
        }
}
