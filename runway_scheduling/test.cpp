#include "bst.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    binaray_search_tree s = binaray_search_tree();

    s.insert(49);
    s.insert(41);
    s.insert(79);
    s.insert(39);
    s.insert(46);

    cout << s.rank(s.m_root) << endl;

    return 0;
}
