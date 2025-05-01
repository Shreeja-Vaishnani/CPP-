#include <iostream>
 using namespace std;
 
 class DynamicArray {
 private:
     int* data;        // Pointer to the dynamic array
     int size;         // Current number of elements
     int capacity;     // Total allocated size
 
     void resize() {
         // Double the capacity
         int newCapacity = capacity * 2;
         int* newData = new int[newCapacity];
 
         // Copy old data to new array
         for (int i = 0; i < size; ++i) {
             newData[i] = data[i];
         }
 
         // Delete old array
         delete[] data;
 
         // Update pointer and capacity
         data = newData;
         capacity = newCapacity;
     }
 
 public:
     DynamicArray(int initialCapacity = 2) {
         capacity = initialCapacity;
         size = 0;
         data = new int[capacity];
     }
 
     ~DynamicArray() {
         delete[] data;
     }
 
     void insert(int value) {
         if (size == capacity) {
             resize();
         }
         data[size++] = value;
     }
 
     void remove(int index) {
         if (index < 0 || index >= size) {
             cout << "Invalid index for removal." << endl;
             return;
         }
 
         // Shift elements left
         for (int i = index; i < size - 1; ++i) {
             data[i] = data[i + 1];
         }
         --size;
     }
 
     void display() const {
         cout << "[ ";
         for (int i = 0; i < size; ++i) {
             cout << data[i] << " ";
         }
         cout << "]" << endl;
     }
 
     int getSize() const {
         return size;
     }
 
     int getCapacity() const {
         return capacity;
     }
 
     int get(int index) const {
         if (index < 0 || index >= size) {
             cout << "Invalid index for get." << endl;
             return -1; // Error value
         }
         return data[index];
     }
 };
 
 int main() {
     DynamicArray arr;
 
     // Insert some values
     arr.insert(10);
     arr.insert(20);
     arr.insert(30);
     arr.insert(40);
 
     cout << "After insertions: ";
     arr.display();
 
     // Remove an element
     arr.remove(1); // Remove the element at index 1 (value 20)
 
     cout << "After removal: ";
     arr.display();
 
     cout << "Current size: " << arr.getSize() << endl;
     cout << "Current capacity: " << arr.getCapacity() << endl;
     cout<<"24ce138_shreeja vaishnani"<<endl;
 
     return 0;
 }