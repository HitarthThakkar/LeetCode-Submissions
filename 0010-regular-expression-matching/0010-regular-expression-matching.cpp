class Solution
{
public:
    vector<vector<int>> dp;

    bool recur(int i, int j, int n, int m, string &s, string &p)
    {
        if(i == n)
        {
            if(j==m-2 && p[j+1]=='*') return true;
            if(j == m || (j == m - 1 && p[j] == '*')) return true;
            if(p[j]=='*') j++;
            while(j<m&&j+1<m)if(p[j+1]=='*')j+=2; else return false;
            if(j==m)return true;
            if(j==m-1) return (p[j]=='*');
            return false;
        }
        if(j == m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '.') {
            bool primeMember = false;
            if(j+1<m&&p[j+1]=='*') primeMember=true;
            if(primeMember) if(recur(i,j+2,n,m,s,p)) return dp[i][j]= true;
            return dp[i][j]= recur(i+1,j+1,n,m,s,p);}
        else if(p[j] != '*') {
            bool primeMember = false;
            if(j+1<m&&p[j+1]=='*') primeMember=true;
            if(primeMember) {
                if(s[i]==p[j]){
                    return dp[i][j]= (recur(i+1,j+1,n,m,s,p) || recur(i,j+2,n,m,s,p));
                }
                else{
                    return dp[i][j]= recur(i,j+2,n,m,s,p);
                }
            }
            else {if(s[i] == p[j]) return dp[i][j]= recur(i+1,j+1,n,m,s,p); else return dp[i][j]= false;}
        }
        else {
            if(p[j-1] == '.' || p[j-1] == s[i])
                return dp[i][j]= (recur(i+1,j,n,m,s,p) || recur(i+1,j+1,n,m,s,p) || recur(i,j+1,n,m,s,p));
            else return dp[i][j]= recur(i,j+1,n,m,s,p);
        }
        return dp[i][j]= false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dpp(n, vector<int> (m, -1));
        dp = dpp;
        return recur(0, 0, n, m, s, p);
    }
};