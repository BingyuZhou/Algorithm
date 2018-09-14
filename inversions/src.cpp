#include <iostream>
#include <vector>
using namespace std;

class solver
{
  public:
    solver(){};
    int merge(vector<int> &res, vector<int> left, vector<int> right)
    {
        // if left[i]>right[j], then left[i+1]...left[end] > right[j]
        int num = 0, j = 0;
        res.clear();
        for (int i = 0; i < left.size(); ++i)
        {
            while (j < right.size() && left[i] > right[j])
            {
                num += left.size() - i;
                res.push_back(right[j]);
                ++j;
            }
            res.push_back(left[i]);
        }
        if (j < right.size())
            res.insert(res.end(), right.begin() + j, right.end());
        return num;
    }

    int solve(vector<int> &seq)
    {
        if (seq.size() == 1)
            return 0;

        int len = seq.size();
        vector<int> left(seq.begin(), seq.begin() + len / 2);
        vector<int> right(seq.begin() + len / 2, seq.end());
        int num_left = solve(left);
        int num_right = solve(right);
        int num_merge = merge(seq, left, right);
        return num_left + num_right + num_merge;
    }
};