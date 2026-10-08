client.exe : client.o tree.o stack.o
	gcc client.o tree.o stack.o -o client.exe

client.o : client.c tree.h
	gcc -Wall -c client.c

tree.o : tree.c tree.h stack.h
	gcc -Wall -c tree.c

stack.o : stack.c stack.h
	gcc -Wall -c stack.c