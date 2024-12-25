#include <iostream>
#include "./includes/my_stl.h"

using namespace std;

// to compile g++ -o main.exe main.cpp src/*.cpp
int main()
{
    BST bst;

    bst.insert(1);
    bst.insert(5);
    bst.insert(10);
    bst.insert(15);
    bst.insert(25);

    vector<int> result1;
    levelorder(bst.root, result1);
    print_vector(result1);
    cout << endl;

    AVL avl;
    avl.insert(1);
    avl.insert(5);
    avl.insert(10);
    avl.insert(15);
    avl.insert(25);

    vector<int> result2;
    levelorder(avl.root, result2);
    print_vector(result2);
    cout << endl;
    cout << bst.minValue;
    cout << endl;
    cout << avl.minValue;
    cout << endl;
    cout << avl.root->height;

    // same inorder but different levelorder you will get
}