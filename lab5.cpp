/* Compression and Decompression using Huffman Codes */

#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream weightsFile;
    string weightsFileName = "weightsFile.bin";
    //ifstream encodedFile;
    
    //Get name of weightsFileName
    
    //Open weightsFile
    weightsFile.open( weightsFileName, std::ifstream::in );
    
    string c; 		// TODO change back to a char?
    int weight;

    string tmp;		// holds a line in weights file 
    stringstream ss;        // Using to convert string to int
    while(getline(weightsFile, tmp)) {
        c = tmp.substr(0,1); 	

        /* Convert string to int */
        ss << tmp.substr(2);
        ss >> weight;

        /* Clean out the buffer */
        ss.str("");
        ss.clear();

        cout << c << endl;
        cout << weight << endl;
        cout << endl;

        /* make trees here */
    }

    //Close weightsFile
    weightsFile.close();


    return 0;
}
