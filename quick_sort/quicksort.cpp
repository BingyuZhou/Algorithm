#include <iostream>
#include <array>

using namespace std;

void *swap(int *l, int a, int b)
{
    int c = l[b];
    l[b] = l[a];
    l[a] = c;
}

int partition(int *l, int lo, int hi, int pivot)
{
    int lo_ptr = lo;     //pointer starts from begin
    int hi_ptr = hi - 1; //pointer starts from end excluding pivot

    while (true)
    {
        // find the element bigger than pivot
        while (lo_ptr < hi && l[lo_ptr] <= pivot) // do not need to check teh accessibility of lo_ptr, since the last value equals pivot
        {
            lo_ptr++;
        }
        // find the element smaller than pivot
        while (hi_ptr > lo && l[hi_ptr] >= pivot)
        {
            hi_ptr--;
        }
        if (lo_ptr < hi_ptr)
            swap(l, lo_ptr, hi_ptr);
        else
            break;
    }
    // the last lo_ptr will be the right position for pivot, just swap
    swap(l, lo_ptr, hi);
    return lo_ptr;
}

void quicksort(int l[], int lo, int hi)
{
    if (lo < hi)
    {
        int pivot = l[hi]; // last number as pivot

        int p = partition(l, lo, hi, pivot); // find the right position of pivot

        quicksort(l, lo, p - 1); // quick sort left partition
        quicksort(l, p + 1, hi); // quick sort right partition
    }
}

int main()
{
    int test1[11] = {1, 2, 90, 87, 32, 4, 9, 100, 22, 21, 10};
    quicksort(test1, 0, 10);

    int test2[] = {0, 0, -2, 3, 0, 1}; //for duplicate numbers
    quicksort(test2, 0, 5);
    for (auto c : test1)
        cout << c << endl;
}