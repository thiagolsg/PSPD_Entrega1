#include "projeto_1.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

void
projeto_1_43(char *host)
{
	CLIENT *clnt;
	maior_menor  *result_1;
	vetor  compara_43_arg;

	srand(time(0));
	for(int i=0;i<500;i++) compara_43_arg.array[i] = sqrt(pow((i+1) - ((rand()%500000)/2), 2));

#ifndef	DEBUG
	clnt = clnt_create (host, projeto_1, projeto_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = compara_43(&compara_43_arg, clnt);
	if (result_1 == (maior_menor *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	double a = result_1->maior_menor[0];
	double b = result_1->maior_menor[1];
	printf("menor = %lf\n",a);
	printf("maior = %lf\n",b);
//	printf("menor = %d, maior =%d/n",**result_1->maior_menor[0],**result_1->maior_menor[1]);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	projeto_1_43 (host);
exit (0);
}
