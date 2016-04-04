/* Compression and Decompression using Huffman Codes */

#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <sstream>

#include "HuffmanTree.h"
#include "BinaryNode.h"
using namespace std;

int main() {
    ifstream weightsFile;
    string weightsFileName = "weightsFile.bin";
    //ifstream encodedFile;
    
    //Get name of weightsFileName
    
    //Open weightsFile
    weightsFile.open( weightsFileName, std::ifstream::in );
    
    char c; 		
    int weight;

    string tmp;		// holds a line in weights file 
    stringstream ss;        // Using to convert string to int

    HuffmanTree tree = HuffmanTree();
    
    while(getline(weightsFile, tmp)) {
        c = tmp.at(0); 	

        /* Convert string to int */
        ss << tmp.substr(2);
        ss >> weight;

        /* Clean out the buffer */
        ss.str("");
        ss.clear();

        /* Debug
            cout << c << endl;
            cout << weight << endl;
            cout << endl;
        */

        tree.insert(weight, c);

    }

    tree.print();

    //Close weightsFile
    weightsFile.close();


    return 0;
}
