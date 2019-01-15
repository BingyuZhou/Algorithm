#include <iostream>
#include <algorithm>
#include <vector>
#include "node.h"
using namespace std;

// left root right
class in_order
{

  public:
    in_order(){};
    static vector<int> traverse(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;

        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        res.insert(res.end(), left.begin(), left.end());
        res.push_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};