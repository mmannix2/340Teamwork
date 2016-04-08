/* CPSC 340
 * Lab #5 - lab5.cpp
 * A binary tree used for Huffman Encoding
 * Robert Blake
 * Matthew Mannix
 */
#ifndef _HUFFMANTREE_H_INCLUDED
#define _HUFFMANTREE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
using namespace std;

#include "BinaryNode.h"

class HuffmanTree {

private:
    BinaryNode<int, char>* root;
    int nodeCount;
    int leafCount;

public:
    /*  Constructs a HuffmanTree from a given fileName. */
    /*  I'm sure there are ways to clean this up, but this works for now.
        It uses a vector which is like C++'s version of an ArrayList instead
        of a queue because I was hving trouble getting the queue to work right.
        After the HuffmanTree is built, the vector of BinaryNodes is no longer
        required. */
    /* TODO Remove debug output & clear up code. */
    HuffmanTree(string fileName) {
        vector< BinaryNode<int, char> > nodes;
        ifstream weightsFile;
        string temp;
        nodeCount = 0;
        leafCount = 0;

        // Get all nodes from weightsFile
        weightsFile.open(fileName.c_str());
        
        while(getline(weightsFile, temp)) {
            #ifdef DEBUG
            cout << "thisLine: " << temp << "\n";
            #endif
            // Read in weight and value
            stringstream ss;
            int weight;
            ss << temp.substr(2);
            ss >> weight;
            char value = temp.at(0);
            
            // Make newNode with weight and value
            BinaryNode<int, char>* newNode = new BinaryNode<int, char>(
                weight, value);

            // Add newNode to nodes vector
            nodes.push_back(*newNode);
            nodeCount++;
            leafCount++;
        }
        // Combine nodes into tree
        while( (int)(nodes.size()) > 1) {
            #ifdef DEBUG
            cout << "numNodes: " << (int)(nodes.size()) << "\n";
            #endif
            
            int smallest = 0;
            int nextSmallest = 0;
            
            // Find smallest node
            for( int i=1; i < (int)(nodes.size()); i++) {
                #ifdef DEBUG
                cout << "Node " << i+1 << ": ";
                cout << nodes.at(i).getData() << "\n"; 
                #endif
                // Find the smallest node by key (weight)
                if( nodes.at(i).getKey() < nodes.at(smallest).getKey()) {
                    #ifdef DEBUG
                    cout << "\n" << "smallest -> thisNode.\n";
                    #endif
                    // Swap smallest and thisNode
                    smallest = i;
                }
            }
            
            BinaryNode<int, char> smallestNode = nodes.at(smallest);
            nodes.erase(nodes.begin()+smallest);

            // Find nextSmallest node
            for( int i=1; i < (int)(nodes.size()); i++) {
                #ifdef DEBUG
                cout << "Node " << i+1 << ": ";
                cout << nodes.at(i).getData() << "\n"; 
                #endif
                // Find the smallest node by key (weight)
                if( nodes.at(i).getKey() < nodes.at(nextSmallest).getKey()) {
                    #ifdef DEBUG
                    cout << "\n" << "nextSmallest -> thisNode.\n";
                    #endif
                    // Swap smallest and thisNode
                    nextSmallest = i;
                }
            }
            
            BinaryNode<int, char> nextSmallestNode = nodes.at(nextSmallest);
            nodes.erase(nodes.begin()+nextSmallest);
            
            #ifdef DEBUG
            cout << "Smallest Node: " << smallestNode.getData();
            cout << " weight: " << smallestNode.getKey() << "\n";
            cout << "Next Smallest Node: " << nextSmallestNode.getData();
            cout << " weight: " << nextSmallestNode.getKey() << "\n";
            #endif
            
            // Replace smallestNode and nextSmallestNode with a new node
            BinaryNode<int, char> newNode = BinaryNode<int, char>();//('\0', -1);
            newNode.setKey(smallestNode.getKey() + nextSmallestNode.getKey());
            #ifdef DEBUG
            cout << "Left: -> ";
            cout << "Char: " << nextSmallestNode.getData() << " ";
            cout << "Key: " << nextSmallestNode.getKey() << "\n";
            
            cout << "Right: -> ";
            cout << "Char: " << smallestNode.getData() << " ";
            cout << "Key: " << smallestNode.getKey() << "\n";
            #endif
            newNode.setLeft(&nextSmallestNode);
            newNode.setRight(&smallestNode);
            nodes.insert(nodes.begin(), newNode);
            nodeCount++;
            #ifdef DEBUG
            cout << "nodeCount: " << getNodeCount() << "\n";
            cout << "Inserting a new node with weight of ";
            cout << newNode.getKey() << "\n";
            #endif
        }
        #ifdef DEBUG
        cout << "numNodes: " << (int)(nodes.size()) << "\n";
        cout << "nodeCount: " << getNodeCount() << "\n";
        #endif
        root = &(nodes.at(0));
        //TODO Consider deleting nodes to free up memory
        //nodes.clear();
        //delete nodes;
    }

    /*  Returns a c string of 1s and 0s that represents the encoding for
        the given char. */
    char getBitSeq(char c) {
        //cout << "c: " << c << "right: " << root->getRight()->getData() << "\n";
        // Right is 1, Left is 0
        if(root != NULL) {
            cout << "root != NULL.\n";
            char k = root->getRight()->getData();
            cout << "k: " << k << "\n";
            cout << "c: " << c << "\n";
        }
        else {
            cout << "root == NULL. Bailing...\n";
        }

        return '\0';
    }
    
    /*  Prints out all elements in the HuffmanTree from greatest weight
        to least. */
    void print() {
        cout << "leafCount: " << getLeafCount();
        cout << " nodeCount: " << getNodeCount() << "\n";
        print(root);
    }
    
    void print(BinaryNode<int, char>* node) {
        /*
        cout << "Node->Left: " << node->getLeft() << "\n";
        cout << "Node->Right: " << node->getRight() << "\n";
        */
        if(node != 0) {
            if(node->isLeaf()) {
                cout << "This node is a leaf.\n";
                cout << "\tChar: " << node->getData() << " "; 
                cout << "Weight: " << node->getKey() << "\n";
            }
            else {
                cout << "This node is NOT a leaf.\n";
                cout << "\tChar: " << node->getData() << " "; 
                cout << "Weight: " << node->getKey() << "\n";
                // Check to the Right
                if(node->getRight() != NULL) {
                   print(node->getRight());
                }
                // Check to the Left
                if(node->getLeft() != NULL) {
                    print(node->getLeft());
                }
            }
        }
    }
    
    /*  Returns the total number of leaves in this HuffmanTree 
        A leaf has no children and will have both a weight and value */
    int getLeafCount() {
        return leafCount;
    }
    
    /*  Returns the total number of nodes in this HuffmanTree
        A node is any BinaryNode that exists in the HuffmanTree.
        A node may have children xor a value, but will always have a weight. */
    int getNodeCount() {
        return nodeCount;
    }
};
#endif
