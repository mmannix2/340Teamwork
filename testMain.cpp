/* Compression and Decompression using Huffman Codes */
#define DEBUG

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "HuffmanTree.h"
#include "BinaryNode.h"
using namespace std;

/* Function Prototypes */
HuffmanTree buildTree( string );
void encode( string );
void decode( string );
string getFileExt( string );

int main() {
    string fileName;
    ofstream outFile;

    /* Get fileName */
    cout << "Please enter the name of the weights file: ";
    getline(cin, fileName);
    cout << "\n";
    
    /* Build the tree */
    HuffmanTree tree = buildTree(fileName);
    tree.print();
    
    return 0;
}

HuffmanTree buildTree( string weightsFileName ) {
    ifstream weightsFile;
    HuffmanTree tree = HuffmanTree(5);
    
    string tmp;		// holds a line in weights file 
    stringstream ss;    // Using to convert string to int
    char c; 		
    int weight;

    // TODO add some line counter thing
    
    /* Open weightsFile */
    weightsFile.open( weightsFileName.c_str() ); 
    
    while(getline(weightsFile, tmp)) {
        #ifdef DEBUG
        cout << "tmp: " + tmp  + "\n";
        #endif
        
        c = tmp.at(0); 	
        
        /* Convert string to int */
        ss << tmp.substr(2);
        ss >> weight;
        
        /* Clean out the buffer */
        ss.str("");
        ss.clear();
        
        tree.addLeaf(weight, c);

    }
    //Close weightsFile
    weightsFile.close();
    cout << "Tree size: " <<  tree.getSize() << endl;
    
    return tree;
}
