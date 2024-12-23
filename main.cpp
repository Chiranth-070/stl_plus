#include <iostream>
#include "./includes/my_stl.h"

using namespace std;

// to compile g++ -o main.exe main.cpp src/*.cpp
int main()
{
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(8);
    bst.insert(15);

    vector<int> result;
    inorder(bst.root, result);
    print_vector(result);

    cout << endl;
    cout << bst.minValue;
}