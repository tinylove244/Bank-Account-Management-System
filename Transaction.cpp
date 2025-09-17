#include "Transaction.h"
#include <iostream>
using namespace std;

// Constructor
Transaction::Transaction(double amt, const string& t, const string& d) {
    this->amount = amt;
    this->type = t;
    this->date = d;
}

// Destructor
Transaction::~Transaction() {}

// Getters
double Transaction::getAmount() const {
    return amount;
}

string Transaction::getType() const {
    return type;
}

string Transaction::getDate() const {
    return date;
}

// Display
void Transaction::display() const {
    cout << "[" << date << "] "
         << type << ": " << amount << endl;
}
