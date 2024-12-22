#include <iostream>
#include "./includes/my_tree.h"
#include "./includes/my_vector.h"
using namespace std;

// to compile g++ -o main.exe main.cpp src/*.cpp
int main()
{
    Node *root = new Node(1);
    attach_left(root, 2);
    attach_right(root, 3);

    vector<int> ans;
    inorder(root, ans);

    print_vector(ans);
}