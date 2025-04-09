#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    static int totalAccounts; // Static variable to track the total accounts

public:
    // Constructor to initialize an account
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
        totalAccounts++; // Increment total accounts when a new account is created
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
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Function to transfer money between accounts
    void transfer(BankAccount &receiver, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful! New Balance: $" << balance << endl;
        } else {
            cout << "Transfer failed! Insufficient balance or invalid amount!" << endl;
        }
    }

    // Function to display account details
    void displayAccount() {
        cout << "\nAccount Holder: " << accountHolder;
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: $" << balance << endl;
    }

    // Static function to get total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Initialize static variable
int BankAccount::totalAccounts = 0;

int main() {
    // Creating two bank accounts
    BankAccount acc1("shreeja", 1001, 5000);
    BankAccount acc2("riddhi", 1002, 3000);

    // Display initial account details
    acc1.displayAccount();
    acc2.displayAccount();

    // Perform some transactions
    acc1.deposit(1000);
    acc2.withdraw(500);
    
    // Transfer money from acc1 to acc2
    acc1.transfer(acc2, 2000);

    // Display updated details
    acc1.displayAccount();
    acc2.displayAccount();

    // Display total number of accounts
    cout << "\nTotal Accounts Created: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}

