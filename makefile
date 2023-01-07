CFLAGS = -g -fPIC -Wall
CC=gcc
AR=ar

.PHONY: all clean

all: graph

graph: edge.o node.o algo.o main.o
	$(CC) $(CFLAGS) edge.o node.o algo.o main.o -o graph

main.o: main.c node.h graph.h
	$(CC) $(CFLAGS) -c main.c

algo.o: algo.c algo.h edge.h node.h graph.h
	$(CC) $(CFLAGS) -c algo.c

node.o: node.c node.h edge.h
	$(CC) $(CFLAGS) -c node.c

edge.o: edge.c edge.h
	$(CC) $(CFLAGS) -c edge.c

clean:
	rm *.o graph