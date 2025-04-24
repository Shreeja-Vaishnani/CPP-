#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <string>
#include <iomanip>

=======
#include <stack>
using namespace std;

// Base class
>>>>>>> 1e67f4e72ba5f8d8660e8b72c1447051855436b2
class BankAccount {
protected:
    int accountNumber;
    double balance;
<<<<<<< HEAD
    std::vector<std::string> transactionHistory;

public:
    BankAccount(int accNum, double initBalance)
        : accountNumber(accNum), balance(initBalance) {
        std::cout << "BankAccount #" << accountNumber << " created.\n";
    }

    virtual ~BankAccount() {
        std::cout << "BankAccount #" << accountNumber << " destroyed.\n";
    }

    virtual void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposit: +" + std::to_string(amount));
        std::cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    virtual bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds.\n";
            return false;
        }
        balance -= amount;
        transactionHistory.push_back("Withdraw: -" + std::to_string(amount));
        std::cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        return true;
    }

    void undoLastTransaction() {
        if (transactionHistory.empty()) {
            std::cout << "No transaction to undo.\n";
            return;
        }

        std::string last = transactionHistory.back();
        transactionHistory.pop_back();

        if (last.find("Deposit") != std::string::npos) {
            double amt = std::stod(last.substr(last.find("+") + 1));
            balance -= amt;
            std::cout << "Undid deposit of $" << amt << ". Balance: $" << balance << "\n";
        } else if (last.find("Withdraw") != std::string::npos) {
            double amt = std::stod(last.substr(last.find("-") + 1));
            balance += amt;
            std::cout << "Undid withdrawal of $" << amt << ". Balance: $" << balance << "\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void printTransactionHistory() const {
        std::cout << "Transaction history:\n";
        for (const auto& t : transactionHistory) {
            std::cout << " - " << t << "\n";
        }
    }
};

=======
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
>>>>>>> 1e67f4e72ba5f8d8660e8b72c1447051855436b2
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
<<<<<<< HEAD
    SavingsAccount(int accNum, double initBalance, double rate)
        : BankAccount(accNum, initBalance), interestRate(rate) {
        std::cout << "SavingsAccount created with interest rate: " << rate << "%\n";
    }

    void applyInterest() {
        double interest = balance * (interestRate / 100);
        deposit(interest);
        std::cout << "Interest applied: $" << interest << "\n";
    }
};

=======
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
>>>>>>> 1e67f4e72ba5f8d8660e8b72c1447051855436b2
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
<<<<<<< HEAD
    CurrentAccount(int accNum, double initBalance, double overdraft)
        : BankAccount(accNum, initBalance), overdraftLimit(overdraft) {
        std::cout << "CurrentAccount created with overdraft limit: $" << overdraft << "\n";
    }

    bool withdraw(double amount) override {
        if (amount > (balance + overdraftLimit)) {
            std::cout << "Overdraft limit exceeded.\n";
            return false;
        }
        balance -= amount;
        transactionHistory.push_back("Withdraw: -" + std::to_string(amount));
        std::cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        return true;
    }
};

// -------------------------
// Sample usage (main):
// -------------------------

int main() {
    SavingsAccount sa(101, 1000.0, 2.5);
    sa.deposit(200);
    sa.withdraw(100);
    sa.applyInterest();
    sa.printTransactionHistory();
    sa.undoLastTransaction();
    sa.printTransactionHistory();

    std::cout << "\n";

    CurrentAccount ca(102, 500.0, 200.0);
    ca.deposit(150);
    ca.withdraw(800); // should be allowed (within overdraft)
    ca.withdraw(100); // should fail
    ca.undoLastTransaction();
    ca.printTransactionHistory();
=======
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
>>>>>>> 1e67f4e72ba5f8d8660e8b72c1447051855436b2

    return 0;
}
