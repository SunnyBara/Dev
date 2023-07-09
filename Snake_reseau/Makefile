
CC 		:= gcc
SRCS 	:= $(wildcard *.c)
OBJ		:= game.o
BIN  	:= prog.out
WARN 	:= -W -Wall -Werror
FLAG 	:= -g -ggdb
GLUT 	:= -I/usr/include -L/usr/lib -lGL -lGLU -lglut

all : clean ${BIN}

debug : clean ${OBJ}
	${CC} ${WARN} ${FLAG} -o ${BIN} game.c 

${BIN}: ${OBJ}
	${CC} ${FLAG} -o $@ $^ ${GLUT}

client: 
	rm -f client.out
	${CC} ${FLAG} -o client.out client.c ${GLUT}

serveur: 
	rm -f game.out
	${CC} ${FLAG} -o game.out game.c ${GLUT}
*.o : game.c 
	${CC} -c $^

clean :
	rm -f *.o
	rm -f ${BIN}

use : ${BIN}
	./${BIN}