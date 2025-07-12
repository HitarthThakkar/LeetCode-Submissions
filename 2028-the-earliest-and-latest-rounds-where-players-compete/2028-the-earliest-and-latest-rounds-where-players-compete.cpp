class Solution
{
public:
    // DP submission, not as readable as this one, but built upon recursive one.

    int mini = INT_MAX, mexi = INT_MIN; // mini and mexi which is to be returned;

    // Global variables (we can actually pass these in recur, but lazy).
    int ncp;
    int f, s;

    int dp[27][27][27];

    void recur(int i, int j, int mask, int curRoundNo, int l, int m, int r)
    {
        if(i >= j)
        {
            // l, m, r does not change cuz we are not killing anyone here.
            recur(0, ncp - 1, mask, curRoundNo + 1, l, m, r);
        }
        else if((mask & (1 << i)) == 0)
        {
            // l, m, r does not change cuz we are not killing anyone here.
            recur(i + 1, j, mask, curRoundNo, l, m, r);
        }
        else if((mask & (1 << j)) == 0)
        {
            // l, m, r does not change cuz we are not killing anyone here.
            recur(i, j - 1, mask, curRoundNo, l, m, r);
        }

        // now i and j are both alive and can compete.

        else if((i == f && j == s) || (i == s && j == f))
        {
            // base case, no killing.
            mini = min(mini, curRoundNo);
            mexi = max(mexi, curRoundNo);
        }
        else if(i == f || i == s)
        {
            // j is going to die, how to change l, m, r ?
            // depends upon j's position.
            // if j is before the 'f', then l decreases by 1.
            // if j is in between of 'f' and 's', then m decreases by 1.
            // if j is after the 's', then r decreases by 1.
            mask = mask ^ (1 << j);
            recur(i + 1, j - 1, mask, curRoundNo, l - (j < f), m - ((j > f) && (j < s)), r - (j > s));
        }
        else if(j == f || j == s)
        {
            // same as j
            mask = mask ^ (1 << i);
            recur(i + 1, j - 1, mask, curRoundNo, l - (i < f), m - ((i > f) && (i < s)), r - (i > s));
        }
        else if(dp[l][m][r] == -1)
        {
            dp[l][m][r] = 1;    // Marking this state as visited so in future we dont call these two recur.
            // we dont need to call a function with if its called before with exact l,m,r before. why? idk, but works.

            // killing both whichever might give better answer in future.
            recur(i + 1, j - 1, mask ^ (1 << j), curRoundNo, l - (j < f), m - ((j > f) && (j < s)), r - (j > s));   // j dead
            recur(i + 1, j - 1, mask ^ (1 << i), curRoundNo, l - (i < f), m - ((i > f) && (i < s)), r - (i > s));   // i dead
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        // Initialize global ppl
        ncp = n;
        f = firstPlayer - 1;
        s = secondPlayer - 1;
        // Initializing DP also
        memset(dp, -1, sizeof dp);

        // Initially all are alive, hence mask is 111....1, when someone dies we'll set it to 0.

        // We now have 3 more variables passing through called {l, m, r}.
        // l -> ct of ppl before the firstPlayer at any time
        // m -> ct of ppl after the firstPlayer and before the secondPlayer at any time
        // r -> ct of ppl after the secondPlayer at any time

        // Why this variables ? cuz there ppl define the DP state uniquely and consicely.
        // how do i know that these can define the DP state perfectly ? i actually don't.
        // how can i (future me) know that ? idk read / practice.

        recur(0, n - 1, (1 << n) - 1, 1, f, s - f - 1, n - s - 1);  // initial values of l,m,r.

        return {mini, mexi};
    }
};