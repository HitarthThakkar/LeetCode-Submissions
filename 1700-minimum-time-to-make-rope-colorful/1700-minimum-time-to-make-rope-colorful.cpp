class Solution
{
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int mex = neededTime[0];
        int total = mex;
        int result = 0;

        for(int i = 1; i < colors.length(); i++)
        {
            if(colors[i] == colors[i - 1])
            {
                mex = max(mex, neededTime[i]);
                total += neededTime[i];
            }
            else
            {
                result += (total - mex);
                total = neededTime[i]; mex = total;
            }
        }

        result += (total - mex);
        return result;
    }
};