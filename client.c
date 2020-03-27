/*
    Project: Client.c
    Developed by Agariy

    typedef struct SOCKET{
        short si_family
        unsigned short si_port
        struct in_addr
    };

*/

#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>          
#define SA struct sockaddr

int main(){

    
    int sock; // declaration of structure SOCKET
    struct sockaddr_in si; 
    char data[] = ""; //recv data
    FILE *fp;
    char p[] = "";

    /*
        Attribute configuration input
        of structure sockaddr_in

    */
    si.sin_family = AF_INET;
    si.sin_addr.s_addr = inet_addr("127.0.0.1");
    si.sin_port = htons(1337);

    sock = socket(AF_INET, SOCK_STREAM, 0); //af, type, protocole 

    // if response socket is INVALID_SOCKET so printf("sock failed") and return error -1
    if(sock == -1){
        printf("Error socket\n");
        return -1;
    }

    printf("Socket created\n");

    //create connection to server
    if (connect(sock, (SA*)&si, sizeof(si)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    while(1){
        recv(sock, &data, sizeof(data), 0);
        printf("MSG: ");
        scanf("%s", &p);
        send(sock, p, sizeof(p), 0);
        printf("Server: %s", data);    
        
        
        
    }
    
    
    

    

    return 0;
}