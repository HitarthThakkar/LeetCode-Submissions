class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int totalSeats = 0;
        for(auto c : corridor) if(c == 'S') totalSeats++;
        if(totalSeats & 1 || totalSeats == 0) return 0;

        int podhaCount = 0;
        int runningSeatsCount = 0;
        long long int res = 1;
        int mod = 1e9 + 7;

        for(auto c : corridor) {
            if(c == 'S') {
                runningSeatsCount++;

                if((runningSeatsCount > 0) && (runningSeatsCount % 2 == 0)) {
                    podhaCount = 0;
                }
                else if((runningSeatsCount > 1) && (runningSeatsCount & 1)) {
                    res = (((res % mod) * (((podhaCount + 1) % mod))) % mod);
                }
            }
            else {
                podhaCount++;
            }
        }

        return res;
    }
};