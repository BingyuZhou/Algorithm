#include "src.cpp"

int main(int argc, char const *argv[])
{
    vector<int> a{2, 3, 8, 6, 1, 9};
    solver s = solver();
    int num = s.solve(a);
    cout << num << endl;
    return 0;
}
