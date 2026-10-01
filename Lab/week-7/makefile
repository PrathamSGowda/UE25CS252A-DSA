client.exe : client.o dll.o webpage.o
	gcc client.o dll.o webpage.o -o client.exe 
client.o : client.c dll.h 
	gcc -Wall -c client.c 
dll.o : dll.c dll.h 
	gcc -Wall -c dll.c 
webpage.o : webpage.c webpage.h
	gcc -Wall -c webpage.c 