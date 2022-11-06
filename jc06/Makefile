CC	 	 := gcc
SRCS	 := $(wildcard *.c) 
BIN 	 := prog.out
FLAG := -g -ggdb

all : clean ${BIN}

${BIN}:  ${SRCS}
	${CC} ${FLAG} -o $@  $^


clean :
	rm -f ${BIN}

use : ${BIN}
	./prog.out