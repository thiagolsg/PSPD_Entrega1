/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "projeto_1.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

maior_menor *
compara_43(vetor *argp, CLIENT *clnt)
{
	static maior_menor clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, compara,
		(xdrproc_t) xdr_vetor, (caddr_t) argp,
		(xdrproc_t) xdr_maior_menor, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
