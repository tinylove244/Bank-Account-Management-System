#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
using namespace std;

// The Bank class manages all customers and their accounts
class Bank {
private:
    string bankName;
    vector<Customer*> customers;

public:
    // Constructor & Destructor
    Bank(const string& name);
    ~Bank();

    // Getters
    string getBankName() const;

    // Setters
    void setBankName(const string& name);

    // Customer management
    void addCustomer(Customer* c);
    Customer* findCustomerByID(int id) const;
    void showAllCustomers() const;
};
