#include <iostream>
#include "headers/Blockchain.h"

int main() {

    Blockchain bchain = Blockchain();

    cout << "Mining block 1 ..." << endl;
    bchain.addBlock(Block(1, "Data 1"));

    cout << "Mining block 2 ..." << endl;
    bchain.addBlock(Block(2, "Data 2"));

    cout << "Mining block 3 ..." << endl;
    bchain.addBlock(Block(2, "Data 3"));

    return 0;
}