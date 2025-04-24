#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class BankAccount {
protected:
    int accountNumber;
    double balance;
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

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
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

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
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

    return 0;
}
