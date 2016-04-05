/* A binary tree used for Huffman Encoding */
#ifndef _HUFFMANTREE_H_INCLUDED
#define _HUFFMANTREE_H_INCLUDED

#include <iostream>
#include <typeinfo>
using namespace std;

#include "BinaryNode.h"

class HuffmanTree {

    struct leaf {
        int weight;
        char tag;
    };

private:
    BinaryNode<int, char>* root;
    int nodeCount;
    int leafCount;
    Queue<BinaryNode<int,char>> nodes;


public:
    HuffmanTree(int totalLeaves){
        root = new BinaryNode<int, char>(0, '\0');
        nodes = 
        nodeCount = 1;
        leafCount = 0;
    }
    
    /* Stages the leaves before adding them to tree */
    void addLeaf(const int& k, const char& d) {
        
        BinaryNode<int, char> * tmpNode = new BinaryNode<int, char>;
        nodes -> key = k;
        nodes -> data = d;

        nodes[leafCount] = tmpNode;

#ifdef DEBUG
        cout << "Leaves: " << leafCount << endl;
        cout << tmpNode << endl;
#endif
        leafCount++;

        return;
    }


    /* Sorts all the nodes */
    void sortNodes() {
        BinaryNode<int, char> * temp;
        /* assume first one is sorted, i starts at 1 */
        for(int i=1; i < leafCount; i++) {
            for(int j=i; j > 0; j--) {
                if(nodes[j].key < nodes[j-1].key) {
                    /* swap the values */
                    temp = nodes[j];
                    nodes[j] = nodes[j-1];
                    nodes[j-1] = temp;
                }
            }
        }
    }

    void insert(const int& k, const char& d) {
        #ifdef DEBUG
        cout << "Inserting " << d << " with weight " << k << ".\n";
        #endif
        //Make a new BinaryNode
        BinaryNode<int, char> newNode = BinaryNode<int, char>(k, d);
        BinaryNode<int, char>* tempNode;

        //Insert newNode
        if(root->getKey() == 0) {
            #ifdef DEBUG
            cout << "\tTree is empty.\n";
            cout << "\tAdding node left of root.\n";
            #endif

            root->setLeft( &newNode );               //Set newNode as root's left child
            root->setKey(newNode.getKey());          //Change root's key

        } else {
            #ifdef DEBUG
            cout << "\tTree is not empty.\n";
            #endif

            /* If root's right child isn't empty */
            if(root->getRight() != NULL) {
                #ifdef DEBUG
                cout << "\tCreating new Node.\n";
                #endif

                tempNode = new BinaryNode<int, char>(0, '\0');       //Make a new node
                tempNode->setLeft(root);
                root = tempNode;
            }

            //Set newNode as root's right child
            #ifdef DEBUG
            cout << "\tAdding node right of root.\n";
            #endif
            root->setRight( &newNode );
            //Change root's key to the sum of its children's keys.
            root->setKey(root->getLeft()->getKey() + newNode.getKey());
        }

        //TODO Add some sort error exception for
        // weights that exceed 100 weightsFileError?

        nodeCount++;
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

    int getSize() {
        return nodeCount;
    }
};
#endif
