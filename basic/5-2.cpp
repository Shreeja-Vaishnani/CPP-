#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload << operator (output)
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) out << " + " << c.imag << "i";
        else out << " - " << -c.imag << "i";
        return out;
    }

    // Overload >> operator (input)
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

// Function to perform batch addition
Complex batchAdd(const vector<Complex>& nums) {
    Complex result;
    for (const auto& num : nums)
        result = result + num;
    return result;
}

// Function to perform batch subtraction (from the first element)
Complex batchSubtract(const vector<Complex>& nums) {
    if (nums.empty()) return Complex();
    Complex result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
        result = result - nums[i];
    return result;
}

int main() {
    int n;
    cout << "Enter the number of complex numbers: ";
    cin >> n;

    vector<Complex> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "Complex number " << i + 1 << ":\n";
        cin >> numbers[i];
    }

    cout << "\nEntered complex numbers:\n";
    for (const auto& c : numbers)
        cout << c << endl;

    Complex sum = batchAdd(numbers);
    Complex diff = batchSubtract(numbers);

    cout << "\nSum of complex numbers: " << sum << endl;
    cout << "Difference of complex numbers: " << diff << endl;

    return 0;
}
