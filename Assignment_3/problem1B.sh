#!/bin/bash
# problem1.sh
TESTIMAGES=testImages/*.png
SUBSTRINGTOREMOVE='testImages/'
SUBSTRING2TOREMOVE='.png'
DEFAULTPROGRAMDATAFOLDER='dataDefaultGrayscale'
OPTIMIZEDPROGRAMDATAFOLDER='dataOptimizedGrayscale'
rm -rf $DEFAULTPROGRAMDATAFOLDER
rm -rf $OPTIMIZEDPROGRAMDATAFOLDER
mkdir -p $DEFAULTPROGRAMDATAFOLDER
mkdir -p $OPTIMIZEDPROGRAMDATAFOLDER
                                                     
# run the default program for each test image testing for each repeat count 
for INPUTIMAGE in $TESTIMAGES;
do
		TEMPCSVFILENAME="${INPUTIMAGE//$SUBSTRINGTOREMOVE/}"
		CSVFILENAME="$DEFAULTPROGRAMDATAFOLDER/${TEMPCSVFILENAME//$SUBSTRING2TOREMOVE/}_execution_time.csv"
		echo $CSVFILENAME

		echo 'RepeatCount,AvgLoadTime,GreyScaleTime' >> $CSVFILENAME

    for REPEATCOUNT in {1..10};
    do
        # OUTPUTIMAGE="${INPUTIMAGE%.png}_output.png"
        # echo -e $INPUTIMAGE
        # echo -e $OUTPUTIMAGE
        './grayscale' $INPUTIMAGE $REPEATCOUNT |
        awk -v repeatcount="$REPEATCOUNT" -F ',' 'NR>1 {sumLoadTime += $2; sumGreyScaleTime += $3; ++n} END { print repeatcount "," sumLoadTime/n "," sumGreyScaleTime/n }' >> $CSVFILENAME
    done

		CSVFILENAME="$OPTIMIZEDPROGRAMDATAFOLDER/${TEMPCSVFILENAME//$SUBSTRING2TOREMOVE/}_execution_time.csv"
		echo $CSVFILENAME

		echo 'RepeatCount,AvgLoadTime,GreyScaleTime' >> $CSVFILENAME
		for REPEATCOUNT in {1..10};
    do
        './grayscaleLoopInterchange' $INPUTIMAGE $REPEATCOUNT |
        awk -v repeatcount="$REPEATCOUNT" -F ',' 'NR>1 {sumLoadTime += $2; sumGreyScaleTime += $3; ++n} END { print repeatcount "," sumLoadTime/n "," sumGreyScaleTime/n }' >> $CSVFILENAME
    done
done
