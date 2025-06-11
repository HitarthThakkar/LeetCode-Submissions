class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        // Swap sort / Cyclic sort ALGORITHM

        // Credits :- 'Aditya Verma' and 'Code concepts with Animesh' [youtube]

        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] < nums.size() && nums[i] != i) swap(nums[nums[i]], nums[i]);
            else i++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};