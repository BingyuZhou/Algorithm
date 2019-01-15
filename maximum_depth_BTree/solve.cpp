#include "../tree_traversal/node.h"
#include <algorithm>
class max_depth_BTree
{
    int max_depth = 0;
    void step(TreeNode *n, int depth)
    {
        if (!n)
            return;
        if (n->left == nullptr && n->right == nullptr)
            max_depth = std::max(depth, max_depth);
        step(n->left, depth + 1);
        step(n->right, depth + 1);
    }

  public:
    max_depth_BTree() {}
    int top_down(TreeNode *root)
    {
        step(root, 1);
        return max_depth;
    }
    int bottom_up(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int depth_l = bottom_up(root->left);
        int depth_r = bottom_up(root->right);
        return std::max(depth_l, depth_r) + 1;
    }
};