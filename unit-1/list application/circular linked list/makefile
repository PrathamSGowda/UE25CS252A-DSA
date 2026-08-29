client.exe : client.o clist.o
	gcc client.o clist.o -o client 
client.o : client.c clist.h 
	gcc -Wall -c client.c 
clist.o : clist.c clist.h 
	gcc -Wall -c clist.c 
	