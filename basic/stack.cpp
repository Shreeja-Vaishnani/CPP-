#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s; //creating a stack of integers
    //push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // display top elements
    cout<<"top elements:"<<s.top()<<endl;
    //pop one element
    s.pop();
    cout<<"top after pop: "<<s.top()<<endl;
    //stack size
    cout<<"size of stack: "<<s.size()<<endl;
    //check if stack is empty
    if(s.empty()){
        cout<<"stack is empty."<<endl;
    }
    else{
        cout<<"stack is not empty."<<endl;
    }
    return 0;
}
