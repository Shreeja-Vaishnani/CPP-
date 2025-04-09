#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Default constructor (No initial balance)
    BankAccount() {
        accountHolder = "Unknown";
        accountNumber = 0;
        balance = 0.0;
    }

    // Parameterized constructor (With initial balance)
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    // Function to display account details
    void displayAccount() {
        cout << "\nAccount Holder: " << accountHolder
             << "\nAccount Number: " << accountNumber
             << "\nCurrent Balance: $" << balance << endl;
    }
};

int main() {
    // Creating an account with details
    BankAccount account1("shreeja", 1001, 500.0);

    // Display initial account details
    cout << "Initial Account Details:\n";
    account1.displayAccount();

    // Perform transactions
    account1.deposit(200.0);
    account1.withdraw(100.0);
    account1.withdraw(700.0); // Attempting to withdraw more than the balance

    // Display updated account details
    cout << "\nFinal Account Details:";
    account1.displayAccount();

    return 0;
}

