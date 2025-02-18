class Solution
{
private:
    bool recur(int ind, char prev, bool sign, map<char, int> &left, string &answer, string pattern)
    {
        for(auto &pr : left)
        {
            if((pr.second > 0) && ((sign && pr.first > prev) || (!sign && pr.first < prev)))
            {
                answer += pr.first;
                if(ind == pattern.length()) return true;
                pr.second--;
                bool newsign = (pattern[ind] == 'D' ? false : true);
                if(recur(ind + 1, pr.first, newsign, left, answer, pattern)) return true;
                pr.second++;
                answer.pop_back();
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern)
    {
        map<char, int> left;
        for(char c = '1'; c <= '9'; c++) left.insert({c, 1});
        bool sign = true;
        string answer = "";
        recur(0, '0', sign, left, answer, pattern);
        return answer;
    }
};