#include "SavingsAccount.h"
#include <iostream>
using namespace std;

// Constructor
SavingsAccount::SavingsAccount(int accNumber, const string& owner, double balance, double rate)
    : Account(accNumber, owner, balance) {
    this->interestRate = rate;
}

// Destructor
SavingsAccount::~SavingsAccount() {}

// Getter & Setter
double SavingsAccount::getInterestRate() const {
    return interestRate;
}

void SavingsAccount::setInterestRate(double rate) {
    this->interestRate = rate;
}

// Apply interest to balance
void SavingsAccount::applyInterest() {
    double interest = balance * (interestRate / 100.0);
    balance += interest;

    // Ghi lại transaction
    Transaction t(interest, "Interest", "N/A");
    history.push_back(t);
}

// Override withdraw
bool SavingsAccount::withdraw(double amount) {
    // Ví dụ: SavingsAccount không cho rút nếu dưới 100 trong tài khoản
    if (balance - amount < 100) {
        cout << "Withdrawal denied: Savings account must keep at least 100." << endl;
        return false;
    }
    balance -= amount;
    Transaction t(-amount, "Withdrawal", "N/A");
    history.push_back(t);
    return true;
}
