#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <math.h> 
#include <time.h>

#define SIZE 500
#define IP "127.0.0.1"
#define PORT 8080

 

int main(int argc, char* argv[]) {
	int sock;
	struct sockaddr_in server;
	double result[2];
    double array[SIZE];


	
    srand(time(0));
	for(int i=0;i<SIZE;i++) array[i] = sqrt(pow((i+1) - ((rand()%500)/2), 2));


	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		printf("Nao foi possivel criar o socket");
	}
	puts("Socket criado");

	// Configuração do Socket
	server.sin_addr.s_addr = inet_addr(IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	// Conectar ao servidor remoto
	if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
		perror("connexao falhou. Error");
		return 1;
	}

	puts("Conectado\n");

	// Enviando vetor para o servidor
	if (send(sock, &result, SIZE * sizeof(float), 0) < 0) {
		puts("Envio falhado");
		return 1;
	}

	// Recebendo resposta do servidor
	if (recv(sock, &result, 2 * sizeof(float), 0) < 0) {
		puts("recv falhou");
		return 0;
	}

	//Escrevendo resposta do servidor
	puts("Resposta do servidor :\n");
    printf("maior = %lf \n",result[0]);
    printf("menor = %lf \n",result[1]);
	
	close(sock);
	return 0;
}

