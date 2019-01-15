#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "node.h"
using namespace std;

// root left right
class pre_order
{

  public:
    pre_order(){};
    static vector<int> traverse(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;

        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        res.push_back(root->val);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }

    static vector<int> traverse_itr(TreeNode *root)
    {
        // Iterative version of traverse using stack
        stack<TreeNode *> col;
        col.push(root);
        vector<int> res;
        while (!col.empty())
        {
            TreeNode *tmp = col.top();
            res.push_back(tmp->val);
            col.pop();
            if (tmp->right)
                col.push(tmp->right);
            if (tmp->left)
                col.push(tmp->left);
        }
        return res;
    }
};