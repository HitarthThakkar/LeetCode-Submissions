class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int nxt = 0, res = 0, n = bank.size();
        for(int i = n - 1; i >= 0; i--)
        {
            int cur = 0;
            for(char e : bank[i]) {
                if(e == '1') cur++;
            }
            res += (cur * nxt);
            if(cur != 0) nxt = cur;
        }
        return res;
    }
};