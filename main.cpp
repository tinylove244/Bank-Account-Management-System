#include <iostream>
#include <fstream>
#include "Bank.h"
#include "Customer.h"
#include "SavingsAccount.h"
#include "Transaction.h"
using namespace std;

// Hàm menu
void menu(ostream &out) {
    out << "\n========== BANK MENU ==========\n";
    out << "1. Create Customer\n";
    out << "2. Open Account\n";
    out << "3. Deposit\n";
    out << "4. Withdraw\n";
    out << "5. Show All Customers\n";
    out << "6. Exit\n";
    out << "==============================\n";
}

int main() {
    // mở file output.txt trong thư mục ../Document
    ofstream fout("../Document/output.txt");
    if (!fout.is_open()) {
        cerr << "Error: Cannot open ../Document/output.txt\n";
        return 1;
    }

    // Tạo 1 đối tượng Bank
    Bank bank("My Local Bank");

    // Action 1: Tạo Customer
    Customer* c1 = new Customer(1, "Nguyen Van A", "123 Main St");
    bank.addCustomer(c1);
    cout << "Action 1: Created customer Nguyen Van A\n\n";
    fout << "Action 1: Created customer Nguyen Van A\n\n";

    // Action 2: Tạo Account cho Customer
    Account* acc1 = new SavingsAccount(1001, "Nguyen Van A", 500.0, 2.5);
    c1->addAccount(acc1);
    cout << "Action 2: Created SavingsAccount for Nguyen Van A with balance 500\n\n";
    fout << "Action 2: Created SavingsAccount for Nguyen Van A with balance 500\n\n";

    // Action 3: Deposit tiền
    acc1->deposit(200);
    cout << "Action 3: Deposited 200 into account 1001\n\n";
    fout << "Action 3: Deposited 200 into account 1001\n\n";

    // Action 4: Withdraw tiền
    acc1->withdraw(150);
    cout << "Action 4: Withdrew 150 from account 1001\n\n";
    fout << "Action 4: Withdrew 150 from account 1001\n\n";

    // Action 5: Apply interest cho SavingsAccount
    SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc1);
    if (sa) {
        sa->applyInterest();
        cout << "Action 5: Applied interest to SavingsAccount (rate 2.5%)\n\n";
        fout << "Action 5: Applied interest to SavingsAccount (rate 2.5%)\n\n";
    }

    // Hiển thị toàn bộ khách hàng
    bank.showAllCustomers();
    fout << "=== Bank Data ===\n";
    bank.showAllCustomers(); // in ra terminal
    // để in ra file, cần hàm showAllCustomers nhận ostream, ta tạm redirect:
    // có thể viết lại showAllCustomers để nhận ostream, còn tạm thời gọi displayInfo thủ công
    for (Account* acc : c1->getAccounts()) {
        acc->displayInfo();
        fout << "Account Number: " << acc->getAccountNumber()
             << ", Owner: " << acc->getOwnerName()
             << ", Balance: " << acc->getBalance() << "\n";
    }

    // In menu ra cả terminal và file
    menu(cout);
    menu(fout);

    fout.close();
    return 0;
}
