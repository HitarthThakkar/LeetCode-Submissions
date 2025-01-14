class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            int ct = 0;
            m[A[i]]++;
            if(m[A[i]] == 2) ct++;
            m[B[i]]++;
            if(m[B[i]] == 2) ct++;
            ans[i] = ct;
            if(i > 0) ans[i] += ans[i - 1];
        }
        return ans;
    }
};