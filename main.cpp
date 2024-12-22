#include <iostream>
#include "./includes/my_stack.h"
using namespace std;

// to compile g++ -o main.exe main.cpp src/*.cpp
int main()
{
    stack<int> stk;
    stk.push(1);
    cout << endl;
    cout << stk.top();
    stk.pop();
}