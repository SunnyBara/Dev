
CC 		:= gcc
SRCS 	:= $(wildcard *.c)
OBJ		:= *.o
BIN  	:= prog.out
WARN 	:= -W -Wall -Werror
FLAG 	:= -g -ggdb

all : clean ${BIN}

debug : clean ${OBJ}
	${CC} ${WARN} ${FLAG} -o ${BIN} ${OBJ}

${BIN}: ${SRCS}
	${CC} ${FLAG} -o $@ $^

*.o : *.c 
	${CC} -c $^

clean :
	rm -f *.o
	rm -f ${BIN}

use : ${BIN}
	./${BIN}