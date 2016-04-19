OBJS = lab5.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
DEPS = include/HuffmanTree.h include/BinaryNode.h

default: lab5

lab5.o: lab5.cpp $(DEPS)
	$(CC) $(CFLAGS) lab5.cpp -o $(OBJS)

lab5 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab5

test : testMain.cpp $(DEPS)
	$(CC) $(LFLAGS) $(OBJS) -o test

clean : 
	-rm -f lab5.o
	-rm -f lab5
