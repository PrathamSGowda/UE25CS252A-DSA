client.exe : client.o graph.o queue.o
	gcc client.o graph.o queue.o -o client.exe 
client.o : client.c graph.h 
	gcc -Wall -c client.c 
graph.o : graph.c graph.c 
	gcc -Wall -c graph.c 
queue.o : queue.c queue.h
	gcc -Wall -c queue.c 
	
	