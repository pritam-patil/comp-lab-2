/*
	Web service is like IPC but it's used between processes on single machine. A web service is used for comm. between diff. app's
may be running on diff types of machines. Because it is based on XML based message passing.
	A client sends a message in SOAP format, server analyses it and send response in another SOAP message, which is then analysed by client.
	So, where master and slaves are used */

#include "soapH.h" /* get the gSOAP-generated definitions */
#include "calc.nsmap" /* get the gSOAP-generated namespace bindings */
#include <math.h>  
int main(int argc, char **argv)  
{ 
	int m, s;
	struct soap *soap = soap_new();//Allocates, initializes, and returns a pointer to a runtime context
	m = soap_bind(soap, NULL, 8000, 100); /* bind to the port to listen SOAP requests from slaves */
	printf("Offering on port 8000 services of Calculator:\n");
	while(1)
	{
		s = soap_accept(soap);		//accept SOAP request
		soap_serve(soap);			//server the request using functions in given namespace
		soap_end(soap);				//remove temporary data
	}
	soap_done(soap);//Reset, close communications, and remove callbacks
	soap_free(soap);
	return 0;
} 
int ns__add(struct soap *soap, double a, double b, double *result)  
{ 
	*result = a + b;  
	return SOAP_OK;  
}  
int ns__sub(struct soap *soap, double a, double b, double *result)  
{ 
	*result = a - b;  
	return SOAP_OK;  
}  
int ns__mul(struct soap *soap, double a, double b, double *result)  
{ 
	*result = a * b;  
	return SOAP_OK;  
}  
int ns__div(struct soap *soap, double a, double b, double *result)  
{ 
	if(b)*result = a/b;  
	return SOAP_OK;  
}  
