#include <iostream>

class node
{
  public:
    int val;
    int size;
    node *left, *right, *parent;
    node(int v) : val(v), size{1}, left(NULL), right(NULL), parent(NULL) {}
};

class binaray_search_tree
{
  public:
    node *m_root = NULL;

    binaray_search_tree(){};
    void insert(int v)
    {
        node *newnode = new node(v);

        if (!m_root)
            m_root = newnode;
        else
        {
            node *tmp = m_root;
            while (tmp)
            {
                tmp->size++;
                if (v < tmp->val)
                {
                    if (!tmp->left)
                    {
                        tmp->left = newnode;
                        newnode->parent = tmp;
                        break;
                    }
                    else
                        tmp = tmp->left;
                }
                else
                {
                    if (!tmp->right)
                    {
                        tmp->right = newnode;
                        newnode->parent = tmp->right;
                        break;
                    }
                    else
                        tmp = tmp->right;
                }
            }
        }
    }

    node *find(int v)
    {
        node *tmp = m_root;
        while (tmp)
        {
            if (tmp->val == v)
                return tmp;
            else
            {
                if (v < tmp->val)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
        }
        return NULL;
    }
    node *min(node *root)
    {
        node *tmp = root;
        while (tmp->left)
            tmp = tmp->left;
        return tmp;
    }

    int delete_min()
    { //delete minimal node and return it
        node *tmp = m_root;
        // tranverse to leftmost node
        while (tmp->left)
        {
            tmp = tmp->left;
        }
        if (tmp->right)
            tmp->right->parent = tmp->parent;
        if (tmp->parent)
            tmp->parent->left = tmp->right;
        else // smallest node is the root
            m_root = tmp->right;

        return tmp->val;
    }

    node *next_large(node *curr)
    {
        //return the next larger node than curr
        if (curr->right)
            return min(curr->right);
        else
        {
            node *x = curr;
            while (x->parent && x->parent->right == x)
            {
                x = x->parent;
            }
            return x->parent;
        }
    }

    int rank(node *curr)
    { // return the number of keys <= t in the subtree rooted at this node
        if (!curr->left)
            return 1;
        else
        {
            if (!curr->right)
                return curr->size;
            else
                return curr->size - curr->right->size;
        }
    }
};