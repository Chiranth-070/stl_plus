#ifndef MY_AVL_H
#define MY_AVL_H

#include <iostream>
#include <vector>
#include <queue>

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    explicit AVLNode(int data);
    ~AVLNode();
};

class AVL
{
public:
    AVLNode *root;
    int minValue;
    AVLNode *minValueNode;
    AVL();
    ~AVL();
    void insert(int data);
    void deleteNode(int data);

private:
    int height(AVLNode *node);
    int getBalanceFactor(AVLNode *node);

    AVLNode *rightRotate(AVLNode *y);
    AVLNode *leftRotate(AVLNode *x);

    AVLNode *insert(AVLNode *node, int data);
    AVLNode *deleteNode(AVLNode *root, int data);
};

void inorder(AVLNode *node, std::vector<int> &ans);
void levelorder(AVLNode *node, std::vector<int> &result);

#endif