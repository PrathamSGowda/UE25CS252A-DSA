client.exe : client.o list.o rect.o 
	gcc client.o list.o rect.o -o client.exe
list.o : list.c list.h 
	gcc -Wall -c list.c
rect.o : rect.c rect.h 
	gcc -Wall -c rect.c 
client.o : client.c list.h  rect.h 
	gcc -Wall -c client.c