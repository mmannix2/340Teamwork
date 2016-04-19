/* DLinkedList.h
 * Matthew Mannix
 * CPSC 340
 * April 18th, 2016
 * A Doubly Linked List designed to hold a numeric type (int, char, double)
 */
#ifndef _DLINKEDLIST_H_DEFINED
#define _DLINKEDLIST_H_DEFINED

#include "DLLNode.h"

template <class T>
class DLinkedList {
private:
    DLLNode<T>* head;
    DLLNode<T>* tail;
    DLLNode<T>* current;
    int count;

    void init() {
        current = head = new DLLNode<T>;
        tail = new DLLNode<T>;
        
        head->next = tail;
        tail->prev = head;
        
        count = 0;
    }
   
    void removeAll() {
        while(head->next != tail) {
            current = head;
            head = head->next;
            delete current;
        }
        count = 0;
    }

public:
    DLinkedList(int size=0) {
        init();
    }
    ~DLinkedList() {
        removeAll();
        delete head;
        delete tail;
        delete current;
    }

    // Insert newData at the current position
    void insert(const T& newData) {
        DLLNode<T>* newNode = new DLLNode<T>(newData, current, current->next);
        current->next = newNode;
        current->next->prev = newNode;
        count++;
    }
    

    // Append newData to the end of the list
    void append(T newData) {
        DLLNode<T>* newNode = new DLLNode<T>(newData, tail->prev, tail); 
        tail->prev = newNode;
        newNode->prev->next = newNode;
        count++;
    }
    
    // Prepend newData to the beginning of the list
    void prepend(T newData) {
        DLLNode<T>* newNode = new DLLNode<T>(newData, head, head->next); 
        head->next = newNode;
        newNode->next->prev = newNode;
        count++;
    }
    
    // Return the element at the current position
    T remove() {
        T data = current->next->getData();
        DLLNode<T>* temp = current->next;
        temp->next->prev = current;
        current->next = temp->next;
        delete temp;
        count--;
        return data;
    }

    bool prev() {
        if(current != head && current->prev != NULL) {
            current = current->prev;
            return true;
        }
        return false;
    }

    bool next() {
        if(current != tail && current->next != NULL) {
            current = current->next;
            return true;
        }
        return false;
    }
    
    int length() {
        return count;
    }
    
    int currentPos() {
        DLLNode<T>* temp = head;
        int i;
        for( i=0; current != temp; i++) {
            temp = temp->next;
        }
        return i;
    }
    
    // Positions are 0 based
    bool moveToPos(int pos) {
        if(pos >= 0 && pos < length()) {
            current = head;
            for(int i = 0; i<pos; i++)
            {
                next();
            }
            return true;
        }
        return false;
    }

    T getData() {
        if(current->next != NULL) {
            return current->next->getData();
        }
        else {
            //Cast NULL as a T so the compiler stops complaining
            return (T)(NULL);
        }
    }
    
    DLLNode<T>* getFirstNode() {
        return head->next;
    }
    
    DLLNode<T>* getLastNode() {
        return tail->prev;
    }
};
#endif
