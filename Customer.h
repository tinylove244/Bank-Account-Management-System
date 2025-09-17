#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

// The Customer class represents a bank customer
// Each customer has personal information and owns multiple accounts
class Customer {
private:
    int customerID;
    string name;
    string address;
    vector<Account*> accounts;  // customer can have multiple accounts

public:
    // Constructor & Destructor
    Customer(int id, const string& n, const string& addr);
    ~Customer();

    // Getters
    int getCustomerID() const;
    string getName() const;
    string getAddress() const;

    // Setters
    void setName(const string& n);
    void setAddress(const string& addr);

    // Account management
    void addAccount(Account* acc);
    void showAccounts() const;

    const std::vector<Account*>& getAccounts() const { return accounts; }
};
