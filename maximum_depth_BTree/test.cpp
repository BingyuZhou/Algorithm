#include "solve.cpp"
#include <iostream>
using namespace std;

int main()
{
    // Build tree
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(3);

    root->right = n1;
    root->left = n2;
    n1->left = n3;
    n1->right = n4;

    auto solve = max_depth_BTree();
    int r_1 = solve.top_down(root);
    int r_2 = solve.bottom_up(root);

    cout << r_1 << "\t" << r_2 << endl;
}