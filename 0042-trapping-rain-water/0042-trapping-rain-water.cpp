class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        vector<int> rightmex(n, 0), leftmex(n, 0);
        int mex = 0;
        for(int i = n - 1; i >= 0; i--) {
            rightmex[i] = mex; mex = max(mex, height[i]);
        }
        mex = 0;
        for(int i = 0; i < n; i++) {
            leftmex[i] = mex; mex = max(mex, height[i]);
        }
        int answer = 0;
        for(int i = 0; i < n; i++)
            answer += max(0, min(leftmex[i], rightmex[i]) - height[i]);
        return answer;
    }
};