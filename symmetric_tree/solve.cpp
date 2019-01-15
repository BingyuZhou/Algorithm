#include <algorithm>
#include "../tree_traversal/node.h"
using namespace std;

class is_symmetric
{
    bool check_sym(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        else
        {
            if (r1 == nullptr || r2 == nullptr)
                return false;
        }
        if (r1->val != r2->val)
            return false;
        bool res1 = check_sym(r1->left, r2->right);
        bool res2 = check_sym(r1->right, r2->left);
        return (res1 & res2);
    }

  public:
    is_symmetric(){};
    bool solve(TreeNode *root)
    {
        return check_sym(root->left, root->right);
    }
};