#define max(a,b) (a) > (b) ? (a) : (b)

int longestSubarray(int* nums, int n)
{
    int mex = 0;
    for(int i = 0; i < n; i++) mex = max(mex, nums[i]);

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] == mex)
        {
            int start = i;
            while(i < n && nums[i] == mex) i++;
            res = max(res, i - start);
        }
    }

    return res;
}