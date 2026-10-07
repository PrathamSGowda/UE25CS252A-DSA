client.exe : client.o heap.o job.o priority_queue.o
	gcc client.o heap.o job.o priority_queue.o -o client.exe
heap.o : heap.c heap.h 
	gcc -Wall -c heap.c 
client.o : client.c heap.h 
	gcc -Wall -c client.c 
job.o : job.c job.h 
	gcc -Wall -c job.c 
priority_queue.o : priority_queue.c priority_queue.h 
	gcc -Wall -c priority_queue.c 
	
	
