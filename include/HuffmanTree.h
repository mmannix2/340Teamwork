/* A binary tree used for Huffman Encoding */
#ifndef _HUFFMANTREE_H_INCLUDED
#define _HUFFMANTREE_H_INCLUDED

#define CONST_DEBUG

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
        int nodeCount = 0;
        int leafCount = 0;

        // Get all nodes from weightsFile
        weightsFile.open(fileName.c_str());
        
        while(getline(weightsFile, temp)) {
            #ifdef CONST_DEBUG
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
            #ifdef CONST_DEBUG
            cout << "numNodes: " << (int)(nodes.size()) << "\n";
            #endif
            
            int smallest = 0;
            int nextSmallest = 0;
            
            // Find smallest node
            for( int i=1; i < (int)(nodes.size()); i++) {
                #ifdef CONST_DEBUG
                cout << "Node " << i+1 << ": ";
                cout << nodes.at(i).getData() << "\n"; 
                #endif
                // Find the smallest node by key (weight)
                if( nodes.at(i).getKey() < nodes.at(smallest).getKey()) {
                    #ifdef CONST_DEBUG
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
                #ifdef CONST_DEBUG
                cout << "Node " << i+1 << ": ";
                cout << nodes.at(i).getData() << "\n"; 
                #endif
                // Find the smallest node by key (weight)
                if( nodes.at(i).getKey() < nodes.at(nextSmallest).getKey()) {
                    #ifdef CONST_DEBUG
                    cout << "\n" << "nextSmallest -> thisNode.\n";
                    #endif
                    // Swap smallest and thisNode
                    nextSmallest = i;
                }
            }
            
            BinaryNode<int, char> nextSmallestNode = nodes.at(nextSmallest);
            nodes.erase(nodes.begin()+nextSmallest);
            
            #ifdef CONST_DEBUG
            cout << "Smallest Node: " << smallestNode.getData();
            cout << " weight: " << smallestNode.getKey() << "\n";
            cout << "Next Smallest Node: " << nextSmallestNode.getData();
            cout << " weight: " << nextSmallestNode.getKey() << "\n";
            #endif
            
            // Replace smallestNode and nextSmallestNode with a new node
            BinaryNode<int, char> newNode = BinaryNode<int, char>();//('\0', -1);
            newNode.setKey(smallestNode.getKey() + nextSmallestNode.getKey());
            newNode.setLeft(&smallestNode);
            newNode.setRight(&nextSmallestNode);

            nodes.insert(nodes.begin(), newNode);
            nodeCount++;
            #ifdef CONST_DEBUG
            cout << "Inserting a new node with weight of ";
            cout << newNode.getKey() << "\n";
            #endif
        }
        #ifdef CONST_DEBUG
        cout << "numNodes: " << (int)(nodes.size()) << "\n";
        #endif
        root = &(nodes.at(0));
        //TODO Consider deleting nodes to free up memory
        //nodes.clear();
        //delete nodes;
    }

    /*  returns the binary sequence that corresponds to the given char
     *  TODO Right now just returns 1 for every char; fix this.
     */
    string getEncoding( char thisChar) {
        string encoding = "";
        
        BinaryNode<int, char>* temp = root;
        
        if(temp->getRight()->getData() == thisChar) {
            //cout << "Root->right: " << root->getRight()->getData() << "\n";
            encoding += "1";
            cout << "Match found.\n";
        }
        else {
            encoding += "0";
            cout << "Match not found.\n";
        }

        encoding = "1"; 
        cout << "thisChar: " << thisChar << " enc: " << encoding << "\n";
        return encoding;
    }

    /*  returns the total number of leaves in this HuffmanTree 
        A leaf has no children and will have both a weight and value */
    int getLeafCount() {
        return leafCount;
    }
    
    /*  returns the total number of nodes in this HuffmanTree
        A node is any BinaryNode that exists in the HuffmanTree.
        A node may have children xor a value, but will always have a weight. */
    int getNodeCount() {
        return nodeCount;
    }

    void print() {
        cout << "Root:\n\tKey: " << root->getKey();
        cout << " Data: " << root->getData() << "\n";
        
        /*
        if(root->hasRight()) {
            cout << "\tRoot has right!\n";
            print(root->getRight());
        }
        else {
            cout << "\tRoot does NOT have right!!!\n";
        }
        */
        if(root->hasLeft()) {
            cout << "\tRoot has left!\n";
            print(root->getLeft());
        }
        else {
            cout << "\tRoot does NOT have left!!!\n";
        }
    }

    void print(BinaryNode<int, char>* node) {
        cout << "Node:\n\tKey: " << node->getKey();
        cout << " Data: " << node->getData() << "\n";
        
        if(node->hasRight()) {
            cout << "\tNode has right!\n";
            print(node->getRight());
        }
        else {
            cout << "\tNode does NOT have right!!!\n";
        }
        if(node->hasLeft()) {
            cout << "\tNode has left!\n";
            print(node->getLeft());
        }
        else {
            cout << "\tNode does NOT have left!!!\n";
        }
    }
};
#endif
