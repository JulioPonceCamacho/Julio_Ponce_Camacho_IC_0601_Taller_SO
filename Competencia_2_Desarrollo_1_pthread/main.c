#include "scheduler.h"

//Funciones para crear threads
void thread_reproducir_musica(void);
void thread_abrir_youtube(void);
void thread_escribir_texto_word(void);
void thread_descargar_archivo(void);
void thread_subiendo_archivo(void);
void thread_compilando_programa(void);
void thread_ejecutando_programa(void);
void thread_usando_terminal(void);

//Acciones que realizan los threads
void *accion_reproducir_musica(void *data);
void *accion_abrir_youtube(void *data);
void *accion_escribir_texto_word(void *data);
void *accion_descargar_archivo(void *data);
void *accion_subiendo_archivo(void *data);
void *accion_compilando_programa(void *data);
void *accion_ejecutando_programa(void *data);
void *accion_usando_terminal(void *data);


int main(int argc, char const *argv[]){
  printf("\t\t\t\t\t\t|||Creando de procesos |||\n\n");
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", thread_reproducir_musica, ACTIVO); //<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", thread_abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", thread_escribir_texto_word, ACTIVO);	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", thread_descargar_archivo, ACTIVO);//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", thread_subiendo_archivo, ACTIVO);
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", thread_compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", thread_ejecutando_programa, ACTIVO);	//<--
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", thread_usando_terminal, ACTIVO);//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", thread_usando_terminal, NO_ACTIVO);//<--

    printf("\t\t\t\t\t\t|||Agregando procesos |||\n\n");
	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

    printf("\n\t\t\t\t\t\t|||Ejecutando procesos |||\n\n");
	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}

//Creacion de los threads
void thread_reproducir_musica(void){
    pthread_t thread_reproducir;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_reproducir,NULL,accion_reproducir_musica,">>>| Reproduciendo musica |<<<")) {
    printf("<<<<<Error al crear el hilo para reproducir musica>>>");}
    if(0 != pthread_join(thread_reproducir,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo reproducir musica>>>");}
}
void thread_abrir_youtube(void){
    pthread_t thread_youtube;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_youtube,NULL,accion_abrir_youtube,">>>| Abriendo Youtube |<<<")) {
    printf("<<<<<Error al crear el hilo para abrir youtube>>>");}
    if(0 != pthread_join(thread_youtube,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo abrir youtube>>>");}

}
void thread_escribir_texto_word(void){
    pthread_t thread_escribir;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_escribir,NULL,accion_escribir_texto_word,">>>| Escribiendo en archivo de texto |<<<")) {
    printf("<<<<<Error al crear el hilo para escribir en el word>>>");}
    if(0 != pthread_join(thread_escribir,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo escribir texto>>>");}

}
void thread_descargar_archivo(void){
     pthread_t thread_descargar;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_descargar,NULL,accion_descargar_archivo,">>>| Descargando archivo |<<<")) {
    printf("<<<<<Error al crear el hilo para descargar el archivo>>>");}
    if(0 != pthread_join(thread_descargar,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo  descargar archivo>>>");}

}
void thread_subiendo_archivo(void){
    pthread_t thread_subir;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_subir,NULL,accion_subiendo_archivo,">>>| Subiendo Archivo |<<<")) {
    printf("<<<<<Error al crear el hilo para subir el archivo>>>");}
    if(0 != pthread_join(thread_subir,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo subir archivo>>>");}

}
void thread_compilando_programa(void){
    pthread_t thread_compilar;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_compilar,NULL,accion_compilando_programa,">>>| Compilando programa |<<<")) {
    printf("<<<<<Error al crear el hilo de compilación>>>");}
    if(0 != pthread_join(thread_compilar,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo compilar programa>>>");}

}
void thread_ejecutando_programa(void){
    pthread_t thread_ejecutar;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_ejecutar,NULL,accion_ejecutando_programa,">>>| Ejecutando programa |<<<")) {
    printf("<<<<<Error al crear el hilo para ejecutar el programa>>>");}
    if(0 !=pthread_join(thread_ejecutar,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo ejecutar programa>>>");}
}
void thread_usando_terminal(void){
    pthread_t thread_terminal;
    //Creacion del hilo, si existe algun problema en su creacion mostrara el mensaje de error 
    if(0 != pthread_create(&thread_terminal,NULL,accion_usando_terminal,">>>| Usando terminal |<<<")) {
    printf("<<<<<Error al crear el hilo para usar la terminal>>>");}
    if(0 != pthread_join(thread_terminal,NULL)) {
    printf("<<<<<Error en la funcion pthread_join para el hilo usar la terminal>>>");}
}


//Instrucciones que realizan los threads
void *accion_reproducir_musica(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n",texto);
    printf("\t\t\tReproduciendo pista1.m4a");
    for(int cont=0 ;cont<50;cont++){
        printf(".");
        }
     printf("\n\n\t\t\t\t\t\tFin de la reproduccion\n");
     pthread_exit(NULL);
}

void *accion_abrir_youtube(void *data){
    char *texto= (char *) data;
     printf("\t\t\t\t\t%s\n\n",texto);
     printf("\t\t\t Recibiendo información de la dirección www.youtube.com");
    for(int cont=0 ;cont<50;cont++){
        printf(".");
        }
     printf("\n\n\t\t\t\t\t\tYotube completamente listo...");
     pthread_exit(NULL);
}

void *accion_escribir_texto_word(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n",texto);
    printf("\n\t\t\tEscribiendo");
    for(int cont=0 ;cont<50;cont++){
        printf(".");
        }
    printf("\n\n\t\t\t\t\t\tEscritura finalizada...\n");
    pthread_exit(NULL);
}

void *accion_descargar_archivo(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n",texto);
    printf("\t\t\t[");
    for(int cont=0;cont<=100;cont++){
        if(cont%10==0) {printf("%%[%i] ",cont);}
    }
    printf("]");
    printf("\n\n\t\t\t\t\t\tArchivo descargado. \n");
    pthread_exit(NULL);	
}

void *accion_subiendo_archivo(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n",texto);
     printf(" \t\t\t[");
        for(int cont=0;cont<=100;cont++){
            if(cont%10==0) {printf("%%[%i] ",cont);}
        }
     printf("]");
     printf("\n\n\t\t\t\t\t\tArchivo subido. \n");
     pthread_exit(NULL);
}

void *accion_compilando_programa(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n",texto);
    printf("\t\t\tCompilando application.c");
    for(int cont=0 ;cont<50;cont++){
        printf(".");
        }
   printf("\n\n\t\t\t\t\t\tPrograma compilado...\n");
   pthread_exit(NULL);
}

void *accion_ejecutando_programa(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n",texto);
    printf("\t\t\tEjecutando");
    for(int cont=0 ;cont<50;cont++){
        printf(".");
        }
    printf("\n\n\t\t\t\t\t\tEjecución Finalizada...\n");
    pthread_exit(NULL);
}

void *accion_usando_terminal(void *data){
    char *texto= (char *) data;
    printf("\t\t\t\t\t%s\n\n\t\t\t",texto);
    printf("En uso");
    for(int cont=0 ;cont<50;cont++){
        printf(".");
        }
     printf("\n\n\t\t\t\t\t\tTerminal Cerrada...\n");
     pthread_exit(NULL);
}
