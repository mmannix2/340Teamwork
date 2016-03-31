/* A binary tree used for Huffman Encoding */
#ifndef _HUFFMANTREE_H_INCLUDED
#define _HUFFMANTREE_H_INCLUDED

#include <iostream>
using namespace std;

#include "BinaryNode.h"

class HuffmanTree {
private:
    BinaryNode<int, char>* root;

public:
    HuffmanTree(){
        root = NULL;
    }
    
    void insert(const Key& k, const T& d) {
        //Make a new BinaryNode
        BinaryNode newNode = BinaryNode(k, d);
        //Insert newNode
        if(root == NULL) {
            root = newNode;
        }
        else {
        }
    }
    
    void print() {
        cout << root->getData();
    }
};
#endif
