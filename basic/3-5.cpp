
#include <iostream>
using namespace std;

// Recursive function to compute the super digit
int superDigit(long long num) {
    if (num < 10)  // Base case: If it's a single-digit number, return it
        return num;

    long long sum = 0;
    while (num > 0) {  // Compute sum of digits
        sum += num % 10;
        num /= 10;
    }

    return superDigit(sum);  // Recursively call superDigit on the sum
}

// Function to compute the super digit efficiently for large numbers
int computeSuperDigit(string n, int k) {
    long long sum = 0;
    
    // Compute sum of digits in n
    for (char digit : n) {
        sum += (digit - '0');  // Convert char to int and add to sum
    }

    // Multiply sum by k to simulate repeated concatenation
    sum *= k;

    // Compute the final super digit
    return superDigit(sum);
}

int main() {
    string n;
    int k;

    // Taking input for n (string representation of the number) and k (repetitions)
    cout << "Enter number (as string): ";
    cin >> n;
    cout << "Enter repetition count: ";
    cin >> k;

    // Compute and display the super digit
    cout << "Super Digit: " << computeSuperDigit(n, k) << endl;

    return 0;
}
