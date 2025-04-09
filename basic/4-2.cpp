#include <iostream>
#include <vector>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}  // Constructor
    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// Intermediate class: Employee (inherits Person)
class Employee : public Person {
protected:
    int employeeID;
public:
    Employee(string n, int a, int id) : Person(n, a), employeeID(id) {}  // Constructor
    void displayEmployee() const {
        displayPerson();
        cout << ", Employee ID: " << employeeID;
    }
};

// Derived class: Manager (inherits Employee)
class Manager : public Employee {
private:
    string department;
public:
    Manager(string n, int a, int id, string dept) : Employee(n, a, id), department(dept) {}  // Constructor
    void displayManager() const {
        displayEmployee();
        cout << ", Department: " << department << endl;
    }
};

// Class to manage multiple managers dynamically (using vector)
class DynamicManagerStorage {
private:
    vector<Manager*> managers;  // Store managers dynamically
public:
    ~DynamicManagerStorage() {  // Destructor to free memory
        for (Manager* m : managers)
            delete m;
    }

    void addManager(string name, int age, int id, string dept) {
        managers.push_back(new Manager(name, age, id, dept));
    }

    void displayAllManagers() const {
        for (const Manager* m : managers) {
            m->displayManager();
        }
    }
};

// Class to manage managers using a static array
class StaticManagerStorage {
private:
    static const int MAX_MANAGERS = 3;
    Manager managers[MAX_MANAGERS] = {
        Manager("shreeja", 45, 101, "HR"),
        Manager("vishwa", 50, 102, "IT"),
        Manager("riddhi", 40, 103, "Finance")
    };
public:
    void displayAllManagers() const {
        for (int i = 0; i < MAX_MANAGERS; i++) {
            managers[i].displayManager();
        }
    }
};

// Main function
int main() {
    // Dynamic approach using vector
    DynamicManagerStorage dynamicStorage;
    dynamicStorage.addManager("disu", 38, 104, "Sales");
    dynamicStorage.addManager("naitri", 42, 105, "Marketing");

    cout << "Dynamic Manager Storage:\n";
    dynamicStorage.displayAllManagers();

    cout << "\nStatic Manager Storage:\n";
    StaticManagerStorage staticStorage;
    staticStorage.displayAllManagers();

    return 0;
}
