# Written by Charles O.
# charles.0x4f@gmail.com
# Github: https://github.com/charles-0x4f

# Challenge 117 (easy)
# Hexdump to ASCII
# See challenge.txt

import sys
import binascii

try:
	file = open(sys.argv[1], "r")
except IOError:
	print "Please send me a valid file name from the commandline!"

hexstring = binascii.hexlify(file.read())

count = 0
sys.stdout.write('%08x' % count + ' ')

for x, y in enumerate(hexstring):
	if((x != 0) and (x % 32 == 0)):
		print
		count += 1
		sys.stdout.write('%08x' % count + ' ')

	if(x % 2 == 0):
		sys.stdout.write(hexstring[x] + hexstring[x+1] + ' ')

print
