#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transaction {
private:
    double amount;
    string type;   // "Deposit", "Withdrawal", "Transfer"
    string date;   // lưu ngày (đơn giản: chuỗi)

public:
    // Constructor & Destructor
    Transaction(double amt, const string& t, const string& d = "N/A");
    ~Transaction();

    // Getters
    double getAmount() const;
    string getType() const;
    string getDate() const;

    // Display
    void display() const;
};
