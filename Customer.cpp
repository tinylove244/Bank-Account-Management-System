#include "Customer.h"
#include <iostream>
using namespace std;

// Constructor
Customer::Customer(int id, const string& n, const string& addr) {
    this->customerID = id;
    this->name = n;
    this->address = addr;
}

// Destructor
Customer::~Customer() {
    // Clean up dynamic accounts if needed
    for (auto acc : accounts) {
        delete acc;
    }
    accounts.clear();
}

// Getters
int Customer::getCustomerID() const {
    return customerID;
}

string Customer::getName() const {
    return name;
}

string Customer::getAddress() const {
    return address;
}

// Setters
void Customer::setName(const string& n) {
    this->name = n;
}

void Customer::setAddress(const string& addr) {
    this->address = addr;
}

// Add a new account
void Customer::addAccount(Account* acc) {
    if (acc != nullptr) {
        accounts.push_back(acc);
    }
}

// Show all accounts of this customer
void Customer::showAccounts() const {
    cout << "Customer " << name << " (ID: " << customerID << ") owns:\n";
    for (auto acc : accounts) {
        acc->displayInfo();
    }
}
