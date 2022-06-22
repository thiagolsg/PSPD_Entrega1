#include "projeto_1.h"
#include <float.h>
maior_menor *
compara_43_svc(vetor *argp, struct svc_req *rqstp)
{
	static maior_menor  result;

	double maior = DBL_MIN;
	double menor = DBL_MAX;
	for(int i = 0;i<500;i++){
		if(argp->array[i] < menor) menor = argp->array[i];
		if(argp->array[i] > maior) maior = argp->array[i];
}

	result.maior_menor[0] = menor;
	result.maior_menor[1] = maior;

	return &result;
}