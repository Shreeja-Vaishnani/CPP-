#include <iostream>
#include <string>

using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    // Default constructor
    Item() {
        itemID = 0;
        itemName = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    Item(int id, string name, double p, int qty) {
        itemID = id;
        itemName = name;
        price = p;
        quantity = qty;
    }

    // Function to add stock
    void addStock(int qty) {
        if (qty > 0) {
            quantity += qty;
            cout << qty << " items added successfully!\n";
        } else {
            cout << "Invalid stock quantity!\n";
        }
    }

    // Function to sell items
    void sellItem(int qty) {
        if (qty > 0 && qty <= quantity) {
            quantity -= qty;
            cout << qty << " items sold successfully!\n";
        } else {
            cout << "Insufficient stock or invalid quantity!\n";
        }
    }

    // Function to display item details
    void displayItem() {
        cout << "\nItem ID: " << itemID
             << "\nItem Name: " << itemName
             << "\nPrice: $" << price
             << "\nStock Available: " << quantity << " units\n";
    }
};

int main() {
    // Creating an inventory item
    Item item1(101, "Laptop", 750.99, 10);

    // Display initial item details
    cout << "Initial Item Details:\n";
    item1.displayItem();

    // Performing stock operations
    item1.addStock(5);  // Adding stock
    item1.sellItem(3);   // Selling items
    item1.sellItem(20);  // Attempting to sell more than available

    // Display updated item details
    cout << "\nUpdated Item Details:";
    item1.displayItem();

    return 0;
}
