#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction structure
struct Transaction {
    string type;
    double amount;
};

class BankAccount {
protected:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    BankAccount(int accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {
        cout << "BankAccount created.\n";
    }

    virtual ~BankAccount() {
        cout << "BankAccount destroyed.\n";
    }

    virtual void deposit(double amount) {
        balance += amount;
        history.push_back({"Deposit", amount});
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        history.push_back({"Withdraw", amount});
    }

    void undoLastTransaction() {
        if (history.empty()) {
            cout << "No transactions to undo.\n";
            return;
        }
        Transaction last = history.back();
        history.pop_back();
        if (last.type == "Deposit") balance -= last.amount;
        else if (last.type == "Withdraw") balance += last.amount;

        cout << "Last transaction undone: " << last.type << " of " << last.amount << "\n";
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << "\n";
    }
};

// Savings Account
class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {
        cout << "SavingsAccount created.\n";
    }

    ~SavingsAccount() {
        cout << "SavingsAccount destroyed.\n";
    }

    void addInterest() {
        double interest = balance * interestRate;
        deposit(interest);
        cout << "Interest added: " << interest << "\n";
    }

    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate * 100 << "%\n";
    }
};

// Current Account
class CurrentAccount : public BankAccount {
    double overdraftLimit;

public:
    CurrentAccount(int accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {
        cout << "CurrentAccount created.\n";
    }

    ~CurrentAccount() {
        cout << "CurrentAccount destroyed.\n";
    }

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded.\n";
            return;
        }
        balance -= amount;
        history.push_back({"Withdraw", amount});
    }

    void display() const override {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }
};