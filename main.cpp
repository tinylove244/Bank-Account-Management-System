#include <iostream>
#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "SavingsAccount.h"
#include "Transaction.h"
using namespace std;

// Hàm menu: chỉ in ra màn hình
void menu() {
    cout << "\n========== BANK MENU ==========\n";
    cout << "1. Create Customer\n";
    cout << "2. Open Account\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Show All Customers\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
}

int main() {
    // Tạo 1 đối tượng Bank
    Bank bank("My Local Bank");

    // Action 1: Tạo Customer
    Customer* c1 = new Customer(1, "Nguyen Van A", "123 Main St");
    bank.addCustomer(c1);
    cout << "Action 1: Created customer Nguyen Van A\n\n";

    // Action 2: Tạo Account cho Customer
    Account* acc1 = new SavingsAccount(1001, "Nguyen Van A", 500.0, 2.5);
    c1->addAccount(acc1);
    cout << "Action 2: Created SavingsAccount for Nguyen Van A with balance 500\n\n";

    // Action 3: Deposit tiền
    acc1->deposit(200);
    cout << "Action 3: Deposited 200 into account 1001\n\n";

    // Action 4: Withdraw tiền
    acc1->withdraw(150);
    cout << "Action 4: Withdrew 150 from account 1001\n\n";

    // Action 5: Apply interest cho SavingsAccount
    SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc1);
    if (sa) {
        sa->applyInterest();
        cout << "Action 5: Applied interest to SavingsAccount (rate 2.5%)\n\n";
    }

    // Hiển thị toàn bộ khách hàng
    cout << "=== Bank Data ===\n";
    bank.showAllCustomers();
    for (Account* acc : c1->getAccounts()) {
        acc->displayInfo();
    }

    // In menu ra màn hình
    menu();

    return 0;
}
