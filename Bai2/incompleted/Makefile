CFLAGS = -c -Wall
CC = gcc
LIBS =  -lm 
SC = scanner_2
all: ${SC}

${SC}: ${SC}.o reader.o charcode.o token.o error.o
	${CC} ${SC}.o reader.o charcode.o token.o error.o -o ${SC}

reader.o: reader.c
	${CC} ${CFLAGS} reader.c

${SC}.o: ${SC}.c
	${CC} ${CFLAGS} ${SC}.c

charcode.o: charcode.c
	${CC} ${CFLAGS} charcode.c

token.o: token.c
	${CC} ${CFLAGS} token.c

error.o: error.c
	${CC} ${CFLAGS} error.c

clean:
	rm -f *.o *~

