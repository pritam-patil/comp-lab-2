/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _SEARCH_H_RPCGEN
#define _SEARCH_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXSIZE 100

struct File {
	char name[MAXSIZE];
};
typedef struct File File;


#define PROG_SEARCH 4148
#define VER_SEARCH 1

#if defined(__STDC__) || defined(__cplusplus)
#define searchFile 1
extern  double * searchfile_1(File *, CLIENT *);
extern  double * searchfile_1_svc(File *, struct svc_req *);
extern int prog_search_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define searchFile 1
extern  double * searchfile_1();
extern  double * searchfile_1_svc();
extern int prog_search_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_File (XDR *, File*);
extern  bool_t xdr_File (XDR *, File*);

#else /* K&R C */
extern bool_t xdr_File ();
extern bool_t xdr_File ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_SEARCH_H_RPCGEN */
