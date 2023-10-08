
CC 		:= gcc
SRCS 	:= $(wildcard *.c)
lib 	:=  data.h
OBJ		:= *.o
BIN  	:= prog.out
WARN 	:= -W -Wall -Werror
FLAG 	:= -g -ggdb
GLUT 	:= -I/usr/include -L/usr/lib -lGL -lGLU -lglut

all : clean ${BIN}

debug : clean ${OBJ}
	${CC} ${WARN} ${FLAG} -o ${BIN} Game.c 

${BIN}: ${OBJ}
	${CC} ${FLAG} -o $@ $^  ${GLUT} 

*.o : *.c 
	${CC} -c ${lib} $^ 

clean :
	rm -f *.o
	rm -f ${BIN}

use : ${BIN}
	./${BIN}