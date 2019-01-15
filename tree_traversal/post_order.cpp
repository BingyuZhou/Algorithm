#include <iostream>
#include <algorithm>
#include <vector>
#include "node.h"
using namespace std;

// left right root
class post_order
{

  public:
    post_order(){};
    static vector<int> traverse(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;

        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);

        return res;
    }
};