/* A binary tree used for Huffman Encoding */
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
    /*
    HuffmanTree(int totalLeaves){
        root = new BinaryNode<int, char>(0, '\0');
        //nodes = ; 
        nodeCount = 1;
        leafCount = 0;
    }
    */

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
            BinaryNode<int, char>* newNode = new BinaryNode<int, char>(weight, value);
            
            // Add newNode to nodes vector
            nodes.push_back(*newNode);
            nodeCount++;
            leafCount++;
        }
        
        cout << "numNodes: " << (int)(nodes.size()) << "\n";

        // Combine nodes into tree
        while( (int)(nodes.size()) > 1) {
            cout << "numNodes: " << (int)(nodes.size()) << "\n";
            
            int smallest = 0;
            int nextSmallest = 0;
            
            // Find smallest node
            for( int i=1; i < (int)(nodes.size()); i++) {
                cout << "Node " << i+1 << ": " << nodes.at(i).getData() << "\n"; 
                // Find the smallest node by key (weight)
                if( nodes.at(i).getKey() < nodes.at(smallest).getKey()) {
                    //cout << thisNode->getKey() << " < " << smallest->getKey();
                    cout << "\n" << "smallest -> thisNode.\n";
                    // Swap smallest and thisNode
                    smallest = i;
                }
            }
            
            BinaryNode<int, char> smallestNode = nodes.at(smallest);
            nodes.erase(nodes.begin()+smallest);

            // Find nextSmallest node
            for( int i=1; i < (int)(nodes.size()); i++) {
                cout << "Node " << i+1 << ": " << nodes.at(i).getData() << "\n"; 
                // Find the smallest node by key (weight)
                if( nodes.at(i).getKey() < nodes.at(nextSmallest).getKey()) {
                    //cout << thisNode->getKey() << " < " << smallest->getKey();
                    cout << "\n" << "nextSmallest -> thisNode.\n";
                    // Swap smallest and thisNode
                    nextSmallest = i;
                }
            }
            
            BinaryNode<int, char> nextSmallestNode = nodes.at(nextSmallest);
            nodes.erase(nodes.begin()+nextSmallest);

            cout << "Smallest Node: " << smallestNode.getData();
            cout << " weight: " << smallestNode.getKey() << "\n";
            cout << "Next Smallest Node: " << nextSmallestNode.getData();
            cout << " weight: " << nextSmallestNode.getKey() << "\n";
        
            // Replace smallestNode and nextSmallestNode with a new node
            BinaryNode<int, char> newNode = BinaryNode<int, char>();//('\0', -1);
            newNode.setKey(smallestNode.getKey() + nextSmallestNode.getKey());
            nodes.insert(nodes.begin(), newNode);
            nodeCount++;
            cout << "Inserting a new node with weight of " << newNode.getKey() << "\n";
        }
        cout << "numNodes: " << (int)(nodes.size()) << "\n";
        root = &(nodes.at(0));
        //nodes.clear();
        //delete nodes;
    }

#ifdef OLD_CODE
    /*  this function is no longer needed when the HuffmanTree(string) 
        constuctor is used. */
    /* Sorts all the nodes */
    /*
    void sortNodes() {
        BinaryNode<int, char> * temp;
        */
        /* assume first one is sorted, i starts at 1 */
        /*
        for(int i=1; i < leafCount; i++) {
            for(int j=i; j > 0; j--) {
                if(nodes[j].key < nodes[j-1].key) {
                    */
                    /* swap the values */
                    /*
                    temp = nodes[j];
                    nodes[j] = nodes[j-1];
                    nodes[j-1] = temp;
                }
            }
        }
    }
    */
#endif 
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
};
#endif
