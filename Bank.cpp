#include "Bank.h"
using namespace std;

// Constructor
Bank::Bank(const string& name) {
    this->bankName = name;
}

// Destructor
Bank::~Bank() {
    for (auto c : customers) {
        delete c;
    }
    customers.clear();
}

// Getter
string Bank::getBankName() const {
    return bankName;
}

// Setter
void Bank::setBankName(const string& name) {
    this->bankName = name;
}

// Add customer
void Bank::addCustomer(Customer* c) {
    if (c != nullptr) {
        customers.push_back(c);
    }
}

// Find customer by ID
Customer* Bank::findCustomerByID(int id) const {
    for (auto c : customers) {
        if (c->getCustomerID() == id) {
            return c;
        }
    }
    return nullptr;
}

// Show all customers
void Bank::showAllCustomers() const {
    cout << "=== Bank: " << bankName << " ===\n";
    for (auto c : customers) {
        cout << "Customer ID: " << c->getCustomerID()
             << ", Name: " << c->getName()
             << ", Address: " << c->getAddress() << endl;
        c->showAccounts();
        cout << "---------------------------\n";
    }
}
