//
// Main.cpp
//
// The main program to show how to use and test class DoubleLinkedList

#include <iostream>
#include "DoubleLinkedList.h"

// If TEST is defined, the main program runs unit tests for class DoubleLinkedList
#if TEST
#include "test_DoubleLinkedList.h"
#endif

int main() {
#if TEST
    run_tests();
#else
    // Examples for how to use class DoubleLinkedList
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    // Add array to the list
    myList.Add(arr[0]);
    myList.Add(arr[1]);
    myList.Add(arr[2]);

    std::cout << "List: ";
    for (auto iter = myList.begin(); iter != myList.end(); iter ++)
        std::cout << *iter << ' ';
    std::cout << std::endl;
    std::cout << "Reverse list: ";
    for (auto iter = myList.rbegin(); iter != myList.rend(); iter --)
        std::cout << *iter << ' ';
    std::cout << std::endl;

    myList.Remove(arr[0]);
    std::cout << "List after first item removed: ";
    for (auto iter = myList.begin(); iter != myList.end(); ++ iter)
        std::cout << *iter << ' ';
    std::cout << std::endl;
#endif

    return 0;
}
