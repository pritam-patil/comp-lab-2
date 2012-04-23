#include "soapcalcProxy.h"		//In this header file change the endpoint 
#include "calc.nsmap"		//namespace mapping table
#include <string.h>
#include <iostream>
using namespace std;

int main()
{ 
  calc c; /* calc SOA object */
  double n,x,y; /* result value */
  cout<<"\nThe syntax of supported operations<web services> :(Not cAse sEnsITivE)"<<endl;	
  cout<<"\tadd x y\n";	//these are the web-services used with Object <calc>
  cout<<"\tsub x y\n";
  cout<<"\tmul x y\n";
  cout<<"\tdiv x y\n";	
  cout<<"\tbye\n";
  while(1)
  {
		char op[5];
		cout<<">>> ";
		cin>>op;
		if(!strcasecmp(op,"add"))
		{
			cin>>x>>y;
			if (c.ns__add(x, y, &n) == SOAP_OK)				// SOAP call
	 		   cout <<x <<"+"<<y<<" = " << n << endl;
		}
		else if(!strcasecmp(op,"sub"))						//SOAP  call
		{
			cin>>x>>y;
			if (c.ns__sub(x, y, &n) == SOAP_OK)
	 		   cout <<x<< "-"<<y<<" = " << n << endl;
		}
		else if(!strcasecmp(op,"mul"))
		{
			cin>>x>>y;
			if (c.ns__mul(x, y, &n) == SOAP_OK)
	 		   cout <<x <<"*"<<y<<" = " << n << endl;
		}
		else if(!strcasecmp(op,"div"))
		{
			cin>>x>>y;
			if (c.ns__div(x, y, &n) == SOAP_OK)
	 		   cout <<x <<"/"<<y<<" = " << n << endl;
		}
		else if(!strcasecmp(op,"bye"))
		{
			break;
		}
	}
  	return 0;
}
