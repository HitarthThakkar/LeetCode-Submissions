#define paic pair<int, char>
class Solution
{
public:
    string reorganizeString(string s)
    {
        vector<int> mp(26, 0);
        for(auto ch : s) mp[ch - 'a']++;
        priority_queue<paic> pq;
        for(int i = 0; i < 26; i++) if(mp[i] > 0) pq.push({mp[i], i + 'a'});
        string res = "";
        paic prev = {0, 'a'};
        while(!pq.empty())
        {
            int f = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            f--;
            res += ch;
            if(prev.first > 0) pq.push(prev);
            prev = {f, ch};
        }
        return (res.length() < s.length() ? "" : res);
    }
};