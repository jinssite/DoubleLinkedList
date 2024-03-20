//
// test_DoubleLinkedList.cpp
//
// This file defines a series of test functions for testing class DoubleLinkedList.

#include <iostream>
#include <exception>
#include "DoubleLinkedList.h"
#include "test_DoubleLinkedList.h"

// To make the test not depending on any Unit Testing Tools, we use the following inline functions for the testing.
// The ASSERT function checks boolean condition 'cond', prints a PASSED message with function name if the condition
// is true, otherwise prints a FAILED message with function name and an error message.
inline void PRINT_PASS(const char *func) { std::cout << "  Test " << func << " PASSED." << std::endl; }
inline void PRINT_FAIL(const char *func, const char *msg) { std::cout << "  Test " << func << " FAILED. " << msg << std::endl; }
inline void ASSERT(bool cond, const char *func, const char *msg) { cond ? PRINT_PASS(func) : PRINT_FAIL(func, msg); }

void test_Constructor() {
    DoubleLinkedList<int> myList;

    ASSERT(myList.begin() == myList.end(), "Constructor 1", "List should be empty");
    ASSERT(myList.rbegin() == myList.rend(), "Constructor 2", "List should be empty");
}

void test_Add() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }
    int i = 0;
    for (auto iter = myList.begin(); iter != myList.end(); ++ iter, ++ i) {
        ASSERT(*iter == arr[i], "Add()", "Elements should be equal");
    }
    ASSERT(i == sizeof(arr)/sizeof(arr[0]), "Add()", "List and array size should be same.");
}

void test_Add_Reference() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }
    arr[1] = 40;
    int i = 0;
    for (auto iter = myList.begin(); iter != myList.end(); ++ iter, ++ i) {
        ASSERT(*iter == arr[i], "Add Reference", "Elements should be equal");
    }
}

void test_Iterator() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }

    int i = 0;
    for (auto iter = myList.begin(); iter != myList.end(); iter ++, ++ i) {
        ASSERT(*iter == arr[i], "Iterator++", "Elements should be equal");
    }

    i = sizeof(arr) / sizeof(arr[0]) - 1;
    for (auto iter = myList.rbegin(); iter != myList.rend(); -- iter, -- i) {
        ASSERT(*iter == arr[i], "--Backward Iterator", "Elements should be equal");
    }

    i = sizeof(arr) / sizeof(arr[0]) - 1;
    for (auto iter = myList.rbegin(); iter != myList.rend(); iter --, -- i) {
        ASSERT(*iter == arr[i], "Backward Iterator--", "Elements should be equal");
    }
}

void test_Remove_First() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }

    myList.Remove(arr[0]);
    int i = 1;
    for (auto iter = myList.begin(); iter != myList.end(); iter ++, ++ i) {
        ASSERT(*iter == arr[i], "Remove First", "Elements should be equal");
    }
    -- i;
    for (auto iter = myList.rbegin(); iter != myList.rend(); iter --, -- i) {
        ASSERT(*iter == arr[i], "Remove First", "Elements should be equal");
    }
}

void test_Remove_Last() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }

    myList.Remove(arr[sizeof(arr)/sizeof(arr[0]) - 1]);
    int i = 0;
    for (auto iter = myList.begin(); iter != myList.end(); iter ++, ++ i) {
        ASSERT(*iter == arr[i], "Remove Last", "Elements should be equal");
    }
    ASSERT(i == sizeof(arr)/sizeof(arr[0]) - 1, "Remove Last", "List size should be one less.");
    -- i;
    for (auto iter = myList.rbegin(); iter != myList.rend(); iter --, -- i) {
        ASSERT(*iter == arr[i], "Remove Last", "Elements should be equal");
    }
}

void test_Remove_Middle() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }

    myList.Remove(arr[1]);
    int i = 0;
    for (auto iter = myList.begin(); iter != myList.end(); iter ++, ++ i) {
        if (i == 1) ++ i;
        ASSERT(*iter == arr[i], "Remove Middle", "Elements should be equal");
    }
    -- i;
    for (auto iter = myList.rbegin(); iter != myList.rend(); iter --, -- i) {
        if (i == 1) -- i;
        ASSERT(*iter == arr[i], "Remove Middle", "Elements should be equal");
    }
}

void test_Remove_NonExist() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }

    int i = 0;
    myList.Remove(i);
    for (auto iter = myList.begin(); iter != myList.end(); iter ++, ++ i) {
        ASSERT(*iter == arr[i], "Remove NonExist", "Elements should be equal");
    }
    ASSERT(i == sizeof(arr)/sizeof(arr[0]), "Remove NonExist", "List and array size should be same.");
}

void test_Destructor() {
    int arr[] = {10, 20, 30};
    DoubleLinkedList<int> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }

    myList.Clear();
    ASSERT(myList.begin() == myList.end(), "Destructor 1", "List should be empty");
    ASSERT(myList.rbegin() == myList.rend(), "Destructor 2", "List should be empty");
}

#include <string>
#include <vector>
using namespace std::string_literals;

void test_Add_String() {
    std::vector<std::string> arr = {"string1"s, "string2"s, "string3"s};
    DoubleLinkedList<std::string> myList;

    for (auto& item : arr) {
        myList.Add(item);
    }
    int i = 0;
    for (auto iter = myList.begin(); iter != myList.end(); iter ++, ++ i) {
        ASSERT(*iter == arr[i], "Add String", "Elements should be equal");
    }
    ASSERT(i == static_cast<int>(arr.size()), "Add String", "List and array size should be same.");
}

void run_tests() {
    std::cout << "Test class DoubleLinkedList:" << std::endl;
    try {
        test_Constructor();
        test_Add();
        test_Iterator();
        test_Remove_First();
        test_Remove_Last();
        test_Remove_Middle();
        test_Remove_NonExist();
        test_Destructor();
        test_Add_String();
    } catch (std::exception &e) {
        std::cerr << "  Error " << e.what() << std::endl;
    }
}

