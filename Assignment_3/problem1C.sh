#!/bin/bash
# problem1.sh
TESTIMAGES=testImages/*.png
SUBSTRINGTOREMOVE='testImages/'
SUBSTRING2TOREMOVE='.png'
DEFAULTPROGRAMDATAFOLDER='dataCachegrindDefaultGrayscale'
OPTIMIZEDPROGRAMDATAFOLDER='dataCachegrindOptimizedGrayscale'
rm -rf $DEFAULTPROGRAMDATAFOLDER
rm -rf $OPTIMIZEDPROGRAMDATAFOLDER
mkdir -p $DEFAULTPROGRAMDATAFOLDER
mkdir -p $OPTIMIZEDPROGRAMDATAFOLDER
                                                     
# run the default program for each test image testing for each repeat count 
for INPUTIMAGE in $TESTIMAGES;
do
	TEMPCSVFILENAME="${INPUTIMAGE//$SUBSTRINGTOREMOVE/}"
	CSVFILENAME="$DEFAULTPROGRAMDATAFOLDER/${TEMPCSVFILENAME//$SUBSTRING2TOREMOVE/}.csv"

    echo $INPUTIMAGE
    echo './grayscale'

    for REPEATCOUNT in {1..10};
    do
        perf stat -x ',' -e instructions:u,cycles:u,cache-misses:u,cache-references:u -r 100 './grayscale' $INPUTIMAGE $REPEATCOUNT > /dev/null
    done

    echo './grayscaleLoopInterchange'
    
    for REPEATCOUNT in {1..10};
    do
        perf stat -x ',' -e instructions:u,cycles:u,cache-misses:u,cache-references:u -r 100 './grayscaleLoopInterchange' $INPUTIMAGE $REPEATCOUNT > /dev/null
    done
done
