client.exe : client.o tree.o 
	gcc client.o tree.o -o client.exe
client.o : client.c tree.h
	gcc -Wall -c client.c 
tree.o : tree.h tree.c 
	gcc -Wall -c tree.c 
	