#include "headers/Blockchain.h"

int main() {

    Blockchain bchain = Blockchain();

    Transaction t1 = Transaction("Alfred", "Tom", 100);
    Transaction t2 = Transaction("Smith", "Patrick", 2);
    Transaction t3 = Transaction("Remy", "Luc", 64);
    Transaction t4 = Transaction("Luc", "Tom", 784);

    bchain.addBlock(Block({t1, t2, t3}));
    bchain.addBlock(Block({t4}));
    bchain.addBlock(Block({}));

    return 0;
}