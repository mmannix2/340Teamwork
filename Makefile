OBJS = lab5.cpp $(DEPS)
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
DEPS = HuffmanTree.h BinaryNode.h queue.h

lab5 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o executable

test : testMain.cpp $(DEPS)
	$(CC) $(LFLAGS) $(OBJS) -o test
