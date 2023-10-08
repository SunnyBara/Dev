CC	 	 := gcc
SRCS	 := $(wildcard *o.c)
OBJ      := $(SRCS:%.c=%.o)
BIN 	 := libfifo.a
FLAG     := -g -ggdb
ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

all :  ${BIN}

${BIN}:  ${OBJ}
	rm -f main.o
	ar csr $@ *.o

%.o : %.c	
	${CC} -c $^

clean :
	rm -f *.o
	rm -f ${BIN}
	rm -f a.out

a.out : main.c ${BIN}
	${CC} $< -lfifo -L. -o  a.out

use : a.out
	./a.out