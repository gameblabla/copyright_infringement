CXX = g++

CFLAGS = -O2
LDFLAGS = 

DEFINES = -Wall
OUTPUT = makemegacart

SOURCES = makemegacart.cpp
OBJS = ${SOURCES:.c=.o}

${OUTPUT}:${OBJS}
	${CXX} -o ${OUTPUT} ${OBJS} ${CFLAGS} ${LDFLAGS} ${DEFINES} 
	
clean:
	rm *.o
	rm ${OUTPUT}

install:
	cp ./${OUTPUT} /usr/bin/${OUTPUT}
