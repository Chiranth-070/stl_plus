#ifndef MY_AVL_CPP
#define MY_AVL_CPP

#include "../includes/my_avl.h"

AVLNode::AVLNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

AVLNode::~AVLNode()
{
    delete left;
    delete right;
}

AVL::AVL()
{
    root = nullptr;
    minValue = 1e9;
    minValueNode = nullptr;
}

AVL::~AVL()
{
    delete root;
}

int AVL::height(AVLNode *node)
{
    return node ? node->height : 0;
}

int AVL::getBalanceFactor(AVLNode *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode *AVL::rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right) + 1);
    x->height = std::max(height(x->left), height(x->right) + 1);

    return x;
}

AVLNode *AVL::leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right) + 1);
    y->height = std::max(height(y->left), height(y->right) + 1);

    return y;
}

AVLNode *AVL::insert(AVLNode *node, int data)
{
    if (!node)
    {
        AVLNode *newnode = new AVLNode(data);
        if (data < minValue)
        {
            minValue = data;
            minValueNode = newnode;
        }
        return newnode;
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = std::max(height(node->left), height(node->right)) + 1;

    int balance = getBalanceFactor(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode *AVL::deleteNode(AVLNode *root, int data)
{
    if (!root)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (!root->left || !root->right)
        {
            AVLNode *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            AVLNode *temp = minValueNode;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    root->height = std::max(height(root->left), height(root->right) + 1);
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVL::insert(int data)
{
    root = insert(root, data);
}

void AVL::deleteNode(int data)
{
    root = deleteNode(root, data);
}

void inorder(AVLNode *node, std::vector<int> &result)
{
    if (node)
    {
        inorder(node->left, result);
        result.push_back(node->data);
        inorder(node->right, result);
    }
}

void levelorder(AVLNode *node, std::vector<int> &result)
{
    std::queue<AVLNode *> q;
    q.push(node);
    while (!q.empty())
    {
        AVLNode *current = q.front();
        q.pop();
        result.push_back(current->data);
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

#endif