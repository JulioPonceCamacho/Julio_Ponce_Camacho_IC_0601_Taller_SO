#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h>

#define MAX_DATA 10000
char buf_tx[] = "Soy un cliente, requiero de tus servicios";   
char buf_txt2[]="Recibido, gracias";   
char buf_rx[MAX_DATA];                     
char v1[MAX_DATA],v2[MAX_DATA], result[MAX_DATA];

void pedirNumero(char numero[]); 
 
int main(int argc, char **argv) 
{ 
    if(argc<2 || argc<3){
        printf("ERROR: Faltan los argumentos <HOST> <PUERTO>\n");
        return 0;
    }
    const char *SERVER_ADDRESS=argv[1];
    int PORT=atoi(argv[2]);
    printf("\n->Host: %s",SERVER_ADDRESS);
    printf("\n->Puerto: %d \n",PORT);
    int sockfd; 
    struct sockaddr_in servaddr; 
    
    //Creacion del socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) 
    { 
        printf("  [CLIENTE] La creacion del socket fallo...\n"); 
        return -1;  
    } 
    else
    {
        printf("  [CLIENTE] Creacion del del socket exitosa...\n"); 
    }
    
    memset(&servaddr, 0, sizeof(servaddr));

    //Asignación de la dirección ip y puerto al socket
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr( SERVER_ADDRESS ); 
    servaddr.sin_port = htons(PORT); 
  
   //intentando conectar al socket
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) 
    { 
        printf("  Conexion con el servidor fallida...\n");  
        return -1;
    } 
    printf("\n\t----------------------- Conexion establecida ------------------------\n");   
    //Envio y recibo de datos
    write(sockfd, buf_tx, sizeof(buf_tx));
    read(sockfd, buf_rx, sizeof(buf_rx)); 
    printf("  [CLIENTE]Recibio: %s \n", buf_rx);
    memset(buf_rx,0,strlen(buf_rx));   

    pedirNumero(v1);
    //Manda el supernumero 1
    write(sockfd, v1, sizeof(v1));
    //Manda el supernumero 2 
    pedirNumero(v2);
    write(sockfd, v2, sizeof(v2));        

    //Recibe el resultado de la suma
    read(sockfd, result, sizeof(result)); 
    printf("\n  [CLIENTE]Recibio resultado= %s  (Longitud %d digitos)\n", result,strlen(result));

    read(sockfd, buf_rx, sizeof(buf_rx)); //6
    printf("\n  [CLIENTE]Recibio: %s \n", buf_rx);
    memset(buf_rx,0,strlen(buf_rx));

    write(sockfd, buf_txt2, strlen(buf_txt2)); 
    //Cierra el socket
    close(sockfd); 
    printf("\n\t---------------------------------------------------------------------\n");  
} 


void pedirNumero(char numero[]){
    printf("\n Ingresar valor: ");
    scanf("%s",numero);
}