#include <iostream>
 #include <stack>
 using namespace std;
 
 // Point class
 class Point
 {
 public:
 
     int x, y;
 
     Point(int x = 0, int y = 0) : x(x), y(y) {}
 
     // Overload unary - operator
     Point operator-() const {
         return Point(-x, -y);
     }
 
     // Overload + operator
     Point operator+(const Point& other) const {
         return Point(x + other.x, y + other.y);
     }
 
     // Overload == operator
     bool operator==(const Point& other) const {
         return x == other.x && y == other.y;
     }
 
     void display() const {
         cout << "(" << x << ", " << y << ")" << endl;
     }
 };
 
 // Custom Stack for Points
 class PointStack {
 private:
     stack<Point> s;
 
 public:
     void push(const Point& p) {
         s.push(p);
     }
 
     Point pop() {
         if (!s.empty()) {
             Point top = s.top();
             s.pop();
             return top;
         } else {
             return Point(); // Return default if empty
         }
     }
 
     bool isEmpty() const {
         return s.empty();
     }
 };
 
 int main()
 {
     int a,b,c,d;
     cout<<"enter x and y coordinates for first input";
     cin>>a>>b;
     cout<<endl<<"enter x and y coordinates for second input";
     cin>>c>>d;
 
 
     Point p1(a, b), p2(c, d);
 
     Point result;
 
     PointStack history;
 
     // Operation 1: Addition
     result = p1 + p2;
     history.push(result);
     cout << "After addition: ";
     result.display();
 
     // Operation 2: Negation
     result = -result;
     history.push(result);
     cout << "After negation: ";
     result.display();
 
     // Undo last operation
     cout << "Undo last operation: ";
     history.pop(); // Discard current
     result = history.pop(); // Get previous
     result.display();
     cout<<"24ce138_shreeja"<<endl;
 
     return 0;
 }