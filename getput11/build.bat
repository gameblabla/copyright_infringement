@echo off
echo COMPILING GETPUT SOURCE FILES
FOR %%c in (./*.s) DO sdasz80 -o %%c.rel %%c
echo CREATING GETPUT LIBRARY FILE
FOR %%c in (./*.rel) DO sdcclib getput.lib %%c
echo COPYING GENERATED LIBRARY AND HEADERS FILES
copy getput.lib ..
copy getput1.h ..
echo CLEANING UP GETPUT FOLDER
del *.rel
del getput.lib
pause