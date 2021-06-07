#include "control_archivo.h"

int main(int argc, char *argv[]){
    printf("\n----------------------------------------------------------------------------");
    printf("\n\t::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\t::::::::::: MANEJO DE FICHEROS :::::::::::");
    printf("\n\t::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n-->Nombre ejecutable  [Argumento 1]=  %s",argv[0]);
    printf("\n-->Archivo de entrada [Argumento 2]=  %s",argv[1]);
    printf("\n-->Archivo de Salida  [Argumento 3]=  %s",argv[2]);    
    char *Entrada=argv[1];
    char *Salida=argv[2];
    struct lista *LISTA=NULL;
    char palabras[TAM_NOMBRE];
    int i=0;    
    FILE *archivo_Entrada=NULL;
    FILE *archivo_Salida=NULL;

    printf("\n\nComprobando si existe el archivo de entrada %s",Entrada);
    if (existe_archivo(Entrada)){
        printf("\n--->> Existe el archivo de entrada <----");
        archivo_Entrada=abrir_Archivo_lectura_escritura(Entrada);
    }
    else{
         printf("\n--->> NO Existe el archivo de entrada <----");
         printf("\n--->> Finalizando....\n");
        return 0;
    }

    printf("\nDatos en el archivo [%s] que se almacenan en una lista linkeada",argv[1]);
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    while(!feof(archivo_Entrada)){
        fscanf(archivo_Entrada,"%s",palabras);
        printf("\n ->Palabra[%d] = %s",i+1,palabras);
        LISTA=agregar_elemento(LISTA,palabras);
        i++;
    }
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    if(i>0){
    ordenar_lista(LISTA);
////Abriendo o creando el archivo de salida
    printf("\n\nComprobando si existe el archivo de salida %s",Salida);
    if (existe_archivo(Salida)){
        printf("\n--->> Existe el archivo de Salida <----");
        archivo_Entrada=abrir_Archivo_lectura_escritura(Salida);
    }
    else{
        printf("\n--->> NO Existe el archivo de entrada <----");
        printf("\n Creando archivo [%s]",Salida);
        crear_archivo(Salida);
    }
    archivo_Salida=abrir_Archivo_lectura_escritura(Salida);
    for(int j=1;j<=i;j++){
        fprintf(archivo_Salida,"%s\n",obtener_elemento(LISTA,j));
    }
    printf("\nNOTA: Los datos ordenados se han escrito en el archivo [%s]\n",Salida);

    cerrar_archivo(archivo_Entrada,Entrada);
    cerrar_archivo(archivo_Salida,Salida);
    free(LISTA);
    }
    else {
        printf("\nEl archivo [%s] no tiene ningun dato",Entrada);
        printf("\nNo hay nada que hacer, finalizando...");
        cerrar_archivo(archivo_Entrada,Entrada);
        return 0;
    }
    printf("\n\t<::::::::::::::::::::::::::::::::::::::::::>");
    printf("\n\t<:::::::::: EJECUCION FINALIZADA ::::::::::>");
    printf("\n\t<::::::::::::::::::::::::::::::::::::::::::>");
    printf("\n----------------------------------------------------------------------------\n");
    return 0;
}
