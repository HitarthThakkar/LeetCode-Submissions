class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> answer;
        int min = 0; int mex = s.length();
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'I') answer.push_back(min++);
            else answer.push_back(mex--);
        }
        answer.push_back(min);
        return answer;
    }
};