#include<iostream>
#include<stack>
using namespace std;

class bankaccount
{
    protected:
    string accnum;
    double balance;

    public:
    bankaccount(string acc,double bal) : accnum(acc),balance(bal) {}
    void deposit(double amt)
    {
        balance+= amt;
        cout<<"Deposited :" <<amt <<",Balance:"<<balance<<endl;
    }
    int withdraw(double amt)
    {
        if(balance >= amt)
        {
            balance-= amt;
            cout <<"withdrawn:"<<
            
            
        }
    }
}