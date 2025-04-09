#include <iostream>
#include <string>

using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double principalAmount;  // Loan amount (P)
    double annualInterestRate;  // Annual Interest Rate (R in %)
    int tenureMonths;  // Loan tenure in months (T)

public:
    // Default constructor
    Loan() {
        loanID = 0;
        applicantName = "Unknown";
        principalAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    // Parameterized constructor
    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        principalAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    // Function to calculate (1 + R)^T manually
    double power(double base, int exponent) {
        double result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }

    // Function to calculate EMI
    double calculateEMI() {
        double monthlyInterestRate = (annualInterestRate / 100) / 12; // Convert annual rate to monthly decimal
        double factor = power(1 + monthlyInterestRate, tenureMonths); // Calculate (1 + R)^T using loop

        double EMI = (principalAmount * monthlyInterestRate * factor) / (factor - 1);
        return EMI;
    }

    // Function to display loan details
    void displayLoanDetails() {
        cout << "\nLoan ID: " << loanID
             << "\nApplicant Name: " << applicantName
             << "\nLoan Amount: $" << principalAmount
             << "\nAnnual Interest Rate: " << annualInterestRate << "%"
             << "\nLoan Tenure: " << tenureMonths << " months"
             << "\nCalculated EMI: $" << calculateEMI() << " per month\n";
    }
};

int main() {
    Loan loan1(101, "shreeja", 50000, 7.5, 36); // Creating a loan with details

    // Display loan details
    cout << "Loan Details:\n";
    loan1.displayLoanDetails();

    return 0;
}
