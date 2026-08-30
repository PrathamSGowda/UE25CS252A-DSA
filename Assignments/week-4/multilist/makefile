client.exe : client.o multilist.o
	gcc client.o multilist.o -o client.exe 
client.o : client.c multilist.h 
	gcc -Wall -c client.c 
multilist.o : multilist.c multilist.h 
	gcc -Wall -c multilist.c 