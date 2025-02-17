class Solution
{
public:
    int recur(int lengthLeft, map<char, int> &mp)
    {
        if(lengthLeft == 0) return 1;
        int answer = 0;
        for(auto &ele : mp)
        {
            if(ele.second > 0)
            {
                ele.second--;
                answer += recur(lengthLeft - 1, mp);
                ele.second++;
            }
        }
        return answer;
    }
    int numTilePossibilities(string tiles)
    {
        map<char, int> m;
        for(auto ch : tiles) m[ch]++;
        int ans = 0;
        for(int len = 1; len <= tiles.length(); len++)
        {
            map<char, int> mp = m;
            ans += recur(len, mp);
        }
        return ans;
    }
};