client.exe : stack.o client.o
	gcc stack.o client.o -o client.exe
stack.o : stack.c stack.h
	gcc -Wall -c stack.c
client.o : client.c stack.h
	gcc -Wall -c client.c