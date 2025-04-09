#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    double marks1, marks2, marks3;

public:
    // Function to set student details
    void setDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // To clear the input buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks in 3 Subjects: ";
        cin >> marks1 >> marks2 >> marks3;
    }

    // Function to calculate average marks
    double getAverageMarks() {
        return (marks1 + marks2 + marks3) / 3.0;
    }

    // Function to display student details
    void display() {
        cout << "\nRoll Number: " << rollNumber;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks1 << ", " << marks2 << ", " << marks3;
        cout << "\nAverage Marks: " << getAverageMarks() << endl;
    }
};

int main() {
    Student student1; // Creating an object of Student class

    cout << "Enter Student Details:\n";
    student1.setDetails(); // Getting student details

    cout << "\nStudent Information:";
    student1.display(); // Displaying student details

    return 0;
}
