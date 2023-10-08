all : clean my_mems.out


my_mems.out : my_realloc.c main.c array.c print_int.c
	gcc -g -ggdb -o my_mems.out $^

clean :
	rm -f my_mems.out