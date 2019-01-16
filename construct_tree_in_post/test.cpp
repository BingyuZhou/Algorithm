#include "solve.cpp"
#include <iostream>
#include "../tree_traversal/bfs.cpp"
using namespace std;

int main()
{
    vector<int> in_order{9, 3, 15, 20, 7};
    vector<int> post_order{9, 15, 7, 20, 3};

    TreeNode *root = construct::solve(in_order, post_order);

    vector<vector<int>> res = level_order::traverse(root);
    for_each(res.begin(), res.end(), [](vector<int> v) { for (auto i:v) cout<<i<<"\t"; cout<<endl; });
}