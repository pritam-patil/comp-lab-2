from socket import *

def scan(target):
	print "Scanning ",target
	targetIP=gethostbyname(target)
	print 'Target IP is : %s' %(targetIP)
	for i in range(0,65535):
		s=socket(AF_INET,SOCK_STREAM)
		result=s.connect_ex((targetIP,i))
		if(result==0):
			print 'Port %d :OPEN with address : %s' %(i,s.getsockname())
		s.close()
		
scan(target=raw_input('Enter hostname/ dest^n IP:'))
