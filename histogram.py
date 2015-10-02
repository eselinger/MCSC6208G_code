#!/usr/bin/python

import sys
import numpy as np

infile = sys.argv[1]
readin = open(infile, 'r')
# readout = open('hist_'+infile, 'w')

a = readin.readlines()
readin.close()

data = []

for line in a:
    data.append(float(line))

#array = np.arange(1, len(data) + 1, 1)

#print data

num, bins = np.histogram(data,bins=1000,density=True) 

hist = zip(num, bins)

np.savetxt('hist_'+infile, hist)

# readout.close()
