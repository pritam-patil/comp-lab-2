/* 	Do not get confused //gsoap with comment..It's not..it is a directive used for setting properties for
	web service 
		The server is running at 8000 port . If you want to change, change in this file and the <calc.cpp> i.e. server file	
*/


//gsoap ns service name: calc
//gsoap ns schema namespace: urn:calc 
//gsoap ns service location: localhost:8000

int ns__add(double a, double b, double *result);  /*see last two lines for explain^n*/
int ns__sub(double a, double b, double *result);  
int ns__mul(double a, double b, double *result);  
int ns__div(double a, double b, double *result);  

/*The gSOAP tools use a special convention for identifier names that are part of a namespace: a namespace prefix (ns in this case) followed by a double underscore __. This convention is used to resolve namespaces and to avoid name clashes*/
