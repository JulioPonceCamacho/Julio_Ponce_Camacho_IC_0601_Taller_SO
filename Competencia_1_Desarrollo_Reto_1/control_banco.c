#include "control_banco.h"

void BancoI(Banco* b, char nombrePais[], int tam_clientes){
		strcpy(b->nombrePais, nombrePais);
		construirClientes(b,tam_clientes);

    }
void construirClientes(Banco* b,int tm){
            int i=0;
            for(i = 0; i < tm; i++){
                setTodosDatos1(&b->clientes[i]) ;
            }
        }
void getNombrePais(char *buffer,Banco* banco) {
      strcpy(buffer,banco->nombrePais);
  }
void introducirPaises(Banco *banco){
                char mensaje[100] = "\nIntroduce el nombre del País ";
                strcat(mensaje," : ");
                char pais [100];
                pedirNombrePais(pais, mensaje);
                strcpy(mensaje,"\tIntroduce el total de clientes del pais ");
                strcat(mensaje,pais);
                strcat(mensaje," : ");
                BancoI(banco, pais, validarRango(1, LIMITE_CLIENTES, mensaje));
        }
void pedirNombrePais(char *buffer, char mensaje[]){
            char nombrePais[100];
  					bool se_encuentra=true;
            cadena(nombrePais,mensaje);
  					strcpy(buffer,nombrePais);
         }
bool isTodoOcupado(Banco* banco){
         bool todo_ocupado = false;
         int i,contador = 0;
         for( i = 0; i < getTotalClientes(banco); i++){
             if(isOcupado(&banco->clientes[i])==true){
                 contador++;
             }
         }
         if(contador == getTotalClientes(banco))
             todo_ocupado = true;
         return todo_ocupado;
     }
bool isTodoDesocupado(Banco* banco){
         bool todo_desocupado = false;
         int i,contador = 0;
         for( i = 0; i < getTotalClientes(banco); i++){
             if(isOcupado(&banco->clientes[i])==false){
                 contador++;
             }
         }
         if(contador == getTotalClientes(banco))
             todo_desocupado = true;
         return todo_desocupado;
     }
int indiceVacio(Banco *banco){
     int index_vacio = -1;
     for(int i = 0; i < getTotalClientes(banco); i++){
         if(isOcupado(&banco->clientes[i])==false){
             index_vacio = i;
             break;
         }
     }
     return index_vacio;
}
void imprimirPaises(int i, Banco *banco){
printf("\nPaís [ %i ] %s ",i,banco->nombrePais);
}
bool printSoloOcupados(Banco* banco,int pais){
		 bool imprimio = false;
		 if(existeEspacioOcupado(banco)==true){
				 imprimio = true;
				 printf("\n----------------------------------------------------------------------------------------------------------------");
				 printf("\n\tDel pais [ %i ] %s los clientes disponibles son: ",pais,banco->nombrePais);
				 for(int  i = 0; i < getTotalClientes(banco); i++){
						 if(isOcupado(&banco->clientes[i])==true){
								 printf("\nEl cliente %i es: ",i);
								 imprimirCliente(&banco->clientes[i],i);
						 }
				 }
				 printf("\n----------------------------------------------------------------------------------------------------------------");
		 }
		 return imprimio;
 }
void setEspecificoCliente(Banco *banco, int index,Cliente cliente){
                 strcpy(banco->clientes[index].nombre,cliente.nombre);
         				banco->clientes[index].sexo=cliente.sexo;
         				banco->clientes[index].saldo=cliente.saldo;
         				banco->clientes[index].ocupado=cliente.ocupado;
         }
bool existeEspacioOcupado(Banco* banco){
	        bool existeOcupado = false;
	 				int i;
	 				for(i = 0; i < getTotalClientes(banco); i++){
	             if(isOcupado(&banco->clientes[i])==true){
	                 existeOcupado = true;
	                 break;
	             }
	         }
	         return existeOcupado;
	     }
void printTodosClientes(Banco *banco,int pais){
       			 printf("\n\tDel pais [ %i ] %s : ",pais,banco->nombrePais);
       			 int i;
       			 for(i = 0; i < getTotalClientes(banco); i++){
       					 printf("\nEl cliente %i es: ",i);
       					 imprimirCliente(&banco->clientes[i],i);
       			 }
       	 }
void mostrarLongitudes(Banco* banco){
                     int tam_buf = getTotalClientes(banco);
         						char aux[100];
         						getNombrePais(aux,banco);
                     printf("\n\t-. Del País %s,con capacidad maxima de %i clientes.",aux,tam_buf);
         }
int getTotalClientes(Banco* banco){
         	 	 	int i,contador=0;
         	 		for(i=0;i<LIMITE_CLIENTES;i++){
         	 			if(banco->clientes[i].activo==2222)
         	 					contador=contador+1;
         	 		}
         	 				//return banco.clientes.length;
         	 				return contador;
         	     }
