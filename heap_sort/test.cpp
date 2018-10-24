
#include <algorithm>
#include "heap_sort.cpp"

int main()
{
    vector<int> a{12, 45, -1, 2, 33, 89, 2, 90, 100};

    heap_sort solver = heap_sort();

    solver.sort(a);

    for_each(a.begin(), a.end(), [](int v) { cout << v << endl; });
}