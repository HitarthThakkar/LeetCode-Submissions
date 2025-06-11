class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        // Swap sort / Cyclic sort ALGORITHM
        // Credits :- 'Aditya Verma' and 'Code concepts with Animesh' [youtube]

        int n = nums.size();
        int i = 0;

        while(i < n)
        {
            if(nums[i] > 0 && nums[i] < n + 1 && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                i++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i + 1) return (i + 1);
        }

        return (n + 1);
    }
};