#include <iostream>
using namespace std;

#include "include/HuffmanTree.h"
#include "include/BinaryNode.h"

int main() {
    HuffmanTree ht = HuffmanTree("files/weights");
    
    //ht.getBitSeq('E');
    ht.print();

    return 0;
}
