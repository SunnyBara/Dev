CC	 	 := gcc
SRCS	 := $(wildcard geo_*.c) 
BIN 	 := libgeo.so
OBJ 	 := $(SRCS:%.c=%.o)
ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

all : ${BIN}

libgeo.so :  ${OBJ}
	${CC} -shared -o $@  $^
	export LD_LIBRARY_PATH=toto

%.o : %.c
	${CC} -c $^

clean :
	rm  *.o
	rm ${BIN}
	rm a.out

main : main.c ${BIN} 
	${CC} $< -lgeo -L. -o  a.out

showvar :
	@echo ${MAKEFILE_LIST}
	@echo ${ROOT_DIR}
	@echo ${LD_LIBRARY_PATH}