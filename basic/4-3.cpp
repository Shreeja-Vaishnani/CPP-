#include <iostream>
#include <queue>

using namespace std;

// Base class: FuelType
class FuelType {
protected:
    string fuel;
public:
    FuelType(string f) : fuel(f) {}  // Constructor
    void displayFuelType() const {
        cout << "Fuel Type: " << fuel;
    }
};

// Another base class: Brand
class Brand {
protected:
    string brandName;
public:
    Brand(string b) : brandName(b) {}  // Constructor
    void displayBrand() const {
        cout << "Brand: " << brandName;
    }
};

// Derived class: Car (inherits from both FuelType and Brand)
class Car : public FuelType, public Brand {
public:
    Car(string f, string b) : FuelType(f), Brand(b) {}  // Constructor

    void displayCar() const {
        displayBrand();
        cout << ", ";
        displayFuelType();
        cout << endl;
    }
};

// Class to manage multiple cars using a queue
class CarQueue {
private:
    queue<Car> carQueue;  // Queue to store cars
public:
    void addCar(string fuel, string brand) {
        carQueue.push(Car(fuel, brand));
    }

    void processCars() {
        cout << "Processing Cars in Queue:\n";
        while (!carQueue.empty()) {
            carQueue.front().displayCar();  // Display the car at the front
            carQueue.pop();  // Remove the car from the queue (FIFO)
        }
    }
};

// Main function
int main() {
    CarQueue carQueue;

    // Adding cars to the queue
    carQueue.addCar("Petrol", "Toyota");
    carQueue.addCar("Diesel", "Ford");
    carQueue.addCar("Electric", "Tesla");
    carQueue.addCar("Hybrid", "Honda");

    // Process and remove cars from the queue
    carQueue.processCars();

    return 0;
}
