#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include "node.h"
using namespace std;

// level by level
class level_order
{

  public:
    level_order(){};

    static vector<vector<int>> traverse(TreeNode *root)
    {
        // Iterative version of traverse using stack
        queue<TreeNode *> col;
        queue<TreeNode *> next;
        if (root)
            col.push(root);
        vector<int> level;
        vector<vector<int>> res;
        while (!col.empty())
        {
            TreeNode *tmp = col.front();
            level.push_back(tmp->val);
            col.pop();
            if (tmp->left)
                next.push(tmp->left);
            if (tmp->right)
                next.push(tmp->right);
            if (col.empty())
            {
                res.push_back(level);
                level.clear();
                col = next;
                queue<TreeNode *>().swap(next); // empty the queue
            }
        }
        return res;
    }
};