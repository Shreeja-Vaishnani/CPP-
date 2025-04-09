#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

// Function to add a new product
void addProduct(vector<Product>& inventory) {
    Product newProduct;
    cout << "Enter Product ID: ";
    cin >> newProduct.id;
    cout << "Enter Product Name: ";
    cin.ignore(); 
    getline(cin, newProduct.name);
    cout << "Enter Quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter Price per Unit: ";
    cin >> newProduct.price;
    
    inventory.push_back(newProduct);
    cout << "Product added successfully!\n";
}

// Function to update the quantity of an existing product
void updateQuantity(vector<Product>& inventory) {
    int id, newQuantity;
    cout << "Enter Product ID to update: ";
    cin >> id;

    for (auto& product : inventory) {
        if (product.id == id) {
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            product.quantity = newQuantity;
            cout << "Quantity updated successfully!\n";
            return;
        }
    }
    cout << "Product not found!\n";
}

// Function to calculate the total value of inventory
double calculateTotalValue(const vector<Product>& inventory) {
    double totalValue = 0;
    for (const auto& product : inventory) {
        totalValue += product.quantity * product.price;
    }
    return totalValue;
}

// Function to display all products
void displayInventory(const vector<Product>& inventory) {
    cout << "\nCurrent Inventory:\n";
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Qty" << setw(10) << "Price" << setw(15) << "Total Value\n";
    cout << "---------------------------------------------------------------\n";
    for (const auto& product : inventory) {
        cout << setw(10) << product.id
             << setw(20) << product.name
             << setw(10) << product.quantity
             << setw(10) << fixed << setprecision(2) << product.price
             << setw(15) << fixed << setprecision(2) << (product.quantity * product.price) << "\n";
    }
}

// Main function
int main() {
    vector<Product> inventory;
    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Display Inventory\n";
        cout << "4. Calculate Total Value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice:\n ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                updateQuantity(inventory);
                break;
            case 3:
                displayInventory(inventory);
                break;
            case 4:
                cout << "Total Inventory Value: $" << fixed << setprecision(2) << calculateTotalValue(inventory) << "\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
