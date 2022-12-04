#!/bin/bash
# problem1.sh
TESTIMAGES=testImages/*.png

DEFAULTPROGRAMDATAFOLDER='dataDefaultGrayscale'
OPTIMIZEDPROGRAMDATAFOLDER='dataOptimizedGrayscale'

mkdir -p $DEFAULTPROGRAMDATAFOLDER
mkdir -p $OPTIMIZEDPROGRAMDATAFOLDER
                                                     
#run the default program for each test image testing for each repeat count 
echo 'RepeatCount,AvgLoadTime,GreyScaleTime'
for INPUTIMAGE in $TESTIMAGES;
do
    SUBSTRINGTOREMOVE='testImages/'
		SUBSTRING2TOREMOVE='.png'
		TEMPCSVFILENAME="${INPUTIMAGE//$SUBSTRINGTOREMOVE/}"
		CSVFILENAME="$DEFAULTPROGRAMDATAFOLDER/${TEMPCSVFILENAME//$SUBSTRING2TOREMOVE/}_execution_time.csv"
		echo $CSVFILENAME

    for REPEATCOUNT in {1..10};
    do
        # OUTPUTIMAGE="${INPUTIMAGE%.png}_output.png"
        # echo -e $INPUTIMAGE
        # echo -e $OUTPUTIMAGE
        './grayscale' $INPUTIMAGE $REPEATCOUNT |
        awk -v repeatcount="$REPEATCOUNT" -F ',' 'NR>1 {sumLoadTime += $2; sumGreyScaleTime += $3; ++n} END { print repeatcount "," sumLoadTime/n "," sumGreyScaleTime/n }' 
				>> $CSVFILENAME
    done
done
