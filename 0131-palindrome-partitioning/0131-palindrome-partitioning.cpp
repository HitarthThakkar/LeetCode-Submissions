class Solution
{
private:
    void recur(int i, string &s, string temp, vector<string> &ss, vector<vector<string>> &answer)
    {
        if(i == s.length())
        {
            string rtemp = temp;
            reverse(rtemp.begin(), rtemp.end());
            if(temp == rtemp)
            {
                ss.push_back(temp);
                answer.push_back(ss);
                ss.pop_back();
            }
            return;
        }

        temp += s[i];
        recur(i + 1, s, temp, ss, answer);
        temp.pop_back();

        string rtemp = temp;
        reverse(rtemp.begin(), rtemp.end());
        if(temp == rtemp && temp.length() > 0)
        {
            ss.push_back(temp);
            string newtemp = "";
            newtemp += s[i];
            recur(i + 1, s, newtemp, ss, answer);
            ss.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> answer;
        vector<string> ss;
        string temp = "";
        recur(0, s, temp, ss, answer);
        return answer;
    }
};