/***
 * Implementation of AVL Tree
 * **/

#include <iostream>
#include <cmath>
#include "bst.cpp"

class AVL : public binaray_search_tree
{

  public:
    AVL() {}
    int update_height(node *x)
    {
        return std::max(height(x->left), height(x->right)) + 1;
    }

    void left_rotate(node *x)
    {
        node *y = x->right;
        x->right = y->left;
        if (x->right)
            x->right->parent = x;
        y->parent = x->parent;
        if (!y->parent)
        {
            m_root = y;
        }
        else
        {
            if (y->parent->left == x)
                y->parent->left = y;
            if (y->parent->right == x)
                y->parent->right = y;
        }
        x->parent = y;
        y->left = x;

        x->h = update_height(x);
        y->h = update_height(y);
    }
    void right_rotate(node *x)
    {
        node *y = x->left;
        x->left = y->right;
        if (x->left)
            x->left->parent = x;
        y->parent = x->parent;
        if (!y->parent)
            m_root = y;
        else
        {
            if (y->parent->left == x)
                y->parent->left = y;
            if (y->parent->right == x)
                y->parent->right = y;
        }
        x->parent = y;
        y->right = x;

        x->h = update_height(x);
        y->h = update_height(y);
    }
    void insert(int v)
    {
        node *newnode = binaray_search_tree::insert(v);
        balance(newnode);
    }
    int height(node *x)
    {
        if (x)
            return x->h;
        else //NULL
            return -1;
    }
    void balance(node *x)
    { // Balancing the tree to fulfill the AVL properties
        while (x)
        {
            x->h = update_height(x);
            if (height(x->left) - height(x->right) > 1)
            {
                if (height(x->left->left) >= height(x->left->right))
                    right_rotate(x);
                else
                {
                    left_rotate(x->left);
                    right_rotate(x);
                }
            }
            else
            {
                if (height(x->right) - height(x->left) > 1)
                {
                    if (height(x->right->right) >= height(x->right->left))
                        left_rotate(x);
                    else
                    {
                        right_rotate(x->right);
                        left_rotate(x);
                    }
                }
            }
            x = x->parent;
        }
    }

    void delete_min()
    {
        int deleted_val;
        node *parent;
        std::tie(deleted_val, parent) = binaray_search_tree::delete_min();
        balance(parent);
    }
};