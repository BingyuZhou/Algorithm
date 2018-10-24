#include <iostream>
#include <vector>

using namespace std;

class heap_sort
{
    void build_max_heap(vector<int> &a)
    {
        int s = a.size();
        for (int i = (s >> 1) - 1; i >= 0; --i)
            max_heapify(a, i, s);
    }
    void max_heapify(vector<int> &a, const int &node, const int &heap_size)
    {
        int left = (node << 1) + 1;
        int right = left + 1;
        int largest;

        if (left < heap_size && a[node] < a[left])
            largest = left;
        else
            largest = node;
        if (right < heap_size && a[largest] < a[right])
            largest = right;
        if (largest != node)
        {
            int tmp = a[node];
            a[node] = a[largest];
            a[largest] = tmp;

            max_heapify(a, largest, heap_size);
        }
    }

  public:
    __attribute__((const)) heap_sort(){};
    __attribute__((const)) ~heap_sort(){};

    void sort(vector<int> &a)
    {
        build_max_heap(a);
        int heap_size = a.size();
        for (int i = a.size() - 1; i > 0; --i)
        {
            int tmp = a[0];
            a[0] = a[i];
            a[i] = tmp;
            max_heapify(a, 0, --heap_size);
        }
    }
};