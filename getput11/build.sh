#!/bin/sh
echo COMPILING GETPUT SOURCE FILES
for c in *.s; do 
	echo sdasz80 -o $c.rel $c
	sdasz80 -o $c.rel $c
done
echo CREATING GETPUT LIBRARY FILE
for c in *.rel; do 
	echo sdcclib getput.lib $c
	sdcclib getput.lib $c
done
echo COPYING GENERATED LIBRARY AND HEADERS FILES
cp getput.lib ..
cp getput1.h ..
echo CLEANING UP GETPUT FOLDER
rm *.rel
rm getput.lib
