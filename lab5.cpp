/* Compression and Decompression using Huffman Codes */

#include <fstream>
#include <sys/stat.h>
#include <iostream>
using namespace std;

int main() {
    ifstream weightsFile;
    char* weightsFileName = "weightsFile.bin";
    //ifstream encodedFile;
    
    //Get name of weightsFileName
    
    //Open weightsFile
    weightsFile.open( weightsFileName, std::ifstream::in );
    
    char c;
    double w;
    
    while(!weightsFile.eof()) {
        //Get character
        c = weightsFile.get();
        //Eat whitespace
        //Get weight
        if(c == '\n') {
            cout << endl;
        }
        else {
            cout << c;
        }
    }
    //Close weightsFile
    weightsFile.close();

    return 0;
}
