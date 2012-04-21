from socket import *
import threading

class ScanPort(threading.Thread):
	def __init__(self,target,port):
		threading.Thread.__init__(self)
		self.target=target
		self.port=port
		
	def run(self):
		s=socket(AF_INET,SOCK_STREAM)
		result=s.connect_ex((self.target,self.port))
		if(result==0):
			print 'Port %d :OPEN with address : %s' %(self.port,s.getsockname())
		s.close()

def scan(target):
	print "Scanning ",target
	targetIP=gethostbyname(target)
	print 'Target IP is : %s' %(targetIP)
	for i in range(0,65535):
		ScanPort(targetIP,i).start()
		
scan(target=raw_input('Enter hostname/ dest^n IP:'))
