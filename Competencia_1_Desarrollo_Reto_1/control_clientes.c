#include "control_clientes.h"

void setTodosDatos1(Cliente* c){
     strcpy(c->nombre,"vacio");
     c->sexo ='-';
     c->saldo = 0.0;
     c->ocupado = false;
		 c->activo=2222;
 }
bool isOcupado(Cliente* c) {
         return c->ocupado;
     }
char* imprimirOcupado(bool a){
		if(a==true) return "true";
		else return "false";
	}
void imprimirCliente(Cliente* c, int index){
       printf("\n\t\t.[%i] Nombre: %s | |. Sexo: %c | |.Saldo: %lf | |.Ocupado: %s ",index, c->nombre,c->sexo,c->saldo,imprimirOcupado(c->ocupado));
   }
void retirarSaldo(Cliente* c, double cuanto){
			 if(tieneDatos(c)==true){
					 if(cuanto > 0.0){
							 if(tieneSaldo(c)==true){
									 if(c->saldo >= cuanto){
											 c->saldo=c->saldo-cuanto;
											 printf("\n\t\tSaldo restante: %lf",c->saldo);}
									 else
											 printf("\tImposible, tú saldo es insuficiente para retirar %lf.",cuanto);
							 }
							 else
									 printf("\tImposible, no hay saldo.");
					 }
					 else
							 printf("\tImposible, no puedes retirar saldos negativos o nada.");
			 }
	 }
bool tieneDatos(Cliente* c){
	 				if(strcmp(c->nombre,"vacio")==0)
	         return false;
	 				else return true;


	    }
bool tieneSaldo( Cliente* c){
		 			if(c->saldo > 0.0)
		         return true;
		 			else return false;
		     }
void abonarSaldo(Cliente* c, double cuanto){
     if(tieneDatos(c)==true) {
         if(cuanto > 0.0){
             c->saldo =c->saldo+cuanto;
							printf("\n\t\tSaldo total: %lf",c->saldo);
         }
         else{
             printf("\n\tImposible, no puedes abonar saldos negativos o nada.");
         }
     }
 }
void eliminarCliente(Cliente* c){
	        setTodosDatos1(c);
}
void cambiarNombre(Cliente* c, char nuevoNombre[]){
			 if(nuevoNombre != NULL && strcmp(nuevoNombre," ")!=0){
					 strcpy(c->nombre, nuevoNombre);
			 }
			 setOcupado(c);
	 }
void cambiarSexo(Cliente* c,char sexo){
			bool h=false;
			while(h==false){
			 if(sexo == 'M' || sexo == 'F'){
					 c->sexo = sexo;
					 setOcupado(c);
					 h=true;
			 }
			 else{
				 printf("\nError, solo puede usar los caracteres M|F, vuelve a intentar");
				 sexo=caracter("Introduce el nuevo Sexo(M|F): ");
			 }
		 }
	 }
void setOcupado(Cliente* c) {
        if(tieneDatos(c)!=true){
            setTodosDatos1(c);
        }
        else{
            c->ocupado = true;
        }
    }
bool validarSaldo(double s){
	if(s<0) return false;
	else return true;

}
