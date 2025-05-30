class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int maxSum = 0;
        int runningSum = 0;
        int optimalEndingIndex = 0;
        int starter = 0;

        for(int i = 0; i < n; i++)
        {
            runningSum += (gas[i] - cost[i]);
            if(runningSum >= maxSum)
            {
                maxSum = runningSum;
                optimalEndingIndex = i;
            }
            if(runningSum < 0)
            {
                runningSum = 0;
                starter = i + 1;
                maxSum = 0;
                optimalEndingIndex = 0;
            }
        }

        // cout << optimalEndingIndex << " " << starter << endl;
        // cout << maxSum << endl;

        int i = optimalEndingIndex + 1;

        while(i != optimalEndingIndex)
        {
            // cout << i << " " << maxSum << endl;
            i %= n;
            maxSum += gas[i];
            if(maxSum < cost[i]) return -1;
            else maxSum -= cost[i];
            i++;
            i %= n;
        }

        return starter;
    }
};