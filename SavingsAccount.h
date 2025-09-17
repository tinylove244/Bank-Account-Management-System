#pragma once
#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;  // lãi suất (%)

public:
    // Constructor & Destructor
    SavingsAccount(int accNumber, const string& owner, double balance, double rate);
    ~SavingsAccount();

    // Getter & Setter
    double getInterestRate() const;
    void setInterestRate(double rate);

    // Apply interest to balance
    void applyInterest();

    // Override withdraw (ví dụ: giới hạn hoặc có phí)
    bool withdraw(double amount) override;
};
