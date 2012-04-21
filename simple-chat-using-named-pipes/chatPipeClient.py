#!/usr/bin/python
import os

NP1 = "./p1"	#for writing
NP2 = "./p2"	#for reading

msg=''
while msg!='bye':
	wp = open(NP1, 'w')
	msg=raw_input('>>')
	wp.write(msg)
	wp.close()
	rp = open(NP2, 'r')
	print 'Server says: %s' %(rp.read())
	rp.close()
