class Solution
{
public:
    unordered_set<int> path;
    long long dp[16][2][10];

    vector<int> vect(long long n)
    {
        vector<int> res(16, 0);
        int i = 15;
        while(n)
        {
            res[i] = (n % 10);
            n /= 10;
            i--;
        }
        return res;
    }

    long long recur(int i, int tight, int prv, vector<int> &vr)
    {
        if(i > 15) return 1;
        if(dp[i][tight][prv] != -1) return dp[i][tight][prv];
        long long ct = 0;

        int mexi = (tight ? vr[i] : 9);
        bool pathInd = (path.find(i) != path.end());
        int mini = (pathInd ? prv : 0);

        for(int k = mini; k <= mexi; k++)
        {
            ct += recur(i + 1, (tight && k == mexi), (pathInd ? k : prv), vr);
        }

        return dp[i][tight][prv] = ct;
    }

    long long solve(long long x)
    {
        vector<int> vx = vect(x);
        memset(dp, -1, sizeof(dp));
        return recur(0, 1, 0, vx);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions)
    {
        path.insert(0);
        int row = 0, col = 0;
        for(auto c : directions)
        {
            if(c == 'D') row++; else col++;
            path.insert(row * 4 + col);
        }

        return solve(r) - solve(l - 1);
    }
};