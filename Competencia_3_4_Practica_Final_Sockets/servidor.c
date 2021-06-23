#include <unistd.h>  
//Manejo de sockets y red
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <errno.h> //Manejo de errores
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MAX_CLIENT     5    //Maximo de clientes a la espera de conexion.
#define MAX_DATA 10000
                           
char v1[MAX_DATA],v2[MAX_DATA],result[MAX_DATA];
 char buff_rx[MAX_DATA];
void sumaNumero(char v1[], char v2[], char res[]);
void limpiarVariables(char v1[],char v2[], char v3[]);

int main(int argc, char **argv) 
{ 
    if(argc<2 || argc<3){
        printf("ERROR: Faltan los argumentos <HOST> <PUERTO>\n");
        return 0;
    }
    const char *SERV_HOST_ADDR=argv[1];
    int SERV_PORT=atoi(argv[2]);
    printf("\n->Host: %s",SERV_HOST_ADDR);
    printf("\n->Puerto: %d \n",SERV_PORT);
    int sockfd, connfd ;  //Descriptores del listen del socket y la coneccion del socket
    unsigned int len;     //Longitud de dirección address del cliente
    struct sockaddr_in server, cliente; 
    
    int  len_rx, len_tx = 0;      //Almacena longitud de mensajes de envio y recibo
    char buff_tx[MAX_DATA] = "Hola soy el servidor, digita los numero que quieras sumar";
    char adios[MAX_DATA]="Hasta la proxima!";
      /* buffers for reception  */
    
     
    //Creacion del socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        fprintf(stderr, "[SERVER-error]: Creación del socket fallida. %d: %s \n", errno, strerror( errno ));
        return -1;
    } 
    else{
        printf("[SERVER]: Creacion del socket exitosa..\n"); 
    }
    
    //Limpia la estructura, borrando la basura
    memset(&server, 0, sizeof(server));
  
    //Asigna la direccion IP y el Puerto
    server.sin_family      = AF_INET; 
    server.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR); 
    server.sin_port        = htons(SERV_PORT); 
    
    
    //Asignando direccion IP y puerto al socket
    if ((bind(sockfd, (struct sockaddr *)&server, sizeof(server))) != 0) 
    { 
        fprintf(stderr, "[SERVER-error]: Proceso bind erroneo. %d: %s \n", errno, strerror( errno ));
        return -1;
    } 
    else
    {
        printf("[SERVER]: Proceso bind correcto \n");
    }
  
    //Establece el estado de eschucha del socket
    if ((listen(sockfd, MAX_CLIENT)) != 0) 
    { 
        fprintf(stderr, "[SERVER-error]: Socket en modo escucha erroneo. %d: %s \n", errno, strerror( errno ));
        return -1;
    } 
    else
    {
        printf("[SERVER]: Escuchando en el puerto %d \n\n", ntohs(server.sin_port) ); 
    }
    len = sizeof(cliente); 
      while(1) //Espera la conexion de un socket ciclicamente.
      {
        connfd = accept(sockfd, (struct sockaddr *)&cliente, &len); 
        if (connfd < 0) 
        { 
            fprintf(stderr, "[SERVER-error]: Conexion rechazada. %d: %s \n", errno, strerror( errno ));
            return -1;
        } 
        else
        { 
        printf("\n\t------------------------- Cliente conectado -------------------------\n");         
        write(connfd, buff_tx, strlen(buff_tx));
        int ok=0;      
            while(1) //Lee informacion del cliente hasta que este se cierre
            {  
                //Lee el mensaje del cliente y lo almacena en la variable
                len_rx = read(connfd, buff_rx, sizeof(buff_rx));  
                
                if(len_rx == 0) //Si la longitud del mensaje es 0, se cierra el socket del cliente.
                {
                    printf("[SERVER]: Socket del cliente cerrado \n\n");
                    close(connfd);
                    break; 
                }
                else if(len_rx == -1)
                {
                    fprintf(stderr, "[SERVER-error]: El servidor no puede leer. %d: %s \n", errno, strerror( errno ));
                }
                else
                {
                    ok++;
                    
                    if(ok==2){
                        strcpy(v1,buff_rx);
                        printf("[SERVER] Valor 1 recibido= %s (Longitud: %d digitos) \n", v1,strlen(v1));
                        memset(buff_rx,0,strlen(buff_rx));
                    }
                    else if (ok==3){
                        strcpy(v2,buff_rx);
                        memset(buff_rx,0,strlen(buff_rx));
                        printf("[SERVER] Valor 2 recibido= %s (Longitud: %d digitos)\n", v2,strlen(v2));
			if (strlen(v1)>=strlen(v2))sumaNumero(v1,v2,result);
			else sumaNumero(v2,v1,result);
                        write(connfd, result, sizeof(result));
                        printf("\n[SERVER]\t----> Resultado enviado al cliente <-------\n\n");
                        write(connfd, adios, sizeof(adios));
                        limpiarVariables(v1,v2,result);
                    }
                    else  { 
                    printf("[SERVER] Recibio :  %s \n", buff_rx); 
                    memset(buff_rx,0,strlen(buff_rx)); len_rx=0; 
                    }     
                }
                      
            } 
        printf("\n\t---------------------------------------------------------------------\n");  
        }                      
    }    
} 
void sumaNumero(char v1[], char v2[], char res[]){
    int A,B,C,len,m,n;
    m=strlen(v1);
    n=strlen(v2);

    //Comparacion de longitud de los 2 arreglos
    if(m>n) len=m;
    else len=n;

    int AUX1[m],AUX2[n],AUX3[len];    

    //Convertimos el los valores almacenados en la cadena restandoles '0' (Tiene valor en ASCII)
    for(A=0; A<m; A++) AUX1[A]=v1[A]-'0';
    for(B=0; B<n; B++) AUX2[B]=v2[B]-'0';

    B=n-1; C=len-1;
    for(A=m-1; A>=0 && B>=0; A--){ AUX3[C] = AUX1[A] + AUX2[B]; B--; C--;  }
    for( ;A>=0; A--,C--)AUX3[C] = AUX1[A];
    for( ;A>=0; B--,C--)AUX3[C] = AUX2[B];

    //Manejando los decimos
    for( C=len-1; C>0; C--){
        if( AUX3[C] >9 ){
            AUX3[C] = AUX3[C]%10;
            AUX3[C-1]+=1; 
         }
    }
    A=0;
    for(C=0; C<len; C++){
        if(AUX3[C]>9){
           res[A]='1';
           A++;
           res[A]=(AUX3[C]-10)+'0'; 
        }else res[A]=AUX3[C]+'0';
        A++;
    }
    
}

void limpiarVariables(char v1[],char v2[], char v3[]){
    //Limpia los parametros para eliminar la basura.
    memset(v1,0,strlen(v1));
    memset(v2,0,strlen(v2));
    memset(v3,0,strlen(v3));
}
