#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> lhs, vector<int> rhs)
{
    vector<int> r(lhs.size() + rhs.size());
    int i = 0, j = 0;
    int k = 0;
    for (k = 0; k < r.size(); k++)
    {
        if (lhs[i] < rhs[j])
        {
            r[k] = lhs[i];
            ++i;
            if (i == lhs.size())
                break;
        }
        else
        {
            r[k] = rhs[j];
            ++j;
            if (j == rhs.size())
                break;
        }
    }

    if (i < lhs.size())
    {
        while(k<r.size()-1){
            r[++k] = lhs[i++];
        }
    }
    if (j < rhs.size())
        while(k<r.size()-1){
            r[++k]=rhs[j++];
        }
    
    return r;
}

vector<int> merge_sort(vector<int> v)
{
    if (v.size() == 1)
        return v;
    else
    {
        int mid = v.size() / 2;
        vector<int> a(v.begin(), v.begin() + mid);
        vector<int> b(v.begin() + mid, v.end());

        vector<int> lhs = merge_sort(a);
        vector<int> rhs = merge_sort(b);

        return merge(lhs, rhs);
    }
}

