#include "../headers/Block.h"
#include "../lib/sha256.h"

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        os << "\nFrom : " << v[i].from << " To : " << v[i].to << " (" << v[i].amount << ") " << v[i].timeT;
        if (i != v.size() - 1)
            os << "";
    }
    return os;
}

Block::Block (vector<Transaction> transactions) : _transactions(transactions) {
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
    cout << "Block           " << endl;
    cout << "Date          : " << ctime(&_time);
    cout << "Nonce         : " << _nonce << endl;
    cout << "Transactions  : " << _transactions << endl;
    cout << "Previous hash : " << previousHash << endl;
    cout << "Hash          : " << _hash << endl;
    cout << "---" << endl;
}

inline string Block::_CalculateHash () const {
    stringstream stream;

    stream << _time << _transactions << _nonce << previousHash;

    return sha256(stream.str());
}
