class Solution
{
private:
    long long f(long long time, vector<int> &ranks)
    {
        long long cars = 0;
        for(auto ele : ranks) cars += ((int) sqrt(time / ele));
        return cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars)
    {
        long long mex = *max_element(ranks.begin(), ranks.end());
        mex *= cars; mex *= cars;
        long long mini = 0;
        long long int lo = mini;
        long long int hi = mex;
        long long int ans = mex;
        while(lo <= hi)
        {
            long long mid = ((lo) + ((hi - lo) / 2));
            if(f(mid, ranks) >= cars) ans = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return ans;
    }
};