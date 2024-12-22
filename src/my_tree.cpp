#ifndef MY_TREE_CPP
#define MY_TREE_CPP
#include "../includes/my_tree.h"

Node::Node(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    delete left;
    delete right;
}

Node *attach_left(Node *node, int data)
{
    if (node != nullptr)
    {
        node->left = new Node(data);
        return node->left;
    }
    return nullptr;
}

Node *attach_right(Node *node, int data)
{
    if (node != nullptr)
    {
        node->right = new Node(data);
        return node->right;
    }
    return nullptr;
}

void inorder(Node *node, std::vector<int> &ans)
{
    if (node == nullptr)
    {
        return;
    }

    inorder(node->left, ans);
    ans.push_back(node->data);
    inorder(node->right, ans);
}

#endif