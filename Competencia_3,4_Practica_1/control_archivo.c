#include "control_archivo.h"

int existe_archivo(char *nombre_arch){
	FILE *ptrArchivo;
	int existe = 0;
	// Con r abre un archivo para lectura.
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo != NULL ){
		existe = 1;
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return existe;
}

void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
	fclose(ptrArchivo);
	printf("\n--->> Archivo [%s]  Cerrado Correctamente <<----", nombre_arch);
}

FILE *abrir_Archivo_lectura_escritura(char *nombre_arch){
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "r+");
	if( ptrArchivo == NULL ){
		// con r+ Abre un archivo para actualización (lectura y escritura).
		printf("\n->> El archivo [ %s ] NO pudo abrirse (uso de r+). <<-", nombre_arch);
	}	
	else{
		printf("\n->> Archivo [ %s ] Abierto (uso de r+). <<-", nombre_arch);
	}
	return ptrArchivo;
}
int crear_archivo(char *nombre_arch){
	int creado = 0;
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "w");
	if( ptrArchivo == NULL ){
		// con w crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.
		printf("\n->> El archivo [ %s ] no pudo crearse (abrir; uso de w). <<-", nombre_arch);
	}	
	else{
		creado = 1;
		printf("\n-->> Archivo [ %s ] Creado (abierto; uso de w). <<--", nombre_arch);
		cerrar_archivo(ptrArchivo, nombre_arch);
	}
	return creado;
}