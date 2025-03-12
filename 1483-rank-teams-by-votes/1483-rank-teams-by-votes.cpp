class Solution
{
public:
    string rankTeams(vector<string>& votes)
    {
        // 2025 Hiring Prep Sprint Q6 [Very Good Medium]
        // Previous soln was using toposort, 
        // but it's actually costly and redundant. we don't need it. WE ARE SMART.
        int n = votes.size();
        int len = votes[0].size();
        vector<vector<int>> v(26, vector<int> (len, 0));
        vector<int> ctr(26, 0);
        set<char> valid;
        for(auto ch : votes[0]) valid.insert(ch);
        for(auto s : votes) for(int i = 0; i < len; i++) v[s[i] - 'A'][i]++;
        for(int i = 0; i < 26; i++)
        {
            if(valid.find('A' + i) != valid.end())
            {
                for(int j = i + 1; j < 26; j++)
                {
                    if(valid.find('A' + j) != valid.end())
                    {
                        int k = 0;
                        while(k < len && v[i][k] == v[j][k]) k++;
                        if(k == len || v[i][k] > v[j][k]) ctr[i]++;
                        else if(v[i][k] < v[j][k]) ctr[j]++;
                    }
                }
            }
        }
        map<int, char> order;
        for(int i = 0; i < 26; i++)
        {
            if(valid.find('A' + i) != valid.end())
            {
                char ch = (char) ('A' + i);
                order[ctr[i]] = ch;
            }
        }
        string result = "";
        for(auto ele : order) result += ele.second;
        reverse(result.begin(), result.end());
        return result;
    }
};