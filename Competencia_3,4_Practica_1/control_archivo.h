#ifndef __CONTROL_ARCHIVO_H
#define __CONTROL_ARCHIVO_H

    #include "control_lista.h"
    
    int existe_archivo(char *nombre_arch);
    FILE *abrir_Archivo_lectura_escritura(char *nombre_arch);
    void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch);
    int crear_archivo(char *nombre_arch);


#endif