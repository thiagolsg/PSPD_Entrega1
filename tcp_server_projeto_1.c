#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <float.h>

#define SIZE 500

#define PORT 8080

double compara_maior(double *array)
{
	// static maior_menor  result;

	double maior = DBL_MIN;
	double menor = DBL_MAX;
	for(int i = 0;i<500;i++){
		if(array[i] < menor) menor = array[i];
		if(array[i] > maior) maior = array[i];
}

	// result.maior_menor[0] = menor;
	// result.maior_menor[1] = maior;

	return maior;
};

double compara_menor(double *array)
{
	// static maior_menor  result;

	double maior = DBL_MIN;
	double menor = DBL_MAX;
	for(int i = 0;i<SIZE;i++){
		if(array[i] < menor) menor = array[i];
		if(array[i] > maior) maior = array[i];
}

	// result.maior_menor[0] = menor;
	// result.maior_menor[1] = maior;

	return menor;
};


int main(int argc, char* argv[]) {
	int socket_desc, client_sock, c, read_size;
	struct sockaddr_in server, client;
    double result[2];
    double array[SIZE], i = 0;

	
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		printf("Nao foi possivel criar socket");
	}
	puts("Socket criado");

	// Configura a estrutura do socket
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	// Faz o bind do socket
	if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {

		// print the error arg.array
		perror("bind falhou. Error");
		return 1;
	}
	puts("bind feito");

	// Escuta o socket por até 3 conexoes
	listen(socket_desc, 3);

	puts("Esperando conexoes");
	c = sizeof(struct sockaddr_in);

	// Aceita conexao com o cliente
	client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);

	// Verifica se aceitou conexao com cliente
	if (client_sock < 0) {
		perror("accept failed");
		return 1;
	}

	puts("Conexao aceita");

	// Recebe mensagem do cliente
	while ((read_size = recv(client_sock, &array, SIZE * sizeof(float), 0)) > 0) {

		result[0] = compara_maior(array);
        result[1] = compara_menor(array);



		write(client_sock, &result, 2 * sizeof(float));
	}

	// se cliente não mandou nada desconecta ou se houver erro avisa
	if (read_size == 0) {
		puts("Cliente desconectado");
	}
	else if (read_size == -1) {
		perror("recv falhou");
	}

	return 0;
}




// // pega maximo valor do vetor
// float max (float *v) {
// 	int i;
// 	float n;
// 	n = v[0];
// 	for(i = 1; i < SIZE; i++) {
// 		if(v[i] > n)
// 			n = v[i];
// 	}
// 	return n;
// }

// // pega minimo valor do vetor
// float min (float *v) {
// 	int i;
// 	float n;
// 	n = v[0];
// 	for(i = 1; i < SIZE; i++) {
// 		if(v[i] < n)
// 			n = v[i];
// 	}
// 	return n;
// }

