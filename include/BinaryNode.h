/* A Node to be used within a Binary Tree */
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
    
    bool hasLeft() {
        return left != NULL;
    }

    bool hasRight() {
        return right != NULL;
    }
    
    /* Returns TRUE if both left and right
     * nodes are NULL, otherwise FALSE */
    bool isLeaf() {
        return ( (right==NULL) && (left==NULL) );
    }
};
#endif
