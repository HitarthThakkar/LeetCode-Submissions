class Solution
{
public:
    int maximumCandies(vector<int>& candies, long long k)
    {
        long long int sum = 0;
        for(auto candy : candies) sum += candy;
        long long int lo = 1;
        long long int hi = sum;
        int answer = 0;
        long long int ogk = k;
        while(lo <= hi)
        {
            long long int mid = (lo + hi) / 2;
            for(auto noofcandy : candies)
            {
                long long int times = (noofcandy / mid);
                if(k > 0) k -= times; else break;
            }
            if(k <= 0)
            {
                answer = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
            k = ogk;
        }
        return answer;
    }
};