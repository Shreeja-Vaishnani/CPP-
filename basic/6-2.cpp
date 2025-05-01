#include <iostream>
 using namespace std;
 
 class point {
 private:
     int x, y;
 
 public:
     // Constructor
     point(int x = 0, int y = 0) {
         this->x = x;
         this->y = y;
     }
 
     // Chainable move function using pass by reference
     point* move(int &dx, int &dy) {
         x += dx;
         y += dy;
         return this;
     }
 
     // Display function
     void display() const {
         cout << "Point (" << x << " , " << y << ")" << endl;
     }
 };
 
 int main() {
     int x, y;
 
     cout << "Enter initial x and y coordinates: ";
     cin >> x >> y;
 
     // Create point object using pointer
     point *p = new point(x, y);
 
     cout << "Initial position: ";
     p->display();
 
     // Input offsets from user
     int dx1, dy1, dx2, dy2;
 
     cout << "Enter dx1 and dy1: ";
     cin >> dx1 >> dy1;
 
     cout << "Enter dx2 and dy2: ";
     cin >> dx2 >> dy2;
 
     // Apply movements with method chaining
     p->move(dx1, dy1)->move(dx2, dy2);
 
     cout << "Final position after movements: ";
     p->display();
 
     // Clean up dynamically allocated memory
     delete p;
 
     return 0;
 }