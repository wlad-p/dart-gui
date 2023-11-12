PROG = main
PAGES = pages/page_start.c pages/page_menu.c pages/page_new_player.c

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

${PROG}: ${PROG}.c
	${CC} ${CFLAGS} -o ${PROG} ${PROG}.c ${PAGES} ${LIBS}	

run: ${PROG}
	./${PROG}

clean:
	rm ${PROG}
