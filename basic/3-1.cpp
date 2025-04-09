#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    // Constructor with a default bonus value
    Employee(string empName, double salary, double empBonus = 1000) {
        name = empName;
        basicSalary = salary;
        bonus = empBonus;
    }

    // Inline function to calculate total salary
    inline double calculateTotalSalary() {
        return basicSalary + bonus;
    }

    // Function to display employee details
    void displayEmployeeDetails() {
        cout << "\nEmployee Name: " << name
             << "\nBasic Salary: $" << basicSalary
             << "\nBonus: $" << bonus
             << "\nTotal Salary: $" << calculateTotalSalary() << endl;
    }
};

int main() {
    int numEmployees;

    cout << "Enter number of employees: ";
    cin >> numEmployees;
    cin.ignore(); // Clear input buffer

    // Dynamically allocate memory for employee records
    Employee* employees[numEmployees];

    // Input employee details
    for (int i = 0; i < numEmployees; i++) {
        string name;
        double salary, bonus;
        char customBonus;

        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Basic Salary: ";
        cin >> salary;
        cout << "Does this employee have a custom bonus? (y/n): ";
        cin >> customBonus;

        if (customBonus == 'y' || customBonus == 'Y') {
            cout << "Enter custom bonus amount: ";
            cin >> bonus;
            employees[i] = new Employee(name, salary, bonus);
        } else {
            employees[i] = new Employee(name, salary);
        }

        cin.ignore(); // Clear input buffer
    }

    // Display all employee details
    cout << "\nEmployee Payroll Details:\n";
    for (int i = 0; i < numEmployees; i++) {
        employees[i]->displayEmployeeDetails();
        delete employees[i]; // Free dynamically allocated memory
    }

    return 0;
}
