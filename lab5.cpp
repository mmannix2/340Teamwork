/* Compression and Decompression using Huffman Codes */
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
    HuffmanTree tree;
    ofstream outFile;

    /* Get fileName */
    cout << "Please enter the name of the weights file: ";
    getline(cin, fileName);
    cout << "\n";
    
    /* Build the tree */
    tree = buildTree(fileName);
    
    /* Get the next fileName  */
    cout << "Please enter the name of the file to encode or decode: ";
    getline(cin, fileName);
    cout << "\n";
    
    /* encode or decode the new file*/
    /*
    //I don't know a good way to determine if the new file is encoded or not.
    if() { //If new file is plain text
        encode(fileName)
    }
    else if() { //If file is encoded
        decode(fileName);
    }
    */

    return 0;
}

HuffmanTree buildTree( string weightsFileName ) {
    ifstream weightsFile;
    HuffmanTree tree = HuffmanTree();
    
    string tmp;		// holds a line in weights file 
    stringstream ss;    // Using to convert string to int
    char c; 		
    int weight;
    
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
        
        tree.insert(weight, c);
    }
    //Close weightsFile
    weightsFile.close();
    
    return tree;
}

void encode(string fileName) {
    ifstream inFile;
    inFile.open(fileName.c_str());
    
    //TODO turn plain text into encoded binary
    //This will write to a file.
}

void decode(string fileName) {
    ifstream encodedFile;
    encodedFile.open(fileName.c_str());
    
    //TODO turn plain text into encoded binary
    //This will write to a file.
}

string getFileExt(string fileName) {
    if(fileName.find_last_of(".") != string::npos)
        return fileName.substr(fileName.find_last_of(".")+1);
    return "";
}
