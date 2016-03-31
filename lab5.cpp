/* Compression and Decompression using Huffman Codes */

#include <fstream>
#include <sys/stat.h>
using namespace std;

int main() {
    ifstream weightsFile;
    char* weightsFileName = "weightsFile.bin";
    //ifstream encodedFile;
    
    //Get name of weightsFileName
    
    //Open weightsFile
    weightsFile.open( weightsFileName, ios::in|ios::binary );

    //Close weightsFile
    weightsFile.close();

    return 0;
}
