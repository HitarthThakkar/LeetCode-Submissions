class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int n = s.length();
        int weHave = n - k + 1;
        int weNeed = pow(2, k);

        if(weHave < weNeed) return false;

        unordered_set<string> st;
        for(int i = 0; i < weHave; i++) st.insert(s.substr(i, k));

        return (st.size() == weNeed);
    }
};