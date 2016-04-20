/* CPSC 340
 * Lab #5 - lab5.cpp
 * Robert Blake
 * Matthew Mannix
 */

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "include/HuffmanTree.h"
#define DEBUG 
#define DEBUG_make_weights
#define LOADFILES

using namespace std;

/* Using to count appearances of a char */
struct charTuple {
    int count;
    char letter;
};

/* Function Prototypes */
void encode( string );
void decode( string );
string getFileExt( string );
string getFileBasename( string );
vector<charTuple> make_weights(string);


int main() {
    string weightsFile, codeFile, compressFile;
    ofstream outFile;

#ifdef LOADFILES
    weightsFile = "files/weights";
    codeFile = "files/test.txt";
    compressFile = 
#endif

     
#ifndef LOADFILES 
    /* Get fileName */
    cout << "Please enter the name of the weights file: ";
    getline(cin, weightsFile);
    cout << "\n";
#endif
    
    /* Build the tree */
    HuffmanTree tree = HuffmanTree(weightsFile);
    
#ifndef LOADFILES
    /* Get the next fileName  */
    cout << "Please enter the name of the file to encode or decode: ";
    getline(cin, codeFile);
    cout << "\n";
#endif

    
    /* encode or decode the new file*/
    /* I don't know a good way to determine if the new file is encoded or not.
       so I am assuming an encoded file will end with .enc */
    if(getFileExt(codeFile)=="enc") { //If new file is encoded
        #ifdef DEBUG
        cout << "Decoding " << codeFile << ".\n";
        #endif
        decode(codeFile);
    }
    else { //file is plain text
        #ifdef DEBUG
        cout << "Encoding " << codeFile << ".\n";
        #endif
        encode(codeFile);
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
    //outFile << "\n";
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

/**************************
 * Functions for problem 2 *
 * ************************/
vector<charTuple> make_weights(string fileName) {
    fstream compress;
    compress.open(fileName);
    string line;
    bool firstChar = true;      // allows us to populate the vector 
    bool haveIt = false;


    vector<charTuple> charFreq;
#ifdef DEBUG_make_weights
    cout << "*\033[1m*************************************" << endl;
    cout << "We're in the make_weights function now" << endl;
    cout << "**************************************\033[0m" << endl;
#endif
    /* Loop through each line in file */
    while(getline(compress, line)) {
        cout << line << endl;
        /* Loop through each character in line */
        for(char& c : line) {
#ifdef DEBUG_make_weights
            cout << "Found char: " << c << endl;
#endif
            if(firstChar) {
#ifdef DEBUG_make_weights
                cout << "\tAdding the first character: " << c << endl;
#endif
                charTuple * tmp = new charTuple;
                tmp->letter = c;
                tmp->count = 1;
                charFreq.push_back(*tmp);

                firstChar = false;
            } else {
                
                /* Check if the character is already in our vector */ 
                for(charTuple& x : charFreq) {
                    if(x.letter == c) {
                        x.count++;
#ifdef DEBUG_make_weights
                        cout << "\tHave it!\tCount: " << x.count << endl;
#endif
                        haveIt = true;
                        break;
                    }               
                }

                if(!haveIt) {
#ifdef DEBUG_make_weights
                    cout << "\tAdding to the vector" << endl;
#endif
                    charTuple * tmp = new charTuple;
                    tmp->letter = c;
                    tmp->count = 1;
                    charFreq.push_back(*tmp);

                    haveIt = false;
                } else {
                    haveIt = false;
                }
            }
        }
    }

    /* Done putting the characters and their places */
    /* Print out our frequencies */
#ifdef DEBUG_make_weights
    cout << "\033[1mCharacter Frequency Vector\033[0m" << endl;
    for(charTuple& x : charFreq) {
        cout << x.letter << "\t" << x.count << endl;
    }
#endif

    return charFreq;
}
