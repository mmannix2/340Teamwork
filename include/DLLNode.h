/* DLLNode.h
 * Matthew Mannix
 * CPSC 340
 * April 18th, 2016
 * A basic DLLNode for use in a Doubly Linked List
 */
#ifndef _DLLNODE_H_INCLUDED
#define _DLLNODE_H_INCLUDED

#include <iostream>
using namespace std;

template <typename T>
class DLLNode {
public:
    T               data;
    DLLNode<T>*     next;
    DLLNode<T>*     prev;
    
    // Constructors
    DLLNode(const T& newData, DLLNode* prevPtr =NULL, DLLNode* nextPtr =NULL) {
        data = newData;
        prev = prevPtr;
        next = nextPtr;
    }
    DLLNode(DLLNode* prevPtr =NULL, DLLNode* newNext =NULL) {
        prev = prevPtr;
        next = newNext;
    }
    
    T getData() {
        return data;
    }

    void setData(T newData) {
        data = newData;
    }
    
    void swapData(DLLNode<T>* other) {
        T temp = other->getData();
        other->setData(this->data);
        this->setData(temp);
    }
};

#endif
