class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int>& heights)
    {
        stack<int> s;
        vector<int> res(heights.size(), 0);

        for(int i = heights.size() - 1; i >= 0; i--)
        {
            int eaten = 0;
            while(!s.empty() && heights[i] > s.top())
            {
                eaten++;
                s.pop();
            }
            if(!s.empty()) eaten++;
            res[i] = eaten;
            s.push(heights[i]);
        }
        return res;
    }
};