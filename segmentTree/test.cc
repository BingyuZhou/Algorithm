#include "range_sum_query.cc"
#include <iostream>

int main()
{
    vector<int> nums{-1, 2, 3, 4, 5, -2, -6, -7, 2, 5};
    NumArray s(nums);

    int sum = s.sumRange(2, 8);
    s.update(5, -100);
    cout << sum << endl;
    sum = s.sumRange(2, 8);
    cout << sum << endl;
}