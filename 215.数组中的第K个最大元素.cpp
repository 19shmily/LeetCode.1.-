#include<iostream>
#include<vector>

using namespace std;

class Solution_215 {
    void adjust(vector<int>& heap, int root)
    {
        int m = heap.size();
        int l = 2 * root + 1;
        int r = 2 * root + 2;
        int tmp = root;
        if (l < m && heap[tmp] < heap[l])
        {
            tmp = l;
        }
        if (r < m && heap[tmp] < heap[r])
        {
            tmp = r;
        }
        if (tmp != root)
        {
            swap(heap[root], heap[tmp]);
            adjust(heap, tmp);
        }
    }
    void build_heap(vector<int>&heap)
    {
        int m = heap.size();
        for (int n = m / 2; n >= 0; n--)
        {
            adjust(heap, n);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>heap(nums);
        build_heap(heap);
        for (int n = 0; n < k - 1; n++)
        {
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            adjust(heap, 0);
        }
        return heap[0];
    }
};

int main()
{
    Solution_215 test;
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(4);
    test.findKthLargest(arr, 2);
    return 0;
}