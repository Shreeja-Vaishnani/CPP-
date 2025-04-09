#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(string holder, string number, double initialBalance) {
        accountHolder = holder;
        accountNumber = number;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    // Function to check balance
    void checkBalance() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    // Creating a bank account
    BankAccount account("shreeja", "123456789", 1000.0);

    // Performing transactions
    account.checkBalance();
    account.deposit(500);
    account.withdraw(300);
    account.withdraw(1500); // Attempting to withdraw more than balance
    account.checkBalance();

    return 0;
}
