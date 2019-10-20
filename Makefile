all: exo

exo : main.c liste.o stack.o
	clang main.c liste.o stack.o -o exo

liste.o : liste.c 
	clang -c liste.c

stack.o : stack.c
	clang -c stack.c

clean : 
	rm *.o
	rm exo