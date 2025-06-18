class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        // 0 to lo - 1 => zeros
        // lo to mid - 1 => ones
        // mid to hi => unsorted
        // hi + 1 to end => twos

        int n = nums.size();
        int lo = 0;
        int mid = 0;
        int hi = n - 1;

        while(mid <= hi)
        {
            if(nums[mid] == 0)
            {
                if(lo == mid) mid++;
                else {
                    swap(nums[lo], nums[mid]);
                    lo++;
                }
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
    }
};