#ifndef MY_TREE_CPP
#define MY_TREE_CPP
#include "../includes/my_tree.h"
#define INT_MAX 1e9

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

BST::BST()
{
    root = nullptr;
    minValue = INT_MAX;
    minValueNode = nullptr;
}

BST::~BST()
{
    delete root;
}

void BST::insert(int data)
{
    root = insert(root, data);
}

Node *BST::insert(Node *node, int data)
{
    if (node == nullptr)
    {
        Node *newNode = new Node(data);
        if (data < minValue)
        {
            minValue = data;
            minValueNode = newNode;
        }
        return newNode;
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

bool BST::search(int data)
{
    Node *result = search(root, data);
    return result != nullptr;
}

Node *BST::search(Node *node, int data)
{
    if (node == nullptr || node->data == data)
    { // Use '==' to compare
        return node;
    }

    if (data < node->data)
    {
        return search(node->left, data);
    }

    return search(node->right, data);
}

void BST::deleteNode(int data)
{
    root = deleteNode(root, data);
}

Node *BST::deleteNode(Node *node, int data)
{
    if (node == nullptr)
        return node;

    std::cout << "to be implemented";
}

#endif