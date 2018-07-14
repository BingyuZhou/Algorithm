
#include "merge_sort.cpp"

int main()
{
    std::vector<int> v1{1, 2, 9, 3, 5, 4, 11, 7};
    std::vector<int> v2{2, 12, 43, 1, 9};

    std::vector<int>
        result = merge_sort(v2);

    for (int i = 0; i < v2.size(); i++)
    {
        std::cout<< result[i]<<std::endl;
    }
}
