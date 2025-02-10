class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;string ans="";
        for(auto ch : s) if(ch <= '9')st.pop();else st.push(ch);
        while(!st.empty()){ans+=st.top();st.pop();}
        reverse(ans.begin(),ans.end());return ans;
    }
};