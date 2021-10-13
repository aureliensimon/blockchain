#include "../headers/Blockchain.h"

Blockchain::Blockchain () {
    _chain.emplace_back(Block(0, {}));
    _difficulty = 1;
}

void Blockchain::addBlock (Block newBlock) {
    newBlock.previousHash = _GetLastBlock().GetHash();
    newBlock.MineBlock(_difficulty);
    _chain.push_back(newBlock);
}

Block Blockchain::_GetLastBlock () const {
    return _chain.back();
}