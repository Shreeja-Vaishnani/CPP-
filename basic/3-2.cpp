#include <iostream>

using namespace std;

// Recursive function to calculate sum
int sumRecursive(int arr[], int size) {
    if (size == 0) 
        return 0; // Base case
    return arr[size - 1] + sumRecursive(arr, size - 1); // Recursive step
}

// Iterative function to calculate sum
int sumIterative(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;

    // Get array size from user
    cout << "Enter array size: ";
    cin >> size;

    int arr[size]; // Declare array

    // Get array elements from user
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Compute sums using both methods
    cout << "\nSum using Recursion: " << sumRecursive(arr, size);
    cout << "\nSum using Iteration: " << sumIterative(arr, size) << endl;

    return 0;
}
