#include "control_system.h"

int TM;
void titulo(){
	printf("\n\t\t=======================================================================");
	printf("\n\t\t||_______________________SYSTEMA BANCARIO.___________________________||");
	printf("\n\t\t=======================================================================");

}
void saltoLinea(){
       printf("\n");
   }
void instrucciones(){
					titulo();
	        printf("\n-------------------------------");
	        printf("\n---- Menú ----\n");
	        printf("\n 0 Mostrar menú.\n");
	        printf("\n 1 Dar de alta Cliente.\n");
	        printf("\n 2 Dar de baja Cliente.\n");
	        printf("\n 3 Mostrar todos los clientes.\n");
	        printf("\n 4 Mostrar cliente en especifico.\n");
	        printf("\n 5 Mostrar solo clientes dados de alta.\n");
	        printf("\n 6 Abonar saldo a cliente.\n");
	        printf("\n 7 Retirar saldo de cliente.\n");
	        printf("\n 8 Buscar indice vacio en toda la estructura.\n");
	        printf("\n 9 Mostrar si esta toda llena la estructura.\n");
	        printf("\n 10 Mostrar si esta toda vacia la estructura.\n");
	        printf("\n 11 Mostrar nombre de paises.\n");
	       	printf("\n 12 Mostrar longitudes.\n");
	        printf("\n 13 Actualizar datos de cliente especifico.\n");
	        printf("\n 14 Salir.\n");
	        printf("-------------------------------");
	    }
void instrucciones_actualizar(){
	        printf("\n-------------------------------");
	        printf("\n---- Menú Actualizar ----\n");
	        printf("\n 0 Mostrar menú.\n");
	        printf("\n 1 Actualizar Nombre.\n");
	        printf("\n 2 Actualizar Sexo.\n");
	        printf("\n 3 Regresar a ménu principal.\n");
	        printf("\n-------------------------------");
	    }
void  Ejecucion(){
      				titulo();
      			  int eleccion;
      			  TM=validarRango(1, LIMITE_PAISES, "\nIntroduce el número de paises: ");
      			  Banco banco[TM+1];
      				for(int i = 0; i < TM; i++){
      						introducirPaises(&banco[i]);
      				}
      			  saltoLinea();
              int i=0;
              while(i<TM)  {
      					 mostrarLongitudes(&banco[i]);
      					 i++;
      				}
      			  saltoLinea();
      			  instrucciones();
      			  eleccion = entero(" Elija una opción: ");
      				while(eleccion != SALIR){
                  switch(eleccion){
      							case 1:
      							printf(" --- Opción alta ---");
      									int con=0;
      							        for(i=0;i<TM;i++) {
      												if(isTodoOcupado(&banco[i])==true) con++;
      											}
      									if(con<TM){
      										   char nombre_pais[100];
      											 int id_pais=-1;
      											 bool se_encuentra=true;
      															 while(se_encuentra==true){
      																 pedirNombrePais(nombre_pais,"\tIntroduce el nombre del pais: ");
      															 for(i = 0; i <TM; i++){
      																	 if(strcmp(banco[i].nombrePais,nombre_pais)==0){id_pais=i;}
      														 }
      														 if(id_pais==-1) {se_encuentra = true; printf("\n---Pais no encontrado, vuelve a intentar---");}
      														 else se_encuentra = false;
      													 }
      										  int cliente = indiceVacio(&banco[id_pais]);
      											if(cliente != -1){
      													Cliente temp;
      																   cadena(temp.nombre,"Introduce nombre del cliente: ");
      																	 bool h=false;char auxS=caracter("Introduce el Sexo (M|F): ");
      																 			while(h==false){
      																 			 if(auxS == 'M' || auxS == 'F'){
      																 					 h=true;
      																 			 }
      																 			 else{
      																 				 printf("\nError, solo puede usar los caracteres M|F, vuelve a intentar");
      																 				 auxS=caracter("Introduce el nuevo Sexo(M|F): ");
      																 			 }
      																 		 }
      																	 temp.sexo=auxS;
      																	 h=false;
      																	 double auxD;
      																				while(h==false){
      																				auxD=doble("Introduce el saldo: ");
      																				if(validarSaldo(auxD)==true) h=true;
      																				else printf("\n No se permiten saldos negativos.");
      																				}
      																	 temp.saldo=auxD;
      																	 temp.ocupado=true;
      																	 setEspecificoCliente(&banco[id_pais],cliente,temp);
      											}
      											else
      													printf("\nNo existe indice vacio en el pais %s.", banco[id_pais].nombrePais);

      									//printf("\n\t\t La estructura esta completamente vacia.");
      							}
      									else {
      											printf("\n---------------------------------------------------------------------");
      											printf("\n\t\t La estructura esta completamente llena.");
      											printf("\n---------------------------------------------------------------------");
      									}
      									break;
      							case 2:
      									printf("\n --- Opción baja ---");
      									con=0;
      											for(i=0;i<TM;i++) {
      												if(isTodoDesocupado(&banco[i])==false) con++;
      											}
      									if(con>0){
      											 char nombre_pais[100];
      											 int id_pais=-1;
      											 bool se_encuentra=true;
      															 while(se_encuentra==true){
      																 pedirNombrePais(nombre_pais,"\tIntroduce el nombre del pais: ");
      															 for(i = 0; i <TM; i++){
      																	 if(strcmp(banco[i].nombrePais,nombre_pais)==0){id_pais=i;}
      														 }
      														 if(id_pais==-1) {se_encuentra = true; printf("\n---Pais no encontrado, vuelve a intentar---");}
      														 else se_encuentra = false;
      													 }
      										int cliente = validarRango(0, getTotalClientes(&banco[id_pais])-1, "\tIntroduce el indice del cliente: ");
      											if(isOcupado(&banco[id_pais].clientes[cliente])==true){
      														printf("\n\t-. Cliente %s dado de baja.",banco[id_pais].clientes[cliente].nombre);
      														eliminarCliente(&banco[id_pais].clientes[cliente]);
      												}
      												else
      														printf("\n\tEl cliente %i del pais %s no tiene datos.",cliente,banco[id_pais].nombrePais);
      										}
      										else {
      												printf("\n---------------------------------------------------------------------");
      												printf("\n\t\t La estructura esta toda vacia.");
      												printf("\n---------------------------------------------------------------------");
      										}
      									break;
      							case 3:
      											printf("\n--- Opción mostrar todo ---");
      											for(int i = 0; i < TM; i++){
      													printf("\n----------------------------------------------------------------------------------------------------------------");
      													printTodosClientes(&banco[i],i);
      											}
      													printf("\n----------------------------------------------------------------------------------------------------------------");
      											break;
      							case 4:
      											printf("\n--- Opción mostrar especifico ---");
      											con=0;
      													for(i=0;i<TM;i++) {
      														if(isTodoDesocupado(&banco[i])==false) con++;
      													}
      											if(con>0){
      													 char nombre_pais[100];
      													 int id_pais=-1;
      													 bool se_encuentra=true;
      																	 while(se_encuentra==true){
      																		 pedirNombrePais(nombre_pais,"\tIntroduce el nombre del pais: ");
      																	 for(i = 0; i <TM; i++){
      																			 if(strcmp(banco[i].nombrePais,nombre_pais)==0){id_pais=i;}
      																 }
      																 if(id_pais==-1) {se_encuentra = true; printf("\n---Pais no encontrado, vuelve a intentar---");}
      																 else se_encuentra = false;
      															 }
      												int cliente = validarRango(0, getTotalClientes(&banco[id_pais])-1, "\tIntroduce el indice del cliente: ");
      													if(isOcupado(&banco[id_pais].clientes[cliente])==true){
      															imprimirCliente(&banco[id_pais].clientes[cliente],cliente);
      													}
      													else
      															printf("\n\tEl cliente %i del pais %s no tiene datos.",cliente,banco[id_pais].nombrePais);
      											}else{
      													printf("\n---------------------------------------------------------------------");
      													printf("\n\t\t La estructura esta toda vacia.");
      													printf("\n---------------------------------------------------------------------");

      											}
      											break;
      							case 5:
      										printf("\n--- Opción mostrar solo ocupados ---");
      										con=0;
      										for(i = 0; i < TM; i++){
      						            if(printSoloOcupados(&banco[i],i)==true)
      						                con++;
      						        }
      						        if(con==0){
      						            printf("\n\t\t --. No existen clientes que mostrar...");
      						        }
      										break;
      							case 6:
      								printf("\n --- Opción abonar ---");
      								con=0;
      										for(i=0;i<TM;i++) {
      											if(isTodoDesocupado(&banco[i])==false) con++;
      														}
      												if(con>0){
      												char nombre_pais[100];
      												int id_pais=-1;
      												bool se_encuentra=true;
      																while(se_encuentra==true){
      																	pedirNombrePais(nombre_pais,"\tIntroduce el nombre del pais: ");
      																for(i = 0; i <TM; i++){
      																		if(strcmp(banco[i].nombrePais,nombre_pais)==0){id_pais=i;}
      															}
      															if(id_pais==-1) {se_encuentra = true; printf("\n---Pais no encontrado, vuelve a intentar---");}
      															else se_encuentra = false;
      														}
      										 int cliente = validarRango(0, getTotalClientes(&banco[id_pais])-1, "\tIntroduce el indice del cliente: ");
      												if(isOcupado(&banco[id_pais].clientes[cliente])==true){
      														double cuanto = doble("\tIntroduce cuanto ingresarás a tú cuenta: ");
      														abonarSaldo(&banco[id_pais].clientes[cliente], cuanto);
      												}
      												else
      														printf("\n\tEl cliente %i del pais %s no tiene datos.",cliente,banco[id_pais].nombrePais);
      										}
      										else {
      												printf("\n---------------------------------------------------------------------");
      												printf("\n\t\t La estructura esta toda vacia.");
      												printf("\n---------------------------------------------------------------------");
      										}
      										break;
      							case 7:
      										printf("\n --- Opción retirar ---");
      										con=0;
      												for(i=0;i<TM;i++) {
      													if(isTodoDesocupado(&banco[i])==false) con++;
      												}
      										if(con>0){
      												 char nombre_pais[100];
      												 int id_pais=-1;
      												 bool se_encuentra=true;
      																 while(se_encuentra==true){
      																	 pedirNombrePais(nombre_pais,"\tIntroduce el nombre del pais: ");
      																 for(i = 0; i <TM; i++){
      																		 if(strcmp(banco[i].nombrePais,nombre_pais)==0){id_pais=i;}
      															 }
      															 if(id_pais==-1) {se_encuentra = true; printf("\n---Pais no encontrado, vuelve a intentar---");}
      															 else se_encuentra = false;
      														 }
      											int cliente = validarRango(0, getTotalClientes(&banco[id_pais])-1, "\tIntroduce el indice del cliente: ");
      											if(isOcupado(&banco[id_pais].clientes[cliente])==true){
      													double cuanto = doble("\tIntroduce cuanto retirarás de tú cuenta: ");
      													retirarSaldo(&banco[id_pais].clientes[cliente], cuanto);
      											}
      											else
      													printf("\n\tEl cliente %i del pais %s no tiene datos.",cliente,banco[id_pais].nombrePais);
      									}
      									else {
      											printf("\n---------------------------------------------------------------------");
      											printf("\n\t\t La estructura esta toda vacia.");
      											printf("\n---------------------------------------------------------------------");
      										}
      										break;
      							case 8:
      								printf("\n--- Opción buscar id vacio en toda estructura ---");
      								con=0;
      									 for(i=0;i<TM;i++) {
      										 if(isTodoOcupado(&banco[i])==true) con++;
      									 }
      							 if(i!=con){
      								 		int j;
      										i=0;
      										while(i<TM){
      												printf("\n---------------------------------------------------------------------");
      											for(j=0;j< getTotalClientes(&banco[i]);j++){
      										if(isOcupado(&banco[i].clientes[j])==false){
      												printf("\n\tEl pais [ %i ] %s tiene el cliente [ %i ] vacio.",i,banco[i].nombrePais,j);
      											}}
      										printf("\n---------------------------------------------------------------------");
      									i++;}
      								}
      								else {
      										printf("\n---------------------------------------------------------------------");
      										printf("\n\t\t La estructura esta completamente llena.");
      										printf("\n---------------------------------------------------------------------");
      								}

      									break;
      							case 9:
      							printf("\n --- Opción esta llena toda la estructura ---");
      							con=0;
      								 for(i=0;i<TM;i++) {
      									 if(isTodoOcupado(&banco[i])==true) con++;
      								 }
      						 if(i==con){
      										printf("\n---------------------------------------------------------------------");
      										printf("\n\ttrue, la estructura esta toda llena.");
      										printf("\n---------------------------------------------------------------------");
      								}
      								else {
      										printf("\n---------------------------------------------------------------------");
      										printf("\n\tfalse, la estructura no esta toda llena.");
      										printf("\n---------------------------------------------------------------------");
      								}
      									break;
      							case 10:
      									printf("\n --- Opción esta vacia toda la estructura ---");
      									con=0;
      											for(i=0;i<TM;i++) {
      												if(isTodoDesocupado(&banco[i])==false) con++;
      											}
      									if(con>0){
      									printf("\n---------------------------------------------------------------------");
      									 printf("\n\tfalse, la estructura no esta vacia.");
      									 printf("\n---------------------------------------------------------------------");
      								 }
      								 else {
      										 printf("\n---------------------------------------------------------------------");
      										 printf("\n\ttrue, la estructura esta toda vacia.");
      										 printf("\n---------------------------------------------------------------------");
      								 }
      									break;
      						  case 11:
      									printf("\n--- Opción imprimir nombre de paises ---");
      									printf("\n---------------------------------------------------------------------");
      									printf("\n\tLos paises son: ");
      									int i;
      									for( i = 0; i < TM; i++){
      											imprimirPaises(i,&banco[i]);
      									}
      									printf("\n---------------------------------------------------------------------");
      									break;
      							case 13:
      									printf("\n--- Opción actualizar ---");
      									con=0;
      											for(i=0;i<TM;i++) {
      												if(isTodoDesocupado(&banco[i])==false) con++;
      											}
      									if(con>0){
      											 char nombre_pais[100];
      											 int id_pais=-1;
      											 bool se_encuentra=true;
      															 while(se_encuentra==true){
      																 pedirNombrePais(nombre_pais,"\tIntroduce el nombre del pais: ");
      															 for(i = 0; i <TM; i++){
      																	 if(strcmp(banco[i].nombrePais,nombre_pais)==0){id_pais=i;}
      														 }
      														 if(id_pais==-1) {se_encuentra = true; printf("\n---Pais no encontrado, vuelve a intentar---");}
      														 else se_encuentra = false;
      													 }
      										int cliente = validarRango(0, getTotalClientes(&banco[id_pais])-1, "\tIntroduce el indice del cliente: ");
      										if(isOcupado(&banco[id_pais].clientes[cliente])==true){
      													instrucciones_actualizar();
      													char nombre[100];
      													eleccion = entero(" Elija una opción: ");
      													while(eleccion != SALIR_ACTUALIZAR) {
      															switch (eleccion) {
      																	case 1:
      																			printf("\n --- Opción actualizar nombre ---");
      																			cadena(nombre,"Introduce nuevo nombre del cliente: ");
      																			cambiarNombre(&banco[id_pais].clientes[cliente],nombre);
      																			printf("\n-----------------------------------------------------------------");
      																			imprimirCliente(&banco[id_pais].clientes[cliente],cliente);
      																			printf("\n-----------------------------------------------------------------");
      																			break;
      																	case 2:
      																			printf("\n --- Opción actualizar sexo ---");
      																			cambiarSexo(&banco[id_pais].clientes[cliente], caracter("Introduce el nuevo Sexo(M|F): "));
      																			printf("\n-----------------------------------------------------------------");
      																			imprimirCliente(&banco[id_pais].clientes[cliente],cliente);
      																			printf("\n-----------------------------------------------------------------");
      																			break;
      																	case 0:
      																			 instrucciones_actualizar();
      																			break;
      																	default:
      																			printf("\n******************************************");
      																			printf("\n --- Opción Desconocida ---");
      																			printf("\n******************************************");
      																			instrucciones_actualizar();
      															}
      															eleccion = entero(" Elija una opción: ");
      													}
      													instrucciones();
      											}
      											else
      													printf("\n\tEl cliente %i del pais %s no tiene datos.",cliente,banco[id_pais].nombrePais);
      									}
      									else {
      											printf("\n---------------------------------------------------------------------");
      											printf("\n\t\t La estructura esta toda vacia.");
      											printf("\n---------------------------------------------------------------------");
      									}
      									break;
      										break;
      							case 12:
      										printf("\n--- Opción mostrar longitudes ---");
      										printf("\n---------------------------------------------------------------------");
      										i=0;
      										while(i<TM)  {
      											 mostrarLongitudes(&banco[i]);
      											 i++;
      										}
      										printf("\n---------------------------------------------------------------------");
      									break;
      							case 0:
      									 instrucciones();
      									 break;
      							default:
      							printf("\n******************************************");
      								printf("\n --- Opción Desconocida ---");
      								printf("\n******************************************");
      								instrucciones();
      						}
      						eleccion = entero(" \nElija una opción: ");
      				}
      				 printf("\n--- Fin de la Ejecución del Sistema ---");
      	saltoLinea();
      }
