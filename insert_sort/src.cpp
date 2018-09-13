#include <iostream>
#include <vector>
using namespace std;

class insert_sort
{
  public:
    insert_sort(){};

    void sort(vector<int> &seq)
    {
        int length = seq.size();

        for (int i = 1; i < length; ++i)
        {
            int key = seq[i];
            int j = i - 1;
            while (j >= 0 && seq[j] > key)
            {
                seq[j + 1] = seq[j];
                --j;
            }
            seq[j + 1] = key;
        }
    }

    ~insert_sort(){};
};