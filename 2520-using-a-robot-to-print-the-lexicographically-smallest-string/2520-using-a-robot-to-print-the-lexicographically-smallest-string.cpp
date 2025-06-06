class Solution
{
public:
    string robotWithString(string s)
    {
        int n = s.length();

        string ss = s;
        sort(ss.begin(), ss.end());
        // cout << ss << endl;

        stack<char> st;

        vector<int> rem(26, 0);
        for(auto c : ss) rem[c - 'a']++;

        // for(auto e : rem) cout << e << " "; cout << endl;

        string result = "";
        int i = 0;

        for(int ptr = 0; ptr < n; ptr++)
        {
            // cout << result << endl;

            if(rem[ss[ptr] - 'a'] > 0)
            {
                char c = ss[ptr];

                while(!st.empty())
                {
                    if(st.top() <= c)
                    {
                        result += st.top();
                        st.pop();
                    }
                    else
                    {
                        break;
                    }
                }

                while(i < n && s[i] != c)
                {
                    st.push(s[i]);
                    rem[s[i] - 'a']--;
                    i++;
                }

                if(i >= n) break;

                rem[c - 'a']--;
                result += c;
                i++;
            }
        }

        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};