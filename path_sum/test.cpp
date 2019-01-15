#include "solve.cpp"
#include <iostream>

int main()
{
    // Build tree
    TreeNode *root = new TreeNode(5);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(8);
    TreeNode *n3 = new TreeNode(11);
    TreeNode *n4 = new TreeNode(13);
    TreeNode *n5 = new TreeNode(4);
    TreeNode *n6 = new TreeNode(7);
    TreeNode *n7 = new TreeNode(2);

    root->left = n1;
    root->right = n2;
    n1->left = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    auto solve = is_path_sum();
    bool r = solve.solve(root, 22);
    cout << r << endl;
}