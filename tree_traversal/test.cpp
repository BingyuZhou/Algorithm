#include "pre_order.cpp"
#include "in_order.cpp"
#include "post_order.cpp"
#include "bfs.cpp"

int main()
{
    // Build tree
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);

    root->right = n1;
    n1->left = n2;

    vector<int> preorder = pre_order::traverse(root);
    vector<int> inorder = in_order::traverse(root);
    vector<int> postorder = post_order::traverse(root);

    vector<int> preorder_itr = pre_order::traverse_itr(root);

    vector<vector<int>> bfs = level_order::traverse(root);

    cout << "-----pre order----" << endl;
    for_each(preorder.begin(), preorder.end(), [](int v) { cout << v << endl; });
    cout << "-----in order----" << endl;
    for_each(inorder.begin(), inorder.end(), [](int v) { cout << v << endl; });
    cout << "-----post order----" << endl;
    for_each(postorder.begin(), postorder.end(), [](int v) { cout << v << endl; });
    cout << "-----pre order itr----" << endl;
    for_each(preorder_itr.begin(), preorder_itr.end(), [](int v) { cout << v << endl; });

    cout << "--------level order------------" << endl;
    for_each(bfs.begin(), bfs.end(), [](vector<int> v) { for (auto i:v) cout<<i; cout<<endl; });
}