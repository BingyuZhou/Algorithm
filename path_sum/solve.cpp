#include <algorithm>
#include <stack>
#include <unordered_map>
#include "../tree_traversal/node.h"
using namespace std;

class is_path_sum
{
    bool exist = false;
    int m_sum;

  public:
    is_path_sum(){};
    bool solve(TreeNode *root, int sum)
    {
        stack<TreeNode *> s;
        s.push(root);
        unordered_map<TreeNode *, int> col;
        col[root] = root->val;
        while (!s.empty())
        {
            auto tmp = s.top();
            s.pop();
            if (tmp->left == nullptr && tmp->right == nullptr)
                if (col[tmp] == sum)
                    return true;
            if (tmp->right)
            {
                col[tmp->right] = col[tmp] + tmp->right->val;
                s.push(tmp->right);
            }
            if (tmp->left)
            {
                col[tmp->left] = col[tmp] + tmp->left->val;
                s.push(tmp->left);
            }
        }
        return false;
    }
};