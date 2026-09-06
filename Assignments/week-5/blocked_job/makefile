client.exe : client.o priority_queue.o job.o
	gcc client.o priority_queue.o job.o -o client.exe 
client.o : client.c priority_queue.h 
	gcc -Wall -c client.c 
priority_queue.o : priority_queue.c priority_queue.h 
	gcc -Wall -c priority_queue.c 
job.o : job.c job.h
	gcc -Wall -c job.c 
	
