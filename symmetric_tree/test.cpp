#include "solve.cpp"
#include <iostream>

int main()
{
    // Build tree
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(4);
    TreeNode *n6 = new TreeNode(1);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    auto solve = is_symmetric();
    bool r = solve.solve(root);
    cout << r << endl;
}