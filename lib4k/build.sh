#!/bin/sh 
echo COMPILING LIB4k SOURCE FILES
for c in *.s; do 
	echo sdasz80 -o `echo $c|sed -e 's/.s/.rel/'` $c
	sdasz80 -o `echo $c|sed -e 's/.s/.rel/'` $c
done
mv crtcv.rel ..
echo CREATING LIB4K LIBRARY
for c in *.rel; do 
	echo sdcclib cvlib.lib $c
	sdcclib cvlib.lib $c
done
echo COPYING GENERATED LIBRARY AND HEADERS FILES
cp cvlib.lib ..
cp coleco.h ..
echo CLEANING UP LIB4K FOLDER
rm *.rel
rm cvlib.lib

