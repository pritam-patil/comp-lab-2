/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "search.h"

bool_t
xdr_File (XDR *xdrs, File *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->name, MAXSIZE,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}