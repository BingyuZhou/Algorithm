
#include "avlt.cpp"
using namespace std;

void test_bst()
{
    binaray_search_tree s = binaray_search_tree();

    s.insert(49);
    s.insert(41);
    s.insert(79);
    s.insert(39);
    s.insert(46);

    cout << "expect 4 : " << s.rank(s.m_root) << endl;
    cout << "expect 79 : " << s.next_large(s.m_root)->val << endl;

    int min_val;
    node *p;
    std::tie(min_val, p) = s.delete_min();
    cout << "expect 39 41 : " << min_val << " " << p->val << endl;
}

void test_avl()
{
    AVL s = AVL();
    s.insert(41);
    s.insert(20);
    s.insert(65);
    s.insert(11);
    s.insert(29);
    s.insert(50);
    s.insert(26);

    cout << "expect 29 : " << s.m_root->left->right->val << endl;

    s.insert(23);
    cout << "expect 26 : " << s.m_root->left->right->val << endl;
    cout << "expect 1 : " << s.m_root->left->right->h << endl;

    s.insert(55);
    cout << "expect 55 : " << s.m_root->right->val << endl;
}
int main(int argc, char const *argv[])
{
    test_bst();
    test_avl();

    return 0;
}
