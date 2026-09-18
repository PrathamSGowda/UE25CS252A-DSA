client.exe : client.o dll.o queue.o
	gcc client.o dll.o queue.o -o client.exe

client.o : client.c queue.h
	gcc -Wall -c client.c

dll.o : dll.c dll.h
	gcc -Wall -c dll.c

queue.o : queue.c queue.h dll.h
	gcc -Wall -c queue.c