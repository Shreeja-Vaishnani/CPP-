#include<iostream>
#include<vector>

using namespace std;

class calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double x, double y)
    {
        return x + y;
    }

    double add(int aa, double bb)
    {
        return aa + bb;
    }
};

int main()
{
    calculator calc;

    vector<double> vec;

    vec.push_back(calc.add(2, 3));
    vec.push_back(calc.add(2.3, 3.3));
    vec.push_back(calc.add(2, 3.5));

    cout << endl << "Using STL approach (vector):";
    for (double element : vec)
    {
        cout << endl << element;
    }
    cout << endl << "Using array:";

    double cal[3];

    cal[0] = calc.add(2, 3);
    cal[1] = calc.add(2.4, 3.3);
    cal[2] = calc.add(2, 3.5);

    for (int i = 0; i < 3; i++)
    {
        cout << endl << cal[i];
    }

    cout<<endl<<endl<<"24ce138_shreeja";

return 0;
}
