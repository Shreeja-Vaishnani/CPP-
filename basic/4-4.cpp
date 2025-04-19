#include <iostream>
#include <stack>
using namespace std;

// Base class
class BankAccount {
protected:
    int accountNumber;
    double balance;
    stack<double> transactionHistory;

public:
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
        transactionHistory.push(balance);
    }

    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
        transactionHistory.push(balance);
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push(balance);
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void undoLastTransaction() {
        if (transactionHistory.size() > 1) {
            transactionHistory.pop();
            balance = transactionHistory.top();
            cout << "Last transaction undone. Current Balance: " << balance << endl;
        } else {
            cout << "No transaction to undo." << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

// Derived class: Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        transactionHistory.push(balance);
        cout << "Interest Applied: " << interest << ", New Balance: " << balance << endl;
    }

    void display() const override {
        cout << "[Savings Account] ";
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class: Current Account
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= (balance + overdraftLimit)) {
            balance -= amount;
            transactionHistory.push(balance);
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Overdraft limit exceeded." << endl;
        }
    }

    void display() const override {
        cout << "[Current Account] ";
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

// Main function
int main() {
    SavingsAccount sa(1001, 1000.0, 5.0); // accNum, balance, interestRate
    CurrentAccount ca(2001, 500.0, 300.0); // accNum, balance, overdraftLimit

    cout << "=== Savings Account Transactions ===" << endl;
    sa.display();
    sa.deposit(500);
    sa.withdraw(200);
    sa.applyInterest();
    sa.undoLastTransaction();
    sa.display();

    cout << "\n=== Current Account Transactions ===" << endl;
    ca.display();
    ca.withdraw(700); // allowed due to overdraft
    ca.deposit(300);
    ca.undoLastTransaction();
    ca.display();

    return 0;
}
