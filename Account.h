#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string ownerName;
    vector<Transaction> history;

public:
    // Constructor & Destructor
    Account(int accNum, const string& owner, double initBalance = 0.0);
    virtual ~Account();

    // Getters
    int getAccountNumber() const;
    double getBalance() const;
    string getOwnerName() const;

    // Setters
    void setOwnerName(const string& name);

    // Core Methods
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void displayInfo() const;

    // Operator Overloading
    Account& operator+=(const Transaction& t); // add transaction & update balance
    bool operator==(const Account& other) const; // compare accounts

    // Show transaction history
    void showHistory() const;
};
