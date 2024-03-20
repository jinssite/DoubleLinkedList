# DoubleLinkedList
A class to implement double linked list that allowing movement forward and backward. The class allows to add and remove nodes from the list. For simplicity, the class does not allow to copy or assign the list. Each node contains a reference to the application data.

Files included
  Main.cpp: Main program to show and test the linked list
  DoubleLinkedList.h: Implementation of double linked list
  test_DoubleLinkedList.cpp: A series of test functions for unit tests test_DoubleLinkedList.h: Header file for test_DoubleLinkedList.cpp
  Makefile: Build the example and test programs

To build the example program
```
make
```
or
```
g++ -std=c++17 Main.cpp -o DoubleLinkedList
```

To build the test
```
make test
```
or
```
g++ -std=c++17 -D TEST Main.cpp test_DoubleLinkedList.cpp -o testDoubleLinkedList
```
