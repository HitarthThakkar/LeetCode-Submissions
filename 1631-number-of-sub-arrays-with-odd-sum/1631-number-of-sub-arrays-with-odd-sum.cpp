class Solution
{
public:
    int numOfSubarrays(vector<int>& arr)
    {
        int mod = 1e9 + 7;
        long long int ans = 0;
        long long int sum = 0;
        int even = 1, odd = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if(sum & 1) ans += even; else ans += odd;
            if(sum & 1) odd++; else even++;
            ans %= mod;
        }
        return ans;
    }
};