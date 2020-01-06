all: main.o linked.o ssv.o
	gcc -o bank main.o linked.o ssv.o

main.o: main.c
	gcc -c main.c

linked.o: linked.c
	gcc -c linked.c

ssv.o: ssv.c
	gcc -c ssv.c
run: ./bank
