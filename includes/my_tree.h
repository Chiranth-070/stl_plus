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

class BST
{
private:
    Node *insert(Node *node, int data);
    Node *search(Node *node, int data);
    Node *deleteNode(Node *node, int data);

public:
    Node *root;
    int minValue;
    Node *minValueNode;
    BST();
    ~BST();

    void insert(int data);
    bool search(int data);
    void deleteNode(int data);
};

Node *attach_left(Node *node, int data);
Node *attach_right(Node *node, int data);
void inorder(Node *node, std::vector<int> &ans);

#endif