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
        root = new BinaryNode<int, char>(0, '\0');
    }
    
    void insert(const int& k, const char& d) {
        cout << "Inserting " << d << " with weight " << k << ".\n";
        //Make a new BinaryNode
        BinaryNode<int, char> newNode = BinaryNode<int, char>(k, d);
        BinaryNode<int, char>* tempNode;
        //Insert newNode
        if(root->getKey() == 0) {
            cout << "\tTree is empty.\n";
            cout << "\tAdding node left of root.\n";
            //Set newNode as root's left child
            root->setLeft( &newNode );
            //Change root's key
            root->setKey(newNode.getKey());
        } else {
            cout << "\tTree is not empty.\n";
            //If root's right child is empty
            if(root->getRight() != NULL) {
                cout << "\tCreating new Node.\n";
                //Make a new node
                tempNode = new BinaryNode<int, char>(0, '\0');
                tempNode->setLeft(root);
                root = tempNode;
            }
            //Set newNode as root's right child
            cout << "\tAdding node right of root.\n";
            root->setRight( &newNode );
            //Change root's key to the sum of its children's keys.
            root->setKey(root->getLeft()->getKey() + newNode.getKey());
        }
    }
    
    void print() {
        //TODO Fix print().
        BinaryNode<int, char>* temp = root;
        while(temp->getLeft()->isLeaf()) {
            //Print right child
            cout << "Weight: " << temp->getRight()->getKey() << endl;
            cout << "Char: " << temp->getRight()->getData() << endl;
            //Move temp
            temp = temp->getLeft();
        }

        if(temp->getLeft() != NULL) {
            //Print left child
            cout << "Weight: " << temp->getLeft()->getKey() << endl;
            cout << "Char: " << temp->getLeft()->getData() << endl;
        }

        //cout << "root key: " << root->getKey() << endl;
        //cout << "root data: " << root->getData() << endl;
    }
};
#endif
