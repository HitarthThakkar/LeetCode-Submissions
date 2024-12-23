class Solution
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        // Min_Heap storing first k elements
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        // for every element now on,
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > min_heap.top()) // If greater than smallest one of those k elements then push
            {
                min_heap.pop();
                min_heap.push(nums[i]); // This way min-heap will contain first k largest elements.
            }
        }

        return min_heap.top(); // smallest of those k largest, i.e. 'k'th largest.
    }
};