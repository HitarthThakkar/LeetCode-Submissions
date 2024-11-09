class Solution
{
public:
    long long minEnd(int n, int x)
    {
        n--; int i = 63, j = 63; long long int ans = 0, mul = 1;
        vector<int> binx(64, 0), binnmo(64, 0);
        while(n) { if(n & 1) binnmo[i] = 1; else binnmo[i] = 0; n /= 2; i--; }
        i = 63;
        while(x) { if(x & 1) binx[i] = 1; else binx[i] = 0; x /= 2; i--; }
        for(int i = 63; i >= 0; i--)
        {
            while(j >= 0 && binx[j] != 0) j--;
            if(j >= 0) binx[j] = binnmo[i], j--; else break;
        }
        for(int i = 63; i >= 2; i--) { ans += (mul * binx[i]); mul *= 2; }
        return ans;
    }
};