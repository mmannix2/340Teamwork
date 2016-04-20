/* CPSC 340
 * Lab #5 - BinaryNode.h
 * A Node to be used within a Binary Tree
 * Robert Blake
 * Matthew Mannix
 */
#ifndef _BINARYNODE_H_INCLUDED
#define _BINARYNODE_H_INCLUDED

#include <iostream>
using namespace std;

template <typename Key, typename T>
class BinaryNode {
private:
    Key         key;
    T           data;
    BinaryNode* left;
    BinaryNode* right;

public:
    BinaryNode(Key k, T d) {
        key = k;
        data = d;
        left = NULL;
        right = NULL;
    }
    
    /* Default constructor for making an array */
    BinaryNode() {
        left = NULL;
        right = NULL;
    }

    //key and data setters & getters
    void setKey(Key k) {
        key = k;
    }
    Key getKey() {
        if(this == NULL) {
            cout << "Key is NULL!\n";
            return NULL;
        }
        else {
            return key;
        }
    }
    void setData(T d) {
        data = d;
    }
    T getData() {
        if(this == NULL) {
            cout << "Data is NULL!\n";
            return NULL;
        }
        else {
            return data;
        }
    }
    
    //Child BinaryNode setters & getters
    void setLeft(BinaryNode<Key, T>* l) {
        left = l;
    }
    BinaryNode* getLeft() {
        return left;
    }
    void setRight(BinaryNode<Key, T>* r) {
        right = r;
    }
    BinaryNode* getRight() {
        return right;
    }
    
    bool hasLeft() {
        return !isLeaf();
    }

    bool hasRight() {
        return !isLeaf();
    }

    /* Returns TRUE if both left and right
     * nodes are NULL, otherwise FALSE */
    bool isLeaf() {
        //cout << right << "\n";
        //cout << left << "\n";
        //return ( (right == NULL) && (left == NULL) );
        return data != '\0';
    }
};
#endif
