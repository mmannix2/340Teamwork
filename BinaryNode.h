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
    /* Method Prototypes I guess
     
        BinaryNode(Key, T);
        void setKey(Key);
        T getKey();
        void setData(T);
        T getData();

        void setLeft(BinaryNode*);
        BinaryNode* getLeft();
        void setRight(BinaryNode*);
        BinaryNode* getRight();
        bool isLeaf();
    */


    BinaryNode(Key k, T d) {
        key = k;
        data = d;
        left = NULL;
        right = NULL;
    }

    //key and data setters & getters
    void setKey(Key k) {
        key = k;
    }
    Key getKey() {
        return key;
    }
    void setData(T d) {
        data = d;
    }
    T getData() {
        return data;
    }
    
    //Child BinaryNode setters & getters
    void setLeft(BinaryNode* l) {
        left = l;
    }
    BinaryNode* getLeft() {
        return left;
    }
    void setRight(BinaryNode* r) {
        right = r;
    }
    BinaryNode* getRight() {
        return right;
    }
    
    /* Returns TRUE if both left and right
     * nodes are NULL, otherwise FALSE */
    bool isLeaf() {
        return ( (right==NULL) && (left==NULL) );
    }
};
#endif
