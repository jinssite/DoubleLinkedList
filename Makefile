CC = g++
CFLAGS = -std=c++17 -Wall

all: DoubleLinkedList

DoubleLinkedList: Main.o
	$(CC) $(CFLAGS) $^ -o $@

Main.o: Main.cpp DoubleLinkedList.h
	$(CC) $(CFLAGS) -c $<

test_DoubleLinkedList.o: test_DoubleLinkedList.cpp DoubleLinkedList.h
	$(CC) $(CFLAGS) -c $<

test: Main.cpp test_DoubleLinkedList.o
	$(CC) $(CFLAGS) -D TEST $^ -o testDoubleLinkedList

clean:
	rm -f *.o DoubleLinkedList testDoubleLinkedList

