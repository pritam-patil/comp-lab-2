/* soapClient.cpp
   Generated by gSOAP 2.8.3 from calc.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.3 2012-04-24 19:55:32 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result)
{	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse *soap_tmp_ns__addResponse;
	if (!soap_endpoint)
		soap_endpoint = "localhost:8000";
	soap->encodingStyle = NULL;
	soap_tmp_ns__add.a = a;
	soap_tmp_ns__add.b = b;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__add(soap, &soap_tmp_ns__add);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__addResponse = soap_get_ns__addResponse(soap, NULL, "ns:addResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__addResponse->result)
		*result = *soap_tmp_ns__addResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__sub(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result)
{	struct ns__sub soap_tmp_ns__sub;
	struct ns__subResponse *soap_tmp_ns__subResponse;
	if (!soap_endpoint)
		soap_endpoint = "localhost:8000";
	soap->encodingStyle = NULL;
	soap_tmp_ns__sub.a = a;
	soap_tmp_ns__sub.b = b;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__sub(soap, &soap_tmp_ns__sub);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__sub(soap, &soap_tmp_ns__sub, "ns:sub", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__sub(soap, &soap_tmp_ns__sub, "ns:sub", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__subResponse = soap_get_ns__subResponse(soap, NULL, "ns:subResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__subResponse->result)
		*result = *soap_tmp_ns__subResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__mul(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result)
{	struct ns__mul soap_tmp_ns__mul;
	struct ns__mulResponse *soap_tmp_ns__mulResponse;
	if (!soap_endpoint)
		soap_endpoint = "localhost:8000";
	soap->encodingStyle = NULL;
	soap_tmp_ns__mul.a = a;
	soap_tmp_ns__mul.b = b;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__mul(soap, &soap_tmp_ns__mul);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__mul(soap, &soap_tmp_ns__mul, "ns:mul", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__mul(soap, &soap_tmp_ns__mul, "ns:mul", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__mulResponse = soap_get_ns__mulResponse(soap, NULL, "ns:mulResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__mulResponse->result)
		*result = *soap_tmp_ns__mulResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__div(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result)
{	struct ns__div soap_tmp_ns__div;
	struct ns__divResponse *soap_tmp_ns__divResponse;
	if (!soap_endpoint)
		soap_endpoint = "localhost:8000";
	soap->encodingStyle = NULL;
	soap_tmp_ns__div.a = a;
	soap_tmp_ns__div.b = b;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__div(soap, &soap_tmp_ns__div);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__div(soap, &soap_tmp_ns__div, "ns:div", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__div(soap, &soap_tmp_ns__div, "ns:div", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__divResponse = soap_get_ns__divResponse(soap, NULL, "ns:divResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__divResponse->result)
		*result = *soap_tmp_ns__divResponse->result;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */
