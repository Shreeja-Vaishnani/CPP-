#include <iostream>
 #include <queue>
 
 using namespace std;
 
 // Forward declaration
 class Fahrenheit;
 
 class Celsius
  {
 public:
     float temp;
 
     Celsius()
     {
         temp = 0;
     }
 
     Celsius(float t)
     {
         temp = t;
     }
 
     // Convert Celsius to Fahrenheit
     Fahrenheit toFahrenheit();
 
     // Compare two Celsius temperatures
     bool operator==(Celsius c) {
         return temp == c.temp;
     }
 };
 
 class Fahrenheit {
 public:
     float temp;
 
     Fahrenheit() {
         temp = 32;
     }
 
     Fahrenheit(float t) {
         temp = t;
     }
 
     // Convert Fahrenheit to Celsius
     Celsius toCelsius();
 
     // Compare two Fahrenheit temperatures
     bool operator==(Fahrenheit f)
     {
         return temp == f.temp;
     }
 };
 
 // Define conversions after both classes are fully declared
 Fahrenheit Celsius::toFahrenheit()
 {
     return Fahrenheit((temp * 9.0 / 5.0) + 32);
 }
 
 Celsius Fahrenheit::toCelsius()
  {
     return Celsius((temp - 32) * 5.0 / 9.0);
 }
 
 // ---------- Main Program ----------
 int main()
 
 {
     // === Static Array Example ===
     cout << "=== Static Array (Celsius to Fahrenheit) ===" << endl;
     Celsius cArr[3] = { Celsius(0), Celsius(37), Celsius(100) };
     Fahrenheit fArr[3];
 
     for (int i = 0; i < 3; i++) {
         fArr[i] = cArr[i].toFahrenheit();
         cout << cArr[i].temp << "°C = " << fArr[i].temp << "°F" << endl;
     }
 
     // === Queue Example ===
     cout << "\n=== Queue (FIFO) Example ===" << endl;
     queue<Celsius> celsiusQueue;
     celsiusQueue.push(Fahrenheit(32).toCelsius());
     celsiusQueue.push(Fahrenheit(212).toCelsius());
 
     while (!celsiusQueue.empty())
     {
         Celsius c = celsiusQueue.front();
         celsiusQueue.pop();
         cout << "From Fahrenheit -> Celsius: " << c.temp << "°C" << endl;
     }
 
     // === Comparison Example ===
     cout << "\n=== Comparison ===" << endl;
     Celsius c1(100);
     Fahrenheit f1(212);
     if (c1 == f1.toCelsius()) {
         cout << "100°C is equal to 212°F" << endl;
     } else {
         cout << "They are not equal." << endl;
     }
     cout<<"24ce138_shreeja"<<endl;
 
     return 0;
 }