/* A binary tree used for Huffman Encoding */
#ifndef _HUFFMANTREE_H_INCLUDED
#define _HUFFMANTREE_H_INCLUDED

#include <iostream>
using namespace std;

#include "BinaryNode.h"

class HuffmanTree {
private:
    BinaryNode<double, char>* root;

public:
    HuffmanTree(){
        root = NULL;
    }
    
    void insert(const double& k, const char& d) {
        //Make a new BinaryNode
        BinaryNode<double, char> newNode = BinaryNode<double, char>(k, d);
        //Insert newNode
        if(root == NULL) {
            root = &newNode;
        }
        else {
        }
    }
    
    void print() {
        cout << root->getData();
    }
};
#endif
