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
	echo $CSVFILENAME

	echo 'Ir,I1mr,ILmr,Dr,D1mr,DLmr,Dw,D1mw,DLmw' >> $CSVFILENAME

    for REPEATCOUNT in {1..10};
    do
				rm cachegrindOutput
        		valgrind --tool=cachegrind --cachegrind-out-file=cachegrindOutput './grayscale' $INPUTIMAGE $REPEATCOUNT
				cg_annotate cachegrindOutput | grep 'PROGRAM TOTALS' | sed 's/,//g' | sed 's/ (100.0%) /,/g' | sed 's/, PROGRAM TOTALS//g' >> $CSVFILENAME
    done

	CSVFILENAME="$OPTIMIZEDPROGRAMDATAFOLDER/${TEMPCSVFILENAME//$SUBSTRING2TOREMOVE/}.csv"
	echo $CSVFILENAME
	echo 'Ir,I1mr,ILmr,Dr,D1mr,DLmr,Dw,D1mw,DLmw' >> $CSVFILENAME
    for REPEATCOUNT in {1..10};
    do
				rm cachegrindOutput
        		valgrind --tool=cachegrind --cachegrind-out-file=cachegrindOutput './grayscaleLoopInterchange' $INPUTIMAGE $REPEATCOUNT
				cg_annotate cachegrindOutput | grep 'PROGRAM TOTALS' | sed 's/,//g' | sed 's/ (100.0%) /,/g' | sed 's/, PROGRAM TOTALS//g' >> $CSVFILENAME
    done
done