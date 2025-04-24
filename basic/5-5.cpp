#include<iostream>
 #include<vector>
 using namespace std;
 
 class shape //abstract class
 {
 public :
     //pure virtual class
     virtual double area() const=0;
 
 
 };
 
 
 class rectangle : public shape
 {
     double length, width;
 
 public:
 
     rectangle(double l , double w)
     {
         length = l;
         width = w;
     }
 
     double area() const override
      {
         return length * width;
 
      }
 };
 
 class circle : public shape
 {
     double radius;
 
 public :
 
     circle(double r)
     {
         radius =r;
     }
 
     double area()const override
     {
         return 3.14*radius*radius;
     }
 
 };
 
 int main()
  {
     // Dynamic collection using vector of Shape pointers
     vector<shape*> shapes;
 
     // Add shapes to the collection
     shapes.push_back(new rectangle(5.0, 3.0));
     shapes.push_back(new circle(2.0));
     shapes.push_back(new rectangle(2.5, 4.0));
     shapes.push_back(new circle(3.5));
 
     // Calculate and display area of each shape
     for (size_t i = 0; i < shapes.size(); ++i)
         {
         cout << "Shape " << i + 1 << " Area: " << shapes[i]->area() << endl;
     }
 
     // Clean up memory
     for (shape* s : shapes)
     {
         delete s;
     }
     cout<<"24ce138_shreeja"<<endl;
 /*
 
     cout<<endl<<endl<<endl<<endl;
     cout<<"using array: "<<endl<<endl;
 
 
      const int SIZE = 4;
     shape* shapes[SIZE];
 
     shapes[0] = new rectangle(4.0, 6.0);
     shapes[1] = new circle(1.5);
     shapes[2] = new rectangle(3.0, 3.0);
     shapes[3] = new circle(2.2);
 
     for (int i = 0; i < SIZE; ++i) {
         cout << "Shape " << i + 1 << " Area: " << shapes[i]->area() <<endl;
     }
 
     // Cleanup
     for (int i = 0; i < SIZE; ++i)
     {
         delete shapes[i];
     }
 
     */
     return 0;
 }