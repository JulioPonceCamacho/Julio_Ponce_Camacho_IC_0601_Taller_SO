all:
	gcc -g -c -Wall main.c -o main.o
	gcc -g -c -Wall control_archivo.c -o control_archivo.o
	gcc -g -c -Wall control_lista.c -o control_lista.o
	gcc -g -Wall main.o control_archivo.o control_lista.o -o application

clean:
	rm *.o
	rm application