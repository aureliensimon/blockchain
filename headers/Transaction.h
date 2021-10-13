#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

#include <cstdint>
#include <ctime>
#include <iostream>

using namespace std;

class Transaction {
public:
    Transaction(string from, string to, double amount);
    string from;
    string to;
    double amount;
    time_t timeT;
};

#endif //BLOCKCHAIN_TRANSACTION_H
