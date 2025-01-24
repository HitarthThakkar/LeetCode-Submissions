class Solution
{
private:
    void recur(int ind, string &digits,map<char, vector<char>> &mp,
                vector<string> &ans, string &temp)
    {
        if(ind == digits.length()) { ans.push_back(temp); return; }
        for(auto ele : mp[digits[ind]])
        {
            temp.push_back(ele);
            recur(ind + 1, digits, mp, ans, temp);
            temp.pop_back();
        }
    } 
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        map<char, vector<char>> mp;
        mp.insert({'2', {'a','b','c'}});
        mp.insert({'3', {'d','e','f'}});
        mp.insert({'4', {'g','h','i'}});
        mp.insert({'5', {'j','k','l'}});
        mp.insert({'6', {'m','n','o'}});
        mp.insert({'7', {'p','q','r','s'}});
        mp.insert({'8', {'t','u','v'}});
        mp.insert({'9', {'w','x','y','z'}});
        string temp = "";
        recur(0, digits, mp, ans, temp);
        return ans;
    }
};