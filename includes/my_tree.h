#ifndef MY_TREE_H
#define MY_TREE_H

#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int data);
    ~Node();
};

Node *attach_left(Node *node, int data);
Node *attach_right(Node *node, int data);
void inorder(Node *node, std::vector<int> &ans);

#endif