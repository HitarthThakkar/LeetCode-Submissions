class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int stn = 1;
        for(int i = 2; i <= sqrt(num); i++)
        {
            if((i * i) == num) stn += i;
            else if(num % i == 0) stn += i, stn += (num / i);
        }
        return ((stn == num) && (num != 1));
    }
};