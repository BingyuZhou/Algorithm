#include "src.cpp"
#include <algorithm>

int main(){
    vector<int> a{0, -2, 3,2,4,34, 2,-9, 236,1116, 96};
    insert_sort solver = insert_sort();
    solver.sort(a);

    for_each(a.begin(), a.end(), [](int b){cout<<b << " "<<endl;});

}