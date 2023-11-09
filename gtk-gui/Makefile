PROG = main

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

${PROG}: ${PROG}.c
	${CC} ${CFLAGS} -o ${PROG} ${PROG}.c stack_page1.c stack_page2.c ${LIBS}	

run: ${PROG}
	./${PROG}

clean:
	rm ${PROG}
