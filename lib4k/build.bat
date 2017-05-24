@echo off
echo COMPILING LIB4k SOURCE FILES
FOR %%c in (./*.s) DO sdasz80 -o %%c.rel %%c
copy crtcv.s.rel ..\crtcv.rel
del crtcv.s.rel
echo CREATING LIB4K LIBRARY
FOR %%c in (./*.rel) DO sdcclib cvlib.lib %%c
echo COPYING GENERATED LIBRARY AND HEADERS FILES
copy cvlib.lib ..
copy coleco.h ..
echo CLEANING UP LIB4K FOLDER
del *.rel
del cvlib.lib
pause