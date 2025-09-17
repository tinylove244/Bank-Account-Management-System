#include "Account.h"

// Constructor
Account::Account(int accNum, const string& owner, double initBalance) {
    this->accountNumber = accNum;
    this->ownerName = owner;
    this->balance = initBalance;
}

// Destructor
Account::~Account() {}

// Getters
int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

string Account::getOwnerName() const {
    return ownerName;
}

// Setters
void Account::setOwnerName(const string& name) {
    this->ownerName = name;
}

// Deposit
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        history.emplace_back(amount, "Deposit");
    } else {
        cout << "Deposit amount must be positive.\n";
    }
}

// Withdraw
bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        history.emplace_back(-amount, "Withdrawal");
        return true;
    }
    cout << "Withdrawal failed: insufficient funds or invalid amount.\n";
    return false;
}

// Display account info
void Account::displayInfo() const {
    cout << "Account Number: " << accountNumber
         << ", Owner: " << ownerName
         << ", Balance: " << balance << endl;
}

// Operator += (add transaction)
Account& Account::operator+=(const Transaction& t) {
    if (t.getType() == "Deposit") {
        balance += t.getAmount();
        history.push_back(t);
    } else if (t.getType() == "Withdrawal") {
        if (t.getAmount() <= balance) {
            balance -= t.getAmount();
            history.push_back(t);
        } else {
            cout << "Insufficient funds for transaction.\n";
        }
    }
    return *this;
}

// Operator == (compare accounts by account number)
bool Account::operator==(const Account& other) const {
    return this->accountNumber == other.accountNumber;
}

// Show history
void Account::showHistory() const {
    cout << "Transaction history for account " << accountNumber << ":\n";
    for (const auto& t : history) {
        t.display();
    }
}
