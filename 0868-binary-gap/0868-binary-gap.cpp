class Solution
{
public:
    int binaryGap(int n)
    {
        int i = 0;
        int loi = -1;
        int res = 0;
        while(n) {
            if(n & 1) {
                if(loi != -1) {
                    res = max(res, i - loi);
                }
                loi = i;
            }
            n /= 2;
            i++;
        }
        return res;
    }
};