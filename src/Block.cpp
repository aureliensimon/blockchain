#include "../headers/Block.h"
#include "../lib/sha256.h"

Block::Block (uint32_t index, const string &data) : _index(index), _data(data) {
    _nonce = -1;
    _time = time(nullptr);
}

string Block::GetHash () {
    return _hash;
}

void Block::MineBlock (uint32_t difficulty) {
    char cstr[difficulty - 1];

    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    string str(cstr);

    do {
        _nonce++;
        _hash = _CalculateHash();
    } while (_hash.substr(0, difficulty) != str);

    cout << "---" << endl;
    cout << "Block         : " << _index << endl;
    cout << "Date          : " << ctime(&_time);
    cout << "Nonce         : " << _nonce << endl;
    cout << "Data          : " << _data << endl;
    cout << "Previous hash : " << previousHash << endl;
    cout << "Hash          : " << _hash << endl;
    cout << "---" << endl;
}

inline string Block::_CalculateHash () const {
    stringstream stream;

    stream << _index << _time << _data << _nonce << previousHash;

    return sha256(stream.str());
}
