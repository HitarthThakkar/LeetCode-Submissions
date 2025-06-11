class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        // Swap sort / Cyclic sort ALGORITHM
        // Credits :- 'Aditya Verma' and 'Code concepts with Animesh' [youtube]

        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == i + 1) continue;

            while(nums[i] != i + 1)
            {
                if(nums[nums[i] - 1] == nums[i]) return nums[i];
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        return -1;
    }
};