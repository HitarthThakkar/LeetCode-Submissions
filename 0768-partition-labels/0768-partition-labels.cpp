class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last(26, -1);
        for(int i = 0; i < s.length(); i++) last[s[i] - 'a'] = i;
        vector<int> answer;
        int start = 0, end = 0, maxReach = 0;
        while(end < s.length())
        {
            maxReach = max(maxReach, last[s[end] - 'a']);
            if(end == maxReach)
            {
                answer.push_back(end - start + 1);
                start = end + 1;
            }
            end++;
        }
        return answer;
    }
};