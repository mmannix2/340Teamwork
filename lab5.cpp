/* Compression and Decompression using Huffman Codes */
#define DEBUG

#include <string>
#include <fstream>
#include <iostream>

#include "include/HuffmanTree.h"
using namespace std;

/* Function Prototypes */
void encode( string );
void decode( string );
string getFileExt( string );
string getFileBasename( string );

int main() {
    string fileName;
    ofstream outFile;
     
    /* Get fileName */
    cout << "Please enter the name of the weights file: ";
    getline(cin, fileName);
    cout << "\n";
    
    /* Build the tree */
    HuffmanTree tree = HuffmanTree(fileName);
    
    //tree.print();
    
    /* Get the next fileName  */
    cout << "Please enter the name of the file to encode or decode: ";
    getline(cin, fileName);
    cout << "\n";
    
    /* encode or decode the new file*/
    /* I don't know a good way to determine if the new file is encoded or not.
       so I am assuming an encoded file will end with .enc */
    if(getFileExt(fileName)=="enc") { //If new file is encoded
        #ifdef DEBUG
        cout << "Decoding " << fileName << ".\n";
        #endif
        decode(fileName);
    }
    else { //file is plain text
        #ifdef DEBUG
        cout << "Encoding " << fileName << ".\n";
        #endif
        encode(fileName);
    }

    return 0;
}

void encode(string fileName) {
    //TODO turn plain text into encoded binary. Right now it just reads the
    //input in and stores it into a .enc file
    ifstream inFile;
    ofstream outFile;
    string outFileName = getFileBasename(fileName) + ".enc";
    char thisChar;
    
    /* Open the files */
    inFile.open(fileName.c_str());
    outFile.open(outFileName.c_str(), std::ofstream::out);

    while(inFile.good()) {
        thisChar = inFile.get();
        //Convert thisChar to binary
        outFile << thisChar;
    }
    outFile << "\n";
    outFile.close();
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

string getFileBasename(string fileName) {
    //If fileName has an extension
    if(fileName.find_last_of(".") != string::npos) {
        return fileName.substr(0, fileName.find_last_of("."));
    }
    else {
        return fileName;
    }
}
