
CC 		:= gcc
SRCS 	:= $(wildcard *.c)
OBJ		:= *.o
BIN  	:= prog.out
WARN 	:= -W -Wall -Werror
FLAG 	:= -g -ggdb
GLUT 	:= -I/usr/include -L/usr/lib -lGL -lGLU -lglut

all : clean ${BIN}

debug : clean ${OBJ}
	${CC}  ${FLAG} -o ${BIN} 

${BIN}: ${OBJ}
	${CC} ${FLAG} -o $@ $^ ${GLUT}

*.o : ${SRCS} 
	${CC} -c $^

clean :
	rm -f *.o
	rm -f ${BIN}

use : ${BIN}
	./${BIN}