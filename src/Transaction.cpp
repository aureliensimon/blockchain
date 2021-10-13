#include "../headers/Transaction.h"

Transaction::Transaction(string from, string to, double amount) : from(from), to(to), amount(amount) {
    timeT = time(nullptr);
}