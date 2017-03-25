#include <iostream>
#include "TwoWayLinkedList.hpp"

using namespace std;

TwoWayLinkedList::TwoWayLinkedList() {
    size = 0;
}

TwoWayLinkedList::~TwoWayLinkedList() {
    Node *ptr = head;
    Node *ptrNext = ptr;
    for (int i = 0; i < size; i++) {
        ptr = ptrNext;
        if (ptr == nullptr) {
            break;
        }
        ptrNext = ptr->next;
        delete ptr;
    }
}

void TwoWayLinkedList::add(int element) {
    if (size == 0) {
        Node *tmp = new Node();
        tmp->index = 0;
        tmp->number = element;
        head = tmp;
        tail = tmp;
        size++;
    } else {
        Node *tmp = new Node();
        tmp->index = size;
        tmp->number = element;
        head->prev = tmp;
        head = tmp;
        size++;
    }

}

void TwoWayLinkedList::append(int element) {
    if (size == 0) {
        Node *tmp = new Node();
        tmp->index = 0;
        tmp->number = element;
        head = tmp;
        tail = tmp;
        size++;
    } else {
        Node *tmp = new Node();
        tmp->index = size;
        tmp->number = element;
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
        size++;
    }
}

void TwoWayLinkedList::display() {
    Node *ptr;
    if (head == nullptr) {
        cout << "List is empty." << endl;
    }
    ptr = head;
    while (ptr != nullptr) {
        cout << ptr->number << " <--> ";
        ptr = ptr->next;
    }
    cout << endl;
}

void TwoWayLinkedList::delete_by_index(int index) {
    Node *tmp, *ptr;
    if (head->index == index) {
        head = head->next;
        head->prev = nullptr;
        size--;
        return;
    }
    ptr = head;
    while (ptr->next->next != nullptr) {
        if (ptr->next->index == index) {
            tmp = ptr->next;
            ptr->next = tmp->next;
            tmp->next->prev = ptr;
            size--;
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->next->index == index) {
        ptr->next = nullptr;
        size--;
        return;

    }
    cout << "Not Found" << endl;
}

void TwoWayLinkedList::sort() {
    Node *tmpPtr = head;
    Node *tmpNext = head->next;

    while (tmpNext != nullptr) {
        while (tmpNext != tmpPtr) {
            int tmpNumber;
            if (tmpNext->number < tmpPtr->number) {
                tmpNumber = tmpPtr->number;

                tmpPtr->number = tmpNext->number;
                tmpNext->number = tmpNumber;
            }
            tmpPtr = tmpPtr->next;
        }
        tmpPtr = head;
        tmpNext = tmpNext->next;
    }

}

TwoWayLinkedList operator+(const TwoWayLinkedList &a, const TwoWayLinkedList &b) {
    TwoWayLinkedList newList;
    Node *ptrA = a.head;
    for (int i = 0; i < a.size; i++) {
        if (ptrA == nullptr) {
            break;
        }
        newList.append(ptrA->number);
        ptrA = ptrA->next;
    }
    Node *ptrB = b.head;
    for (int i = 0; i < b.size; i++) {
        if (ptrB == nullptr) {
            break;
        }
        newList.append(ptrB->number);
        ptrB = ptrB->next;
    }
    return newList;
}

