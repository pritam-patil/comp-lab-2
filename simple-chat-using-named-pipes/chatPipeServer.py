#!/usr/bin/python
import os

NP1 = "./p1"	#for reading
NP2 = "./p2"	#for writing

try:
    os.mkfifo(NP1)
    os.mkfifo(NP2)
except OSError:
    pass

msg=''
while msg!='bye':
	rp = open(NP1, 'r')
	msg=rp.read()
	print 'Client says : %s' %(msg)
	rp.close()
	wp = open(NP2, 'w')
	wp.write(raw_input('>>'))		
	wp.close()
