/* Compression and Decompression using Huffman Codes */

#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream weightsFile;
    char* weightsFileName = "weightsFile.bin";
    //ifstream encodedFile;
    
    //Get name of weightsFileName
    
    //Open weightsFile
    weightsFile.open( weightsFileName, std::ifstream::in );
    
    string c; 		// TODO change back to a char?
    int weight;

    string tmp;		// holds a line in weights file 
    stringstream ss;
    while(getline(weightsFile, tmp)) {
   	c = tmp.substr(0,1); 	

	ss << tmp.substr(2);
	ss >> weight;

	ss.str("");
	ss.clear();

	cout << c << endl;
	cout << weight << endl;
	cout << endl;
    }

    //Close weightsFile
    weightsFile.close();


    return 0;
}
