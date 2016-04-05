/*
 * Robert Blake
 * CPSC 340
 *
 * Implementation of a doubly-linked list queue
 */

#include <string>

using namespace std;

template <class T>
class Queue {
    public:
        Queue();
        Queue(T); 
        ~Queue(); 

    private:
        /* define the node struct as base of
         * doubly linked list */
        struct node {
            node *back;     // previous node in stack
            T value;
            node *next;     // next node in the stack
        };


        node * head;        /* first to get popped off */
        node * tail;        /* most recently added node */

        int size;

    public:
        void push(T);
        T pop(); 
        T peek();        /* returns the next to be popped */
        int get_size();
        void reverse();     /* flips the queue over */
};


template <class T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T> Queue<T>::~Queue() {}

template <class T> Queue<T>::Queue(T init) {
    /* wrapper for cleaner looking code I think
     * hopefully this isn't some c++ sin */
    push(init);
}

template <class T>
void Queue<T>::push(T a) {
    if(size > 0) {
        node * tmp = new node;

        tmp -> back = NULL;
        tmp -> value = a;
        tmp -> next = tail;

        tail -> back = tmp;

        tail = tmp;

        size++;

    } else {
        head = new node;
        tail = head;
        
        head -> next = NULL;
        head -> back = NULL;
        head -> value = a;
        
        size++;
    }

}

/* Removes the first-in value and
 * returns it, then sets the next 
 * value to be the head */
template <class T>
T Queue<T>::pop() {
    if(size > 1) {
        T popped = head -> value;        /* store the value before popping */

        node * tmp = new node;
        tmp = head;

        head = tmp -> back;       
        head->next = NULL;

        size--;
        delete tmp;
        return popped;

    } else if(size == 1) {
        T popped = head -> value;        /* store the value before popping */

        head = NULL;
        
        size--;
        return popped;

    } else {
        return NULL;
    }

}

/* Gives ya a look at the next value to be popped */
template <class T>
T Queue<T>::peek() {
    if(size > 0) {
        return head->value;
    } else {
        return NULL;
    }
}

/* It's all in the name homie */
template <class T>
int Queue<T>::get_size() {
    return size;
}

template <class T>
void Queue<T>::reverse() {
    /* this one is gonna be dope */
}



