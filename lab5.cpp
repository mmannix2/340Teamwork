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
//#define DEBUG_make_weights
#define LOADFILES
#define USEFLAGS

using namespace std;

/* Using to count appearances of a char */
struct charTuple {
    int count;
    char letter;
};

/* Function Prototypes */
<<<<<<< HEAD
void encode( HuffmanTree, string );
void decode( HuffmanTree, string );

string getFileExt( string );
string getFileBasename( string );
string make_weights(string);


/*** Main Function ***/
int main(int argc, char* argv[]) {
    string weightsFile, compressFile;
    string hcodeFile, hzipFile;
    ofstream outFile;

    if(argc < 2) {
        cout << "Proper usage:" << endl;
        cout << "-c [file].txt\t\t\tCompresses a file" << endl;
        cout << "-x [file].hzip [file].hcode\tUnzips a file" << endl;
        cout << "Or for filename prompts:" << endl;
        cout << "-c" << endl;
        cout << "-x" << endl;
        return 1;

    } else if(string(argv[1]) == "-c") {         /* -c compresses a txt file */
        if((argc == 3) && (getFileExt(argv[2]) == "txt")) {
            cout << "Compressing "<< argv[2] << "..." << endl;
            compressFile = argv[2];
        } else {
            cout << "Enter the name of a .txt file to compress: ";
            getline(cin, compressFile);
            cout << "\n";

            if(!(getFileExt(hzipFile) == "hzip")) {
                cout << "Please enter valid .txt file." << endl;
                return 1;
            }
        }

        weightsFile = make_weights(compressFile);

        /* Build the tree */
        HuffmanTree tree = HuffmanTree(weightsFile);

        encode(tree, compressFile);

    } else if(string(argv[1]) == "-x") {
        if((argc == 4) && (getFileExt(argv[2]) == "hzip") && (getFileExt(argv[3]) == "hcodes")) {
            cout << "We're going to unzip a file using: " << argv[2] << " " << argv[3] << endl;
            hzipFile = argv[2];
            hcodeFile = argv[3];
        } else {

            cout << "Enter the name of a .hzip file to unzip: ";
            getline(cin, hzipFile);
            cout << "\n";

            if(!(getFileExt(hzipFile) == "hzip")) {
                cout << "Please enter valid .hzip file to unzip." << endl;
                return 1;
            }

            cout << "Enter the name of a .hcode file to interpret: ";
            getline(cin, hcodeFile);
            cout << "\n";

            if(!(getFileExt(hzipFile) == "hzip")) {
                cout << "Please enter valid .hcodes file." << endl;
                return 1;
            }
        }

        /* Build the tree */
        HuffmanTree tree = HuffmanTree(weightsFile);

        decode(tree, hzipFile, hcodeFile);

    } else if(string(argv[1]) == "-db") {
        /* Use this alone to debug some stuff. For matt and robert only */

        weightsFile = "files/weights";
        hcodeFile = "files/test.txt";
        compressFile = "files/MobyDick.txt";

        /* Custom weights from file */
        weightsFile = make_weights(compressFile);
        
        /* Build the tree */
        HuffmanTree tree = HuffmanTree(weightsFile);
     
    }

    return 0;
}

void encode(HuffmanTree tree, string fileName) {
    //TODO turn plain text into encoded binary. Right now it just reads the
    //input in and stores it into a .enc file
    ifstream inFile;
    ofstream outFile;
    
    string outFileName = getFileBasename(fileName) + ".hzip";
    char thisChar;
    
    /* Open the files */
    inFile.open(fileName.c_str());
    outFile.open(outFileName.c_str(), std::ofstream::out);

    while(inFile.good()) {
        thisChar = inFile.get();
        //Convert thisChar to binary
        string enc = tree.getEncoding(thisChar);
        outFile << thisChar;
    }
    //outFile << "\n";
    outFile.close();
}

void decode(HuffmanTree tree, string hzip, string hcodes) {
    ifstream encodedFile;
    encodedFile.open(hzip.c_str());
    
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

/* Takes in a file name and calculates the frequency
 * of each letter and saves a weights file as [filename]_weights
 *
 * Returns string name of weights file
 */
string make_weights(string fileName) {
    fstream compress;
    compress.open(fileName);

    string weights = getFileBasename(fileName) + "_weights";
    ofstream foundWeights;

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

    compress.close();

    

    /* Done putting the characters and their places */
    /* Print out our frequencies */
#ifdef DEBUG_make_weights
    cout << "\033[1mCharacter Frequency Vector\033[0m" << endl;
    for(charTuple& x : charFreq) {
        cout << x.letter << "\t" << x.count << endl;
    }
#endif

    foundWeights.open(weights);

    for(charTuple& x : charFreq) {
        foundWeights << x.letter << " " << x.count << endl;
    }

    foundWeights.close();

    return weights;
}
