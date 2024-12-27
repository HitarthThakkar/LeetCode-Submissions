class Solution
{
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int n = values.size();
        int i_val = values[0];
        int max_value = 0;
        for(int j = 1; j < n; j++)
        {
            int j_val = values[j] - j;
            max_value = max(max_value, i_val + j_val);
            i_val = max(i_val, values[j] + j);
        }
        return max_value;
    }
};