#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int m_start;
    int m_end;
    int m_sum;
    Node *m_left;
    Node *m_right;
    Node(int start, int end, int sum = 0) : m_start(start), m_end(end), m_sum(sum), m_left(nullptr), m_right(nullptr) {}
};

/** 
 * Range Sum Query - Mutable.
 * 
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * 
 * Example:
 * Given nums = [1, 3, 5]
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 */
class NumArray
{
    Node *m_root = nullptr;

    // Build segment tree
    Node *build_segTree(const vector<int> &nums, const int &start, const int &end)
    {

        if (start == end)
            return new Node(start, end, nums[start]);

        int mid = (start + end) / 2;
        auto node = new Node(start, end);
        node->m_left = build_segTree(nums, start, mid);
        node->m_right = build_segTree(nums, mid + 1, end);
        node->m_sum = node->m_left->m_sum + node->m_right->m_sum;
        return node;
    }

    void update(Node *node, const int &i, const int &val)
    {
        if (node->m_start == node->m_end && node->m_start == i)
            node->m_sum = val;
        else
        {
            if (i >= node->m_left->m_start && i <= node->m_left->m_end)
                update(node->m_left, i, val);
            else
                update(node->m_right, i, val);

            node->m_sum = node->m_left->m_sum + node->m_right->m_sum;
        }
    }
    int sumRange(Node *node, const int &i, const int &j)
    {
        if (node->m_start == i && node->m_end == j)
            return node->m_sum;
        int mid = (node->m_start + node->m_end) / 2;
        // [i,j] lies inside left child
        if (j <= mid)
            return sumRange(node->m_left, i, j);
        // [i,j] lies inside right child
        else
        {
            if (i > mid)
                return sumRange(node->m_right, i, j);
            // [i,j] crosses left and right, have to split to [i, mid], [mid+1,j]
            else
            {
                int sum_left = sumRange(node->m_left, i, mid);
                int sum_right = sumRange(node->m_right, mid + 1, j);
                return sum_left + sum_right;
            }
        }
    }

  public:
    NumArray(vector<int> nums)
    {
        if (nums.size() != 0)
            m_root = build_segTree(nums, 0, nums.size() - 1);
    }
    /**
     *  Update one element in array, O(lgN)
     */
    void update(int i, int val)
    {
        if (m_root)
            update(m_root, i, val);
    }
    /** 
     * Range of sum O(lgN)
     */
    int sumRange(int i, int j)
    {
        if (m_root)
            return sumRange(m_root, i, j);
        else
            return 0;
    }
};