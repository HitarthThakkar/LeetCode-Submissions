class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int lmex = height[0];
        int rmex = height[n - 1];
        int answer = 0;

        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                answer += max(min(lmex, rmex) - height[l], 0);
                l++;
                if(l < n) lmex = max(lmex, height[l]);
            }
            else
            {
                answer += max(min(lmex, rmex) - height[r], 0);
                r--;
                if(r >= 0) rmex = max(rmex, height[r]);
            }
        }

        return answer;
    }
};