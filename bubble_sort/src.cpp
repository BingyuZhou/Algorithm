#include <iostream>
#include <vector>

using namespace std;

class bubble_sort
{
  public:
    bubble_sort(){};
    void solve(vector<int> &seq)
    {
        int length = seq.size();
        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = length - 1; j > i; --j)
            {
                if (seq[j] < seq[j - 1])
                {
                    int tmp = seq[j];
                    seq[j] = seq[j - 1];
                    seq[j - 1] = tmp;
                }
            }
        }
    }

    ~bubble_sort(){};
};