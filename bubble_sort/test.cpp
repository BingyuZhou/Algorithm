#include "src.cpp"
#include <algorithm>

int main(int argc, char const *argv[])
{
    vector<int> a{-23, 23, 1, 8, 3, 21, 5, -23};
    bubble_sort solver = bubble_sort();
    solver.solve(a);
    for_each(a.begin(), a.end(), [](int i) { cout << i << endl; });
    return 0;
}
