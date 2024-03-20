//
// DoubleLinkedList.h
//
// This file defines a class that implements a double linked list, allowing movement forward and backward.
// The class allows to add and remove nodes from the list. For simplicity, the class does not allow to
// copy or assign the list. Each node contains a reference to the application data.

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

template <typename T>
class DoubleLinkedList {
    private:
        struct Node {
            Node(T& d) noexcept : data(d), prev(nullptr), next(nullptr) {}

            T& data;
            Node *prev, *next;
        };
        Node *head, *tail;

    public:
        DoubleLinkedList() noexcept : head(nullptr), tail(nullptr) {}
        DoubleLinkedList(const DoubleLinkedList& other) = delete;
        DoubleLinkedList& operator=(const DoubleLinkedList& other) = delete;
        void Add(T& data);
        void Remove(const T& data);
        // To clear the list
        void Clear () {
            while (head != nullptr) {
                Node *curr = head;
                head = head->next;
                delete curr;
            }
            tail = nullptr;
        }
        ~DoubleLinkedList() { Clear(); }

        // The Iterator to allow the movement forward and backward, and the access of the data
        class Iterator {
            public:
                Iterator() noexcept : curr(nullptr) {}
                Iterator(Node *node) noexcept : curr(node) {}
                Iterator&  operator++() noexcept {
                    if (curr != nullptr) {
                        curr = curr->next;
                    }
                    return *this;
                }
                Iterator operator++(int) noexcept {
                    Iterator tempIter = *this;
                    ++ *this;
                    return tempIter;
                }
                Iterator&  operator--() noexcept {
                    if (curr != nullptr) {
                        curr = curr->prev;
                    }
                    return *this;
                }
                Iterator operator--(int) noexcept {
                    Iterator tempIter = *this;
                    -- *this;
                    return tempIter;
                }
                bool operator==(const Iterator& other) const noexcept { return curr == other.curr; }
                bool operator!=(const Iterator& other) const noexcept { return curr != other.curr; }
                T& operator*() const { return curr->data; }
            private:
                Node *curr;
        };
        // For forward movement
        Iterator begin() const noexcept { return Iterator(head); }
        Iterator end() const noexcept { return Iterator(); }
        // For backward movement
        Iterator rbegin() const noexcept { return Iterator(tail); }
        Iterator rend() const noexcept { return Iterator(); }
};

template <typename T>
void DoubleLinkedList<T>::Add(T& data) {
    Node *newNode = new Node(data);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->prev = nullptr;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoubleLinkedList<T>::Remove(const T& data) {
    for (auto curr = head; curr != nullptr; curr = curr->next) {
        if (&curr->data == &data) {
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            } else {
                tail = curr->prev;
            }
            delete curr;
            return;
        }
    }
}

#endif


