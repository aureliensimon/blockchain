#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <iterator>
#include "Transaction.h"

using namespace std;

class Block {
public:
    string previousHash;

    Block(uint32_t index, vector<Transaction> transactions);
    string GetHash();
    void MineBlock(uint32_t difficulty);

private:
    uint32_t _index;
    int64_t _nonce;
    vector<Transaction> _transactions;
    string _hash;
    time_t _time;

    string _CalculateHash() const;
};


#endif //BLOCKCHAIN_BLOCK_H
