#!/bin/bash
# problem 2
TESTPROGRAMS=matrixmul-r1*
                                                     
for PROGRAM in $TESTPROGRAMS;
do
	echo $PROGRAM
    # echo ${PROGRAM//matrixmul-r1-n1024-b/}
    valgrind --tool=cachegrind --LL=2097152,8,64 "./${PROGRAM}" > /dev/null | grep 'LL '
done