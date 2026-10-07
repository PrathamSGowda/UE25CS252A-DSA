client.exe : client.o stack.o 
	gcc client.o stack.o -o client.exe
client.o : client.c stack.h 
	gcc -Wall -c client.c 
stack.o : stack.c stack.h 
	gcc -Wall -c stack.c 