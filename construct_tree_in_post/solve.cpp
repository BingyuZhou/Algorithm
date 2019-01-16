#include "../tree_traversal/node.h"
#include <algorithm>
#include <vector>

using namespace std;

// https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/942/
class construct
{

  public:
    construct() {}

    static TreeNode *solve(vector<int> &inorder, vector<int> &postorder)
    {
        /** 
         * - Last element in postorder is the root
         * - Find the root in inorder, note as [P]
         * - Left elements of the root in inorder are left branch
         * - Right elements of the root in inorder are right branch
         * - Seperate the postorder according the index [P]
         * - Recurse for the left branch and right branch
         * */
        TreeNode *root = new TreeNode(postorder.back());

        if (inorder.size() == 1)
            return root;
        int ind = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();

        if (ind == 0)
        {
            vector<int> tmp(inorder.begin() + 1, inorder.end());
            vector<int> post_tmp(postorder.begin(), postorder.begin() + postorder.size() - 1);
            TreeNode *right = solve(tmp, post_tmp);
            root->right = right;
        }
        else
        {
            if (ind == inorder.size() - 1)
            {
                vector<int> tmp(inorder.begin(), inorder.begin() + inorder.size() - 1);
                vector<int> post_tmp(postorder.begin(), postorder.begin() + postorder.size() - 1);
                TreeNode *left = solve(tmp, post_tmp);
                root->left = left;
            }
            else
            {
                vector<int> tmp_l(inorder.begin(), inorder.begin() + ind);
                vector<int> tmp_r(inorder.begin() + ind + 1, inorder.end());
                vector<int> post_tmp_l(postorder.begin(), postorder.begin() + ind);
                vector<int> post_tmp_r(postorder.begin() + ind, postorder.begin() + postorder.size() - 1);
                TreeNode *left = solve(tmp_l, post_tmp_l);
                TreeNode *right = solve(tmp_r, post_tmp_r);
                root->left = left;
                root->right = right;
            }
        }
        return root;
    }
};