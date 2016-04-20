OBJS = lab5.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
DEPS = include/*.h

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
