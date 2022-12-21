#!/bin/bash
# problem 2
TESTPROGRAMS=matrixmul-r1-n2048*
                                                     
for PROGRAM in $TESTPROGRAMS;
do
	echo $PROGRAM
    # echo ${PROGRAM//matrixmul-r1-n1024-b/}
    perf stat -r 1 taskset -c 1 ./$PROGRAM
done