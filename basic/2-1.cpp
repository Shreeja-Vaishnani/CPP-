#include <iostream>

using namespace std;

#define MAX_RECTANGLES 100  // Maximum number of rectangles

// Rectangle class to store dimensions and perform calculations
class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle() : length(0), width(0) {}

    // Function to set dimensions
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    // Function to calculate area
    double getArea() const {
        return length * width;
    }

    // Function to calculate perimeter
    double getPerimeter() const {
        return 2 * (length + width);
    }

    // Function to display rectangle details
    void display(int index) const {
        cout << "Rectangle " << index + 1 << " - Length: " << length
             << ", Width: " << width
             << ", Area: " << getArea()
             << ", Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    Rectangle rectangles[MAX_RECTANGLES]; // Array to store rectangles
    int count = 0; // Number of rectangles stored
    int choice;

    do {
        cout << "\nRectangle Management System\n";
        cout << "1. Add a new rectangle\n";
        cout << "2. Update rectangle dimensions\n";
        cout << "3. Display all rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (count >= MAX_RECTANGLES) {
                    cout << "Maximum rectangle limit reached!\n";
                    break;
                }

                double length, width;
                cout << "Enter length: ";
                cin >> length;
                cout << "Enter width: ";
                cin >> width;
                rectangles[count].setDimensions(length, width);
                count++;
                cout << "Rectangle added successfully!\n";
                break;
            }
            case 2: {
                if (count == 0) {
                    cout << "No rectangles available to update.\n";
                    break;
                }

                int index;
                double length, width;
                cout << "Enter the rectangle number to update (1 to " << count << "): ";
                cin >> index;

                if (index < 1 || index > count) {
                    cout << "Invalid rectangle number!\n";
                    break;
                }

                cout << "Enter new length: ";
                cin >> length;
                cout << "Enter new width: ";
                cin >> width;
                rectangles[index - 1].setDimensions(length, width);
                cout << "Rectangle updated successfully!\n";
                break;
            }
            case 3:
                if (count == 0) {
                    cout << "No rectangles available.\n";
                } else {
                    for (int i = 0; i < count; i++) {
                        rectangles[i].display(i);
                    }
                }
                break;
            case 4:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
