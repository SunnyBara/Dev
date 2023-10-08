all : clean jc05.out
	./jc05.out

jc05.out : main.c  swap.c mystrlen.c ispalimdrome.c reverse.c  raiseit.c arithmétique_des_pointeurs.c allocation_dynamique.c
	gcc -o ./jc05.out $^

clean :
	rm -f jc05.out
