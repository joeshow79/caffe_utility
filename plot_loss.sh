#!/bin/bash


grep Iteration $1  | grep loss | awk '{print NR,$9}' > loss.txt

python -c "import numpy as np;import pylab as pl;data=np.loadtxt('loss.txt');pl.plot(data[:,0],data[:,1]);pl.xlabel('iter');pl.ylabel('loss');pl.show()"
